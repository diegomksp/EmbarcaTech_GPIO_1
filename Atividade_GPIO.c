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
void morse();
void sos();
void ola();
void completo();
void cascata();


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
            case '1':
                sos(LED_BLUE);
                break;
            case '2':
                sos(LED_RED);
                break;
            case '3':
                sos(LED_GREEN);
                break;           
            case '4':
                ola(LED_BLUE);
                break;
            case '5':
                ola(LED_RED);
                break;
            case '6':
                ola(LED_GREEN);
                break;
            case '7':
               Pisca_GREEN();
               buzzer_beep();
               break;
            case '8':
                Pisca_BLUE();
                buzzer_beep();
                break;
            case '9':
                Pisca_RED();
                buzzer_beep();
                break;
            case '0':
               cascata();
               break;
            case 'A':
                Pisca_RED();
                break;
            case 'B':
                Pisca_GREEN();
                break;
            case 'C':
                Pisca_BLUE();
                break;
            case 'D':
                completo();
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
} // Fim buzzer_beep

void Pisca_RED()
{
    gpio_put(LED_RED, true);
    sleep_ms(500);
    gpio_put(LED_RED, false);
}
void Pisca_BLUE()
{
    gpio_put(LED_BLUE, true);
    sleep_ms(500);
    gpio_put(LED_BLUE, false);
}
void Pisca_GREEN()
{
    gpio_put(LED_GREEN, true);
    sleep_ms(500);
    gpio_put(LED_GREEN, false);
}
void morse(int led_pin, int a){
    gpio_put(led_pin, true);
    sleep_ms(a);
    gpio_put(led_pin, false);
    sleep_ms(125);
}
void tmed(){
  sleep_ms(125);
}
void tfinal(){
  sleep_ms(875);
}
void sos(int led){
    int t;
    t=200;
    morse(led, t);//S 
    morse(led, t);
    morse(led, t);
    tmed();  
    t=800;
    morse(led, t);//O
    morse(led, t);
    morse(led, t);
    tmed();
    t=200;
    morse(led, t);//S 
    morse(led, t);
    morse(led, t);
    tmed();
}
void ola(int led){
    int t;
    t=200;
    morse(led, t);//O
    morse(led, t);
    morse(led, t);
    tmed();
    morse(led, t);//L
    t=800;
    morse(led, t);
    t=200;
    morse(led, t);
    morse(led, t);
    tmed();
    morse(led, t);//Á
    t=800;
    morse(led, t);
    t=200;
    morse(led, t);
    t=800;
    morse(led, t);
    tfinal();
}
void completo(){
    gpio_put(LED_BLUE, true);
    gpio_put(LED_GREEN, true);
    gpio_put(LED_RED, true);
    sleep_ms(500);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_GREEN, false);
    gpio_put(LED_RED, false);    
}
void cascata(){
    gpio_put(LED_BLUE, true);
    sleep_ms(250);
    gpio_put(LED_GREEN, true);
    sleep_ms(250);
    gpio_put(LED_RED, true);
    sleep_ms(250);
    gpio_put(LED_BLUE, false);
    sleep_ms(250);
    gpio_put(LED_GREEN, false);
    sleep_ms(250);
    gpio_put(LED_RED, false); 
}
