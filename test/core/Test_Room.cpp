#include "collabserver/core/Room.h"

#include <gtest/gtest.h>

namespace collab {

/** Simple Mock Connector for Debug. */
class MockConnector : public Broadcaster {
    public:
        void sendRoomUserOperation(const OperationInfo& op, const int roomID,
                                   const int userID) {
        }
};
static MockConnector mockConnector;


// -----------------------------------------------------------------------------
// Room()
// -----------------------------------------------------------------------------
TEST(Room, roomConstructorTest) {
    Room r(DataFactory::SIMPLE_GRAPH, mockConnector);
}


// -----------------------------------------------------------------------------
// Room()
// -----------------------------------------------------------------------------

TEST(Room, addUserTest) {

}


} // End namespace


