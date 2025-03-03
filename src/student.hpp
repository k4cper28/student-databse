#pragma once
#include <string>

enum class Gender{
    Male,
    Female
};

constexpr const char* genderToString(Gender e) throw(){
    switch (e) {
        case Gender::Male:   return "Male";
        case Gender::Female: return "Female";
        default:    return "Unknown";
    }
}

class Student{
public:
    Student(std::string name,
            std::string lastname,
            std::string address,
            int index,
            std::string pesel,
            Gender gender);
    std::string show() const;
    std::string getLastname() const;
    std::string getPesel() const;
    int getIndex() const;
    void swap(Student &s1, Student &s2);

private:
    std::string name_;
    std::string lastName_;
    std::string address_;
    int index_;
    std::string pesel_;
    Gender gender_;

};