#pragma once

#include "CvRDT/2PSet.h"

#include <iostream>

namespace CRDT {
namespace CvRDT {


void TwoPSet_example() {
    TwoPSet<int> data0; // Ex: data at replicat 0
    TwoPSet<int> data1; // Ex: data at replicat 1


    // Replicat 0 (data0) ------------------------------------------------------

    // Modif (Add) from user0
    data0.insert(0);
    data0.insert(1);
    data0.insert(2);
    data0.insert(3);
    data0.insert(4);

    // Modif (erase) from user0
    data0.erase(0);
    data0.erase(3);

    // -> User 0: [1,2,4]

    std::cout << "\n--- Iterator data0 (BEFORE merge) ---\n";
    for(auto it = data0.begin(); it != data0.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n------\n";


    // Replicat 1 (data1) ------------------------------------------------------

    // Modif (Add) from user1
    data1.insert(0);
    data1.insert(2);
    data1.insert(4);
    data1.insert(5);
    data1.insert(6);

    // Modif (erase) from user1
    data1.erase(0);
    data1.erase(4);

    // -> User 1: [2,6]


    data0.merge(data1);
    data1.merge(data0);
    // Merge result -> [1,2,5,6]

    std::cout << "\n--- Iterator data0 (AFTER merge) ---\n";
    for(auto it = data0.begin(); it != data0.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n------\n";

    std::cout << data0 << "\n";
    std::cout << data1 << "\n";
}


}} // End namespaces
