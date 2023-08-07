#pragma once
#include <string>

enum class Gender{
    Male,
    Female
};

class Student{
public:
    Student(std::string name,
            std::string lastname,
            std::string address,
            int index,
            std::string pesel,
            Gender gender);
private:
    Gender g;
};