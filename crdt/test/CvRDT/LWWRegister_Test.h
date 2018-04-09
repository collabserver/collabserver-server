#pragma once

#include "CvRDT/LWWRegister.h"

#include <stdio.h>

namespace CRDT {
namespace CvRDT {


void LWWRegister_example() {
    LWWRegister<int> data0;
    LWWRegister<int> data1;

    LWWRegister_assign(data0, 1);
    LWWRegister_assign(data1, 2);

    LWWRegister_assign(data1, 3);
    LWWRegister_assign(data0, 4);

    LWWRegister_merge(data0, data1);
    LWWRegister_merge(data1, data0);

    int v0 = LWWRegister_query(data0);
    int v1 = LWWRegister_query(data1);

    fprintf(stdout, "CvRDT LWWRegister (data0) = %d\n", v0);
    fprintf(stdout, "CvRDT LWWRegister (data1) = %d\n", v1);
}


}} // End namespace
