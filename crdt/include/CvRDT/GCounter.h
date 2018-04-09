#pragma once

#include <unordered_map>
#include <algorithm> // std::max
#include <iostream>

namespace CRDT {
namespace CvRDT {


/**
 * Grow Only Counter.
 * CvRDT (State-based)
 *
 * \note
 * Internally stores counter in a map. Key is the replicate's unique id.
 *
 *
 * \tparam T Type of counter. (Default int)
 * \tparam ID Type of the id used to identify each replicated. (Each unique).
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
template<typename T = int, typename ID = std::string>
class GCounter {
    private:
        std::unordered_map<ID, T> _map;
        const ID _currentID;


    public:
        GCounter(const ID id) : _currentID(id) {}


    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------

    public:

        /**
         * Get the current counter value.
         */
        T query() const {
            T value = 0;
            for(const auto& it : _map) {
                value += it.second;
            }
            return value;
        }

        /**
         * Increment by one the counter for the current process ID.
         */
        void increment() {
            _map[_currentID]++;
        }

        /**
         * Merge this Counter with another.
         * Current counter is modified.
         */
        void merge(const GCounter<T,ID>& other) {
            for(const auto& it : other._map) {
                _map[it.first] = std::max(_map[it.first], it.second);
            }
        }


    // -------------------------------------------------------------------------
    // Operators overload
    // -------------------------------------------------------------------------

    public:

        friend std::ostream& operator<<(std::ostream& out, const GCounter& o) {
            out << "GCounter: " << o.query() << " -> [";
            for(const auto& it: o._map) {
                out << it.second << " ";
            }
            out << "]";
            return out;
        }
};


}} // End namespaces
