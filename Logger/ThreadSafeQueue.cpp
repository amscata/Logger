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


#include "ThreadSafeQueue.h"

#include <QMutex>
#include <QMutexLocker>

#include <queue>

namespace logger
{

struct ThreadSafeQueueBase::Impl
{
    std::queue<void*> m_queue;
    QMutex m_mutex;

    Impl()
    {

    }

    ~Impl()
    {

    }

    void push(void* value)
    {
        QMutexLocker locker(&m_mutex);
        m_queue.push(value);
    }

    void* pop()
    {
        QMutexLocker locker(&m_mutex);

        if(m_queue.empty())
        {
            return nullptr;
        }

        void* retVal = m_queue.front();
        m_queue.pop();

        return retVal;
    }
};

ThreadSafeQueueBase::ThreadSafeQueueBase() : m_impl(new Impl)
{

}

ThreadSafeQueueBase::~ThreadSafeQueueBase()
{
    delete m_impl;
    m_impl = nullptr;
}

void ThreadSafeQueueBase::push(void* value)
{
    m_impl->push(value);
}

void* ThreadSafeQueueBase::pop()
{
    return m_impl->pop();
}

}
