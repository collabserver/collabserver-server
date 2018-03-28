/*
 * Increment / Decrement Integer Counter
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


struct CvRDT_PNIntCounter
{
    size_t _size;
    unsigned int _mPos[NB_PROCESS]; // Positive
    unsigned int _mNeg[NB_PROCESS]; // Negative
};

struct CvRDT_PNIntCounter CvRDT_PNIntCounter_init()
{
    struct CvRDT_PNIntCounter counter = {NB_PROCESS, {0}, {0}};
    return counter;
}

int CvRDT_PNIntCounter_query(const struct CvRDT_PNIntCounter* data)
{
    assert(data != NULL);

    int total = 0;
    for(int k = 0; k < data->_size; ++k)
    {
        total += data->_mPos[k] - data->_mNeg[k];
    }

    return total;
}

void CvRDT_PNIntCounter_updateIncrement(struct CvRDT_PNIntCounter* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0);
    assert(i < data->_size);

    data->_mPos[i]++;
}

void CvRDT_PNIntCounter_updateDecrement(struct CvRDT_PNIntCounter* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0);
    assert(i < data->_size);

    data->_mNeg[i]++;
}

void CvRDT_PNIntCounter_merge(struct CvRDT_PNIntCounter* ours,
                              const struct CvRDT_PNIntCounter* theirs)
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

void CvRDT_PNIntCounter_print(const struct CvRDT_PNIntCounter* data) {
    assert(data != NULL);

    int value = CvRDT_PNIntCounter_query(data);
    fprintf(stdout, "CvRDT PNIntCounter: %d -> Pos[%d", value, data->_mPos[0]);
    for(int k = 1; k < data->_size; ++k)
    {
        fprintf(stdout, ", %d", data->_mPos[k]);
    }
    fprintf(stdout, "] Neg[%d", data->_mNeg[0]);
    for(int k = 1; k < data->_size; ++k)
    {
        fprintf(stdout, ", %d", data->_mNeg[k]);
    }
    fprintf(stdout, "]\n");
}
