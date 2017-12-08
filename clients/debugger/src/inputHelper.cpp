#include "inputHelper.h"

#include <stdio.h>  // getchar, fgets
#include <string.h> // strchr


void clearBuffer() {
    int tmp;
    while((tmp = getchar()) != EOF && tmp != '\n');
}

void readFromStream(FILE* stream, char* buffer, const int size) {
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
