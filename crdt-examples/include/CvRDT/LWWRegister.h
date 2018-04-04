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
template<typename T>
struct LWWRegister {
    T _m;
    time_t _timestamp; // WARNING: in practice, not precise enought (only hh:mm:ss here)
};


// -----------------------------------------------------------------------------
// Data Methods
// -----------------------------------------------------------------------------

// Return current time.
// WARNING: This is only for education and test purpose
// now actually returns an unique ordered number for the running instance.
// This is to fake that all replicate create update with unique timestamp
// with total order
// (Ex: MAC Address + actual timestamp).
static time_t now() {
    static int counter = 0;
    counter++;
    time_t t = time(NULL) + counter;
    return t;
}

template<typename T>
T LWWRegister_query(const LWWRegister<T>& data) {
    return data._m;
}

template<typename T>
void LWWRegister_assign(LWWRegister<T>& data, T x) {
    data._m = x;
    data._timestamp = now();
}

template<typename T>
void LWWRegister_merge(LWWRegister<T>& ours, const LWWRegister<T>& theirs) {
    double elapsed = difftime(ours._timestamp, theirs._timestamp);
    if(elapsed < 0) {
        // This assume timestamp has a total order so that elapsed can't be 0
        ours._m = theirs._m;
    }
}


}} // End namespaces

