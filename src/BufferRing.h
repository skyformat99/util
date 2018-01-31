#ifndef BUFFERRING_H
#define BUFFERRING_H

#include <vector>

#include "Semaphore.h"

namespace Util {

template<class T>
class BufferRing
{
public:
    BufferRing(size_t size)
    {
        if (0 == m_size)
        {
            throw "BuffRing size can not be zero";
        }
        m_queue.reserve(size);
        m_wSem.post(size);
    }

    void push(const T& data)
    {
        m_wSem.wait();
        m_queue[m_wIndex++ % m_size] = data;
        m_rSem.post();
    }

    void pop(T& data)
    {
        m_rSem.wait();
        data = m_queue[m_rIndex++ % m_size];
        m_wSem.post();
    }

    bool tryPush(const T& data)
    {
        if (!m_wSem.tryWait())
        {
            return false;
        }
        m_queue[m_wIndex++ % m_size] = data;
        m_rSem.post();
        return true;
    }

    void tryPop(T& data)
    {
        if (!m_rSem.tryWait())
        {
            return false;
        }
        data = m_queue[m_rIndex++ % m_size];
        m_wSem.post();
        return true;
    }

private:
    Util::Semaphore m_rSem;
    Util::Semaphore m_wSem;
    std::vector<T> m_queue;
    size_t m_wIndex = 0;
    size_t m_rIndex = 0;
    size_t m_size = 0;
};

}

#endif // BUFFERRING_H
