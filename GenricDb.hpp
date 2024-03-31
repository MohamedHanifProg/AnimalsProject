#ifndef GENERICDATABASE_HPP
#define GENERICDATABASE_HPP

#include <map>
#include <string>
#include <vector>

template<typename T>
class GenericDatabase {
protected:
    std::map<std::string, T> records; // Assume each record can be uniquely identified by a std::string key

public:
    virtual void insert(const T& record) = 0;
    virtual void deleteRecord(const std::string& recordId) = 0;
    virtual void update(const T& record) = 0;
    virtual std::vector<T> query(const std::string& field, const std::string& value) = 0;
};

#endif // GENERICDATABASE_HPP
