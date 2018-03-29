#pragma once

#include "CvRDT/GSetInt.h"

namespace CRDT {
namespace CvRDT {


void GSetInt_example() {
    GSetInt data0;
    GSetInt data1;

    // Modif from user0
    GSetInt_add(data0, 0);
    GSetInt_add(data0, 1);
    GSetInt_add(data0, 3);
    GSetInt_add(data0, 4);

    // Modif from user1
    GSetInt_add(data1, 4);
    GSetInt_add(data1, 7);

    GSetInt_merge(data0, data1);
    GSetInt_merge(data1, data0);

    GSetInt_print(data0);
    GSetInt_print(data1);
}


}} // End namespaces
