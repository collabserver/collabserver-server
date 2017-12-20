#include "DatabaseDebugger.h"


void DatabaseDebugger::run() {
    assert(this->m_isRunning == false);
    if(this->m_isRunning) {
        return;
    }
    this->m_isRunning = true;

    this->m_proxy.connect("localhost", 5556);
}

void DatabaseDebugger::stop() {
    this->m_isRunning = false;
}
