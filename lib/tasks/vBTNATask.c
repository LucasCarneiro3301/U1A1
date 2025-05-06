#include "tasks.h"

volatile uint32_t last_time = 0;
int flag = true;

void vBTNATask() {
    btn_setup();

    while (true)
    {
        uint32_t current_time = to_us_since_boot(get_absolute_time());	// Obtém o tempo atual em microssegundos

        if (current_time - last_time > 2e5 && !gpio_get(BTNA)) {	// 200 ms de debouncing
            last_time = current_time;
            flag = !flag;
        }
    }
}