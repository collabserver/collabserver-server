#pragma once

#include <set>
#include <iterator>
#include <iostream>

namespace CRDT {
namespace CvRDT {


/**
 * Two-Phase Set (2P-Set).
 *
 * Grow Only Add / Remove Set.
 * Elements are added only once and removed only if already added.
 * Once removed, an element cannot be added again.
 * Removing an element is allowed only if already in the 'add' set.
 *
 * \note
 * 2P-Set gives precedences to remove operation.
 * (OR-Set however, gives precedences to add).
 *
 * \note
 * CvRDT (State-based)
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
class TwoPSet {
    private:
        std::set<T> _add; // Set of added elt (Without removed elt)
        std::set<T> _rem; // Set of removed elt (tombstone)

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
         * This internally count elements in add set.
         *
         * \return Size of the set.
         */
        size_type size() const {
            return _add.size();
        }


    // -------------------------------------------------------------------------
    // Modifiers
    // -------------------------------------------------------------------------

    public:

        /**
         * Removes all elements from the container.
         * Internally, Add and Remove list are cleared.
         */
        void clear() {
            _add.clear();
            _rem.clear();
        }

        /**
         * Insert a value.
         * Set has no duplicate. Do nothing if already in the set.
         * Element may be added only once.
         * Do nothing if element has already been removed (Is in tombstone set).
         *
         * \param Element value to insert.
         */
        void insert(const T& value) {
            if(_rem.count(value) == 0) {
                _add.insert(value);
            }
        }

        /**
         * Removes the element (if one exists) with the key equivalent to key.
         *
         * \param key Key value of the elements to remove.
         * \return Number of elements removed.
         */
        size_type erase(const T& key) {
            size_type count = _add.erase(key);
            if(count != 0) {
                _rem.insert(key);
            }
            return count;
        }

        /**
         * Merge other CRDT with this current data.
         *
         * \param other CRDT to merge with.
         */
        void merge(const TwoPSet<T>& other) {
            for(auto it = other._rem.begin(); it != other._rem.end(); ++it) {
                _add.erase(*it);
                _rem.insert(*it);
            }
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
         * \note
         * Internally returns the number of elements in add set.
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
        const_iterator cbegin() const {
            return _add.cbegin();
        }

        /**
         * \copydoc end()
         */
        const_iterator cend() const {
            return _add.cend();
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------
    public:

        friend std::ostream& operator<<(std::ostream& out, const TwoPSet& o) {
            //TODO: atm, this is mostly a debug print.
            out << "2PSet: a(";
            for(auto it = o._add.begin(); it != o._add.end(); ++it) {
                out << *it << " ";
            }
            out << ") - r(";
            for(auto it = o._rem.begin(); it != o._rem.end(); ++it) {
                out << *it << " ";
            }
            out << ")";
            return out;
        }
};


}} // End namespace


