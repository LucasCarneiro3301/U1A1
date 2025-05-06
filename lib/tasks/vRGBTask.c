#include "tasks.h"

// Implementa semáforo no LED RGB
void vRGBTask()
{
    led_setup();    // Inicializa e configura os leds
    
    while (true)    
    {
        bool mode = flag;

        if(mode)    // Modo Normal
        {
            gpio_put(RED, false);
            gpio_put(GREEN, true);  // VERDE
            if(!delay(7e3,mode)) continue;
            gpio_put(RED, true);    // AMARELO
            if(!delay(2e3,mode)) continue;
            gpio_put(GREEN, false); // VERMELHO
            if(!delay(6e3,mode)) continue;
        }
        else 
        {
            gpio_put(RED, true);
            gpio_put(GREEN, true);  // AMARELO
            if(!delay(2e3,mode)) continue;
            gpio_put(RED, false);
            gpio_put(GREEN, false); // APAGADO
            if(!delay(2e3,mode)) continue;
        }
    }
}