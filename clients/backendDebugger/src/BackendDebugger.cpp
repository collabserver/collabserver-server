#include "BackendDebugger.h"


void BackendDebugger::run() {
    assert(this->m_isRunning == false);
    if(this->m_isRunning) {
        return;
    }
    this->m_isRunning = true;

    this->m_proxy.connect("localhost", 5556);
}

void BackendDebugger::stop() {
    this->m_isRunning = false;
}
