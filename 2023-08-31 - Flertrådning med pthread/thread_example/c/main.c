/********************************************************************************
 * @brief Thread example by using pthread in C.
 * 
 * @note  Thread functions in C must have void* as return type and void* as
 *        only input argument, so multiple input arguments have to be packed
 *        in a struct.
 ********************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/********************************************************************************
 * @brief Struct for packing input arguments for thread functions.
 * 
 * @param id
 *        Thread ID stored as a positive integer.
 * @param delay_time_ms
 *         Delay time between prints in ms.
 ********************************************************************************/
struct thread_args {
    int id;                
    uint16_t delay_time_ms;
};

/********************************************************************************
 * @brief Runs thread continuously and prints the thread ID with set frequency.
 * 
 * @param args
 *        Void pointer to the input arguments. This pointer must be converted 
 *        to the correct pointer type, i.e. struct thread_args*, before usage.
 * @return
 *        A nullptr, since a void pointer has to be returned, desipte it not
 *        being used in this program.
 ********************************************************************************/
void* run_thread(void* arg) {
    struct thread_args* self = (struct thread_args*)(arg);
    while (1) {
        printf("Runs thread with ID %d!\n\n", self->id);
        usleep(self->delay_time_ms * 1000);
    }
    return 0; 
}

/********************************************************************************
 * @brief Creates two threads running the run_thread function:
 * 
 *        - t1: Thread ID = 1, delay time between prints = 500 ms.
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
    struct thread_args args1 = { 1, 500 }, args2 = { 2, 1000 };
    pthread_t t1, t2; 
    pthread_create(&t1, 0, run_thread, &args1);
    pthread_create(&t2, 0, run_thread, &args2);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
}