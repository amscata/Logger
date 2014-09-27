#ifndef LOGGER_ASYNCHRONOUSLOGGER_H
#define LOGGER_ASYNCHRONOUSLOGGER_H

#include "ILogger.h"
#include "ILoggingSource.h"

namespace logger
{

class AsynchronousLogger : public ILogger
{
public:
    AsynchronousLogger(ILoggingSource& logSrc);

    ~AsynchronousLogger();

    // ILogger interface
public:
    void log(const LogMessage& logMsg, unsigned int threadId = 0);

private:
    AsynchronousLogger(const AsynchronousLogger&);
    AsynchronousLogger& operator= (const AsynchronousLogger&);

    struct Impl;
    Impl* m_impl;
};

}

#endif // LOGGER_ASYNCHRONOUSLOGGER_H
