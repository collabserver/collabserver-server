#pragma once

#include "CmRDT/LWWGraph.h"

#include <iostream>
#include <string>

namespace CRDT {
namespace CmRDT {


void LWWGraph_example() {
    std::cout << "\n----- CmRDT LWWGraph Example ----------\n";

    LWWGraph<std::string, int, int> data0; // Data at replicate 0
    LWWGraph<std::string, int, int> data1; // Data at replicate 1


    // --- Final ---
    std::cout << "data0 = " << data0 << "\n";
    std::cout << "data1 = " << data1 << "\n";

    std::cout << "(data0 == data1) = " << (data0 == data1);
    std::cout << " (true=" << true << ")\n";
    std::cout << "(data0 != data1) = " << (data0 != data1) << "\n";
}


}} // End namespaces


