#pragma once

#include <cstdint>
#include <string>

#include "collabserver/network/messaging/Message.h"
#include "collabserver/network/messaging/MessageList.h"
#include "collabserver/server/core/Broadcaster.h"
#include "collabserver/server/core/CollabServer.h"
#include "collabserver/server/utils/constants.h"

namespace collabserver {

struct ServerConfig {
    uint16_t port;
};

/**
 * \brief
 * Server for network communication.
 *
 * \par Default settings
 *  - port: 4242
 */
class Server : public Broadcaster {
   private:
    bool _isRunning = false;
    std::string _address = "*";
    uint16_t _port = COLLAB_DEFAULT_SERVER_PORT;

   private:
    CollabServer* _collabserver = nullptr;

   public:
    Server();
    Server(const ServerConfig& config);
    ~Server();

   public:
    void start();
    void stop();

   private:
    void handleMessage(const Message& msg);
    void handleMessage(const MsgConnectionRequest& msg);
    void handleMessage(const MsgDisconnectRequest& msg);
    void handleMessage(const MsgCreaDataRequest& msg);
    void handleMessage(const MsgJoinDataRequest& msg);
    void handleMessage(const MsgLeaveDataRequest& msg);
    void handleMessage(const MsgRoomOperation& msg);
    void handleMessage(const MsgUgly& msg);

   private:
    void sendOperationToUser(const OperationInfo& op, unsigned int id) override;
    void broadcastOperationToRoom(const OperationInfo& op, unsigned int id) override;
};

}  // namespace collabserver
