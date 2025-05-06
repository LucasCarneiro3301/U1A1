#include "tasks.h"

void vRGBTask()
{
    led_setup();
    
    while (true)
    {
        bool mode = flag;

        if(mode) 
        {
            gpio_put(RED, false);
            gpio_put(GREEN, true);
            if(!delay(7e3,mode)) continue;
            gpio_put(RED, true);
            if(!delay(2e3,mode)) continue;
            gpio_put(GREEN, false);
            if(!delay(6e3,mode)) continue;
        }
        else 
        {
            gpio_put(RED, true);
            gpio_put(GREEN, true);
            if(!delay(2e3,mode)) continue;
            gpio_put(RED, false);
            gpio_put(GREEN, false);
            if(!delay(2e3,mode)) continue;
        }
    }
}