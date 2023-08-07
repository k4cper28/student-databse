#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
EXPECT_STRNE("hello", "world");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
};

TEST(CheckStructure, CanAddStudentToDb_req1_Req2) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    };

    Database db;
    db.add(adam);


};