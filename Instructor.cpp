#include "Instructor.hpp"

// Constructor
Instructor::Instructor(const std::string& _name)
    : name(_name) {}

// Getter
std::string Instructor::getName() const {
    return name;
}

// Setter
void Instructor::setName(const std::string& _name) {
    name = _name;
}
