#pragma once

#include "CvRDT_PNIntCounter.h"



void example_CvRDT_PNIntCounter()
{
    struct CvRDT_PNIntCounter counter_process0 = CvRDT_PNIntCounter_init();
    struct CvRDT_PNIntCounter counter_process1 = CvRDT_PNIntCounter_init();

    // Process 0 increments counter three times
    CvRDT_PNIntCounter_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntCounter_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntCounter_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntCounter_updateIncrement(&counter_process0, 0);
    CvRDT_PNIntCounter_updateIncrement(&counter_process0, 0);

    // Process 0 decrement two times
    CvRDT_PNIntCounter_updateDecrement(&counter_process0, 0);
    CvRDT_PNIntCounter_updateDecrement(&counter_process0, 0);


    // Process 1 increments counter two times
    CvRDT_PNIntCounter_updateIncrement(&counter_process1, 1);
    CvRDT_PNIntCounter_updateIncrement(&counter_process1, 1);


    // Process 1 decrement 3 times
    CvRDT_PNIntCounter_updateDecrement(&counter_process1, 1);
    CvRDT_PNIntCounter_updateDecrement(&counter_process1, 1);
    CvRDT_PNIntCounter_updateDecrement(&counter_process1, 1);


    // Merge
    CvRDT_PNIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntCounter_merge(&counter_process1, &counter_process0);

    // Because idempotent, these calls won't do anything
    CvRDT_PNIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntCounter_merge(&counter_process1, &counter_process0);
    CvRDT_PNIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntCounter_merge(&counter_process0, &counter_process1);
    CvRDT_PNIntCounter_merge(&counter_process1, &counter_process0);

    // Print result (Should be 2)
    CvRDT_PNIntCounter_print(&counter_process0);
    CvRDT_PNIntCounter_print(&counter_process1);
}

