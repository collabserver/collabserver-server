#include "messageSpawner.h"

#include <elephantlogger/log.h>


int main(int argc, char** argv) {
    elephantlogger::initDefault();

    runSpawner();
    return 0;
}
