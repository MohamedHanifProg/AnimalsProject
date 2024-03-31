#ifndef STUDENTDB_HPP
#define STUDENTDB_HPP

#include "Genricdb.hpp"
#include "Student.hpp"
#include <string>
#include <vector>

class StudentDB : public GenericDatabase<Student> {
public:
    void insert(const Student& record) override;
    void deleteRecord(const std::string& recordId) override;
    void update(const Student& record) override;
    std::vector<Student> query(const std::string& field, const std::string& value) override;
};

#endif // STUDENTDB_HPP
