#pragma once

#include "CvRDT/PNVectorInt.h"

namespace CRDT {
namespace CvRDT {


void PNVectorInt_example() {
    PNVectorInt data0; // At process 0
    PNVectorInt data1; // At process 1

    // Process 0 increments counter three times
    PNVectorInt_increment(data0, 0);
    PNVectorInt_increment(data0, 0);
    PNVectorInt_increment(data0, 0);
    PNVectorInt_increment(data0, 0);
    PNVectorInt_increment(data0, 0);

    // Process 0 decrement two times
    PNVectorInt_decrement(data0, 0);
    PNVectorInt_decrement(data0, 0);


    // Process 1 increments counter two times
    PNVectorInt_increment(data1, 1);
    PNVectorInt_increment(data1, 1);


    // Process 1 decrement 3 times
    PNVectorInt_decrement(data1, 1);
    PNVectorInt_decrement(data1, 1);
    PNVectorInt_decrement(data1, 1);


    // Merge
    PNVectorInt_merge(data0, data1);
    PNVectorInt_merge(data1, data0);

    // Because idempotent, these calls won't do anything
    PNVectorInt_merge(data0, data1);
    PNVectorInt_merge(data1, data0);
    PNVectorInt_merge(data0, data1);
    PNVectorInt_merge(data0, data1);
    PNVectorInt_merge(data1, data0);

    // Print result (Should be [3,-1])
    PNVectorInt_print(data0);
    PNVectorInt_print(data1);
}


}} // End namespace
