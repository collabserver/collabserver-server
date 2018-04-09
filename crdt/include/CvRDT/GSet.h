#pragma once

#include <set>
#include <iterator>
#include <iostream>

namespace CRDT {
namespace CvRDT {


/**
 * Grow Only (add-only) Set.
 * Do not support remove element.
 *
 * \note
 * CvRDT (State-based).
 *
 * \note
 * Internally, uses two std::set (Add set and Remove set).
 *
 *
 * \tparam T Type of element. (Default int)
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename T = int>
class GSet {
    private:
        std::set<T> _add; // Set of added elements

    public:
        typedef typename std::set<T>::iterator              iterator;
        typedef typename std::set<T>::const_iterator        const_iterator;
        typedef typename std::set<T>::size_type             size_type;


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
            return _add.empty();
        }

        /**
         * Returns the number of elements in the container.
         *
         * \return Size of the set.
         */
        size_type size() const {
            return _add.size();
        }


    // -------------------------------------------------------------------------
    // Modifier
    // -------------------------------------------------------------------------

    public:

        /**
         * Removes all elements from the container.
         * Internally, Add set is cleared.
         */
        void clear() {
            _add.clear();
        }

        /**
         * Insert a value.
         * Set has no duplicate. Do nothing if already in the set.
         *
         * \param Element value to insert.
         */
        void insert(const T& value) {
            _add.insert(value);
        }

        /**
         * Merge other CRDT with this current data.
         *
         * \param other CRDT to merge with.
         */
        void merge(const GSet<T>& other) {
            //_add.insert(other._add.begin(), other._add.end()); // TODO
            for(auto it = other._add.begin(); it != other._add.end(); ++it) {
                _add.insert(*it);
            }
        }


    // -------------------------------------------------------------------------
    // Lookup
    // -------------------------------------------------------------------------

    public:

        /**
         * Returns the number of elements matching specific key.
         * Since keys are unique, this returns 0 or 1.
         *
         * \return Number of element with key key.
         */
        size_type count(const T& key) const {
            return _add.count(key);
        }

        /**
         * Finds an element with key equivalent to key.
         *
         * \param key key value of the element to search for.
         * \return Constant iterator to the element (Or end if no element).
         */
        const_iterator find(const T& key) const {
            return _add.find(key);
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
            return _add.begin();
        }

        /**
         * Returns an iterator to the element following the last element of
         * the container. This element acts as a placeholder.
         * Attempting to access it results in undefined behavior.
         *
         * \return Iterator to the element following the last element.
         */
        iterator end() {
            return _add.end();
        }

        /**
         * \copydoc begin()
         */
        const_iterator cbegin() {
            return _add.cbegin();
        }

        /**
         * \copydoc end()
         */
        const_iterator cend() {
            return _add.cend();
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        friend std::ostream& operator<<(std::ostream& out, const GSet<T>& o) {
            out << "GSet: a(";
            for(auto it = o._add.begin(); it != o._add.end(); ++it) {
                out << *it << " ";
            }
            out << ")";
            return out;
        }
};


}} // End namespaces



