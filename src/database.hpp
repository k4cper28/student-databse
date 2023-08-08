#pragma once
#include "student.hpp"
#include <vector>


class Database {
public:
    void add(const Student &s);
    void display() const;
    std::string show() const;
    std::string findByLastname(std::string SearchedLastname) const;

private:
    std::vector<Student> students_;
};