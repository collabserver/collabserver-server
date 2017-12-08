#include "messageSpawner.h"

#include <elephantlogger/log.h>


int main(int argc, char** argv) {
    elephantlogger::init();
    elephantlogger::setDefaultChannels();

    runSpawner();
    return 0;
}
