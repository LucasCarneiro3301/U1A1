#include "tasks.h"

void vMATRIZTask() 
{
    ws2812_setup(pio, sm);
    
    while (true)
    {
        bool mode = flag;

        if(mode) 
        {
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.0,0.03,0.0,1,false,true);
                if(!delay(700,mode)) continue;
            }

            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.03,0.03,0.0,2,false,true);
                if(!delay(200,mode)) continue;
            }

            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.03,0.0,0.0,3,false,true);
                if(!delay(600,mode)) continue;
            }
        }
        else 
        {
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.03,0.03,0.0,2,false,true);
                if(!delay(200,mode)) continue;
            }
            
            for(int i = 0; i < 10; i++) {
                ws2812_draw_column(0.0,0.0,0.0,2,false,true);
                if(!delay(200,mode)) continue;
            }
        }
    }
}