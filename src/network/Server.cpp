#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/utils/Log.h"

namespace collab {


static ZMQSocket* local_socketREP = nullptr;
static ZMQSocket* local_socketPUB = nullptr;


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
    LOG << "Binding REP socket: (" << _address << ", " << _port << ")\n";
    LOG << "Binding PUB socket: (" << _address << ", " << COLLAB_SOCKET_SUB_PORT << ")\n";
    local_socketREP->bind(_address.c_str(), _port);
    local_socketPUB->bind(_address.c_str(), COLLAB_SOCKET_SUB_PORT);
    LOG << "Sockets successfully binded\n";

    while(_isRunning) {
        LOG << "Waiting for any message...\n";
        Message* msg = local_socketREP->receiveMessage();
        assert(msg != nullptr);
        this->handleMessage(*msg);
        MessageFactory::getInstance().freeMessage(msg);
    }

    LOG << "Unbinding sockets\n";
    local_socketREP->unbind();
}

void Server::stop() {
    LOG << "Server stop requested\n";
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
            LOG << "Unknown msg or invalid type (TypeID=" << msg.getType() << ")\n";
            break;
    }
}


// -----------------------------------------------------------------------------
// Message handling (Connection msg)
// -----------------------------------------------------------------------------

void Server::handleMessage(const MsgConnectionRequest& msg) {
    LOG << "Message received (MsgConnectionRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    const User* user = _collabserver->createNewUser();

    Message* response;
    if(user != nullptr) {
        unsigned int userID = user->getUserID();
        LOG << "(UserID=" << userID << "): New user successfully created\n";
        response = factory.newMessage(MessageFactory::MSG_CONNECTION_SUCCESS);
        static_cast<MsgConnectionSuccess*>(response)->setUserID(userID);
        local_socketREP->sendMessage(*response);
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

    unsigned int userID = static_cast<MsgDisconnectRequest>(msg).getUserID();
    bool success = _collabserver->deleteUser(userID);

    Message* response = nullptr;
    if(success) {
        LOG << "(UserID=" << userID << "): User successfully disconnect\n";
        response = factory.newMessage(MessageFactory::MSG_DISCONNECT_SUCCESS);
        local_socketREP->sendMessage(*response);
    }
    else {
        LOG << "(UserID=" << userID << "): Unable to disconnect user\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }
    factory.freeMessage(response);
}


// -----------------------------------------------------------------------------
// Message handling (Data msg)
// -----------------------------------------------------------------------------

void Server::handleMessage(const MsgCreaDataRequest& msg) {
    LOG << "Message received (MsgCreaDataRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    unsigned int userID = static_cast<MsgCreaDataRequest>(msg).getUserID();
    const Room* room = _collabserver->createNewRoom();
    unsigned int roomID = (room != nullptr) ? room->getRoomID() : -1;

    Message* response = nullptr;
    if(room != nullptr && _collabserver->userJoinRoom(userID, roomID)) {
        LOG << "(UserID=" << userID << "): Room successfully created (RoomID=" << roomID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_CREA_DATA_SUCCESS);
        static_cast<MsgCreaDataSuccess*>(response)->setDataID(roomID);
        local_socketREP->sendMessage(*response);
    }
    else {
        LOG << "(UserID=" << userID << "): Unable to create new room\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgJoinDataRequest& msg) {
    LOG << "Message received (MsgJoinDataRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    unsigned int userID = static_cast<MsgJoinDataRequest>(msg).getUserID();
    unsigned int roomID = static_cast<MsgJoinDataRequest>(msg).getDataID();

    bool success = _collabserver->userJoinRoom(userID, roomID);
    Message* response = nullptr;
    if(success) {
        LOG << "(UserID=" << userID << "): User successfully joined room (RoomID=" << roomID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_JOIN_DATA_SUCCESS);
        local_socketREP->sendMessage(*response);
    }
    else {
        LOG << "(UserID=" << userID << "): Unable to join room (RoomID=" << roomID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgLeaveDataRequest& msg) {
    LOG << "Message received (MsgLeaveDataRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    unsigned int userID = static_cast<MsgLeaveDataRequest>(msg).getUserID();
    bool success = _collabserver->userLeaveCurrentRoom(userID);

    Message* response = nullptr;
    if(success) {
        LOG << "(UserID=" << userID << "): Successfully left his room\n";
        response = factory.newMessage(MessageFactory::MSG_LEAVE_DATA_SUCCESS);
        local_socketREP->sendMessage(*response);
    }
    else {
        LOG << "(UserID=" << userID << "): Unable to left his room\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}


// -----------------------------------------------------------------------------
// Message handling (Various msg)
// -----------------------------------------------------------------------------

void Server::handleMessage(const MsgUgly& msg) {
    LOG << "Message received (MsgUgly)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    unsigned int userID = static_cast<MsgUgly>(msg).getUserID();
    bool isUgly = _collabserver->isUserUgly(userID);

    LOG << "(UserID=" << userID << "): isUgly response = " << isUgly << "\n";

    Message* response = factory.newMessage(MessageFactory::MSG_UGLY);
    static_cast<MsgUgly*>(response)->setResponse(isUgly);
    local_socketREP->sendMessage(*response);

    factory.freeMessage(response);
}


// -----------------------------------------------------------------------------
// Message handling (Room msg)
// -----------------------------------------------------------------------------

void Server::handleMessage(const MsgRoomOperation& msg) {
    LOG << "Message received (MsgRoomOperation)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    OperationInfo op;
    op.roomID   = static_cast<const MsgRoomOperation>(msg).getRoomID();
    op.userID   = static_cast<const MsgRoomOperation>(msg).getUserID();
    op.opTypeID = static_cast<const MsgRoomOperation>(msg).getOpTypeID();
    op.buffer   = static_cast<const MsgRoomOperation>(msg).getOperationBuffer();

    // It's just aliases for visibility
    const unsigned int roomID = op.roomID;
    const unsigned int userID = op.userID;

    bool success = _collabserver->commitOperationInRoom(op, roomID);

    Message* response = nullptr;
    if(success) {
        // DevNote: REP Pattern requires a response, here, this is a dummy response.
        LOG << "(UserID=" << userID << "): Successfully broadcasted operation (RoomID=" << roomID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_EMPTY);
        local_socketREP->sendMessage(*response);
    }
    else {
        LOG << "(UserID=" << userID << "): Unable to broadcast operation (RoomID=" << roomID << ")\n";
        response = factory.newMessage(MessageFactory::MSG_ERROR);
        local_socketREP->sendMessage(*response);
    }

    factory.freeMessage(response);
}


// -----------------------------------------------------------------------------
// Broadcaster methods
// -----------------------------------------------------------------------------

void Server::sendOperationToUser(const OperationInfo& op, unsigned int id) {
    MessageFactory& factory = MessageFactory::getInstance();

    LOG << "(RoomID=" << op.roomID << "): Sending operation to user (UserID=" << id << ")\n";

    Message* msg = factory.newMessage(MessageFactory::MSG_ROOM_OPERATION);

    static_cast<MsgRoomOperation*>(msg)->setRoomID(op.roomID);
    static_cast<MsgRoomOperation*>(msg)->setUserID(op.userID);
    static_cast<MsgRoomOperation*>(msg)->setOpTypeID(op.opTypeID);
    static_cast<MsgRoomOperation*>(msg)->setOperationBuffer(op.buffer);

    local_socketPUB->sendMessage(*msg);

    factory.freeMessage(msg);
}

void Server::broadcastOperationToRoom(const OperationInfo& op, unsigned int id) {
    MessageFactory& factory = MessageFactory::getInstance();

    LOG << "(UserID=" << op.userID << "): Broadcasting operation in room (roomID=" << id << ")\n";

    Message* msg = factory.newMessage(MessageFactory::MSG_ROOM_OPERATION);

    static_cast<MsgRoomOperation*>(msg)->setRoomID(op.roomID);
    static_cast<MsgRoomOperation*>(msg)->setUserID(op.userID);
    static_cast<MsgRoomOperation*>(msg)->setOpTypeID(op.opTypeID);
    static_cast<MsgRoomOperation*>(msg)->setOperationBuffer(op.buffer);

    local_socketPUB->sendMessage(*msg);

    factory.freeMessage(msg);
}


} // End namespace


