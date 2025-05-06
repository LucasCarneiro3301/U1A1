#include "tasks.h"

volatile uint32_t last_time = 0;
int flag = true;

/*
 * Função vBTNATask:
 * -----------------
 * Esta é uma tarefa do FreeRTOS responsável por monitorar o botão BTNA. 
 * Ela alterna o estado de uma variável global `flag` sempre que o botão é pressionado.
 * 
 * Para evitar múltiplas leituras indesejadas causadas por ruído mecânico do botão 
 * (efeito "bouncing"), é implementado um sistema de debounce por tempo — o botão só será 
 * considerado pressionado se passaram mais de 200 ms desde a última mudança.
 */
void vBTNATask() {
    btn_setup();    // Inicializa e configura o botão como entrada

    while (true)
    {
        uint32_t current_time = to_us_since_boot(get_absolute_time());	// Obtém o tempo atual em microssegundos

        if (current_time - last_time > 2e5 && !gpio_get(BTNA)) {	// 200 ms de debouncing
            last_time = current_time;
            flag = !flag;
        }
    }
}