#include "collabserver/proxy.h"
#include "ServerProxy.h"
#include "ViewService.h"

using namespace collab;


Proxy::~Proxy() {
    ServerProxy::getInstance().disconnect();
}

bool Proxy::connect(const char* ip, const int port, const float timeout) {
    return ServerProxy::getInstance().connect(ip, port, timeout);
}

bool Proxy::disconnect() {
    return ServerProxy::getInstance().disconnect();
}

void Proxy::loadView(const int viewID) {
    // TODO To update
    ViewService::loadById(viewID);
}
