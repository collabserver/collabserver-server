#pragma once

#include <set>
#include <iterator>
#include <cassert>
#include <stdio.h>

#define NB_PROCESS 2 // TODO: Nb process is hardcoded


namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

struct GSetInt {
    std::set<int> _m;
};


// -----------------------------------------------------------------------------
// Method to work on Data (GSetInt)
// -----------------------------------------------------------------------------


int GSetInt_find(GSetInt& data, const int value) {
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
    //auto it = data._m.begin(); (Better, but for learning purpose, the other)

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
