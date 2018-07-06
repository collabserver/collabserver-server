#include "collabserver/core/Room.h"

#include <gtest/gtest.h>

#include "collabserver/core/Broadcaster.h"
#include "collabserver/core/DataFactory.h"

namespace collab {


/** Simple Mock Connector for Debug. */
class MockConnector : public Broadcaster {
    public:
        void sendOperation(const OperationInfo& op, const int dest) override {}
};
static MockConnector mockConnector;


// TODO


} // End namespace


