/*
	Lucas Carneiro de Araújo Lima
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "ws2812.pio.h"
#include "lib/ssd1306/ssd1306.h"
#include "lib/ssd1306/font.h"


#define I2C_PORT i2c1   // Define que o barramento I2C usado será o "i2c1"
#define I2C_SDA 14      // Define que o pino GPIO 14 será usado como SDA (linha de dados do I2C)
#define I2C_SCL 15      // Define que o pino GPIO 15 será usado como SCL (linha de clock do I2C)
#define address 0x3C    // Define o endereço I2C do dispositivo (0x3C é o endereço padrão de muitos displays OLED SSD1306)
#define BTNA 5          // Botão A
#define ADC 28          // GPIO para o ohmimetro
#define WS2812_PIN 7    // Matriz de LEDs 5x5

#define NUM_PIXELS 25   // 5x5 = 25
#define IS_RGBW false

#define BLUE 12         // LED Azul
#define GREEN 11        // LED Verde
#define RED 13          // LED Vermelho    
#define BUZZER 21       // Buzzer

#define DI 125      // DIVISOR INTEIRO
#define WRAP 19999  // WRAP 

extern PIO pio;
extern int sm;

void btn_setup();

void led_setup();

// Inicializa e configura a comunicação serial I2C 
void i2c_setup();

// Limpa o display
void clear(ssd1306_t* ssd);

// Inicializa e configura o display
void ssd1306_setup(ssd1306_t* ssd);

// Inicializa e configura a matriz de LEDs 5x5 
void ws2812_setup(PIO pio, uint sm);

#endif