#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
    // Constructor with three parameters
    Student():age(0){
        
    }
    Student(const std::string& _fullName, int _age, const std::string& _major);

    // Getters
    std::string getName() const; // Returns the full name
    int getAge() const;
    std::string getMajor() const;
    std::string toString() const;

    // Setters
    void setName(const std::string& _fullName);
    void setAge(int _age);
    void setMajor(const std::string& _major);

private:
    std::string fullName;
    int age;
    std::string major;
};

#endif
