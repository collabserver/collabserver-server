#pragma once

#include <set>
#include <iterator>
#include <cassert>
#include <stdio.h>

namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

/**
 * Grow Only (add-only) Set Integer.
 * CvRDT (State-based object).
 *
 * \author  Constantin Masson
 * \date    March 2018
 */
struct GSetInt {
    std::set<int> _m;
};


// -----------------------------------------------------------------------------
// Data Methods
// -----------------------------------------------------------------------------


int GSetInt_find(const GSetInt& data, const int value) {
    return *(data._m.find(value));
}

void GSetInt_add(GSetInt& data, const int value) {
    data._m.emplace(value);
}

void GSetInt_merge(GSetInt& ours, const GSetInt& theirs) {
    for(auto it = theirs._m.begin(); it != theirs._m.end(); ++it) {
        bool contains = (ours._m.find(*it) != ours._m.end());
        if(!contains) {
            ours._m.emplace(*it);
        }
    }
}

void GSetInt_print(const GSetInt& data) {
    std::set<int>::const_iterator it = data._m.begin();

    if(data._m.empty()) {
        fprintf(stdout, "GSetInt: [empty]\n");
    }
    else {
        fprintf(stdout, "GSetInt: [%d", *it);
        for(++it; it != data._m.end(); ++it) {
            fprintf(stdout, ",%d", *it);
        }
        fprintf(stdout, "]\n");
    }
}


}} // End namespaces
