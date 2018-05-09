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


    std::cout << "data0 = " << data0 << "\n";
    std::cout << "data1 = " << data1 << "\n";

    // --- Final ---
    std::cout << "(data0 == data1) = " << (data0 == data1);
    std::cout << " (true=" << true << ")\n";
    std::cout << "(data0 != data1) = " << (data0 != data1) << "\n";
}


}} // End namespaces


