#pragma once

#include <algorithm> // std::max
#include <cassert>
#include <stdio.h>

#define NB_PROCESS 2

namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

/**
 * Increment / Decrement Integer Counter
 * CvRDT (State based object)
 *
 * \note (Assumptions)
 * Nb process (Replicas) is well known and invariant.
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
struct PNCounterInt {
    size_t _size                    = NB_PROCESS;
    unsigned int _mPos[NB_PROCESS]  = {0}; // Positive
    unsigned int _mNeg[NB_PROCESS]  = {0}; // Negative
};


// -----------------------------------------------------------------------------
// Methods to work on data (PNCounterInt)
// -----------------------------------------------------------------------------

int PNCounterInt_query(const PNCounterInt& data) {
    int total = 0;
    for(unsigned int k = 0; k < data._size; ++k) {
        total += data._mPos[k] - data._mNeg[k];
    }
    return total;
}

void PNCounterInt_increment(PNCounterInt& data, const unsigned int i) {
    assert(i < data._size);

    data._mPos[i]++;
}

void PNCounterInt_decrement(PNCounterInt& data, const unsigned int i) {
    assert(i < data._size);

    data._mNeg[i]++;
}

void PNCounterInt_merge(PNCounterInt& ours, const PNCounterInt& theirs) {
    assert(ours._size == theirs._size);

    for(unsigned int k = 0; k < ours._size; ++k) {
        ours._mPos[k] = std::max(ours._mPos[k], theirs._mPos[k]);
        ours._mNeg[k] = std::max(ours._mNeg[k], theirs._mNeg[k]);
    }
}

void PNCounterInt_print(const PNCounterInt& data) {

    int value = PNCounterInt_query(data);
    fprintf(stdout, "CvRDT PNCounterInt: %d -> Pos[%d", value, data._mPos[0]);
    for(unsigned int k = 1; k < data._size; ++k) {
        fprintf(stdout, ", %d", data._mPos[k]);
    }
    fprintf(stdout, "] Neg[%d", data._mNeg[0]);
    for(unsigned int k = 1; k < data._size; ++k) {
        fprintf(stdout, ", %d", data._mNeg[k]);
    }
    fprintf(stdout, "]\n");
}


}} // End namespaces
