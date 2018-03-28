#pragma once

#include <algorithm> // std::max
#include <cassert>
#include <stdio.h>

#define NB_PROCESS 2 // TODO: Nb process is hardcoded

namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

/**
 * Increment / Decrement Integer Vector
 * CvRDT (State based object)
 *
 * Uses a fixed number of process
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
struct PNVectorInt {
    size_t _size                    = NB_PROCESS;
    unsigned int _mPos[NB_PROCESS]  = {0}; // Positive
    unsigned int _mNeg[NB_PROCESS]  = {0}; // Negative
};


// -----------------------------------------------------------------------------
// Methods to work on data (PNVectorInt)
// -----------------------------------------------------------------------------

int PNVectorInt_query(const PNVectorInt& data, const unsigned int i) {
    assert(i < data._size);

    return (data._mPos[i] - data._mNeg[i]);
}

void PNVectorInt_increment(PNVectorInt& data, const unsigned int i) {
    assert(i < data._size);

    data._mPos[i]++;
}

void PNVectorInt_decrement(PNVectorInt& data, const unsigned int i) {
    assert(i < data._size);

    data._mNeg[i]++;
}

void PNVectorInt_merge(PNVectorInt& ours, const PNVectorInt& theirs) {
    assert(ours._size == theirs._size);

    for(unsigned int k = 0; k < ours._size; ++k) {
        ours._mPos[k] = std::max(ours._mPos[k], theirs._mPos[k]);
        ours._mNeg[k] = std::max(ours._mNeg[k], theirs._mNeg[k]);
    }
}

void PNVectorInt_print(const PNVectorInt& data) {
    assert(data._size > 0);

    int value = PNVectorInt_query(data, 0);
    fprintf(stdout, "CvRDT PNVectorInt: [%d", value);
    for(unsigned int k = 1; k < data._size; ++k) {
        value = PNVectorInt_query(data, k);
        fprintf(stdout, ", %d", value);
    }
    fprintf(stdout, "]\n");
}


}} // End namespaces
