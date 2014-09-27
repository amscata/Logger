#ifndef LOGGER_FILELOG_H
#define LOGGER_FILELOG_H

#include "ILoggingSource.h"
#include <fstream>

namespace logger
{

class FileLog : public ILoggingSource
{
public:
    explicit FileLog(const std::string& file) :
        m_logFile(file, std::ios_base::app)
    {

    }

    ~FileLog()
    {
        m_logFile.close();
    }

    // ILoggingSource interface
public:
    inline void log(const std::string &msg)
    {
        m_logFile << msg;
        m_logFile.flush();
    }

private:
    FileLog(const FileLog&);
    FileLog& operator= (const FileLog&);

    std::ofstream m_logFile;
};

}

#endif // LOGGER_FILELOG_H
