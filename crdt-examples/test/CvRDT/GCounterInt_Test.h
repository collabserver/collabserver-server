#pragma once

#include "CvRDT/GCounterInt.h"

namespace CRDT {
namespace CvRDT {


/**
 * Test for GCounterInt class.
 * CvRDT (State-based object)
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
class GCounterInt_Test {
    private:
        GCounterInt_Test() = delete;

    public:
        static void example() {
            GCounterInt data0;
            GCounterInt data1;

            // Process 0 increments counter to three
            data0.increment(0);
            data0.increment(0);
            data0.increment(0);

            // Process 1 increments counter to two
            data1.increment(1);
            data1.increment(1);

            // Merge
            data0.merge(data1);
            data1.merge(data0);

            // Because idempotent, these calls won't do anything
            data0.merge(data1);
            data1.merge(data0);
            data1.merge(data0);
            data0.merge(data1);
            data1.merge(data0);

            // Expected: 5
            data0.print();
            data1.print();
        }
};

}} // End namespaces
