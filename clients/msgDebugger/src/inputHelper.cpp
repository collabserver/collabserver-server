#include "inputHelper.h"

#include <cassert>
#include <stdio.h>  // getchar, fgets
#include <stdlib.h> // atoi
#include <string.h> // strchr


void clearBuffer() {
    int tmp;
    while((tmp = getchar()) != EOF && tmp != '\n');
}

void readFromStream(FILE* stream, char* buffer, const int size) {
    assert(stream != nullptr);
    assert(buffer != nullptr);
    assert(size >= 1);

    if(fgets(buffer, size + 1, stream) != NULL) { // +1 cuz \n count as one
        char* end = strchr(buffer, '\n');
        if(end != NULL) {
            *end = '\0';
        }
        else {
            clearBuffer();
        }
    }
    else {
        clearBuffer();
    }
}

int readInt(FILE* stream, const int size) {
    assert(stream != nullptr);
    assert(size >= 1);

    char buffer[size];
    readFromStream(stdin, buffer, size -1);
    return atoi(buffer);
}
