#pragma once

#include <set>
#include <iterator>
#include <cassert>

namespace CRDT {
namespace CvRDT {


/**
 * \brief Two-Phase Set (2P-Set).
 *
 * Grow Only Add / Remove Set.
 * Elements are added only once and removed only if already added.
 * Once removed, an element cannot be added again.
 * Removing an element is allowed only if already in the 'add' set.
 *
 * \tparam T Type of element.
 *
 * \todo Create iterator for TwoPSet.
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename T>
class TwoPSet {
    private:
        std::set<T> _add; // Set of added elt
        std::set<T> _rem; // Set of removed elt (tombstone)

    public:

        /**
         * Finds an element with key equivalent to key.
         *
         * \param key key value of the element to search for.
         * \return Copy of the element.
         */
        auto find(const T& key) const {
            auto it_add = _add.find(key);
            auto it_rem = _rem.find(key);

            bool containsAdd = it_add != _add.end();
            bool containsRem = it_rem != _rem.end();

            if(containsAdd && !containsRem) {
                return *it_add;
            }
            return *_add.end(); //TODO
        }

        /**
         * Check whether the key is in the set.
         * Add key added and then removed is not contains (Return false).
         *
         * \return true if key in set, otherwise, return false.
         */
        bool contains(const T& key) const {
            if(_add.count(key) == 0) {
                return false;
            }
            return (_rem.count(key) == 0) ? true : false;
        }

        /**
         * Insert a value.
         * Set has no duplicat. Do nothing if already in the set.
         */
        void insert(const T& value) {
            _add.insert(value);
        }

        /**
         * TODO
         */
        void remove(const T& key) {
            auto it_add = _add.find(key);
            bool containsAdd = it_add != _add.end();
            if(containsAdd) {
                _rem.insert(key);
            }
        }

        void merge(const TwoPSet<T>& other) {
            for(auto it = other._add.begin(); it != other._add.end(); ++it) {
                _add.insert(*it);
            }
            for(auto it = other._rem.begin(); it != other._rem.end(); ++it) {
                _rem.insert(*it);
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const TwoPSet& obj) {
            os << "2PSet: a(";
            for(auto it = obj._add.begin(); it != obj._add.end(); ++it) {
                os << *it << " ";
            }
            os << ") - r(";
            for(auto it = obj._rem.begin(); it != obj._rem.end(); ++it) {
                os << *it << " ";
            }
            os << ")";
            return os;
        }
};



}} // End namespace

