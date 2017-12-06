#include <elephant.h>

#include <zmq.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include <stdio.h>  // getchar, fgets
#include <string.h> // strchr

#include <unistd.h>
#include <msgpack.hpp>


// -----------------------------------------------------------------------------
// Utils
// -----------------------------------------------------------------------------
void clearBuffer() {
    int tmp;
    while((tmp = getchar()) != EOF && tmp != '\n');
}

/**
 * Read from stream and place in buffer.
 * Read up to 'size' elements.
 *
 * \warning
 * Buffer must end with '\0'.
 * The given size should take '\0\ into accound and be at max bufferSize -1.
 *
 * \note
 * No buffer overflow if size < bufferSize, stream buffer is cleared.
 * If size >= bufferSize, risk of overflow!
 *
 * \param stream Where to read from.
 * \param buffer Where to write.
 * \param size Max number of char to write in buffer.
 */
void readFromStream(FILE* stream, char* buffer, const int size) {
    if(fgets(buffer, size + 1, stream) != NULL) { // +1 cuz \n count as one
        char* end = strchr(buffer, '\n');
        if(end != NULL) {
            *end = '\0';
        }
        else {
            clearBuffer();
        }
    }
    else {
        clearBuffer();
    }
}


// -----------------------------------------------------------------------------
// 
// -----------------------------------------------------------------------------
char promptMessageType() {
    std::cout << "Message Type (A number): ";
    char buffer[4];
    readFromStream(stdin, buffer, 3);
    int coco = atoi(buffer);
    return (coco >= 0 && coco <= 255) ? coco : 0;
}

void promptMessageRawContent(std::stringstream& buffer) {
    std::cout << "Message content: " << std::endl;
    std::string inputStr;
    std::getline(std::cin, inputStr);
    msgpack::pack(buffer, inputStr);
    msgpack::pack(buffer, true);
}


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
int main(int argc, char** argv) {
    bool isRunning = true;
    elephant::init();
    std::cout << "----- Start Message Spawner Debugger -----" << std::endl;
    std::cout << "Enter 'stop' in message content to quit" << std::endl;
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to server..." << std::endl;
    socket.connect ("tcp://localhost:5555");

    while(isRunning) {
        std::cout << " ----- Send new message ----- " << std::endl;

        char msgType = promptMessageType();
        std::stringstream msgContent;
        promptMessageRawContent(msgContent);
        msgContent.seekg(0, std::ios::end);
        size_t contentSize = msgContent.tellg();
        msgContent.seekg(0);

        zmq::message_t request(contentSize + 1);
        std::cout << "content: " << msgContent.str().c_str() << std::endl;
        std::cout << "size: " << contentSize << std::endl;

        memcpy(request.data(), &msgType, 1);
        memcpy(request.data()+1, msgContent.str().c_str(), contentSize); 

        socket.send(request);

        zmq::message_t reply;
        socket.recv(&reply);
        std::cout << "Receive acknowledgement" << std::endl;

        std::cout << std::endl;
    }

    std::cout << "----- End Message Spawner Debugger -----" << std::endl;
    return 0;
}
