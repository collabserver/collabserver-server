#pragma once

#include <algorithm> // std::max
#include <cassert>
#include <stdio.h>

#define NB_PROCESS 2 // TODO: Nb process is hardcoded


namespace CRDT {
namespace CvRDT {


/**
 * Grow Only Integer Counter.
 * CvRDT (State-based object)
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
struct GCounterInt {
    private:
        size_t _size = NB_PROCESS;
        unsigned int _m[NB_PROCESS] = {0};

    public:
        GCounterInt() = default;
        ~GCounterInt() = default;

    public:

        /**
         * Get the current counter value.
         */
        int query() const {
            int value = 0;
            for(unsigned int k = 0; k < _size; ++k) {
                value += _m[k];
            }
            return value;
        }

        /**
         * Increment by one the given process.
         */
        void increment(const unsigned int i) {
            assert(i < _size);

            _m[i]++;
        }

        /**
         * Merge this Counter with another.
         * Current counter is modified.
         */
        void merge(const GCounterInt& other) {
            assert(_size == other._size);

            for(unsigned int k = 0; k < _size; ++k) {
                _m[k] = std::max(_m[k], other._m[k]);
            }
        }

        /**
         * Print on cout for debug purpose.
         */
        void print() const {
            int value = this->query();

            fprintf(stdout, "CvRDT GCounterInt %d -> [%d", value, _m[0]);
            for(unsigned int k = 1; k < _size; ++k) {
                fprintf(stdout, ", %d", (int)_m[k]);
            }
            fprintf(stdout, "] (Size: %d) \n", (int)_size);
        }
};


}} // End namespaces
