/********************************************************************************
 * @brief Example program where semaphores are used for thread synchronization.
 ********************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

/********************************************************************************
 * @brief Parameters used for each thread.
 * 
 * @param delay_time_ms
 *        Delay time between each print, measured in milliseconds.
 * @param id
 *        The thread ID.
 ********************************************************************************/
struct thread_parameters {
    const uint16_t delay_time_ms;
    const uint8_t id;
};

/********************************************************************************
 * @brief Delays the calling thread with specified delay time in milliseconds.
 * 
 * @param delay_time_ms
 *        Specified delay time in milliseconds.
 ********************************************************************************/
static inline void delay_ms(const uint16_t delay_time_ms) {
    usleep(delay_time_ms * 1000);
}

/********************************************************************************
 * @brief Runs specified thread continuously, where a thread message is printed.
 *        A semaphore is used to reserve the I/O resources before the print.
 *        After each print, the thread is blocked during specified delay time
 *        set via the thread parameters.
 * 
 * @param arg
 *        Reference to object containing thread parameters.
 * @return
 *        A nullptr upon exit (which should never happen).
 ********************************************************************************/
void* run_thread(void* arg) {
    struct thread_parameters* self = (struct thread_parameters*)(arg);

    while (1) {
        semaphore_reserve(SEMAPHORE_ID_IO);
        printf("Thread with ID %hu running!\n\n", self->id);
        semaphore_release(SEMAPHORE_ID_IO);
        delay_ms(self->delay_time_ms);
    }
    return 0;
}

/********************************************************************************
 * @brief Creates three threads and corresponding thread parameters. The threads
 *        are set to continuously run until the program is terminated.
 ********************************************************************************/
int main(void) {
    pthread_t t1, t2, t3;
    
    struct thread_parameters t1_param = {
        .delay_time_ms = 1000,
        .id = 0
    };

    struct thread_parameters t2_param = {
        .delay_time_ms = 2000,
        .id = 1
    };

    struct thread_parameters t3_param = {
        .delay_time_ms = 5000,
        .id = 2
    };

    pthread_create(&t1, 0, run_thread, &t1_param);
    pthread_create(&t2, 0, run_thread, &t2_param);
    pthread_create(&t3, 0, run_thread, &t3_param);

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    return 0;
}