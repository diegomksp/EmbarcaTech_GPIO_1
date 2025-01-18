#include "pico/stdlib.h"
#include <stdio.h>

#define BUZZER_PIN 28
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

const uint8_t row_pins[KEYPAD_ROWS] = {2, 3, 4, 5};
const uint8_t column_pins[KEYPAD_COLS] = {6, 7, 8, 9};

const char keypad_map[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void initialize_gpio()
{
    for (int row = 0; row < KEYPAD_ROWS; row++)
    {
        gpio_init(row_pins[row]);
        gpio_set_dir(row_pins[row], GPIO_OUT);
        gpio_put(row_pins[row], 0);
    }

    for (int col = 0; col < KEYPAD_COLS; col++)
    {
        gpio_init(column_pins[col]);
        gpio_set_dir(column_pins[col], GPIO_IN);
        gpio_pull_down(column_pins[col]);
    }

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
}

char read_keypad()
{
    for (int row = 0; row < KEYPAD_ROWS; row++)
    {
        gpio_put(row_pins[row], 1);

        for (int col = 0; col < KEYPAD_COLS; col++)
        {
            if (gpio_get(column_pins[col]))
            {
                gpio_put(row_pins[row], 0);
                return keypad_map[row][col];
            }
        }
        gpio_put(row_pins[row], 0);
    }

    return 0;
}

void buzzer_beep()
{
    for (int i = 0; i < 100; i++) {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(50);
        gpio_put(BUZZER_PIN, 0);
        sleep_us(50);
    }
}

void blink_red()
{
    gpio_put(LED_RED, true);
    sleep_ms(500);
    gpio_put(LED_RED, false);
}

void blink_blue()
{
    gpio_put(LED_BLUE, true);
    sleep_ms(500);
    gpio_put(LED_BLUE, false);
}

void blink_green()
{
    gpio_put(LED_GREEN, true);
    sleep_ms(500);
    gpio_put(LED_GREEN, false);
}

int main()
{
    stdio_init_all();
    initialize_gpio();

    printf(">> Pressione uma tecla...\n");

    while (true) {
        char key = read_keypad();

        if (key) {
            switch (key) {
                case '1':
                case '4':
                case '7':
                case '0':
                case 'C':
                    blink_green();
                    break;
                case '2':
                case '5':
                case '8':
                case 'B':
                    blink_blue();
                    break;
                case 'A':
                case '3':
                case '6':
                case '9':
                    blink_red();
                    break;
                case 'D':
                    blink_red();
                    blink_blue();
                    blink_green();
                    break;
                case '#':
                    buzzer_beep();
                    break;
                case '*':
                    blink_red();
                    buzzer_beep();
                    break;
            }
        }

        sleep_ms(50); // debounce
    }

    return 0;
}
