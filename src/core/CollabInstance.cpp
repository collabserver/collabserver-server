#include "collabserver/core/CollabInstance.h"

#include "collabcommon/utils/Log.h"

using namespace collab;

int CollabInstance::addNewUser() {
    // There is a copy but that's ok
    User coco;
    _users.insert(std::make_pair(coco.getID(), coco));
    return coco.getID();
}

bool CollabInstance::removeUser(const int id) {
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
