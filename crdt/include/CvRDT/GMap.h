#pragma once

#include <map>
#include <algorithm> // std::max
#include <utility> // std::pair


namespace CRDT {
namespace CvRDT {


/**
 * Grow Only (add-only) Map.
 * Remove not supported. Update is supported (but merge uses the max value
 * as total order).
 * CvRDT (State-based).
 *
 * Keys are unique.
 *
 * \note
 * Internally, uses std::map
 *
 * \warning
 * Data type T must work with std::max. (is_arithmetic == true)
 *
 *
 * \tparam T Type of element. (Default int)
 * \tparam K Key of element. (Default int)
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename K = int, typename T = int>
class GMap {
    private:
        std::map<K,T> _map;

    public:
        typedef typename std::map<K,T>::iterator            iterator;
        typedef typename std::map<K,T>::const_iterator      const_iterator;
        typedef typename std::map<K,T>::size_type           size_type;
        typedef typename std::map<K,T>::value_type          value_type;


    // -------------------------------------------------------------------------
    // Capacity
    // -------------------------------------------------------------------------

    public:

        /**
         * Check if the container has no elements.
         *
         * \return True if empty, otherwise, return false.
         */
        bool empty() const {
            return _map.empty();
        }

        /**
         * Returns the number of elements in the container.
         *
         * \return Size of the set.
         */
        size_type size() const {
            return _map.size();
        }


    // -------------------------------------------------------------------------
    // Modifier
    // -------------------------------------------------------------------------

    public:

        /**
         * Inserts element into the container, if the container
         * doesn't already contain an element with an equivalent key.
         *
         * \param value {key, data} to add.
         */
        void insert(const value_type& value) {
            _map.insert(value);
        }

        /**
         * Merge with another map.
         * If a key is already in both, replace with max(ours, theirs)
         *
         * std::max is used to create total order.
         * (Won't work is std::max not allowed for T data type).
         */
        void merge(const GMap<K,T>& other) {
            for(const std::pair<K,T>& elt : other._map) {
                if(_map.count(elt.first) == 0) {
                    _map.insert(elt); // Was not already in map
                }
                else {
                    _map[elt.first] = std::max(elt.second, _map[elt.first]);
                }
            }
        }


    // -------------------------------------------------------------------------
    // Lookup
    // -------------------------------------------------------------------------

    public:

        /**
         * Returns the number of elements with key that compares equal
         * to the specified argument key, which is either 1 or 0 since this
         * container does not allow duplicates.
         *
         * \return Number of element with key key.
         */
        size_type count(const K& key) const {
            return _map.count(key);
        }

        /**
         * Finds an element with key equivalent to key.
         *
         * Returns an iterator to an element with key equivalent to key.
         * If no such element is found, past-the-end (see end()) iterator
         * is returned.
         *
         * \param key key value of the element to search for.
         * \return Constant iterator to the element (Or end if no element).
         */
        const_iterator find(const T& key) const {
            return _map.find(key);
        }

        /**
         * Returns a reference to the value that is mapped to a key
         * equivalent to key, performing an insertion if such key does not
         * already exist.
         */
        T& operator[](const K& key) {
            return _map[key];
        }


    // -------------------------------------------------------------------------
    // Iterators
    // -------------------------------------------------------------------------

    public:

        /**
         * Returns an iterator to the first element of the container.
         * If the container is empty, the returned iterator will be
         * equal to end().
         *
         * \return Iterator to the first element.
         */
        iterator begin() {
            return _map.begin();
        }

        /**
         * Returns an iterator to the element following the last element of
         * the container. This element acts as a placeholder.
         * Attempting to access it results in undefined behavior.
         *
         * \return Iterator to the element following the last element.
         */
        iterator end() {
            return _map.end();
        }

        /**
         * \copydoc begin()
         */
        const_iterator cbegin() const {
            return _map.cbegin();
        }

        /**
         * \copydoc end()
         */
        const_iterator cend() const {
            return _map.cend();
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        /**
         * Check if lhs and rhs are equals.
         * Two GMap are equal if their internal map are equal.
         *
         * \return True if equal, otherwise, return false.
         */
        friend bool operator==(const GMap& lhs, const GMap& rhs) {
            return lhs._map == rhs._map;
        }

        /**
         * Check if lhs and rhs are not equals.
         * See operator == for further information about equality meaning.
         *
         * \return True if not equal, otherwise, return false.
         */
        friend bool operator!=(const GMap& lhs, const GMap& rhs) {
            return !(lhs._map == rhs._map);
        }

        /**
         * Display the internal map content.
         * This is mainly for debug print purpose.
         */
        friend std::ostream& operator<<(std::ostream& out, const GMap<K,T>& o) {
            out << "GMap = ";
            for(const std::pair<K,T>& elt : o._map) {
                out << "(" << elt.first << "," << elt.second << ") ";
            }
            return out;
        }
};


}} // End namespace


