#ifndef LOGGER_CONSOLELOG_H
#define LOGGER_CONSOLELOG_H

#include "ILoggingSource.h"
#include <iostream>

namespace logger
{

class ConsoleLog : public ILoggingSource
{
public:
    ConsoleLog()
    {
    }

    ~ConsoleLog()
    {
    }

    // ILoggingSource interface
public:
    inline void log(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }

private:
    ConsoleLog(const ConsoleLog&);
    ConsoleLog& operator= (const ConsoleLog&);
};

}

#endif // LOGGER_CONSOLELOG_H
