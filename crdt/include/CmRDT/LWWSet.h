#pragma once

#include <unordered_map>
#include <utility> // std::pair

namespace CRDT {
namespace CmRDT {


/**
 * Last-Writer-Wins Set (LWW Set).
 * CmRDT (Operation-based)
 *
 * Associative container that contains key-value pairs with unique keys.
 * Internally uses std::unordered_set. See its documentation for further
 * informations.
 *
 * \warning
 * Timestamps must have a total order.
 * Two equal timestamps (t1 == t1 returns true) is undefined and replicated
 * may diverge. (See quote and implementation).
 *
 *
 * \note
 * Quote from the CRDT article "A comprehensive study of CRDT":
 * "
 *  A Last-Writer-Wins [...] creates a total order of
 *  assignments by associating a timestamp with each update.
 *  Timestamps are assumed unique, totally ordered, and consistent with causal
 *  order; i.e., if assignment 1 happened-before assignment 2,
 *  the former's timestamp is less than the latter's. This may be implemented as
 *  a per-replicate counter concatenated with a unique replica identifier,
 *  such as its MAC address.
 * "
 *
 *
 * \tparam Key  Object of type Key.
 * \tparam U    Type of timestamp.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
template<typename Key, typename U>
class LWWSet {
    private:
        typedef typename std::pair<U, bool> Metadata; // bool=true if removed

    public:
        typedef typename std::unordered_map<Key,Metadata>::value_type     value_type;
        typedef typename std::unordered_map<Key,Metadata>::iterator       iterator;
        typedef typename std::unordered_map<Key,Metadata>::const_iterator const_iterator;

    private:
        std::unordered_map<Key, Metadata> _map;


    // -------------------------------------------------------------------------
    // CRDT methods
    // -------------------------------------------------------------------------

    public:

        /**
         * TODO
         */
        const_iterator lookup(const Key& key) const {
            return _map.find(key);
        }

        /**
         * TODO
         */
        void insert(const Key& key, const U& stamp) {
            iterator it = _map.find(key);

            if(it != _map.end()) {
                if(it->second.first < stamp) {
                    it->second.first = stamp;
                    it->second.second = false;
                }
            }
            else {
                _map.emplace(std::make_pair(key, std::make_pair(stamp, false)));
            }
        }

        /**
         * TODO
         */
        void remove(const Key& key, const U& stamp) {
            iterator it = _map.find(key);

            if(it != _map.end()) {
                if(it->second.first < stamp) {
                    it->second.first = stamp;
                    it->second.second = true;
                }
            }
            else {
                _map.emplace(std::make_pair(key, std::make_pair(0, true)));
            }
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
         * Two LWWSet are equal if their internal map are equal.
         * Removed elements are used to determine equality.
         *
         * \return True if equal, otherwise, return false.
         */
        friend bool operator==(const LWWSet& lhs, const LWWSet& rhs) {
            return lhs._map == rhs._map;
        }

        /**
         * Check if lhs and rhs are not equals.
         * See operator == for further information about equality meaning.
         *
         * \return True if not equal, otherwise, return false.
         */
        friend bool operator!=(const LWWSet& lhs, const LWWSet& rhs) {
            return !(lhs == rhs);
        }

        /**
         * Display the internal map content.
         * This is mainly for debug print purpose.
         */
        friend std::ostream& operator<<(std::ostream& out, const LWWSet<Key,U>& o) {
            out << "CmRDT::LWWSet = ";
            for(const auto& elt : o._map) {
                out << "(K=" << elt.first
                    << ",U=" << elt.second.first;
                if(elt.second.second == true) {
                    out << ",removed) ";
                }
                else {
                    out << ",alive) ";
                }
            }
            return out;
        }
};


}} // End namespaces


