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
