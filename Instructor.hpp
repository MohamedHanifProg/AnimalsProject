#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <string>

class Instructor {
public:
    // Existing constructor declaration
    Instructor(){

    };
    Instructor(const std::string& _name);

    // Getter
    std::string getName() const;

    // Setter
    void setName(const std::string& _name);

private:
    std::string name;
};

#endif