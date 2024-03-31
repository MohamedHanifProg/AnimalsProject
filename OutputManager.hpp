#ifndef OUTPUTMANAGER_HPP
#define OUTPUTMANAGER_HPP

#include <string>

class OutputManager {
private:
    std::string filename;

public:
    // Constructor that accepts a filename for output
    OutputManager(const std::string& _filename);

    // Writes output to the file specified by the filename
    void writeOutput(const std::string& output) const;
};

#endif // OUTPUTMANAGER_HPP
