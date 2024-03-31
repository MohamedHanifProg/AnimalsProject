#ifndef COURSE_HPP
#define COURSE_HPP

#include "Instructor.hpp"
#include <string>

class Course {
public:
    Course() = default;
    Course(const std::string& _title, const std::string& _code, Instructor _instructor);
    
    std::string toString() const;

    // Getters
    std::string getTitle() const { return title; }
    std::string getCode() const { return code; }
    std::string getInstructorName() const { return instructor.getName(); } // Assuming Instructor has getName()

    // Setters
    void setTitle(const std::string& _title) { title = _title; }
    void setCode(const std::string& _code) { code = _code; }
    void setInstructor(const Instructor& _instructor) { instructor = _instructor; }

private:
    std::string title;
    std::string code;
    Instructor instructor;
};

#endif // COURSE_HPP
