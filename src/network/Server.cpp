#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/utils/Log.h"

namespace collab {


static ZMQSocket* local_socket = nullptr;


Server::Server() {
    ZMQSocketConfig config = {
        ZMQ_REP,
        &(MessageFactory::getInstance())
    };

    local_socket = new ZMQSocket(config);
    _collabserver = new CollabServer(*this);

    assert(_collabserver != nullptr);
    assert(local_socket != nullptr);
}

Server::Server(const ServerConfig& config) : Server() {
    _port = config.port;
}

Server::~Server() {
    assert(_collabserver != nullptr);
    assert(local_socket != nullptr);
    this->stop();
    delete _collabserver;
    delete local_socket;
}

void Server::start() {
    assert(_isRunning == false);
    assert(local_socket != nullptr);

    if(_isRunning) {
        return;
    }
    _isRunning = true;
    LOG << "Starting network server\n";
    LOG << "Binding socket: (" << _address << ", " << _port << ")...\n";
    local_socket->bind(_address.c_str(), _port);
    LOG << "Socket successfully binded\n";

    while(_isRunning) {
        LOG << "Waiting for any message... \n";
        Message* msg = local_socket->receiveMessage();
        assert(msg != nullptr);
        this->handleMessage(*msg);
        MessageFactory::getInstance().freeMessage(msg);
    }

    LOG << "Unbinding socket...\n";
    local_socket->unbind();
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

        // Various
        case MessageFactory::MSG_DEBUG:
            this->handleMessage(static_cast<const MsgDebug&>(msg));
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
    int userID = _collabserver->createNewUser();
    // TODO Check if error creating user (ex: Server full)

    Message* response = nullptr;
    response = factory.newMessage(MessageFactory::MSG_CONNECTION_SUCCESS);

    static_cast<MsgConnectionSuccess*>(response)->setUserID(userID);
    local_socket->sendMessage(*response);

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgDisconnectRequest& msg) {
    LOG << "Message received (MsgDisconnectRequest)\n";
    MessageFactory& factory = MessageFactory::getInstance();

    int userID = static_cast<MsgDisconnectRequest>(msg).getUserID();
    _collabserver->deleteUser(userID);
    // TODO Check if error deleting user

    Message* response = nullptr;
    response = factory.newMessage(MessageFactory::MSG_DISCONNECT_SUCCESS);
    local_socket->sendMessage(*response);

    factory.freeMessage(response);
}

void Server::handleMessage(const MsgCreaDataRequest& msg) {
    LOG << "Message received (MsgCreaDataRequest)\n";
}

void Server::handleMessage(const MsgJoinDataRequest& msg) {
    LOG << "Message received (MsgJoinDataRequest)\n";
}

void Server::handleMessage(const MsgLeaveDataRequest& msg) {
    LOG << "Message received (MsgLeaveDataRequest)\n";
}

void Server::handleMessage(const MsgDebug& msg) {
    LOG << "Message received (MsgDebug)\n";
    LOG << "Debug content: " << msg.getContent();
}


} // End namespace


