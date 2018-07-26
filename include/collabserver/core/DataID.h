#pragma once

#include <sstream>

namespace collab {


/**
 * \brief
 * Unique Identifier for a data inside the CollabServer.
 *
 * Remember that CollabServer may work for several running database.
 * Two different data may have the same id because in two different
 * database (Data1 with ID=1 in database A and Data2 with ID=1 in database B).
 * Therefore, inside CollabServer, the unique ID must be set from the user
 * ID + a unique ID inside CollabServer.
 *
 * \par Unique Identifier
 * Each database may differentiate an entity using specific unique identifier.
 * For instance, SQL often uses a unique number, file system may uses
 * the full file path etc
 * CollabServer should not know about each concrete ID (For specific database).
 * Inside CollabServer, a unique int ID is used to differentiate data.
 */
class DataID {
    private:
        int _id = 0;
        std::string _content;

    public:
        bool serialize(std::stringstream& buffer) const;
        bool unserialize(const std::stringstream& buffer);

    public:
        int uniqueID() const;
};


} // End namespace


