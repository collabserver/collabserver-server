#pragma once

#include <algorithm> // std::max
#include <cassert>
#include <stdio.h>

#define NB_PROCESS 2

namespace CRDT {
namespace CvRDT {


/**
 * Grow Only Integer Vector.
 * CvRDT (State based object)
 *
 * \note (Assumptions)
 * Nb process (Replicas) is well known and invariant.
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
struct GVectorInt {
    private:
        size_t _size = NB_PROCESS;
        unsigned int _m[NB_PROCESS] = {0};

    public:
        GVectorInt() = default;
        ~GVectorInt() = default;

    public:
        int query(const unsigned int i) const {
            return _m[i];
        }

        void increment(const unsigned int i) {
            assert(i < _size);

            _m[i]++;
        }

        void merge(const GVectorInt& other) {
            assert(_size == other._size);

            for(unsigned int k = 0; k < _size; ++k) {
                _m[k] = std::max(_m[k], other._m[k]);
            }
        }

        void print() const {
            fprintf(stdout, "CvRDT GVectorInt [%d", _m[0]);
            for(unsigned int k = 1; k < _size; ++k) {
                fprintf(stdout, ", %d", (int)_m[k]);
            }
            fprintf(stdout, "] (Size: %d) \n", (int)_size);
        }
};


}} // End namespaces
