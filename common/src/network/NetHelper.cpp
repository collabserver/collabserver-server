#include "network/NetHelper.h"

#include "messaging/IMessage.h"
#include "messaging/MessageFactory.h"

#include <sstream>  // std::stringstream
#include <cassert>
#include <memory> // std::unique_ptr
#include <elephantlogger/log.h>


using namespace collab;


// For local / internal use
static size_t internal_calculStreamSize(std::stringstream & stream) {
    // TODO: There might be a better way to do that!
    stream.seekg(0, std::ios::end);
    const size_t size = stream.tellg();
    stream.seekg(0);
    return size;
}

void NetHelper::sendMessage(zmq::socket_t & socket, const IMessage & msg) {
    std::stringstream buffer;
    msg.serialize(buffer);

    const size_t msgSize = internal_calculStreamSize(buffer);
    const int    msgType = static_cast<int>(msg.getType());

    zmq::message_t request(msgSize + 1); // +1 for the msg type byte

    char* ptrBufferStart = static_cast<char*>(request.data()) + 1;

    memcpy(request.data(), &msgType, 1);
    memcpy(ptrBufferStart, buffer.str().c_str(), msgSize); 

    socket.send(request);
}

void NetHelper::processMessage(const char* msg, const size_t size) {
    const int       msgType = static_cast<int>(msg[0]);
    const char*     msgData = msg + 1;
    const size_t    msgSize = size - 1;

    LOG_DEBUG(0, "Message received! Type: %d, Size: %d, Raw content: %s", msgType, msgSize, msgData);

    std::unique_ptr<IMessage> m = MessageFactory::getInstance().newMessage(static_cast<MessageTypes>(msgType));
    assert(m != nullptr);
    if(m == nullptr) {
        LOG_DEBUG(0, "Unknown message type %d", msgType);
        return;
    }

    std::stringstream stream;
    stream.str(std::string(msgData, msgSize));
    m->unserialize(stream);
    m->apply();
}


