#ifndef LOGGER_SYNCHRONOUSLOGGER_H
#define LOGGER_SYNCHRONOUSLOGGER_H

#include "ILogger.h"
#include "ILoggingSource.h"

namespace logger
{

class SynchronousLogger : public ILogger
{
public:
    SynchronousLogger(ILoggingSource* logSrc);

    ~SynchronousLogger();

    // ILogger interface
public:
    void log(const LogMessage& logMsg, unsigned int threadId = 0);

private:
    SynchronousLogger(const SynchronousLogger&);
    SynchronousLogger& operator= (const SynchronousLogger&);

    ILoggingSource* m_log;
};

}

#endif // LOGGER_SYNCHRONOUSLOGGER_H
