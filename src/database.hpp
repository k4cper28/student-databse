#pragma once
#include "student.hpp"
#include <vector>
#include <algorithm>


class Database {
public:
    void add(const Student &s);
    void display() const;
    std::string show() const;
    std::string findByLastname(std::string searchedLastname) const;
    std::string findByPesel(std::string searchedPesel) const;
    std::string sortByPeselHigh();
    std::string sortByPeselLow();
    std::string sortByLastnameHigh();
    std::string sortByLastnameLow();
    void swap(Student &s1, Student &s2);
    bool whichPeselHigher (Student &s, Student &s1) const;
    bool whichPeselLower (Student &s, Student &s1) const;
    bool whichLastnameHigher (Student &s, Student &s1) const;
    bool whichLastnameLower (Student &s, Student &s1) const;
    std::string delateByIndex(int index);
private:
    std::vector<Student> students_;

};