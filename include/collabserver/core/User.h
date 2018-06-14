#pragma once

namespace collab {


/**
 * TODO Documentation
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class User {
    private:
        const int _id;
        int _currentOperationID = 0;

    public:
        User(const int id) : _id(id) {
            // Hi little rabbit :)
        }
};


} // End namespace
