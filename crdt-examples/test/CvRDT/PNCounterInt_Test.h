#pragma once

#include "CvRDT/PNCounterInt.h"

namespace CRDT {
namespace CvRDT {


void PNCounterInt_example() {
    PNCounterInt data0;
    PNCounterInt data1;

    // Process 0 increments counter three times
    PNCounterInt_increment(data0, 0);
    PNCounterInt_increment(data0, 0);
    PNCounterInt_increment(data0, 0);
    PNCounterInt_increment(data0, 0);
    PNCounterInt_increment(data0, 0);

    // Process 0 decrement two times
    PNCounterInt_decrement(data0, 0);
    PNCounterInt_decrement(data0, 0);


    // Process 1 increments counter two times
    PNCounterInt_increment(data1, 1);
    PNCounterInt_increment(data1, 1);


    // Process 1 decrement 3 times
    PNCounterInt_decrement(data1, 1);
    PNCounterInt_decrement(data1, 1);
    PNCounterInt_decrement(data1, 1);


    // Merge
    PNCounterInt_merge(data0, data1);
    PNCounterInt_merge(data1, data0);

    // Because idempotent, these calls won't do anything
    PNCounterInt_merge(data0, data1);
    PNCounterInt_merge(data1, data0);
    PNCounterInt_merge(data0, data1);
    PNCounterInt_merge(data0, data1);
    PNCounterInt_merge(data1, data0);

    // Print result (Should be 2)
    PNCounterInt_print(data0);
    PNCounterInt_print(data1);
}


}} // End namespaces
