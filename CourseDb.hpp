#ifndef COURSEDB_HPP
#define COURSEDB_HPP

#include "Genricdb.hpp"
#include "Course.hpp"
#include <string>
#include <vector>

class CourseDB : public GenericDatabase<Course> {
public:
    void insert(const Course& record) override;
    void deleteRecord(const std::string& recordId) override;
    void update(const Course& record) override;
    std::vector<Course> query(const std::string& field, const std::string& value) override;
};

#endif // COURSEDB_HPP
