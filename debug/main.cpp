#include <logger/ElephantLogger.h>

#include <zmq.hpp>
#include <iostream>
#include <string>

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>


#define MSG_BUFF_SIZE 512

void clearBuffer() {
    int tmp;
    while((tmp = getchar()) != EOF && tmp != '\n');
}

void stdinInput(char* buffer, const int size) {
    if(fgets(buffer, size-1, stdin) != NULL) {
        char *end = strchr(buffer, '\n');
        if(end != NULL) {
            *end = '\0';
        }
        else {
            buffer[size-1] = '\0';
            clearBuffer();
        }
    }
    else {
        clearBuffer();
    }
}

int main(int argc, char** argv) {
    bool isRunning = true;
    ElephantLogger::init();
    std::cout << "----- Start Message Spawner Debugger -----" << std::endl;

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to server..." << std::endl;
    socket.connect ("tcp://localhost:5555");

    char msg[MSG_BUFF_SIZE];
    while(isRunning) {
        std::cout << "Message to send: ";
        bzero(msg, MSG_BUFF_SIZE);
        stdinInput(msg, MSG_BUFF_SIZE);

        if(memcmp(msg, "stop", 4) == 0) {
            std::cout << "See you" << std::endl;
            isRunning = false; // But useless atm
            break;
        }

        size_t msgSize = strlen(msg);
        zmq::message_t request(msgSize);
        memcpy(request.data(), msg, msgSize);

        socket.send(request);

        zmq::message_t reply;
        socket.recv(&reply);
        std::cout << "Receive acknowledgement" << std::endl;
    }

    std::cout << "----- End Message Spawner Debugger -----" << std::endl;
    return 0;
}
