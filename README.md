# U1A1
Implementação de um semáforo inteligente com dois modos de operação (normal e noturno) usando apenas tarefas do FreeRTOS, sem filas, semáforos ou mutexes.

__Aluno:__
Lucas Carneiro de Araújo Lima

## ATIVIDADE 

__Para este trabalho, os seguintes componentes e ferramentas se fazem necessários:__
1) Microcontrolador Raspberry Pi Pico W.
2) Ambiente de trabalho VSCode.
3) LEDs RGB.
4) _Display_ SSD1306.
5) 1 Botão Pull-Up.
7) Ferramenta educacional BitDogLab.
8) Matriz de LEDs 5x5.

__O resultado do projeto pode ser assistido através deste link: [Vídeo de Apresentação - Semáforo Inteligente.]().__

## Instruções de Uso

### 1. Clone o repositório
Abra o terminal e execute o comando abaixo para clonar o repositório em sua máquina:
```bash
git clone https://github.com/LucasCarneiro3301/U1A1.git
```

### 2. Configure o ambiente de desenvolvimento
Certifique-se de que o [SDK do Raspberry Pi Pico](https://github.com/raspberrypi/pico-sdk) esteja instalado e configurado corretamente no seu sistema.

### 3. Instale o CMake
Certifique-se de que o [CMake](https://cmake.org/download/) esteja instalado e configurado corretamente no seu sistema.

### 4. Clone o repositório do FreeRTOS
Certifique-se de clonar o repositório do FreeRTOS. Repositório: [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel.git).

### 5. Conexão com a Rapberry Pico
1. Conecte o Raspberry Pi Pico ao seu computador via USB.
2. Inicie o modo de gravação pressionando o botão **BOOTSEL** e **RESTART**.
3. O Pico será montado como um dispositivo de armazenamento USB.
4. Execute através do comando **RUN** a fim de copiar o arquivo `U1A1.uf2` para o Pico.
5. O Pico reiniciará automaticamente e executará o programa.

### 6. Observações (IMPORTANTE !!!)
2. Manuseie a placa com cuidado.

## Recursos e Funcionalidades

### 1. Botão

| BOTÃO                            | DESCRIÇÃO                                     | 
|:----------------------------------:|:---------------------------------------------:|
| A                                  | Alterna entre modos de operação              | 

### 2. Display OLED
Exibe informações sobre a cor atual do semáforo, modo de operação atual e tempo restante.

### 3. Matriz de LEDs (5x5)
Representa visualmente em colunas coloridas a cor atual do semáforo. 

### 4. Buzzer
Emite sinal sonoro correspondente a cada etapa do semáforo.

### 5. Tasks e FreeRTOS
Modulariza o programa em subprogramas chamados de tasks. Cada task é responsável por uma função de um componente do BitDogLabb



