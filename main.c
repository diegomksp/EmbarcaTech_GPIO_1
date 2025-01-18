#include "pico/stdlib.h"
#include <stdio.h>

#define NUM_ROW_COLUMNS 4
#define BUZZER_PIN 28
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

void initialize_gpio();
char read_keyboard();
void buzzer_beep();
void blink_red();
void blink_green();
void blink_blue();

uint8_t row_pins[NUM_ROW_COLUMNS] = {2, 3, 4, 5};
uint8_t column_pins[NUM_ROW_COLUMNS] = {6, 7, 8, 9};

char key_board[NUM_ROW_COLUMNS][NUM_ROW_COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

int main()
{
    initialize_gpio();
    stdio_init_all();
    printf("Keyboard and buzzer initialized.\n");

    while (1)
    {
        char key = read_keyboard();

        if (key)
        {
            printf("Key pressed: %c\n", key);

            switch (key)
            {
            case '1':
                blink_green();
                break;
            case '2':
                blink_blue();
                break;
            case '3':
                blink_red();
                break;
            case '4':
                blink_green();
                break;
            case '5':
                blink_blue();
                break;
            case '6':
                blink_red();
                break;
            case '7':
                blink_green();
                break;
            case '8':
                blink_blue();
                break;
            case '9':
                blink_red();
                break;
            case '0':
                blink_green();
                break;
            case 'A':
                blink_blue();
                break;
            case 'B':
                blink_red();
                break;
            case 'C':
                blink_green();
                break;
            case 'D':
                blink_blue();
                break;
            case '#':
                blink_blue();
                break;
            case '*':
                blink_red();
                printf("Buzzer activated!\n");
                buzzer_beep();
                break;
            }
        }

        sleep_ms(50);
    }

    return 0;
}

void initialize_gpio()
{
    int i;

    for (i = 0; i < NUM_ROW_COLUMNS; i++)
    {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 0);
    }

    for (i = 0; i < NUM_ROW_COLUMNS; i++)
    {
        gpio_init(column_pins[i]);
        gpio_set_dir(column_pins[i], GPIO_IN);
        gpio_pull_down(column_pins[i]);
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

char read_keyboard()
{
    int i, j;

    for (i = 0; i < NUM_ROW_COLUMNS; i++)
    {
        gpio_put(row_pins[i], 1);

        for (j = 0; j < NUM_ROW_COLUMNS; j++)
        {
            if (gpio_get(column_pins[j]))
            {
                gpio_put(row_pins[i], 0);
                return key_board[i][j];
            }
        }
        gpio_put(row_pins[i], 0);
    }
    return 0;
}

void buzzer_beep()
{
    int contB;
    for (contB = 0; contB < 100; contB++)
    {
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
