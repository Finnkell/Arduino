# Projeto do Ventilador

O objetivo deste projeto é simular um ventilador de teto. O motor deve rodar de acordo com a porcentagem do potenciômetro.

## Montagem 

Os tópicos a seguir estão relacionados ao processo de montagem do projeto.

### Materiais necessários

|    Componente   | Quantidade |
|:---------------:|:----------:|
|   Arduino UNO   |      1     |
| Placa de ensaio |      1     |
|  Potenciômetro  |      1     |
|    Motor CC     |      1     |
|      Jumper     |      7     |

A quantidade de jumpers necessários pode variar de acordo com a forma de montagem.

### Esquema de montagem

![Esquema de montagem](imagens/esquema-de-montagem.png)

| Componente  | Porta do componente | Porta do Arduino |
|:----------: |:-------------------:|:----------------:|
|  Motor CC   |      Terminal 1     |        GND       |
|             |      Terminal 2     |         5        |
|potenciômetro|      Terminal 1     |        GND       |
|             |      Terminal 2     |        5V        |
|             |       Limpador      |        A5        |


## Código 

Os tópicos a seguir estão relacionados ao código do projeto.

### Código em Scratch

![Código em Scratch](imagens/codigo-scratch.png)

### Dependências

Não foram usadas bibliotecas nesse projeto.