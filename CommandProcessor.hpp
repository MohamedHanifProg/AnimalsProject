#ifndef COMMANDPROCESSOR_HPP
#define COMMANDPROCESSOR_HPP

#include "StudentDB.hpp"
#include "CourseDB.hpp"
#include <string>
#include <memory>

class commandProcessor {
private:
    StudentDB* studentDb;
    CourseDB* courseDb;

public:
    commandProcessor(StudentDB* sDb, CourseDB* cDb)
        : studentDb(sDb), courseDb(cDb) {}

    std::string processCommand(const std::string& command);
};


#endif // COMMANDPROCESSOR_HPP
