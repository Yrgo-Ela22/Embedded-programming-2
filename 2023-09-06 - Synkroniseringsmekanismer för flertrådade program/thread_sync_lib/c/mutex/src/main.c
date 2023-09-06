/********************************************************************************
 * @brief Example program where semaphores are used for thread synchronization.
 ********************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <mutex.h>

/********************************************************************************
 * @brief Parameters used for each thread.
 * 
 * @param delay_time_ms
 *        Delay time between each print, measured in milliseconds.
 * @param id
 *        Unique thread identifier.
 ********************************************************************************/
struct thread_param {
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
 *        A mutex is used to reserve the I/O resources before the print.
 *        After each print, the thread is blocked during specified delay time
 *        set via the thread parameters.
 * 
 * @param arg
 *        Reference to object containing thread parameters.
 * @return
 *        A nullptr upon exit (which should never happen).
 ********************************************************************************/
static void* thread_run(void* arg) {
    struct thread_param* self = (struct thread_param*)(arg);
    struct mutex* mutex = mutex_new();

    while (1) {
        delay_ms(self->delay_time_ms);
        mutex_lock(mutex);
        printf("Running thread with ID %hu!\n\n", self->id);
        mutex_unlock(mutex);
    }

    mutex_delete(&mutex);
    return 0;
}

/********************************************************************************
 * @brief Creates three threads and corresponding thread parameters. The threads
 *        are set to continuously run until the program is terminated.
 ********************************************************************************/
int main(void) {
    pthread_t t1, t2, t3;
    
    struct thread_param t1_param = {
        .delay_time_ms = 500,
        .id = 0
    };

    struct thread_param t2_param = {
        .delay_time_ms = 1000,
        .id = 1
    };

    struct thread_param t3_param = {
        .delay_time_ms = 2000,
        .id = 2
    };

    pthread_create(&t1, 0, thread_run, &t1_param);
    pthread_create(&t2, 0, thread_run, &t2_param);
    pthread_create(&t3, 0, thread_run, &t3_param);

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    return 0;
}