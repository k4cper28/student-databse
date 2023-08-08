#include "student.hpp"

Student::Student(
         std::string name,
            std::string lastname,
            std::string address,
            int index,
            std::string pesel,
            Gender gender)
        : name_(name)
        , lastName_(lastname)
        ,address_(address)
        , index_(index)
        , pesel_(pesel)
        , gender_(gender)
        {}

std::string Student::show() const {

    return name_ + " " + lastName_ + "; " + address_ + "; "
    + std::to_string(index_) + "; " + pesel_ + "; " + "Male";
}