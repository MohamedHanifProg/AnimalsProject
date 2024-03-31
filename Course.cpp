#include "Course.hpp"

Course::Course(const std::string& _title, const std::string& _code, Instructor _instructor)
    : title(_title), code(_code), instructor(_instructor) {}

std::string Course::toString() const {
    return "Course Title: " + title + ", Course Code: " + code + ", Instructor: " + getInstructorName();
}

