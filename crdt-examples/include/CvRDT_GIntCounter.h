/*
 * Grow Only Integer Counter
 * CvRDT (State based object)
 *
 * Uses a fixed number of process.
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


struct CvRDT_GIntCounter
{
    size_t _size;
    unsigned int _m[NB_PROCESS];
};

struct CvRDT_GIntCounter CvRDT_GIntCounter_init() {
    struct CvRDT_GIntCounter counter = {NB_PROCESS, {0}};
    return counter;
}

int CvRDT_GIntCounter_query(const struct CvRDT_GIntCounter* data)
{
    assert(data != NULL);
    assert(data->_size > 0);

    int value = 0;
    for(int k = 0; k < data->_size; ++k)
    {
        value += data->_m[k];
    }
    return value;
}


void CvRDT_GIntCounter_update(struct CvRDT_GIntCounter* data, const int i)
{
    assert(data != NULL);
    assert(data->_size > 0);
    assert(i >= 0);
    assert(i < data->_size);

    data->_m[i]++;
}

void CvRDT_GIntCounter_merge(struct CvRDT_GIntCounter* ours,
                             const struct CvRDT_GIntCounter* theirs)
{
    assert(ours != NULL);
    assert(theirs != NULL);
    assert(ours->_size == theirs->_size);

    for(int k = 0; k < ours->_size; ++k)
    {
        ours->_m[k] = MAX(ours->_m[k], theirs->_m[k]);
    }
}

void CvRDT_GIntCounter_print(const struct CvRDT_GIntCounter* data)
{
    assert(data != NULL);
    assert(data->_size > 0);

    int value = CvRDT_GIntCounter_query(data);
    fprintf(stdout, "CvRDT GIntCounter %d -> [%d", value, data->_m[0]);
    for(int k = 1; k < (int)data->_size; ++k)
    {
        fprintf(stdout, ", %d", (int)data->_m[k]);
    }
    fprintf(stdout, "] (Size: %d) \n", (int)data->_size);
}
