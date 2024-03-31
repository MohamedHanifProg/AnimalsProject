#include "Student.hpp"

Student::Student(const std::string& _fullName, int _age, const std::string& _major)
    : fullName(_fullName), age(_age), major(_major) {}

std::string Student::getName() const {
    return fullName;
}

int Student::getAge() const {
    return age;
}

std::string Student::getMajor() const {
    return major;
}

std::string Student::toString() const {
    return "Student \"" + fullName + ", " + std::to_string(age) + ", " + major + "\"";
}

void Student::setName(const std::string& _fullName) {
    fullName = _fullName;
}

void Student::setAge(int _age) {
    age = _age;
}

void Student::setMajor(const std::string& _major) {
    major = _major;
}
