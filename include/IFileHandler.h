#ifndef IFileHandler_h
#define IFileHandler_h

#include <fstream>
#include <filesystem>
#include <string>
#include <sstream> 

#include "Status.h"

class IFileHandler {
public:
    virtual IOStatus saveToFile(const std::vector<Expense>&, const std::string&) = 0;
    virtual IOStatus loadFromFile(std::vector<Expense>&, const std::string&) = 0;
    virtual ~IFileHandler() = default;
};

#endif