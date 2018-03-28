/*
 * Grow Only Integer Vector
 * CvRDT (State based object)
 *
 * Uses a fixed number of process
 *
 * Author:  Constantin Masson
 * Date:    March 2018
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NB_PROCESS 2


struct CvRDT_GIntVector
{
    size_t _size;
    unsigned int _m[NB_PROCESS];
};

struct CvRDT_GIntVector CvRDT_GIntVector_init() {
    struct CvRDT_GIntVector v = {NB_PROCESS, {0}};
    return v;
}

int CvRDT_GIntVector_query(const struct CvRDT_GIntVector* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0);
    assert(i < (int)data->_size);

    return data->_m[i];
}

void CvRDT_GIntVector_update(struct CvRDT_GIntVector* data, const int i)
{
    assert(data != NULL);
    assert(i >= 0 && i < (int)data->_size);

    data->_m[i]++;
}

void CvRDT_GIntVector_merge(struct CvRDT_GIntVector* ours,
                            const struct CvRDT_GIntVector* theirs)
{
    assert(ours != NULL);
    assert(theirs != NULL);
    assert(ours->_size == theirs->_size);

    for(int k = 0; k < (int)ours->_size; ++k)
    {
        ours->_m[k] = MAX((ours->_m[k]), (theirs->_m[k]));
    }
}

void CvRDT_GIntVector_print(const struct CvRDT_GIntVector* data)
{
    assert(data != NULL);
    assert(data->_size > 0);

    fprintf(stdout, "CvRDT GIntVector [%d", data->_m[0]);
    for(int k = 1; k < (int)data->_size; ++k)
    {
        fprintf(stdout, ", %d", (int)data->_m[k]);
    }
    fprintf(stdout, "] (Size: %d) \n", (int)data->_size);
}
