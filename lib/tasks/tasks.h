/*
	Lucas Carneiro de Araújo Lima
*/

#ifndef TASKS_H
#define TASKS_H


#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include <stdio.h>
#include "../config/config.h"
#include "../ws2812/ws2812.h"

extern volatile uint32_t last_time;
extern volatile uint32_t current_time_ms;
extern volatile uint32_t mode_start_time_ms;
extern int flag;
extern volatile uint32_t counter_1;
extern volatile uint32_t counter_2;

// Frequências das notas musicais (em Hz)
enum Notes {
    DO = 2640, // Dó
    RE = 2970, // Ré
    MI = 3300, // Mi
    FA = 3520, // Fá
    SOL = 3960, // Sol
    LA = 4400, // Lá
    SI = 4950,  // Si
    DO_ALTO = 5280,  // Dó uma oitava acima (C5)
    LA_BAIXO = 880
};

bool delay(uint32_t total_delay_ms, bool mode);
void timer_setup();
void set_buzzer_frequency(uint frequency);
void play_buzzer(uint frequency);
void vBTNATask();
void vBUZZTask();
void vRGBTask();
void vDISPLAYTask();
void vMATRIZTask();

#endif