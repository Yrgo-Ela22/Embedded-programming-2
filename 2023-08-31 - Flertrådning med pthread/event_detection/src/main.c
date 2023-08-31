/********************************************************************************
 * @brief Toggles a LED by pressing down a button. As default, the LED is
 *        connected to pin 17 and the button is connected to pin 27, but the
 *        the user is able to choose pin numbers when running the program.
 *        For instance, to connect the LED to pin 23 and the button to pin 25,
 *        run the program with the following command:
 * 
 *        ./run_program 23 25
 * 
 * @note  run_program is the name of the executable.
 ********************************************************************************/
#include <gpiod_utils.h>
#include <stdlib.h>

static void get_pin_numbers(const int argc, 
                            const char** argv, 
                            uint8_t* led_pin, 
                            uint8_t* button_pin) {
    *led_pin = argc >= 2 ? atoi(argv[1]) : 17;
    *button_pin = argc >= 3 ? atoi(argv[2]) : 27;
}

int main(const int argc, const char** argv) {
    uint8_t led_pin = 0, button_pin = 0, previous_input = 0;
    get_pin_numbers(argc, argv, &led_pin, &button_pin);
    struct gpiod_line* led1 = gpiod_line_new(led_pin, GPIOD_LINE_DIRECTION_OUT);
    struct gpiod_line* button1 = gpiod_line_new(button_pin, GPIOD_LINE_DIRECTION_IN);

    while (1) {
        if (gpiod_line_event_detected(button1, GPIOD_LINE_EDGE_RISING, &previous_input)) {
            gpiod_line_toggle(led1);
        }
    }
    return 0;
}