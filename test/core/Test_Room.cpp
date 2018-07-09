#include "collabserver/core/Room.h"

#include <gtest/gtest.h>

#include "collabserver/core/Broadcaster.h"
#include "collabserver/core/DataFactory.h"

namespace collab {


/** Simple Mock Connector for Debug. */
class MockConnector : public Broadcaster {
    public:
        void sendOperationToUser(const OperationInfo& op,
                                 const int dest) override {
        }
        void sendOperationToStorage(const OperationInfo& op,
                                    const int dest) override {
        }
};
static MockConnector mockConnector;


// TODO


} // End namespace


