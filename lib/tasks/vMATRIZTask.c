#include "tasks.h"

// Implementa a rotina da matriz de LEDs
void vMATRIZTask() 
{
    ws2812_setup(pio, sm);  // Inicializa e configura a matriz de LEDs
    
    while (true)
    {
        bool mode = flag;

        if(mode)  // Modo Normal
        {
            // Coluna 1 Verde
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.0,0.03,0.0,1,false,true);
                if(!delay(700,mode)) continue;
            }

            // Coluna 2 Amarelo
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.03,0.03,0.0,2,false,true);
                if(!delay(200,mode)) continue;
            }

            // Coluna 3 Vermelho
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.03,0.0,0.0,3,false,true);
                if(!delay(600,mode)) continue;
            }
        }
        else    // Modo Noturno
        {
            // Coluna 2 Amarelo
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.03,0.03,0.0,2,false,true);
                if(!delay(200,mode)) continue;
            }
            
            // Coluna 2 apagada
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.0,0.0,0.0,2,false,true);
                if(!delay(200,mode)) continue;
            }
        }
    }
}