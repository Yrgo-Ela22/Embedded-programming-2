/********************************************************************************
 * @brief Example program where a mutex is used for thread synchronization.
 ********************************************************************************/
#include <iostream>
#include <cstdint>
#include <thread>
#include <chrono>
#include <mutex.hpp>

namespace thread_sync = yrgo::thread_sync;

namespace {

/********************************************************************************
 * @brief Mutex used for I/O-resources.
 ********************************************************************************/
thread_sync::Mutex mutex{};

/********************************************************************************
 * @brief Delays the calling thread with specified delay time in milliseconds.
 * 
 * @param delay_time_ms
 *        Specified delay time in milliseconds.
 ********************************************************************************/
inline void Delay_ms(const uint16_t delay_time_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time_ms));
}

/********************************************************************************
 * @brief Runs specified thread continuously, where a thread message is printed.
 *        A mutex is used to reserve the I/O resources before the print.
 *        After each print, the thread is blocked during specified delay time
 *        set via the thread parameters. Lock guards are used to automatically
 *        unlock the mutex after each print.
 * 
 * @param thread_id
 *        Unique thread identifier.
 * @param delay_time_ms
 *        Delay time between each print in milliseconds.
 ********************************************************************************/
void RunThread(const int16_t thread_id, const uint16_t delay_time_ms) {
    while (1) {
        if (1) {
            thread_sync::LockGuard lock{mutex};
            std::cout << "Thread with ID " << thread_id << " running!\n\n";
        }
        Delay_ms(delay_time_ms);
    }
}
} /* namespace */

/********************************************************************************
 * @brief Creates three threads and corresponding thread parameters. The threads
 *        are set to continuously run until the program is terminated.
 ********************************************************************************/
int main(void) {

    std::thread t1{RunThread, 0, 1000};
    std::thread t2{RunThread, 1, 2000};
    std::thread t3{RunThread, 2, 5000};

    t1.join();
    t2.join();
    t3.join();
    return 0;
}