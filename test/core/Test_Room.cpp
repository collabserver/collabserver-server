#include "collabserver/core/Room.h"

#include <gtest/gtest.h>

#include "collabserver/core/Connector.h"
#include "collabserver/core/DataFactory.h"

namespace collab {

/** Simple Mock Connector for Debug. */
class MockConnector : public Connector {
    public:
        void sendRoomUserOperation(const Operation& op, const int roomID,
                                   const int userID) {
        }
};
static MockConnector mockConnector;


// -----------------------------------------------------------------------------
// Room()
// -----------------------------------------------------------------------------
TEST(Room, roomConstructorTest) {
    Room r(DataAvailable::SIMPLE_GRAPH, mockConnector);
}


// -----------------------------------------------------------------------------
// Room()
// -----------------------------------------------------------------------------

TEST(Room, addUserTest) {

}


} // End namespace


