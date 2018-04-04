#pragma once

#include <time.h>

namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

/**
 * Last-Writer-Wins Register (LWW Register).
 */
struct LWWRegister {
    void* _m;
    time_t _timestamp; // WARNING: in practice, not precise enought (only hh:mm:ss here)
};


// -----------------------------------------------------------------------------
// Data Methods
// -----------------------------------------------------------------------------
void* LWWRegister_query(const LWWRegister& data) {
    return data._m;
}

void LWWRegister_assign(LWWRegister& data, const void* x) {
    data._m = x;
    data._timestamp = time(NULL);
}

void LWWRegister_merge(LWWRegister& ours, LWWRegister& theirs) {
    double elapsed = difftime(ours._timestamp, thiers._timestamp);
    if(elapsed > 0) {
        ours._m = thiers._m;
    }
}


}} // End namespaces

