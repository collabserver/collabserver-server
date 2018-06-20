#include "Terminal.h"

#include "collabmessaging/MessageTypes.h"

namespace collab {
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
    const int nbMessages = static_cast<int>(collab::MessageTypes::COUNTER);

    writeLine("All possible messages: ");
    for(int k = 1; k < nbMessages+1; ++k) {
        writeLine(" - Message %d", k);
    }
}


}} // End namespace


