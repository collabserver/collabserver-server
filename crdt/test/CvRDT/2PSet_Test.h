#pragma once

#include "CvRDT/2PSet.h"

#include <iostream>

namespace CRDT {
namespace CvRDT {


void TwoPSet_example() {
    std::cout << "\n----- CvRDT 2PSet Example ----------\n";

    TwoPSet<int> data0; // Ex: data at replicate 0
    TwoPSet<int> data1; // Ex: data at replicate 1


    // --- Replicate 0 (data0) ---

    // Updates from user0 -> [1,2,4]
    data0.insert(0);
    data0.insert(1);
    data0.insert(2);
    data0.insert(3);
    data0.insert(4);

    data0.erase(0);
    data0.erase(3);


    // --- Replicate 1 (data1) ---

    // Updates from user1 -> [2,6]
    data1.insert(0);
    data1.insert(2);
    data1.insert(4);
    data1.insert(5);
    data1.insert(6);

    data1.erase(0);
    data1.erase(4);


    // --- Final ---
    std::cout << "data0 before merge: " << data0 << "\n";
    std::cout << "data1 before merge: " << data1 << "\n";

    // Merge result -> [0,1,2,3,4,5]
    data0.merge(data1);
    data1.merge(data0);

    std::cout << "data0 after merge: " << data0 << "\n";
    std::cout << "data1 after merge: " << data1 << "\n";
}


}} // End namespaces
