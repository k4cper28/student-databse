#include "database.hpp"
#include <iostream>

void Database::add (const Student &s)
{
    students_.push_back(s);
}

void Database::display() const {
    std::cout << show();
}

std::string Database::show() const {

    std::string result = "";
    for(auto && student : students_){
        result += student.show();
    }
    return result;
}

std::string Database::findByLastname(std::string searchedLastname) const {

    std::string result = "";

    for(auto && student : students_){
        if(searchedLastname == student.getLastname())
            result += student.show();
    }

    return result;
}
std::string Database::findByPesel(std::string searchedPesel) const{

    std::string result = "";

    for(auto && student : students_){
        if(searchedPesel == student.getPesel())
            result += student.show();
    }

    return result;
}
