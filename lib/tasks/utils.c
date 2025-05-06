#include "tasks.h"

volatile uint32_t current_time_ms = 0;
volatile uint32_t mode_start_time_ms = 0;
volatile uint32_t counter_1 = 0;
volatile uint32_t counter_2 = 0;

bool delay(uint32_t total_delay_ms, bool mode) {
    uint32_t start_time = current_time_ms;  // Tempo de início
    while ((current_time_ms - start_time) < total_delay_ms) {
        current_time_ms = to_ms_since_boot(get_absolute_time());  // Atualiza o tempo atual em milissegundos
        
        uint32_t elapsed = current_time_ms - mode_start_time_ms;
        counter_1 = ((int) elapsed/1000) % 15;
        counter_2 = ((int) elapsed/1000) % 4;
        if (flag != mode) {
            mode_start_time_ms = current_time_ms;  // reseta tempo do novo modo
            return false;  // Se o modo mudar, sai da função
        }
    }
    return true;  // Retorna true se o delay foi completado
}

// Configura o PWM no pino do buzzer com uma frequência especificada
void set_buzzer_frequency(uint frequency) {
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (frequency * 4096));
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(BUZZER, 0);
}

// Função para tocar o buzzer por um tempo especificado (em milissegundos)
void play_buzzer(uint frequency) {
    set_buzzer_frequency(frequency);
    pwm_set_gpio_level(BUZZER, 32768);
}
