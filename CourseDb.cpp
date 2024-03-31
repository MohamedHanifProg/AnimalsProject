#include "CourseDB.hpp"

void CourseDB::insert(const Course& course) {
    records[course.getCode()] = course;
}

void CourseDB::deleteRecord(const std::string& recordId) {
    records.erase(recordId);
}

void CourseDB::update(const Course& course) {
    records[course.getCode()] = course;
}


std::vector<Course> CourseDB::query(const std::string& field, const std::string& value) {
    std::vector<Course> result;
    for (const auto& record : records) {
        if (field == "title" && record.second.getTitle() == value) {
            result.push_back(record.second);
        } else if (field == "code" && record.second.getCode() == value) {
            result.push_back(record.second);
        }  else if (field == "instructor" && record.second.getInstructorName() == value) 
 {
            result.push_back(record.second);
        }
        
    }
    return result;
}
