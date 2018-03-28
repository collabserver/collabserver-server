#pragma once

#include "CvRDT_PNIntVector.h"


void example_CvRDT_PNIntVector()
{
    struct CvRDT_PNIntVector counter_process0 = CvRDT_PNIntVector_init();
    struct CvRDT_PNIntVector counter_process1 = CvRDT_PNIntVector_init();

    // Process 0 increments counter three times
    CvRDT_PNIntVector_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntVector_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntVector_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntVector_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntVector_updateIncrement(&counter_process0, 0);

    // Process 0 decrement two times
    CvRDT_PNIntVector_updateDecrement(&counter_process0, 0);
    CvRDT_PNIntVector_updateDecrement(&counter_process0, 0);


    // Process 1 increments counter two times
    CvRDT_PNIntVector_updateIncrement(&counter_process1, 1);
    CvRDT_PNIntVector_updateIncrement(&counter_process1, 1);


    // Process 1 decrement 3 times
    CvRDT_PNIntVector_updateDecrement(&counter_process1, 1);
    CvRDT_PNIntVector_updateDecrement(&counter_process1, 1);
    CvRDT_PNIntVector_updateDecrement(&counter_process1, 1);


    // Merge
    CvRDT_PNIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntVector_merge(&counter_process1, &counter_process0);

    // Because idempotent, these calls won't do anything
    CvRDT_PNIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntVector_merge(&counter_process1, &counter_process0);
    CvRDT_PNIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntVector_merge(&counter_process1, &counter_process0);

    // Print result (Should be [3,-1])
    CvRDT_PNIntVector_print(&counter_process0);
    CvRDT_PNIntVector_print(&counter_process1);
}

