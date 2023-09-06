/********************************************************************************
 * @brief Library containing functionality for using mutexes and lock guards.
 ********************************************************************************/
#pragma once

#include <cstdint>

namespace yrgo {
namespace thread_sync {

/********************************************************************************
 * @brief Class for implementation of mutexes.
 ********************************************************************************/
class Mutex {
  public:

    /********************************************************************************
     * @brief Creates new mutex.
     ********************************************************************************/
    Mutex(void) = default;

    /********************************************************************************
     * @brief Unlocks mutex before deletion.
     ********************************************************************************/
    ~Mutex(void) { Unlock(); }

    /********************************************************************************
     * @brief Copy constructor deleted.
     ********************************************************************************/
    Mutex(const Mutex&) = delete;

    /********************************************************************************
     * @brief Copy assignment operator deleted.
     ********************************************************************************/
    Mutex& operator=(const Mutex&) = delete;

    /********************************************************************************
     * @brief Move constructor deleted.
     ********************************************************************************/
    Mutex(const Mutex&&) noexcept = delete;

    /********************************************************************************
     * @brief Indicates if the mutex if blocked by another thread.
     * 
     * @return
     *        True if the mutex is blocked, else false.
     ********************************************************************************/
    bool Blocked(void) const { return blocked_; }

    /********************************************************************************
     * @brief Provides the address of the mutex.
     * 
     * @return
     *        A pointer to the address of the mutex.
     ********************************************************************************/
    const Mutex* NativeHandle(void) const { return this; }

    /********************************************************************************
     * @brief Locks mutex. The calling thread is blocked until the mutex is available.
     ********************************************************************************/
    void Lock(void) {
        while (blocked_);
        blocked_ = true;
    }

    /********************************************************************************
     * @brief Unlocks mutex so it becomes available for other threads.
     ********************************************************************************/
    void Unlock(void) { blocked_ = false; }

    /********************************************************************************
     * @brief Tries to lock mutex, which is done only if the mutex is available.
     *        The calling thread is not blocked if the mutex is unavailable.
     * @return
     *        True if the mutex was locked, else false.
     ********************************************************************************/
    bool TryLock(void) {
        if (!blocked_) {
            blocked_ = true;
            return true;
        } else {
            return false;
        }
    }

  private:

    /********************************************************************************
     * @brief Private member variables.
     * 
     * @param blocked_
     *        Indicates if the mutex if blocked by a thread.
     ********************************************************************************/
    bool blocked_{false}; 
};

/********************************************************************************
 * @brief Class for utilization of mutex lock guards, which is used to 
 *        automatically lock and unlock mutexes.
 ********************************************************************************/
class LockGuard {
  public:

    /********************************************************************************
     * @brief Creates lock guard and locks referenced mutex.
     * 
     * @param mutex
     *        Reference to the mutex to guard.
     ********************************************************************************/
    LockGuard(Mutex& mutex) : mutex_{&mutex} {
        mutex_->Lock();
    }

    /********************************************************************************
     * @brief Unlocks mutex before deletion of the lock guard.
     ********************************************************************************/
    ~LockGuard(void) { mutex_->Unlock(); }

    /********************************************************************************
     * @brief Copy constructor deleted.
     ********************************************************************************/
    LockGuard(LockGuard&) = delete;

    /********************************************************************************
     * @brief Copy assignment operator deleted.
     ********************************************************************************/
    LockGuard& operator=(LockGuard&) = delete;

    /********************************************************************************
     * @brief Move constructor constructor deleted.
     ********************************************************************************/
    LockGuard(LockGuard&&) = delete;

  private:

    /********************************************************************************
     * @brief Private member variables.
     * 
     * @param mutex_
     *        Pointer to the guarded mutex.
     ********************************************************************************/
    Mutex* mutex_{nullptr}; 
};

} /* namespace thread_sync */
} /* namespace yrgo */