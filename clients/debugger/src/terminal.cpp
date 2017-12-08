#include "terminal.h"

namespace ui {


void writeLine(const char* format, va_list argList) {
    vfprintf(stdout, format, argList);
    fprintf(stdout, "\n");
}

void writeLine(const char* format, ...) {
    va_list argList;
    va_start(argList, format);
    writeLine(format, argList);
    va_end(argList);
}

void listAllMessages() {
    const int nbMessages = static_cast<int>(collab::MessageTypes::Counter);

    writeLine("All possible messages: ");
    for(int k = 0; k < nbMessages; ++k) {
        writeLine(" - Message %d", k);
    }
}


} // End namespace
