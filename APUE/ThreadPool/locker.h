//
// Created by kujou on 10/13/2021.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_LOCKER_H
#define DATA_STRUCTURES_AND_ALGORITHM_LOCKER_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>

class Sem {
public:
    Sem() {
        if (sem_init(&m_sem, 0, 0) != 0)
            throw std::exception();
    }
    ~Sem() {
        sem_destroy(&m_sem);
    }

    bool wait() {
        return sem_wait(&m_sem) == 0;
    }

    bool post() {
        return sem_post(&m_sem) == 0;
    }

private:
    sem_t m_sem;
};

class Locker {
public:
    Locker() {
        if (pthread_mutex_init(&m_mutex, nullptr) != 0)
            throw std::exception();
    }
    ~Locker() {
        pthread_mutex_destroy(&m_mutex);
    }

    bool lock() {
        return pthread_mutex_lock(&m_mutex) == 0;
    }

    bool unlock() {
        return pthread_mutex_unlock(&m_mutex) == 0;
    }

private:
    pthread_mutex_t m_mutex;
};

class Cond {
public:
    Cond() {
        if (pthread_mutex_init(&m_mutex, nullptr) != 0)
            throw std::exception();
        if (pthread_cond_init(&m_cond, nullptr) != 0) {
            pthread_mutex_destroy(&m_mutex);
            throw std::exception();
        }
    }
    ~Cond() {
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_cond);
    }

    bool wait() {
        int ret = 0;
        pthread_mutex_lock(&m_mutex);
        ret = pthread_cond_wait(&m_cond, &m_mutex);
        pthread_mutex_unlock(&m_mutex);
        return ret == 0;
    }

    bool signal() {
        return pthread_cond_signal(&m_cond) == 0;
    }

private:
    pthread_mutex_t m_mutex;
    pthread_cond_t m_cond;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_LOCKER_H
