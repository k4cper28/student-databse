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

std::string Database::sortByPesel() {

    for( int i = 0; i < students_.size(); i++ )
    {
        for( int j = 0; j < students_.size() - 1; j++ )
        {
            if(whichPeselHigher(students_[j],students_[j+1]) )
                swap(students_[j] , students_[j+1]);
        }
    }

    std::string result = "";
    for(auto && student : students_){
        result += student.show();
    }
    return result;
}

void Database::swap(Student &s1, Student &s2) {
        std::swap(s1,s2);
}

bool Database::whichPeselHigher(Student s, Student s1) const {

    if(s.getPesel() < s1.getPesel())
        return true;
    else
        return false;
}
