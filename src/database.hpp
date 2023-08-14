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
    std::string sortByPesel();
    void swap(Student &s1, Student &s2);
    bool whichPeselHigher (Student s, Student s1) const;
private:
    std::vector<Student> students_;

};