#pragma once

#include "CvRDT/USetInt.h"

namespace CRDT {
namespace CvRDT {


void USetInt_example() {
    USetInt data0;
    USetInt data1;

    // Modif (Add) from user0
    USetInt_add(data0, 0);
    USetInt_add(data0, 1);
    USetInt_add(data0, 3);
    USetInt_add(data0, 4);
    USetInt_add(data0, 9);

    // Modif (Remove) from user0
    USetInt_remove(data0, 0);
    USetInt_remove(data0, 3);

    // User 1: [1,4,9]


    // Modif (Add) from user1
    USetInt_add(data1, 3);
    USetInt_add(data1, 4);
    USetInt_add(data1, 7);
    USetInt_add(data1, 8);

    // Modif (Remove) from user1
    USetInt_remove(data1, 3);
    USetInt_remove(data1, 4);

    // User 2: [7,8]


    USetInt_merge(data0, data1);
    USetInt_merge(data1, data0);

    USetInt_print(data0);
    USetInt_print(data1);

    // Should be [1,7,8,9]
}


}} // End namespaces
