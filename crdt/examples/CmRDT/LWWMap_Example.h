#pragma once

#include "CmRDT/LWWMap.h"

#include <iostream>
#include <string>

namespace CRDT {
namespace CmRDT {


void LWWMap_example() {
    std::cout << "\n----- CmRDT LWWMap Example ----------\n";

    LWWMap<std::string, int, int> data0; // Data at replicate 0
    LWWMap<std::string, int, int> data1; // Data at replicate 1


    // User1 flow (Normal order)
    data0.update("attr1", 500, 50);
    data0.insert("attr1", 100, 10);
    data0.insert("attr1", 200, 20);
    data0.update("attr1", 600, 60);
    data0.update("attr1", 110, 11);
    data0.update("attr1", 330, 33);
    data0.insert("attr1", 300, 30);
    data0.remove("attr1", 80);


    std::cout << "data0 = " << data0 << "\n";
    std::cout << "data1 = " << data1 << "\n";

    // --- Final ---
    std::cout << "(data0 == data1) = " << (data0 == data1);
    std::cout << " (true=" << true << ")\n";
    std::cout << "(data0 != data1) = " << (data0 != data1) << "\n";
}


}} // End namespaces


