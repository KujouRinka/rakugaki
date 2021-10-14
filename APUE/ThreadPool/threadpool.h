//
// Created by kujou on 10/13/2021.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_THREADPOOL_H
#define DATA_STRUCTURES_AND_ALGORITHM_THREADPOOL_H

#include <mutex>
#include <pthread.h>
#include <queue>
#include "locker.h"

class Runner {
public:
    void run() = 0;
};

class ThreadPool {
public:
    ThreadPool(int thread_num = 12, int max_wait_task = 500);
    ~ThreadPool();

    bool appendTask(Runner *runner);
    static void *worker(void *arg);
    void run();

private:
    int m_thread_num;
    int m_max_wait_task;
    std::queue<Runner *> m_wait_queue;
    pthread_t *m_thread;
    std::mutex m_mutex;
    Sem m_sem;
    bool m_stop;
};

ThreadPool::ThreadPool(int thread_num, int max_wait_task)
        : m_thread_num(thread_num), m_max_wait_task(max_wait_task), m_stop(false) {
    if (m_thread_num <= 0 || m_max_wait_task <= 0)
        throw std::runtime_error();
    m_thread = new pthread_t[m_thread_num];
    pthread_attr_t attr;
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for (int i = 0; i < m_thread_num; ++i) {
        cout << "creating thread " << i << endl;
        if (pthread_create(m_thread + i, &attr, worker, this) != 0) {
            delete[]m_thread;
            throw std::runtime_error();
        }
    }
    delete[]m_thread;
    pthread_attr_destroy(&attr);
}

ThreadPool::~ThreadPool() {
    m_stop = true;
}

bool ThreadPool::appendTask(Runner *runner) {
    m_mutex.lock();
    if (m_wait_queue.size() == m_max_wait_task) {
        m_mutex.unlock();
        return false;
    }
    m_wait_queue.push(runner);
    m_mutex.unlock();
    m_sem.post();
    return true;
}

static void *ThreadPool::worker(void *arg) {
    auto pool = static_cast<ThreadPool *>(arg);
    pool->run();
    return pool;
}

void ThreadPool::run() {
    while (!m_stop) {
        m_sem.wait();
        m_mutex.lock();
        if (m_wait_queue.empty()) {
            m_mutex.unlock();
            continue;
        }
        Runner *runner = m_wait_queue.front();
        m_wait_queue.pop();
        m_mutex.unlock();
        if (runner == nullptr)
            continue;
        runner->run();
    }
}

#endif //DATA_STRUCTURES_AND_ALGORITHM_THREADPOOL_H
