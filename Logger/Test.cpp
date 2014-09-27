#include "ConsoleLog.h"
#include "SynchronousLogger.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace logger
{

void foo()
{
    ILoggingSource* logSrc = new ConsoleLog;
    ILogger* logger = new SynchronousLogger(logSrc);

    LogMessage msg;
    msg.infoType = INFO;
    msg.message = "hello";
    msg.module = "foo";
    msg.subject = "test";

    logger->log(msg);

    delete logSrc;
    logSrc = nullptr;
    delete logger;
    logger = nullptr;

    LONG counter = 0;
    InterlockedIncrement(&counter);
}

}
