#pragma once

#include "ServerProxy.h"

#include <cassert>
#include <elephantlogger/log.h>


namespace collab {


/**
 * Manage all services about Views.
 *
 * \author  Constantin
 * \date    Feb 2018
 * \since   0.1.0
 */
class ViewService {
    private:
        ViewService() = delete;
        ~ViewService() = delete;

    public:

        /**
         * Load a view with the given ID.
         */
        static void loadById(const int viewID) {
            LOG_DEBUG(0, "Proxy sends 'VIEW_LOAD_BY_ID' message");
            if(ServerProxy::getInstance().isConnected()) {
                // TODO
                //ServerProxy::getInstance().sendMessage(nullptr);
            }
        }
};


} // End namespace
