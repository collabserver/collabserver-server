#include <elephant.h>

#include <zmq.hpp>
#include <iostream>
#include <stdio.h>  // getchar, fgets
#include <string.h> // strchr

#include <unistd.h>


#define MSG_BUFF_SIZE 512

void clearBuffer() {
    int tmp;
    while((tmp = getchar()) != EOF && tmp != '\n');
}

// Buffer's size must be at least size + 2
void stdinInput(char* buffer, const int size) {
    if(fgets(buffer, size+1, stdin) != NULL) {
        char *end = strchr(buffer, '\n');
        if(end != NULL) {
            *end = '\0';
        }
        else {
            buffer[size] = '\0';
            clearBuffer();
        }
    }
    else {
        clearBuffer();
    }
}


int main(int argc, char** argv) {
    bool isRunning = true;
    elephant::init();
    std::cout << "----- Start Message Spawner Debugger -----" << std::endl;

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to server..." << std::endl;
    socket.connect ("tcp://localhost:5555");

    char msg[MSG_BUFF_SIZE];
    while(isRunning) {
        bzero(msg, MSG_BUFF_SIZE);

        std::cout << "Send a message" << std::endl;
        std::cout << "Type (A number): ";

        stdinInput(msg, 2); // Max type is 99
        int coco = atoi(msg);
        char c = (char)coco;
        sprintf(msg, "%c", c);

        std::cout << "Content: ";
        stdinInput((msg + 1), MSG_BUFF_SIZE-3); //-3 cuz type byte + 2 for stdinInput doc

        if(memcmp((msg + 1), "stop", 4) == 0) {
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
