#ifndef LOGGER_ILOGGINGSOURCE_H
#define LOGGER_ILOGGINGSOURCE_H

#include <string>

namespace logger
{

class ILoggingSource
{
public:
    virtual ~ILoggingSource(){}

    virtual void log(const std::string&) = 0;
};

}

#endif // LOGGER_ILOGGINGSOURCE_H
