#ifndef Logger_h
#define Logger_h

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

class Logger 
{
    private:
    std::ofstream logFile;
    static Logger* inst;
    std::string levelToString(LogLevel level);
    Logger(const std::string& filename);
    public:
    Logger(Logger &other) = delete;
    void operator=(const Logger &) = delete;
    ~Logger();
    void log(LogLevel level, const std::string& message);
    static Logger * instance();


};

#endif