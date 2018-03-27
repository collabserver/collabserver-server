#pragma once

#include "CvRDT_GIntCounter.h"



void example_CvRDT_GIntCounter()
{
    struct CvRDT_GIntCounter counter_process0 = CvRDT_GIntCounter_init();
    struct CvRDT_GIntCounter counter_process1 = CvRDT_GIntCounter_init();

    // Process 0 increments counter to three
    CvRDT_GIntCounter_update(&counter_process0, 0);
    CvRDT_GIntCounter_update(&counter_process0, 0);
    CvRDT_GIntCounter_update(&counter_process0, 0);

    // Process 1 increments counter to two
    CvRDT_GIntCounter_update(&counter_process1, 1);
    CvRDT_GIntCounter_update(&counter_process1, 1);

    // Merge
    CvRDT_GIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_GIntCounter_merge(&counter_process1, &counter_process0);

    // Because idempotent, these calls won't do anything
    CvRDT_GIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_GIntCounter_merge(&counter_process1, &counter_process0);
    CvRDT_GIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_GIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_GIntCounter_merge(&counter_process1, &counter_process0);

    CvRDT_GIntCounter_print(&counter_process0);
    CvRDT_GIntCounter_print(&counter_process1);
}
