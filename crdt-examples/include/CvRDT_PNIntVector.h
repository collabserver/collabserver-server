/*
 * Increment / Decrement Integer Vector
 * CvRDT (State based object)
 *
 * Uses a fixed number of process
 *
 * Author:  Constantin Masson
 * Date:    March 2018
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NB_PROCESS 2


struct CvRDT_PNIntVector
{
    size_t _size;
    unsigned int _mPos[NB_PROCESS]; // Positive
    unsigned int _mNeg[NB_PROCESS]; // Negative
};

struct CvRDT_PNIntVector CvRDT_PNIntVector_init()
{
    struct CvRDT_PNIntVector vector = {NB_PROCESS, {0}};
    return vector;
}

int CvRDT_PNIntVector_query(const struct CvRDT_PNIntVector* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0);
    assert(i < data->_size);

    return (data->_mPos[i] - data->_mNeg[i]);
}

void CvRDT_PNIntVector_updateIncrement(struct CvRDT_PNIntVector* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0);
    assert(i < data->_size);

    data->_mPos[i]++;
}

void CvRDT_PNIntVector_updateDecrement(struct CvRDT_PNIntVector* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0);
    assert(i < data->_size);

    data->_mNeg[i]++;
}

void CvRDT_PNIntVector_merge(struct CvRDT_PNIntVector* ours,
                             const struct CvRDT_PNIntVector* theirs)
{
    assert(ours != NULL);
    assert(theirs != NULL);
    assert(ours->_size == theirs->_size);

    for(int k = 0; k < ours->_size; ++k)
    {
        ours->_mPos[k] = MAX(ours->_mPos[k], theirs->_mPos[k]);
        ours->_mNeg[k] = MAX(ours->_mNeg[k], theirs->_mNeg[k]);
    }
}

void CvRDT_PNIntVector_print(const struct CvRDT_PNIntVector* data)
{
    assert(data != NULL);
    assert(data->_size > 0);

    int value = CvRDT_PNIntVector_query(data, 0);
    fprintf(stdout, "CvRDT PNIntVector: [%d", value);
    for(int k = 1; k < data->_size; ++k)
    {
        value = CvRDT_PNIntVector_query(data, k);
        fprintf(stdout, ", %d", value);
    }
    fprintf(stdout, "]\n");
}
