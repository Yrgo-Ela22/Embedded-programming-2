/********************************************************************************
 * @brief Example program where semaphores are used for thread synchronization.
 ********************************************************************************/
#include <iostream>
#include <cstdint>
#include <thread>
#include <chrono>
#include <semaphore.hpp>

namespace thread_sync = yrgo::thread_sync;

namespace {

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
 *        A semaphore is used to reserve the I/O resources before the print.
 *        After each print, the thread is blocked during specified delay time
 *        set via the thread parameters.
 * 
 * @param thread_id
 *        Unique thread identifier.
 * @param delay_time_ms
 *        Delay time between each print in milliseconds.
 ********************************************************************************/
void RunThread(const int16_t thread_id, const uint16_t delay_time_ms) {
    thread_sync::Semaphore sem{};
    while (1) {
        sem.Reserve(thread_sync::Semaphore::ID::kIo);
        std::cout << "Thread with ID " << thread_id << " running!\n\n";
        sem.Release(thread_sync::Semaphore::ID::kIo);
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