
// CvRDT (State-based)
#include "CvRDT/GCounter_Example.h"
#include "CvRDT/PNCounter_Example.h"
#include "CvRDT/LWWRegister_Example.h"
#include "CvRDT/GSet_Example.h"
#include "CvRDT/2PSet_Example.h"
#include <CvRDT/2P2PGraph.h>

// CmRDT (Operation-based)
#include "CmRDT/GCounterInt_Example.h"

using namespace CRDT;


int main(int argc, char** argv) {
    // CvRDT (State-based)

    CvRDT::GCounter_example();
    CvRDT::PNCounter_example();

    CvRDT::LWWRegister_example();

    CvRDT::GSet_example();
    CvRDT::TwoPSet_example();


    // CmRDT (Operation-based)
    // TODO

    return 0;
}
