#pragma once

#include <cassert>

namespace collab {


/**
 * \brief
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

    public:
        int getID() const {
            return _id;
        }

        void setCurrentOperationID(const int id) {
            assert(id > _currentOperationID);
            _currentOperationID = id;
        }
};


} // End namespace


