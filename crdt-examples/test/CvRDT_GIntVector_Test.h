#pragma once

#include "CvRDT_GIntVector.h"


void example_CvRDT_GIntVector()
{
    struct CvRDT_GIntVector counter_process0 = CvRDT_GIntVector_init();
    struct CvRDT_GIntVector counter_process1 = CvRDT_GIntVector_init();

    // Process 0 increments counter to three
    CvRDT_GIntVector_update(&counter_process0, 0);
    CvRDT_GIntVector_update(&counter_process0, 0);
    CvRDT_GIntVector_update(&counter_process0, 0);

    // Process 1 increments counter to two
    CvRDT_GIntVector_update(&counter_process1, 1);
    CvRDT_GIntVector_update(&counter_process1, 1);

    // Merge
    CvRDT_GIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_GIntVector_merge(&counter_process1, &counter_process0);

    // Because idempotent, these calls won't do anything
    CvRDT_GIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_GIntVector_merge(&counter_process1, &counter_process0);
    CvRDT_GIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_GIntVector_merge(&counter_process0, &counter_process1);
    CvRDT_GIntVector_merge(&counter_process1, &counter_process0);

    // Print result (Should be [3,2])
    CvRDT_GIntVector_print(&counter_process0);
    CvRDT_GIntVector_print(&counter_process1);
}
