/********************************************************************************
 * @brief Example program where semaphores are used for thread synchronization.
 * 
 * @note  Thread functions in C must have void* as return type and void* as
 *        only input argument, so multiple input arguments have to be packed
 *        in a struct.
 ********************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

/********************************************************************************
 * @brief Struct for packing input arguments for thread functions.
 * 
 * @param id
 *        Thread ID stored as a positive integer.
 * @param delay_time_ms
 *         Delay time between prints in ms.
 ********************************************************************************/
struct thread_args {
    const uint8_t id;                
    const uint16_t delay_time_ms;
};

/********************************************************************************
 * @brief Blocks the calling thread during specified delay time.
 * 
 * @param delay_time_ms
 *        Delay time to block the calling thread, measured in ms.
 ********************************************************************************/
static void delay_ms(const uint16_t delay_time_ms) {
    usleep(delay_time_ms * 1000);
}

/********************************************************************************
 * @brief Runs thread continuously and prints the thread ID with set frequency.
 *        A semaphore is used to reserve the terminal when the calling thread 
 *        is to print. A 10 ms delay is implemented before releasing the semaphore 
 *        to make sure that the print is completed before next thread is getting 
 *        access to the terminal.
 * 
 * @param args
 *        Void pointer to the input arguments. This pointer must be converted 
 *        to the correct pointer type, i.e. struct thread_args*, before usage.
 * @return
 *        A nullptr, since a void pointer has to be returned, desipte it not
 *        being used in this program.
 ********************************************************************************/
static void* run_thread(void* arg) {
    struct thread_args* self = (struct thread_args*)(arg);
    while (1) {
        semaphore_reserve(0);
        printf("Running thread with ID %hu!\n", self->id);
        delay_ms(10);
        semaphore_release(0);
        delay_ms(self->delay_time_ms);
    }
    return 0;
}

/********************************************************************************
 * @brief Creates two threads running the run_thread function:
 * 
 *        - t1: Thread ID = 1, delay time between prints = 1000 ms.
 *        - t2: Thread ID = 2, delay time between prints = 1000 ms.
 * 
 *        The thread arguments are packed in structs, due to thread functions
 *        only being able to receive one input argument (a void pointer).
 *        
 *        The threads are created by calling the pthread function. The second
 *        argument is set to nullptr to make the thread run in default mode.
 *        
 *        The threads are syncronized by calling the pthread join function.
 *        Since the return value of the thread functions isn't needed in this 
 *        program, a nullptr is passed as second argument.
 ********************************************************************************/
int main(void) {
    struct thread_args args1 = { 1, 1000 }, args2 = { 2, 1000 };
    pthread_t t1, t2;
    pthread_create(&t1, 0, run_thread, &args1);
    pthread_create(&t2, 0, run_thread, &args2);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    return 0;
}