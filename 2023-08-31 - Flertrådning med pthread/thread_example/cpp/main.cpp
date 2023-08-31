/********************************************************************************
 * @brief Thread example by using std::thread in C++.
 ********************************************************************************/
#include <thread>
#include <iostream>
#include <cstdint>
#include <unistd.h>

/********************************************************************************
 * @brief Runs thread continuously and prints the thread ID with set frequency.
 * 
 * @param thread_id
 *        The ID of the calling thread.
 * @param delay_time_ms
 *        Delay time between each print.
 ********************************************************************************/
void run_thread(const int thread_id, const uint16_t delay_time_ms) {
     while (1) {
        std::cout << "Running thread with ID " << thread_id << "!\n\n";
        usleep(delay_time_ms * 1000);
     }
}

/********************************************************************************
 * @brief Creates two threads running the run_thread function:
 *        - t1: Thread ID = 1, delay time between prints = 500 ms.
 *        - t2: Thread ID = 2, delay time between prints = 1000 ms.
 * 
 *        The threads are created via the std::thread constructor. The threads
 *        are syncronized by calling the std::thread::join member function.
 ********************************************************************************/
int main(void) {
    std::thread t1{run_thread, 1, 500};  
    std::thread t2{run_thread, 2, 1000}; 
    t1.join();
    t2.join();
}