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

uint8_t row_pins[NUM_ROW_COLUMNS] = {2, 3, 4, 5};
uint8_t column_pins[NUM_ROW_COLUMNS] = {6, 7, 8, 9};

char key_board[NUM_ROW_COLUMNS][NUM_ROW_COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

int main() {
    stdio_init_all();
    initialize_gpio();

    printf("Teclado e buzzer inicializados.\n");

    while (1) {
        char key = read_keyboard();

        if (key) {
            printf("Tecla pressionada: %c\n", key);

            switch(key) {
                case '1':
                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                case '5':
                    break;
                case '6':
                    break;
                case '7':
                    break;
                case '8':
                    break;
                case '9':
                    break;
                case '0':
                    break;
                case 'A':
                    break;
                case 'B':
                    break;
                case 'C':
                    break;
                case 'D':
                    break;
                case '*':
                    break;
                case '#':
                    printf("Buzzer acionado!\n");
                    buzzer_beep();
                    break;
            }
        }

        sleep_ms(50);
    }

    return 0;
}

void initialize_gpio() {
    int i;

    for (i = 0; i < NUM_ROW_COLUMNS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 0);
    }

    for (i = 0; i < NUM_ROW_COLUMNS; i++) {
        gpio_init(column_pins[i]);
        gpio_set_dir(column_pins[i], GPIO_IN);
        gpio_pull_down(column_pins[i]);
    }

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

char read_keyboard() {
    int i, j;

    for (i = 0; i < NUM_ROW_COLUMNS; i++) {
        gpio_put(row_pins[i], 1);

        for (j = 0; j < NUM_ROW_COLUMNS; j++) {
            if (gpio_get(column_pins[j])) {
                gpio_put(row_pins[i], 0);
                return key_board[i][j];
            }
        }

        gpio_put(row_pins[i], 0);
    }
    return 0;
}

void buzzer_beep() {
    gpio_put(BUZZER_PIN, 1);
    sleep_us(200);
    gpio_put(BUZZER_PIN, 0);
    sleep_us(100);
}
