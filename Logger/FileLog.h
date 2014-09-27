/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Amith Chinthaka
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


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
