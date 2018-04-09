
// CvRDT (State-based)
#include "CvRDT/GCounter_Test.h"
#include "CvRDT/PNCounterInt_Test.h"
#include "CvRDT/GVectorInt_Test.h"
#include "CvRDT/PNVectorInt_Test.h"
#include "CvRDT/LWWRegister_Test.h"
#include "CvRDT/GSet_Test.h"
#include "CvRDT/2PSet_Test.h"

// CmRDT (Operation-based)
#include "CmRDT/GCounterInt_Test.h"

using namespace CRDT;

int main(int argc, char** argv) {
    // CvRDT (State-based)
    CvRDT::GVectorInt_Test::example();

    CvRDT::PNCounterInt_example();
    CvRDT::PNVectorInt_example();

    CvRDT::LWWRegister_example();


    CvRDT::GCounter_example();

    CvRDT::GSet_example();
    CvRDT::TwoPSet_example();


    // CmRDT (Operation-based)
    // TODO

    return 0;
}
