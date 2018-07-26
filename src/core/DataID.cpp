#include "collabserver/core/DataID.h"

namespace collab {


bool DataID::serialize(std::stringstream& buffer) const {
    // TODO serialize the id in buffer
    // TODO Place _content after that
    return false;
}

bool DataID::unserialize(const std::stringstream& buffer) {
    // TODO Unserialize the int for id
    // TODO Place what is after in _content
    return false;
}

int DataID::uniqueID() const {
    return _id;
}


} // End namespace


