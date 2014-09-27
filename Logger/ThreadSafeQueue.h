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


#ifndef LOGGER_THREADSAFEQUEUE_H
#define LOGGER_THREADSAFEQUEUE_H

namespace logger
{

class ThreadSafeQueueBase
{
public:
    ThreadSafeQueueBase();

    ~ThreadSafeQueueBase();

    void push(void* value);

    void* pop();

private:
    ThreadSafeQueueBase(const ThreadSafeQueueBase&);
    ThreadSafeQueueBase& operator= (const ThreadSafeQueueBase&);

    struct Impl;
    Impl* m_impl;
};

template<typename T>
class ThreadSafeQueue
{
public:
    ThreadSafeQueue()
    {

    }

    ~ThreadSafeQueue()
    {

    }

    void push(T* value)
    {
        m_baseQueue.push(value);
    }

    T* pop()
    {
        return static_cast<T*>(m_baseQueue.pop());
    }

private:
    ThreadSafeQueue(const ThreadSafeQueue&);
    ThreadSafeQueue& operator= (const ThreadSafeQueue&);

    ThreadSafeQueueBase m_baseQueue;
};

}

#endif // LOGGER_THREADSAFEQUEUE_H
