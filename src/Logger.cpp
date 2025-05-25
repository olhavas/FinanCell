
#include "Logger.h"

Logger::Logger(const std::string &filename)
{

    std::string path = "../log";

    if (!path.empty() && !fs::exists(path)) 
    {
            fs::create_directories(path);
    }
    path = path+'/'+filename;
    logFile.open(path, std::ios::app);
    if (!logFile.is_open())
    {
        std::cerr << "Error opening log file." << std::endl;
    }
}
std::string Logger::levelToString(LogLevel level)
{
    switch (level)
    {
    case DEBUG:
        return "DEBUG";
    case INFO:
        return "INFO";
    case WARNING:
        return "WARNING";
    case ERROR:
        return "ERROR";
    case CRITICAL:
        return "CRITICAL";
    default:
        return "UNKNOWN";
    }
}

Logger::~Logger() 
{
    logFile.close();
    delete inst;
    inst = nullptr;
}

void Logger::log(LogLevel level, const std::string &message)
{
    // Get current timestamp
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S", timeinfo);

    // Create log entry
    std::ostringstream logEntry;
    logEntry << "[" << timestamp << "] "
             << levelToString(level) << " : " << message
             << std::endl;


    // Output to log file
    if (logFile.is_open())
    {
        logFile << logEntry.str();
        logFile
            .flush(); // Ensure immediate write to file
    }
}
Logger* Logger::inst= nullptr;;

Logger* Logger::instance()
{

    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S", timeinfo);

    std::string str(timestamp);

    if(inst==nullptr){
        inst = new Logger("logfile"+str+".log");
    }

    return inst;
}