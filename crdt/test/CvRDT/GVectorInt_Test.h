#pragma once

#include "CvRDT/GVectorInt.h"

namespace CRDT {
namespace CvRDT {


class GVectorInt_Test {
    private:
        GVectorInt_Test() = delete;

    public:
        static void example() {
            GVectorInt data0;
            GVectorInt data1;

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

            // Expected: [3,2]
            data0.print();
            data1.print();
        }
};

}} // End namespaces
