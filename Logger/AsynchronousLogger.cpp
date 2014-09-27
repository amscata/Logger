#include "AsynchronousLogger.h"


namespace logger
{

struct AsynchronousLogger::Impl
{
    Impl(ILoggingSource& logSrc)
    {

    }

    ~Impl()
    {

    }

    void log(const LogMessage& logMsg, unsigned int threadId = 0)
    {
        throw std::exception("This controller path is not implemented");
    }
};

AsynchronousLogger::AsynchronousLogger(ILoggingSource& logSrc) :
    m_impl(new Impl(logSrc))
{

}

AsynchronousLogger::~AsynchronousLogger()
{
    delete m_impl;
    m_impl = nullptr;
}

void AsynchronousLogger::log(const LogMessage& logMsg, unsigned int threadId)
{
    m_impl->log(logMsg);
}

}
