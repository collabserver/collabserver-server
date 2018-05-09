#pragma once

#include <unordered_map>
#include <utility> // std::pair

namespace CRDT {
namespace CmRDT {


/**
 * Last-Writer-Wins Map (LWW Map).
 * CmRDT (Operation-based)
 *
 * Associative container that contains key-value pairs with unique keys.
 * Internally uses std::unordered_map. See its documentation for further
 * informations.
 *
 * \note
 * Quote from the CRDT article "A comprehensive study of CRDT":
 *
 * "
 * A Last-Writer-Wins [...] creates a total order of
 * assignments by associating a timestamp with each update.
 * Timestamps are assumed unique, totally ordered, and consistent with causal
 * order; i.e., if assignment 1 happened-before assignment 2,
 * the former's timestamp is less than the latter's. This may be implemented as
 * a per-replicate counter concatenated with a unique replica identifier,
 * such as its MAC address.
 * "
 *
 * \warning
 * Timestamps must have a total order.
 * Two equal timestamps (t1 == t1 returns true) is undefined and replicated
 * may diverge. (See quote and implementation).
 *
 * \tparam T    Type of element.
 * \tparam Key  Type of key.
 * \tparam U    Type of timestamp.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
template<typename Key, typename T, typename U>
class LWWMap {
    private:
        typedef typename std::pair<U, bool> _meta; // bool=true if removed
        typedef typename std::pair<T, _meta> Elt;

        std::unordered_map<Key,Elt> _map;

    public:
        typedef typename std::unordered_map<Key,Elt>::value_type     value_type;
        typedef typename std::unordered_map<Key,Elt>::const_iterator const_iterator;


    // -------------------------------------------------------------------------
    // CRDT methods
    // -------------------------------------------------------------------------

    public:

        const_iterator query(const Key& key) const {
            // TODO
            return this->cend();
        }

        bool insert(const Key& key, const T& value, const U& stamp) {
            // TODO
            return false;
        }

        bool remove(const Key& key, const U& stamp) {
            // TODO
            return false; // TODO
        }

        bool update(const Key& key, const T& value, const U& stamp) {
            // TODO
            return false;
        }


    // -------------------------------------------------------------------------
    // Iterators
    // -------------------------------------------------------------------------

    public:

        /**
         * Returns a constant iterator to the first element of the container.
         * If the container is empty, the returned iterator will be
         * equal to end().
         *
         * \return Constant iterator to the first element.
         */
        const_iterator cbegin() const {
            return _map.cbegin();
        }

        /**
         * Returns a constant iterator to the element following the last element
         * of the container. This element acts as a placeholder.
         * Attempting to access it results in undefined behavior.
         *
         * \return Constant iterator to the element following the last element.
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
         * Two LWWMap are equal if their internal map are equal.
         *
         * \return True if equal, otherwise, return false.
         */
        friend bool operator==(const LWWMap& lhs, const LWWMap& rhs) {
            return lhs._map == rhs._map;
        }

        /**
         * Check if lhs and rhs are not equals.
         * See operator == for further information about equality meaning.
         *
         * \return True if not equal, otherwise, return false.
         */
        friend bool operator!=(const LWWMap& lhs, const LWWMap& rhs) {
            return !(lhs == rhs);
        }

        /**
         * Display the internal map content.
         * This is mainly for debug print purpose.
         */
        friend std::ostream& operator<<(std::ostream& out,
                                        const LWWMap<Key,T,U>& o) {
            out << "CmRDT::LWWMap = Not Implemented Yet";
            /* TODO
            for(const std::pair<Key,T>& elt : o._map) {
                out << "(" << elt.first << "," << elt.second << ") ";
            }
            */
            return out;
        }
};


}} // End namespace


