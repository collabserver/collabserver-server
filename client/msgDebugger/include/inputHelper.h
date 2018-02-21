#pragma once

#include <stdio.h>


/**
 * Clear the current input buffer.
 */
void clearBuffer();


/**
 * Read from stream and place in buffer.
 * Read up to 'size' elements.
 *
 * \warning
 * Buffer must end with '\0'.
 * The given size should take '\0\ into accound and be at max bufferSize -1.
 *
 * \note
 * No buffer overflow if size < bufferSize, stream buffer is cleared.
 * If size >= bufferSize, risk of overflow!
 *
 * \param stream Where to read from.
 * \param buffer Where to write.
 * \param size Max number of char to write in buffer.
 */
void readFromStream(FILE* stream, char* buffer, const int size);


/**
 * Read an int from the given stream.
 * Read up to size element and convert to int.
 *
 * \param stream Where to read from.
 * \param size Max number of char to read.
 */
int readInt(FILE* stream, const int size);
