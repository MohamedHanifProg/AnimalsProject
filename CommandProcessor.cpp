#include "CommandProcessor.hpp"
#include "OutputManager.hpp"
#include <sstream>
#include <vector>

std::string commandProcessor::processCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string action, entityType;
    iss >> action >> entityType;
    std::string result;

    if (action == "INSERT") {
        if (entityType == "STUDENT") {
            std::string fullName, major;
            int age;
            iss.ignore(); // Ignore the space after "STUDENT"
            std::getline(iss >> std::ws, fullName, ',');
            iss >> age;
            iss.ignore(); // Ignore the space after the age
            std::getline(iss >> std::ws, major);
            Student student(fullName, age, major);
            studentDb->insert(student);
            result = "Success: Student \"" + student.toString() + "\" added.";
        } else if (entityType == "COURSE") {
            std::string title, code, instructor;
            std::getline(iss >> std::ws, title, ',');
            std::getline(iss >> std::ws, code, ',');
            std::getline(iss >> std::ws, instructor);
            Course course(title, code, instructor);
            courseDb->insert(course);
            result = "Success: Course \"" + course.toString() + "\" added.";
        } else {
            result = "Error: Invalid entity type.";
        }
    } else if (action == "QUERY") {
        std::string queryField, queryValue;
        std::getline(iss >> std::ws, queryField, '=');
        std::getline(iss >> std::ws, queryValue);
        
        if (entityType == "STUDENT") {
            std::vector<Student> students = studentDb->query(queryField, queryValue);
            if (!students.empty()) {
                result = "Query Result: " + students.front().toString();
            } else {
                result = "Query Result: No Student found matching criteria.";
            }
        } else if (entityType == "COURSE") {
            std::vector<Course> courses = courseDb->query(queryField, queryValue);
            if (!courses.empty()) {
                result = "Query Result: " + courses.front().toString();
            } else {
                result = "Query Result: No Course found matching criteria.";
            }
        } else {
            result = "Error: Invalid entity type.";
        }
    } else if (action == "UPDATE") {
        if (entityType == "STUDENT") {
            std::string fullName, newMajor;
            int newAge;
            iss.ignore(); // Ignore the space after "UPDATE"
            std::getline(iss >> std::ws, fullName, ',');
            iss >> newAge;
            iss.ignore(); // Ignore the space after the new age
            std::getline(iss >> std::ws, newMajor);
            Student updatedStudent(fullName, newAge, newMajor);
            studentDb->update(updatedStudent);
            result = "Success: Student \"" + updatedStudent.toString() + "\" updated.";
        } else {
            result = "Error: Unsupported update operation.";
        }
    } else if (action == "DELETE") {
        if (entityType == "STUDENT") {
            std::string fullName;
            iss.ignore(); // Ignore the space after "DELETE"
            std::getline(iss >> std::ws, fullName);
            studentDb->deleteRecord(fullName);
            result = "Success: Student \"" + fullName + "\" deleted.";
        } else if (entityType == "COURSE") {
            std::string code;
            iss.ignore(); // Ignore the space after "DELETE"
            std::getline(iss >> std::ws, code);
            courseDb->deleteRecord(code);
            result = "Success: Course \"" + code + "\" deleted.";
        } else {
            result = "Error: Invalid entity type.";
        }
    } else {
        result = "Error: Invalid command format.";
    }

    // Remove extra quotation marks and adjust formatting to match desired output
    size_t pos;
    while ((pos = result.find('\"')) != std::string::npos) {
        result.erase(pos, 1);
    }

    return result;
}
