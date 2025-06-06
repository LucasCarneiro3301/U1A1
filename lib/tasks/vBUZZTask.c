#include "tasks.h"

/*
 Tarefa responsável por controlar o buzzer de acordo com o modo de operação
*/
void vBUZZTask() {
    while(true) 
    {
        bool mode = flag;

        if(mode)    // Modo Normal
        {
            // Pequeno jingle MI SOL DO para sinal verde
            for (int i = 0; i < 3; i++) {
                play_buzzer(MI);
                if (!delay(100, mode)) continue;
                play_buzzer(SOL);
                if (!delay(100, mode)) continue;
                play_buzzer(DO_ALTO);
                if (!delay((i==2)?200:100, mode)) continue;
            }               
            pwm_set_gpio_level(BUZZER, 0);
            if(!delay(6e3,mode)) continue;

            // Beep intermitente para sinal amarelo
            for (int i = 0; i < 6; i++) {
                play_buzzer(LA);
                if(!delay(100, mode)) continue;
                pwm_set_gpio_level(BUZZER, 0);
                if(!delay((i==5)?900:100, mode)) continue;
            }

            // Beep para sinal vermelho
            for(int i = 0; i < 3; i++) {
                play_buzzer(SOL);
                if(!delay(500,mode)) continue;
                pwm_set_gpio_level(BUZZER, 0);
                if(!delay(1.5e3,mode)) continue;
            }
        }
        else // Modo Noturno
        {
            // Beep longo
            pwm_set_gpio_level(BUZZER, LA_BAIXO);
            if(!delay(2e3,mode)) continue;
            pwm_set_gpio_level(BUZZER, 0);
            if(!delay(2e3,mode)) continue;
        }
    }

}