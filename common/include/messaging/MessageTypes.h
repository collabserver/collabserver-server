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
    Create = 1, // Starting from 0 was doing some weird bugs.
    Delete,
    Read,
    Update,


    // Internal use (TO KEEP LAST)
    Counter
};


} // End namespace
