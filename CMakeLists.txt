cmake_minimum_required(VERSION 3.14)
project(database_student)

set(CMAKE_CXX_STANDARD 14)

add_executable(database_student src/main.cpp src/database.cpp src/student.cpp)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(database_student-ut src/test.cpp src/database.cpp src/student.cpp)
target_link_libraries(database_student-ut GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(database_student-ut)