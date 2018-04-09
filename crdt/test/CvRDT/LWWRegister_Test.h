#pragma once

#include "CvRDT/LWWRegister.h"

#include <stdio.h>

namespace CRDT {
namespace CvRDT {


void LWWRegister_example() {
    std::cout << "\n----- CvRDT LWWRegister Example ----------\n";

    LWWRegister<int, int> data0;
    LWWRegister<int, int> data1;


    // --- Replicate 0 (data0) ---
    data0.set(100, 1);
    data0.set(500, 3);
    data0.set(700, 7);


    // --- Replicate 1 (data1) ---
    data1.set(300, 1);
    data1.set(400, 6);


    // --- Final ---
    std::cout << "data0 before merge: " << data0 << "\n";
    std::cout << "data1 before merge: " << data1 << "\n";

    // Merge result -> [0,1,2,3,4,5]
    data0.merge(data1);
    data1.merge(data0);

    std::cout << "data0 after merge: " << data0 << "\n";
    std::cout << "data1 after merge: " << data1 << "\n";
}


}} // End namespace
