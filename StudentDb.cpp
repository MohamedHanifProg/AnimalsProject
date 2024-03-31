#include "StudentDB.hpp"

void StudentDB::insert(const Student& student) {
    records[student.getName()] = student;
}

void StudentDB::deleteRecord(const std::string& recordId) {
    records.erase(recordId);
}

void StudentDB::update(const Student& student) {
    records[student.getName()] = student;
}

std::vector<Student> StudentDB::query(const std::string& field, const std::string& value) {
    std::vector<Student> result;
    for (const auto& record : records) {
        if (field == "name" && record.second.getName() == value) {
            result.push_back(record.second);
        } else if (field == "age" && std::to_string(record.second.getAge()) == value) {
            result.push_back(record.second);
        } else if (field == "major" && record.second.getMajor() == value) {
            result.push_back(record.second);
        }
       
    }
    return result;
}
