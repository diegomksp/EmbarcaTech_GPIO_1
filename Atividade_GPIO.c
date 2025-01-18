// Bibliotecas que usaremos no projeto
#include "pico/stdlib.h"
#include <stdio.h>

// Macros para usarmos como sonstantes no codigo
#define NUM_ROW_COLUMNS 4 // Número de linhas e colunas
#define BUZZER_PIN 28     // Pino do Buzzer
#define LED_RED 11        // Pino do led vermelho
#define LED_GREEN 12      // Pino do led verde
#define LED_BLUE 13       // Pino do led azul

// Definição das funções implementadas no projeto
void initialize_gpio();
char read_keyboard();
void buzzer_beep();
void Pisca_RED();
void Pisca_GREEN();
void Pisca_BLUE();
void tmed();
void tfinal();

// Vetores para as linhas e colunas GPIO do teclado
uint8_t row_pins[NUM_ROW_COLUMNS] = {2, 3, 4, 5};    // Vetor para as linhas GPIO
uint8_t column_pins[NUM_ROW_COLUMNS] = {6, 7, 8, 9}; // Vetor para as colunas GPIO

// Representação do teclado
char key_board[NUM_ROW_COLUMNS][NUM_ROW_COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Função main
int main()
{

    // Inicialialização dos GPIOs
    initialize_gpio();
    stdio_init_all();
    printf("Teclado e buzzer inicializados.\n");

    while (1)
    {
        char key = read_keyboard();

        // Verifica se um botão foi teclado
        if (key)
        {
            int t;
            printf("Tecla pressionada: %c\n", key);

            // Switch case para cada botão do teclado
            switch (key)
            {
            case '1': //SOS vermelho
                t=200;
                Pisca_RED(t);Pisca_RED(t);Pisca_RED(t);tmed();//S   
                t=800;
                Pisca_RED(t);Pisca_RED(t);Pisca_RED(t);tmed();//O
                t=200;
                break;
            case '2': //SOS verde
                t=200;
                Pisca_GREEN(t);Pisca_GREEN(t);Pisca_GREEN(t);tmed();//S
                t=800;
                Pisca_GREEN(t);Pisca_GREEN(t);Pisca_GREEN(t);tmed();//O
                t=200;
                Pisca_GREEN(t);Pisca_GREEN(t);Pisca_GREEN(t);tfinal();//S
                break;
            case '3': //SOS azul
                t=200;
                Pisca_BLUE(t);Pisca_BLUE(t);Pisca_BLUE(t);tmed();//S
                t=800;
                Pisca_BLUE(t);Pisca_BLUE(t);Pisca_BLUE(t);tmed();//O
                t=200;
                Pisca_BLUE(t);Pisca_BLUE(t);Pisca_BLUE(t);tfinal();//S
                break;
            case '4':
                Pisca_GREEN(t);
                break;
            case '5':
                Pisca_BLUE(t);;
                break;
            case '6':
                Pisca_RED(t);
                break;
            case '7':
               Pisca_GREEN(t);
               break;
            case '8':
                Pisca_BLUE(t);;
                break;
            case '9':
                Pisca_RED(t);
                break;
            case '0':
               Pisca_GREEN(t);
               break;
            case 'A':
                Pisca_RED(t);;
                break;
            case 'B':
                int t = 500;
                Pisca_GREEN(t);
                break;
            case 'C':
               Pisca_BLUE(t);
               break;
            case 'D': 
                Pisca_RED(t);Pisca_GREEN(t);Pisca_BLUE(t);      
                break;
            case '#':
                buzzer_beep();
                break;
            case '*':
                Pisca_RED(t);Pisca_GREEN(t);Pisca_BLUE(t); 
                printf("Buzzer acionado!\n");
                buzzer_beep();
                break;
            }
        }
        sleep_ms(50);
    }

    return 0;
} // Fim main

// Função para inicializar os GPIOs
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

    // GPIO do Buzzer
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);

    // GPIO do led azul,verde,vermelho
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
} // Fim initialize_gpio

// Função para leitura do teclado
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
} // Fim read_keyboard

// Função para o buzzer(Ainda em andamento)
void buzzer_beep(int a)
{
    int contB;
    for (contB = 0; contB < 100; contB++)
    {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(50);
        gpio_put(BUZZER_PIN, 0);
        sleep_us(50);
    }
} // Fim buzzer_beep

void Pisca_RED(int a)
{
    gpio_put(LED_RED, true);
    sleep_ms(a);
    gpio_put(LED_RED, false);
    sleep_ms(125);
}
void Pisca_BLUE(int a)
{
    gpio_put(LED_BLUE, true);
    sleep_ms(a);
    gpio_put(LED_BLUE, false);
    sleep_ms(125);
}
void Pisca_GREEN(int a)
{
    gpio_put(LED_GREEN, true);
    sleep_ms(a);
    gpio_put(LED_GREEN, false);
    sleep_ms(125);
}
void tmed()
{
  sleep_ms(125);
}
void tfinal()
{
  sleep_ms(2875);
}
