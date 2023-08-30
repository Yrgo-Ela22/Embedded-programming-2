/********************************************************************************
 * @brief Example of using the libgpiod library for Raspberry Pi in C.
 ********************************************************************************/
#include <gpiod.h>
#include <unistd.h>
#include <stdint.h>

/************************************************************
 * @brief Blocks calling thread for specified time in ms.
 *
 * @param delay_time_ms
 *        The time to block the delay in ms.
 ************************************************************/
static void delay_ms(const uint16_t delay_time_ms) {
    usleep(delay_time_ms * 1000);
}

/********************************************************************************
 * @brief Connects a LED to pin 17 and a push button to pin 27. The LED is set
 *        to output and the button is set to input. The LED is blinking every
 *        100 ms when the button is pressed, the rest of the time it's disabled.
 ********************************************************************************/
int main(void) {
    struct gpiod_chip* chip0 = gpiod_chip_open("/dev/gpiochip0");
    struct gpiod_line* led1 = gpiod_chip_get_line(chip0, 17);
    struct gpiod_line* button1 = gpiod_chip_get_line(chip0, 27);
    gpiod_line_request_output(led1, 0, 0);
    gpiod_line_request_input(button1, 0);

    while (1) {
        if (gpiod_line_get_value(button1)) {
            gpiod_line_set_value(led1, 1);
            delay_ms(100);
            gpiod_line_set_value(led1, 0);
            delay_ms(100);
        } else {
            gpiod_line_set_value(led1, 0);
        }
    }
    return 0;
}

