#include "OutputManager.hpp"
#include <fstream>
#include <iostream>

// Constructor implementation
OutputManager::OutputManager(const std::string& _filename) : filename(_filename) {}

// writeOutput implementation that uses the instance's filename
void OutputManager::writeOutput(const std::string& output) const {
    std::ofstream outFile(filename, std::ios::app); // Open in append mode
    if (outFile.is_open()) {
        outFile << output << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    outFile.close();
}
