#include <gtest/gtest.h>

#include "collabserver/core/Broadcaster.h"
#include "collabserver/core/CollabServer.h"

namespace collabserver {

class MockBroadcaster : public Broadcaster {
   public:
    void sendOperationToUser(const OperationInfo& op, const unsigned int userID) override {}

    void broadcastOperationToRoom(const OperationInfo& op, const unsigned int roomID) override {}
};
static MockBroadcaster local_mockBroadcaster;

TEST(CollabServer, constructor) { CollabServer server = CollabServer(local_mockBroadcaster); }

// -----------------------------------------------------------------------------
// CreateNewUser
// -----------------------------------------------------------------------------

TEST(CollabServer, createNewUser_nbUsersValue) {
    CollabServer server = CollabServer(local_mockBroadcaster);
    ASSERT_EQ(server.getNbUsers(), 0);

    server.createNewUser();
    server.createNewUser();
    server.createNewUser();
    server.createNewUser();
    ASSERT_EQ(server.getNbUsers(), 4);

    server.createNewUser();
    server.createNewUser();
    ASSERT_EQ(server.getNbUsers(), 6);
}

TEST(CollabServer, createNewUser_returnType) {
    CollabServer server = CollabServer(local_mockBroadcaster);
    ASSERT_EQ(server.getNbUsers(), 0);

    const User* u1 = server.createNewUser();
    const User* u2 = server.createNewUser();
    const User* u3 = server.createNewUser();

    ASSERT_TRUE(u1 != nullptr && u2 != nullptr && u3 != nullptr);
    ASSERT_TRUE(u1->getUserID() != u2->getUserID());
    ASSERT_TRUE(u2->getUserID() != u3->getUserID());
}

// -----------------------------------------------------------------------------
// DeleteUser
// -----------------------------------------------------------------------------

TEST(CollabServer, deleteUser_addDell) {
    CollabServer server = CollabServer(local_mockBroadcaster);
    ASSERT_EQ(server.getNbUsers(), 0);

    const User* u1 = server.createNewUser();
    const User* u2 = server.createNewUser();
    unsigned int u1_id = u1->getUserID();
    unsigned int u2_id = u2->getUserID();
    ASSERT_EQ(server.getNbUsers(), 2);

    server.deleteUser(u1_id);
    ASSERT_EQ(server.getNbUsers(), 1);

    server.deleteUser(u2_id);
    ASSERT_EQ(server.getNbUsers(), 0);
}

TEST(CollabServer, deleteUser_duplicateAndInvalidID) {
    CollabServer server = CollabServer(local_mockBroadcaster);
    ASSERT_EQ(server.getNbUsers(), 0);

    const User* u1 = server.createNewUser();
    const User* u2 = server.createNewUser();
    unsigned int u1_id = u1->getUserID();
    unsigned int u2_id = u2->getUserID();
    ASSERT_EQ(server.getNbUsers(), 2);

    ASSERT_FALSE(server.deleteUser(-32));
    ASSERT_FALSE(server.deleteUser(-42));
    ASSERT_FALSE(server.deleteUser(-64));
    ASSERT_EQ(server.getNbUsers(), 2);

    ASSERT_TRUE(server.deleteUser(u2_id));
    ASSERT_FALSE(server.deleteUser(u2_id));
    ASSERT_FALSE(server.deleteUser(u2_id));
    ASSERT_FALSE(server.deleteUser(u2_id));
    ASSERT_EQ(server.getNbUsers(), 1);

    ASSERT_TRUE(server.deleteUser(u1_id));
    ASSERT_FALSE(server.deleteUser(u1_id));
    ASSERT_FALSE(server.deleteUser(u1_id));
    ASSERT_EQ(server.getNbUsers(), 0);
}

// -----------------------------------------------------------------------------
// isUserInRoom
// -----------------------------------------------------------------------------

TEST(CollabServer, isUserInRoom) {
    CollabServer server = CollabServer(local_mockBroadcaster);
    const User* u1 = server.createNewUser();
    ASSERT_TRUE(u1 != nullptr);
    ASSERT_EQ(server.getNbUsers(), 1);
    ASSERT_FALSE(server.isUserInRoom(u1->getUserID(), 1));
    ASSERT_FALSE(server.isUserInRoom(u1->getUserID(), 2));
    ASSERT_FALSE(server.isUserInRoom(u1->getUserID(), 3));

    const Room* r1 = server.createNewRoom();
    ASSERT_TRUE(r1 != nullptr);
    ASSERT_TRUE(server.userJoinRoom(u1->getUserID(), r1->getRoomID()));
    ASSERT_TRUE(server.isUserInRoom(u1->getUserID(), r1->getRoomID()));
}

}  // namespace collabserver
