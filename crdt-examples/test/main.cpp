
// CvRDT (State-based)
#include "CvRDT/GCounterInt_Test.h"
#include "CvRDT/GSetInt_Test.h"
#include "CvRDT/GVectorInt_Test.h"
#include "CvRDT/LWWRegister_Test.h"
#include "CvRDT/PNCounterInt_Test.h"
#include "CvRDT/PNVectorInt_Test.h"
#include "CvRDT/USetInt_Test.h"

// CmRDT (Operation-based)
#include "CmRDT/GCounterInt_Test.h"

using namespace CRDT;

int main(int argc, char** argv) {
    // CvRDT (State-based)
    CvRDT::GCounterInt_Test::example();
    CvRDT::GVectorInt_Test::example();

    CvRDT::PNCounterInt_example();
    CvRDT::PNVectorInt_example();

    CvRDT::GSetInt_example();
    CvRDT::USetInt_example();

    // CmRDT (Operation-based)

    return 0;
}
