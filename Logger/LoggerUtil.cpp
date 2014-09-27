#include "LoggerUtil.h"

namespace logger
{

const std::string LoggerUtil::getLogMessage(const LogMessage& logMsg)
{
    return logMsg.message;
}

}
