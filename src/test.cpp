#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"
#include <string>

struct DatabaseTest : ::testing::Test {
    Database db;

    Student adam{
            "Adam",
            "Kowalski",
            "ul. Dobra 134, 00-200 Warszawa",
            123456,
            "11223344567",
            Gender::Male
    };

    Student karol{
            "Karol",
            "Nowak",
            "ul. Dobra 134, 00-200 Warszawa",
            123457,
            "76544332211",
            Gender::Male
    };

    Student klaudia{
            "Klaudia",
            "Boobek",
            "ul. Dobra 134, 00-200 Warszawa",
            123458,
            "96544332211",
            Gender::Female
    };
};


TEST_F(DatabaseTest, DisplayEmptyDb){
    auto content = db.show();

    auto expected ="";

    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDb){
    db.add(adam);

    auto content = db.show();
    auto expected ="Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; ";

    EXPECT_EQ(content, expected);

}

TEST_F(DatabaseTest, NoFindByLastname){
    db.add(adam);

    auto content = db.findByLastname("Nowak");
    std::string expected = "";

    EXPECT_EQ(content, expected);
}


TEST_F(DatabaseTest, FindByLastname){
    db.add(adam);

    auto content = db.findByLastname("Kowalski");
    std::string expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; ";

    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, NoFindByPesel){
    db.add(adam);

    auto content = db.findByPesel("11223344569");
    std::string expected = "";

    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, FindByPesel){
    db.add(adam);

    auto content = db.findByPesel("11223344567");
    std::string expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; ";

    EXPECT_EQ(content, expected);
}


TEST_F(DatabaseTest, SortByPeselHigh){
    db.add(adam);
    db.add(karol);
    db.add(klaudia);

    auto content = db.sortByPeselHigh();
    std::string expected = "Klaudia Boobek; ul. Dobra 134, 00-200 Warszawa; 123458; 96544332211; Female; "
                           "Karol Nowak; ul. Dobra 134, 00-200 Warszawa; 123457; 76544332211; Male; "
                           "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; ";

    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SortByPeselLow){
    db.add(klaudia);
    db.add(karol);
    db.add(adam);

    auto content = db.sortByPeselLow();
    std::string expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; "
                           "Karol Nowak; ul. Dobra 134, 00-200 Warszawa; 123457; 76544332211; Male; "
                           "Klaudia Boobek; ul. Dobra 134, 00-200 Warszawa; 123458; 96544332211; Female; ";

    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SortByLastnameHigh){
    db.add(adam);
    db.add(karol);
    db.add(klaudia);

    auto content = db.sortByLastnameHigh();
    std::string expected = "Karol Nowak; ul. Dobra 134, 00-200 Warszawa; 123457; 76544332211; Male; "
                           "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; "
                           "Klaudia Boobek; ul. Dobra 134, 00-200 Warszawa; 123458; 96544332211; Female; ";

    EXPECT_EQ(content, expected);
}


TEST_F(DatabaseTest, SortByLastnameLow){
    db.add(klaudia);
    db.add(karol);
    db.add(adam);

    auto content = db.sortByLastnameLow();
    std::string expected =  "Klaudia Boobek; ul. Dobra 134, 00-200 Warszawa; 123458; 96544332211; Female; "
                            "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male; "
                            "Karol Nowak; ul. Dobra 134, 00-200 Warszawa; 123457; 76544332211; Male; ";

    EXPECT_EQ(content, expected);
}