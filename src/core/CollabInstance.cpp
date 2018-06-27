#include "collabserver/core/CollabInstance.h"

#include "collabcommon/utils/Log.h"

namespace collab {

int CollabInstance::createNewUser() {
    // There is a copy but that's ok
    User coco;
    _users.insert(std::make_pair(coco.getUserID(), coco));
    return coco.getUserID();
}

bool CollabInstance::deleteUser(const int id) {
    auto it = _users.find(id);
    if(it == _users.end()) {
        return false;
    }
    User& user = it->second;
    bool success = user.leaveCurrentRoom();
    if(!success) {
        return false;
    }
    return (_users.erase(id) == 1);
}

int CollabInstance::getNbUsers() const {
    return _users.size();
}


} // End namespace


