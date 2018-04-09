#pragma once

namespace CRDT {
namespace CmRDT {


// -----------------------------------------------------------------------------
// Data
// -----------------------------------------------------------------------------


/**
 * Grow-only Integer Counter.
 * CmRDT (Operation Based).
 *
 * Local update must be Broadcasted to other replicates.
 * Updated must be received once by replicated (Not-idempotent)
 */
struct GCounterInt {
    int _m; // The actual counter
};

struct GCounterIntUpdate {
    int _m;
};


// -----------------------------------------------------------------------------
// Data Methods
// -----------------------------------------------------------------------------

int GCounterInt_query(GCounterInt& data) {
    return data._m;
}

/**
 * Increment the counter and creates an update to broadcast.
 */
GCounterIntUpdate GCounterInt_increment(GCounterInt& data) {
    return GCounterIntUpdate{1};
}

/**
 * Decrement the counter and creates an update to broadcast
 */
GCounterIntUpdate GCounterInt_decrement(GCounterInt& data) {
    return GCounterIntUpdate{-1};
}

void GCounterInt_update(GCounterInt& data, GCounterIntUpdate& update) {
    data._m += update._m;
}


}} // End namespaces
