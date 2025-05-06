#include "tasks.h"

void format(ssd1306_t *ssd, uint32_t counter, char color, bool mode) {
    char str_y[5]; // Buffer para armazenar a string

    sprintf(str_y, "%d", counter); // Converte em string
    ssd1306_draw_string(ssd, (color=='g') ? "SINAL:GREEN" : (color == 'y') ? "SINAL:YELLOW": (color == 'r') ? "SINAL:RED" : "SINAL:", 20, 12);  // Desenha uma string
    ssd1306_draw_string(ssd, (mode==true) ? "MODO:NORMAL" : "MODO:NOTURNO", 20, 33); // Desenha uma string
    ssd1306_draw_string(ssd, "TEMPO:", 30, 50);        // Desenha uma string
    ssd1306_draw_string(ssd, str_y, 80, 50);          // Desenha uma string
}

void vDISPLAYTask()
{
    ssd1306_t ssd;          // Inicializa a estrutura do display
    bool cor = true;

    i2c_setup();            // Inicializa a comunicação I2C      
    ssd1306_setup(&ssd);    // Inicializa o display                                            

    while (true)
    {
        bool mode = flag;
        ssd1306_fill(&ssd, !cor);                          // Limpa o display
        ssd1306_rect(&ssd, 3, 3, 122, 60, cor, !cor);      // Desenha um retângulo
        ssd1306_line(&ssd, 3, 25, 123, 25, cor);           // Desenha uma linha
        ssd1306_line(&ssd, 3, 46, 123, 46, cor);           // Desenha uma linha
        if(mode) 
        {
            uint32_t cur_counter = counter_1;

            if(cur_counter < 7)
                format(&ssd, 6-cur_counter, 'g', mode);
            else if(cur_counter < 9)
                format(&ssd, 8-cur_counter, 'y', mode);
            else if(cur_counter < 15)
                format(&ssd, 14-cur_counter, 'r', mode);
        }
        else
        {
            uint32_t cur_counter = counter_2;
            
            if(cur_counter < 2)
                format(&ssd, 1-cur_counter, 'y', mode);
            else if(cur_counter < 4)
                format(&ssd, 3-cur_counter, ' ', mode);
        }
        ssd1306_send_data(&ssd);                           // Atualiza o display
        delay(100,mode);
    }
}