#include "tasks.h"

void vBUZZTask() {
    while(true) 
    {
        bool mode = flag;

        if(mode) {
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

            for (int i = 0; i < 6; i++) {
                play_buzzer(LA);
                if(!delay(100, mode)) continue;
                pwm_set_gpio_level(BUZZER, 0);
                if(!delay((i==5)?900:100, mode)) continue;
            }

            for(int i = 0; i < 3; i++) {
                play_buzzer(SOL);
                if(!delay(500,mode)) continue;
                pwm_set_gpio_level(BUZZER, 0);
                if(!delay(1.5e3,mode)) continue;
            }
        }
        else 
        {
            pwm_set_gpio_level(BUZZER, LA_BAIXO);
            if(!delay(2e3,mode)) continue;
            pwm_set_gpio_level(BUZZER, 0);
            if(!delay(2e3,mode)) continue;
        }
    }

}