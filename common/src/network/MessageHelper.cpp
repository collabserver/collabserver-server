#include "network/MessageHelper.h"

#include "messaging/IMessage.h"
#include "messaging/MessageFactory.h"

#include <sstream>  // std::stringstream


using namespace collab;


static size_t internal_calculStreamSize(std::stringstream & stream) {
    stream.seekg(0, std::ios::end);
    const size_t size = stream.tellg();
    stream.seekg(0);
    return size;
}


static void sendMessage(zmq::socket_t socket, const IMessage & msg) {
    std::stringstream buffer;
    msg.serialize(buffer);
    const size_t msgSize = internal_calculStreamSize(buffer);
    const int type = static_cast<int>(msg.getType());

    zmq::message_t request(msgSize + 1); // +1 for the msg type elt

    char* ptrStart = static_cast<char*>(request.data()) + 1;
    memcpy(request.data(), &type, 1);
    memcpy(ptrStart, buffer.str().c_str(), msgSize); 

    socket.send(request);
}
