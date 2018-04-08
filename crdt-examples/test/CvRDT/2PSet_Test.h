#pragma once

#include "CvRDT/2PSet.h"

#include <iostream>

namespace CRDT {
namespace CvRDT {


void TwoPSet_example() {
    TwoPSet<int> data0; // Ex: data at replicat 0
    TwoPSet<int> data1; // Ex: data at replicat 1


    // Modif (Add) from user0
    data0.insert(0);
    data0.insert(1);
    data0.insert(3);
    data0.insert(4);
    data0.insert(9);

    // Modif (Remove) from user0
    data0.remove(0);
    data0.remove(3);

    // User 1: [1,4,9]


    // Modif (Add) from user1
    data1.insert(3);
    data1.insert(4);
    data1.insert(7);
    data1.insert(8);

    // Modif (Remove) from user1
    data1.remove(3);
    data1.remove(4);

    // User 2: [7,8]


    data0.merge(data1);
    data1.merge(data0);

    std::cout << data0 << "\n";
    std::cout << data1 << "\n";

    // Should be [1,7,8,9]
}


}} // End namespaces
