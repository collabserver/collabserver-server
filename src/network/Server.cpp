#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/utils/Log.h"

namespace collab {


static ZMQSocket* local_socketREP = nullptr;
static ZMQSocket* local_socketPUB = nullptr;

static const int INTERNAL_PUB_PORT = 4243;


Server::Server() {
    ZMQSocketConfig configREP = { ZMQ_REP, &(MessageFactory::getInstance()) };
    ZMQSocketConfig configPUB = { ZMQ_PUB, &(MessageFactory::getInstance()) };

    _collabserver = new CollabServer(*this);
    local_socketREP = new ZMQSocket(configREP);
    local_socketPUB = new ZMQSocket(configPUB);

    assert(_collabserver != nullptr);
    assert(local_socketREP != nullptr);
    assert(local_socketPUB != nullptr);
}

Server::Server(const ServerConfig& config) : Server() {
    _port = config.port;
}

Server::~Server() {
    assert(_collabserver != nullptr);
    assert(local_socketREP != nullptr);
    assert(local_socketPUB != nullptr);
    this->stop();
    delete _collabserver;
    delete local_socketREP;
    delete local_socketPUB;
}

void Server::start() {
    assert(_isRunning == false);
    assert(local_socketREP != nullptr);
    assert(local_socketPUB != nullptr);

    if(_isRunning) { return; }
    _isRunning = true;
    LOG << "Starting network server\n";
    LOG << "Binding REP socket: (" << _address << ", " << _port << ")...\n";
    LOG << "Binding PUB socket: (" << _address << ", " << INTERNAL_PUB_PORT << ")...\n";
    local_socketREP->bind(_address.c_str(), _port);
    local_socketPUB->bind(_address.c_str(), INTERNAL_PUB_PORT);
    LOG << "Sockets successfully binded\n";

    while(_isRunning) {
        LOG << "Waiting for any message... \n";
        Message* msg = local_socketREP->receiveMessage();
        assert(msg != nullptr);
        this->handleMessage(*msg);
        MessageFactory::getInstance().freeMessage(msg);
    }

    LOG << "Unbinding socket...\n";
    local_socketREP->unbind();
}

void Server::stop() {
    this->_isRunning = false;
}


// -----------------------------------------------------------------------------
// Message handling
// -----------------------------------------------------------------------------

void Server::handleMessage(const Message& msg) {
    switch(msg.getType()) {

        // Connection
        case MessageFactory::MSG_CONNECTION_REQUEST:
            this->handleMessage(static_cast<const MsgConnectionRequest&>(msg));
            break;
        case MessageFactory::MSG_DISCONNECT_REQUEST:
            this->handleMessage(static_cast<const MsgDisconnectRequest&>(msg));
            break;

        // Data
        case MessageFactory::MSG_CREA_DATA_REQUEST:
            this->handleMessage(static_cast<const MsgCreaDataRequest&>(msg));
            break;
        case MessageFactory::MSG_JOIN_DATA_REQUEST:
            this->handleMessage(static_cast<const MsgJoinDataRequest&>(msg));
            break;
        case MessageFactory::MSG_LEAVE_DATA_REQUEST:
            this->handleMessage(static_cast<const MsgLeaveDataRequest&>(msg));
            break;

        // Room
        case MessageFactory::MSG_ROOM_OPERATION:
            this->handleMessage(static_cast<const MsgRoomOperation&>(msg));
            break;

        // Various
        case MessageFactory::MSG_UGLY:
            this->handleMessage(static_cast<const MsgUgly&>(msg));
            break;

        default:
            LOG << "Bad message received "
                << "(Unknown or invalid type: " << msg.getType() << ")\n";
            break;
    }
}

void Server::handleMessage(const MsgConnectionRequest& msg) {
    LOG << "Message received (MsgConnectionRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    const User* user = _collabserver->createNewUser();

    Message* response;
    if(user != nullptr) {
        int userID = user->getUserID();
        response = factory.newMessage(MessageFactory::MSG_CONNECTION_SUCCESS);
        static_cast<MsgConnectionSuccess*>(response)->setUserID(userID);
        local_socketREP->sendMessage(*response);
        LOG << "OK: New user successfully (ID = " << userID << ")\n";
    }
    else {
        LOG << "ERROR: Unable to create a new user in CollabServer\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }
    factory.freeMessage(response);
}

void Server::handleMessage(const MsgDisconnectRequest& msg) {
    LOG << "Message received (MsgDisconnectRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgDisconnectRequest>(msg).getUserID();
    bool success = _collabserver->deleteUser(userID);

    Message* response = nullptr;
    if(success) {
        LOG << "OK: User disconnect successfully (ID = " << userID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_DISCONNECT_SUCCESS);
        local_socketREP->sendMessage(*response);
    }
    else {
        LOG << "OK: Unable to disconnect user (ID = " << userID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }
    factory.freeMessage(response);
}

void Server::handleMessage(const MsgCreaDataRequest& msg) {
    LOG << "Message received (MsgCreaDataRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgCreaDataRequest>(msg).getUserID();
    const Room* room = _collabserver->createNewRoom();
    int roomID = (room != nullptr) ? room->getRoomID() : -1;

    Message* response = nullptr;
    if(room != nullptr && _collabserver->userJoinRoom(userID, roomID)) {
        response = factory.newMessage(MessageFactory::MSG_CREA_DATA_SUCCESS);
        static_cast<MsgCreaDataSuccess*>(response)->setDataID(roomID);
        local_socketREP->sendMessage(*response);
        LOG << "OK: Room successfully created (ID = " << roomID << ")\n";
    }
    else {
        LOG << "ERROR: Unable to create a new room\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgJoinDataRequest& msg) {
    LOG << "Message received (MsgJoinDataRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgJoinDataRequest>(msg).getUserID();
    int roomID = static_cast<MsgJoinDataRequest>(msg).getDataID();
    bool success = _collabserver->userJoinRoom(userID, roomID);

    Message* response = nullptr;
    if(success) {
        response = factory.newMessage(MessageFactory::MSG_JOIN_DATA_SUCCESS);
        local_socketREP->sendMessage(*response);
        LOG << "OK: User (ID = " << userID << ") successfully joined room\n";
    }
    else {
        LOG << "ERROR: User (ID = " << userID << ") is unable to join room\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgLeaveDataRequest& msg) {
    LOG << "Message received (MsgLeaveDataRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgLeaveDataRequest>(msg).getUserID();
    bool success = _collabserver->userLeaveCurrentRoom(userID);

    Message* response = nullptr;
    if(success) {
        response = factory.newMessage(MessageFactory::MSG_LEAVE_DATA_SUCCESS);
        local_socketREP->sendMessage(*response);
        LOG << "OK: User (ID = " << userID << ") successfully left room\n";
    }
    else {
        LOG << "ERROR: User (ID = " << userID << ") is unable to leave room\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgRoomOperation& msg) {
    LOG << "Message received (MsgRoomOperation)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgRoomOperation>(msg).getUserID();
    int roomID = static_cast<MsgRoomOperation>(msg).getRoomID();

    //const Room* room = _collabserver->findRoom(roomID);

    Message* response = nullptr;
    if(!_collabserver->isUserInRoom(userID, roomID)) {
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    // TODO

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgUgly& msg) {
    LOG << "Message received (MsgUgly)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgUgly>(msg).getUserID();
    bool isUgly = _collabserver->isUserUgly(userID);

    Message* response = factory.newMessage(MessageFactory::MSG_UGLY);
    static_cast<MsgUgly>(msg).setResponse(isUgly);
    local_socketREP->sendMessage(*response);
    factory.freeMessage(response);
}

void Server::sendOperationToUser(const OperationInfo& op, int id) {
    LOG << "Sending operation (" << op.opTypeID << ") to user (ID="<< id << ")\n";
    MessageFactory& factory = MessageFactory::getInstance();

    Message* msg = nullptr;
    msg = factory.newMessage(MessageFactory::MSG_DEBUG); // TODO TMP
    // TODO Operation msg
    factory.freeMessage(msg);
}

void Server::broadcastOperationToRoom(const OperationInfo& op, int id) {
    LOG << "Broadcasting operation ("<< op.opTypeID <<") to user ("<< id <<")\n";
    MessageFactory& factory = MessageFactory::getInstance();

    Message* msg = nullptr;
    msg = factory.newMessage(MessageFactory::MSG_DEBUG); // TODO TMP
    // TODO Operation msg
    factory.freeMessage(msg);
}

} // End namespace


