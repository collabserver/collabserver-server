#include "CvRDT/GCounterInt_Test.h"
#include "CvRDT/GVectorInt_Test.h"
#include "CvRDT/PNCounterInt_Test.h"
#include "CvRDT/PNVectorInt_Test.h"

using namespace CRDT;

int main(int argc, char** argv) {
    CvRDT::GCounterInt_Test::example();
    CvRDT::GVectorInt_Test::example();

    CvRDT::PNCounterInt_example();
    CvRDT::PNVectorInt_example();

    return 0;
}
