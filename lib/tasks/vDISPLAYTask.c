#include "tasks.h"

void vDISPLAYTask()
{
    ssd1306_t ssd;          // Inicializa a estrutura do display
    char str_y[5], buffer[30]; // Buffer para armazenar a string
    bool cor = true;

    i2c_setup();            // Inicializa a comunicação I2C      
    ssd1306_setup(&ssd);    // Inicializa o display                                            

    while (true)
    {
        bool mode = flag;
        uint32_t cur_counter = counter;
        sprintf(str_y, "%d", cur_counter); // Converte em string
        ssd1306_fill(&ssd, !cor);                          // Limpa o display
        ssd1306_rect(&ssd, 3, 3, 122, 60, cor, !cor);      // Desenha um retângulo
        ssd1306_line(&ssd, 3, 25, 123, 25, cor);           // Desenha uma linha
        ssd1306_line(&ssd, 3, 37, 123, 37, cor);           // Desenha uma linha
        ssd1306_draw_string(&ssd, (cur_counter < 7) ? "SINAL:GREEN" : (cur_counter < 9) ? "SINAL:YELLOW": "SINAL:RED", 20, 12);  // Desenha uma string
        ssd1306_draw_string(&ssd, (mode) ? "Modo Normal" : "Modo Noturno", 10, 28); // Desenha uma string
        ssd1306_draw_string(&ssd, "Contador  LEDs", 10, 41);    // Desenha uma string
        ssd1306_draw_string(&ssd, str_y, 40, 52);          // Desenha uma string
        ssd1306_send_data(&ssd);                           // Atualiza o display
        delay(100,mode);
    }
}