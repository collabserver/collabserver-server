#pragma once

namespace CRDT {
namespace CvRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------

/**
 * Last-Writer-Wins Register (LWW Register).
 */
struct LWWRegister {
    int _m;
    // TODO timestamp
};


// -----------------------------------------------------------------------------
// Data Methods
// -----------------------------------------------------------------------------
int LWWRegister_query(const LWWRegister& data) {
    return data._m;
}


}} // End namespaces

