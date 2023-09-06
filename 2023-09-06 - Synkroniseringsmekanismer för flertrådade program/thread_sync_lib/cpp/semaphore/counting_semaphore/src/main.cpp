/********************************************************************************
 * @brief Example program where semaphores are used for thread synchronization.
 ********************************************************************************/
#include <thread>
#include <iostream>
#include <chrono>
#include <cstdint>
#include <semaphore.hpp>

namespace thread_sync = yrgo::thread_sync;

/********************************************************************************
 * @note The content declared inside an anonymous namespace has internal (static) 
 *       linkage. The functions definied within are therefore static functions,
 *       which makes the static keyword obsolete in this instance.
 ********************************************************************************/
namespace {

thread_sync::CountingSemaphore<1> semaphore{}; /* Creates binary semaphore. */

/********************************************************************************
 * @brief Blocks the calling thread during specified delay time.
 * 
 * @param delay_time_ms
 *        Delay time to block the calling thread, measured in ms.
 ********************************************************************************/
void delay_ms(const uint16_t delay_time_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time_ms));
}

/********************************************************************************
 * @brief Runs thread by printing the ID with specified frequency. A semaphore
 *        is used to reserve the terminal when the calling thread is to print.
 *        A 10 ms delay is implemented before releasing the semaphore to make
 *        sure that the print is completed before next thread is getting access
 *        to the terminal.
 * 
 * @param thread_id
 *        Unique ID of the running thread.
 * @param delay_time_ms
 *        Delay time between each print.
 ********************************************************************************/
void run_thread(const int thread_id, const uint16_t delay_time_ms) {
     while (1) {
        semaphore.Reserve();
        std::cout << "Running thread with ID " << thread_id << "!\n";
        delay_ms(10);
        semaphore.Release();
        delay_ms(delay_time_ms);
     }
}
} /* namespace */

/********************************************************************************
 * @brief Creates two threads running the run_thread function:
 *        - t1: Thread ID = 1, delay time between prints = 1000 ms.
 *        - t2: Thread ID = 2, delay time between prints = 1000 ms.
 * 
 *        The threads are created via the std::thread constructor. The threads
 *        are syncronized by calling the std::thread::join member function.
 ********************************************************************************/
int main(void) {
    std::thread t1{run_thread, 1, 1000};
    std::thread t2{run_thread, 2, 1000};
    t1.join();
    t2.join();
    return 0;
}