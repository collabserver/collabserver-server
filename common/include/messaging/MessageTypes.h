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
    VIEW_LOAD_BY_ID = 1, // Starting from 0 was doing some weird bugs.


    // Internal use (TO KEEP LAST)
    COUNTER
};


} // End namespace
