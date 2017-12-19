#pragma once

#include <string>


namespace collab {


/**
 * C++ proxy.
 *
 * \author  Constantin
 * \date    Dec 2017
 * \since   0.1.0
 */
class ServerProxy {
    private:
        std::string m_ip    = "localhost";
        int m_port          = 0;
        bool m_isRunning    = false;

    public:
        ServerProxy(const std::string ip, const int port);
        ~ServerProxy();

    public:
        void startup();
        void shutdown();

    public:
        void createElt(const int id, const std::string & content);
        void readElt(const int id, const std::string & content);
        void updateElt(const int id, const std::string & content);
        void deleteElt(const int id);
};


} // End namespace
