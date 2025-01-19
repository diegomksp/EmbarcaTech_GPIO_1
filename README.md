# Projeto: Teclado com Buzzer e LEDs usando Raspberry Pi Pico

## Descrição

Este projeto implementa um sistema de controle que utiliza um teclado matricial, um buzzer e LEDs conectados a um Raspberry Pi Pico. O código permite executar diferentes funções e padrões de pisca-pisca ou som, dependendo da tecla pressionada.

O teclado matricial é usado para capturar as entradas do usuário, enquanto o buzzer e os LEDs (vermelho, verde e azul) são acionados para realizar funções como a geração de sinais em código Morse e outros padrões de pisca e som.

## Funcionalidades

1. **Teclado Matricial**:
   - Detecta teclas pressionadas e executa funções associadas.

2. **Buzzer**:
   - Produz sons em padrões curtos e longos.

3. **LEDs RGB**:
   - Pisca diferentes combinações de cores e padrões de acordo com a tecla pressionada.

4. **Funções Morse**:
   - Envia sinais "SOS" e "OLA" usando código Morse com os LEDs.

5. **Padrões Específicos**:
   - Executa sequências predefinidas, como pisca em cascata e iluminação completa dos LEDs.

## Mapeamento de Teclas

| Tecla | Função                  |
|-------|--------------------------|
| 1     | Envia "SOS" (LED Azul)   |
| 2     | Envia "SOS" (LED Vermelho) |
| 3     | Envia "SOS" (LED Verde)   |
| 4     | Envia "OLA" (LED Azul)   |
| 5     | Envia "OLA" (LED Vermelho) |
| 6     | Envia "OLA" (LED Verde)   |
| 7     | Pisca LED Verde e Buzzer |
| 8     | Pisca LED Azul e Buzzer  |
| 9     | Pisca LED Vermelho e Buzzer |
| 0     | Pisca LEDs em Cascata    |
| A     | Pisca LED Vermelho       |
| B     | Pisca LED Verde          |
| C     | Pisca LED Azul           |
| D     | Ilumina todos os LEDs    |
| #     | Aciona o Buzzer          |
| *     | Pisca LEDs e Aciona Buzzer |

## Como Usar

1. Conecte o teclado matricial, buzzer e LEDs às portas GPIO do Raspberry Pi Pico conforme o código.
2. Compile e carregue o código no Raspberry Pi Pico.
3. Pressione as teclas no teclado para ativar as diferentes funções.

## Hardware Necessário

- Raspberry Pi Pico
- Teclado Matricial 4x4
- LEDs (Vermelho, Verde e Azul)
- Buzzer
- Resistores (para LEDs e teclado, se necessário)
- Cabos de conexão

## Estrutura do Código

- **Função `initialize_gpio`**: Configura os GPIOs para o teclado, LEDs e buzzer.
- **Função `read_keyboard`**: Lê a tecla pressionada no teclado matricial.
- **Funções de LEDs e Buzzer**: Executam os padrões de iluminação e som.

## Link para Demonstração

[https://drive.google.com/file/d/1vnW8hbfslwwWvmJr5zDznYLah9hj0fww/view?usp=sharing](#)

## Autor

Projeto desenvolvido por:
Bruno Costa
Caio Andrade
Diego M S Pereira
Josevaldo S de Lima
