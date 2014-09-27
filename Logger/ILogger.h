#ifndef LOGGER_ILOGGER_H
#define LOGGER_ILOGGER_H

#include <string>

namespace logger
{

enum InfoType
{
    INFO,
    ERROR
};

struct LogMessage
{
    InfoType infoType;
    std::string module;
    std::string subject;
    std::string message;
};

class ILogger
{
public:
    virtual ~ILogger() {}

    virtual void log(const LogMessage& logMsg, unsigned int threadId = 0) = 0;
};

}

#endif // LOGGER_ILOGGER_H
