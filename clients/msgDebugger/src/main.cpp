#include "MsgDebugger.h"
#include <elephantlogger/log.h>


using namespace collab;


int main(int argc, char** argv) {
    elephantlogger::initDefault();

    MsgDebugger debugger;
    debugger.run();

    return 0;
}
