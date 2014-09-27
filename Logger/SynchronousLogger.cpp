#include "SynchronousLogger.h"
#include "LoggerUtil.h"


namespace logger
{

SynchronousLogger::SynchronousLogger(ILoggingSource* logSrc) :
    m_log(logSrc)
{

}

SynchronousLogger::~SynchronousLogger()
{

}

void SynchronousLogger::log(const LogMessage& logMsg, unsigned int threadId)
{
    m_log->log(LoggerUtil::getLogMessage(logMsg));
}

}
