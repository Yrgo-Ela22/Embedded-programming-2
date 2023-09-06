#include <stdio.h>
#include <pthread.h>
#include <gpiod_utils.h>
#include <semaphore.h>

/********************************************************************************
 * @brief Structure containing thread arguments.
 * 
 * @param led 
 *        Reference to gpiod line connected to a LED.
 * @param button
 *        Reference to gpiod line connected to a button.
 * @param blink_speed_ms
 *        Blink speed of the LED at pressdown of the button.
 ********************************************************************************/
struct thread_args {
    struct gpiod_line* led;
    struct gpiod_line* button;
    uint16_t blink_speed_ms;
};

/********************************************************************************
 * @brief Runs thread, where a LED is blinking at pressdown of a button.
 *        A semaphore is used to reserve the terminal when the calling thread 
 *        is to print. A 10 ms delay is implemented before releasing the semaphore 
 *        to make sure that the print is completed before next thread is getting 
 *        access to the terminal.
 * 
 * @param arg
 *        Reference to argument containing all thread parameters.
 * @return
 *        A nullptr, since we have to return something.
 ********************************************************************************/
void* run_thread(void* arg) {
    struct thread_args* self = (struct thread_args*)(arg);
    while (1) {
        if (gpiod_line_get_value(self->button)) {
            gpiod_line_set_value(self->led, 1);
            printf("LED connected to pin %hu enabled!\n\n", gpiod_line_offset(self->led));
            delay_ms(self->blink_speed_ms);
            
            gpiod_line_set_value(self->led, 0);
            printf("LED connected to pin %hu disabled!\n\n", gpiod_line_offset(self->led));
            delay_ms(self->blink_speed_ms);
        } 
    }
    return 0;
}

/********************************************************************************
 * @brief Creates two threads and connects a LED and a button in each thread.
 ********************************************************************************/
int main(void) {
    struct gpiod_line* led1 = gpiod_line_new(17, GPIOD_LINE_DIRECTION_OUT);
    struct gpiod_line* led2 = gpiod_line_new(22, GPIOD_LINE_DIRECTION_OUT);
    struct gpiod_line* button1 = gpiod_line_new(27, GPIOD_LINE_DIRECTION_IN);
    struct gpiod_line* button2 = gpiod_line_new(25, GPIOD_LINE_DIRECTION_IN);

    struct thread_args args1 = { led1, button1, 100 };
    struct thread_args args2 = { led2, button2, 500 };
    pthread_t t1, t2; 

    pthread_create(&t1, 0, run_thread, &args1);
    pthread_create(&t2, 0, run_thread, &args2);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    return 0;
}