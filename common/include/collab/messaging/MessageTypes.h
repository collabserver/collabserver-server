#pragma once


namespace collab {


/**
 * List all possible messages.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
enum class MessageTypes : int {
    // Start at 1 because 0 was doing weird behavior with bit-backing types.

    // View Messages
    VIEW_REQUEST_LOAD_BY_ID = 1,
    VIEW_RESPONSE_LOAD_BY_ID,


    // Internal use (TO KEEP LAST)
    COUNTER
};


} // End namespace
