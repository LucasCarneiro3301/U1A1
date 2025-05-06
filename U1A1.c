#include <stdio.h>
#include "lib/tasks/tasks.h"

int main()
{
    xTaskCreate(
        vMATRIZTask,                // Função da tarefa para controlar a matriz de LEDs
        "MATRIZ Task",              // Nome da tarefa (para fins de debug)
        configMINIMAL_STACK_SIZE,   // Tamanho da pilha (mínimo recomendado)
        NULL,                       // Parâmetro passado à tarefa (não usado aqui)
        tskIDLE_PRIORITY,           // Prioridade da tarefa (padrão/baixa)
        NULL                        // Ponteiro para armazenar handle da tarefa (não usado)
    );

    xTaskCreate(vRGBTask, "RGB Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);              // Controla os LEDs RGB
    xTaskCreate(vDISPLAYTask, "Cont Task Disp3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);   // Controla o display OLED
    xTaskCreate(vBTNATask, "BTNA Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);            // Monitora o botão de entrada
    xTaskCreate(vBUZZTask, "BUZZ Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);            // Controla o buzzer sonoro

    vTaskStartScheduler();  // Inicia o escalonador do FreeRTOS. A partir daqui as tarefas começam a rodar.

    panic_unsupported();    // Se o escalonador retornar (o que não deveria acontecer), entra em pânico
}
