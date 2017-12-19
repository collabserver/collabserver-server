#pragma once

#include "messaging/MessageTypes.h"

#include <stdio.h>
#include <stdarg.h>


namespace ui {


void writeLine(const char* format, va_list argList);
void writeLine(const char* format, ...);
void listAllMessages();


} // End namespace
