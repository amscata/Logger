#ifndef LOGGER_LOGGERUTIL_H
#define LOGGER_LOGGERUTIL_H

#include "ILogger.h"
#include <string>

namespace logger
{

class LoggerUtil
{
public:
    static const std::string getLogMessage(const LogMessage& logMsg);
};

}

#endif // LOGGER_LOGGERUTIL_H
