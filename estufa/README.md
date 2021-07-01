# Estufa

O objetivo desse projeto é simular uma estufa com 2 leds, cada um representando uma tela da estufa (led ligado = tela aberta). As telas devem estar abertas se a temperatura na estufa for maior que 20ºC, uma deve aberta caso a temperatura esteja entre 10 e 20ºC e ambas devem estar fechadas caso a temperatura seja menor que 10ºC. 

## Componentes necessários

|    Componente   | Quantidade |
|:---------------:|:----------:|
|   Arduino UNO   |      1     |
| Placa de ensaio |      1     |
|      TMP36      |      1     |
|Resistor 220 ohms|      2     |
|       LED       |      2     |
|      Jumper     |      9     |

A quantidade de jumpers necessários pode variar de acordo com a forma de montagem.

## Esquema de montagem

![Esquema de montagem](imagens/esquema-de-montagem.png)

| Componente | Porta do componente | Porta do Arduino | Resistor |
|:----------:|:-------------------:|:----------------:|:--------:|
|    TMP36   |         Vout        |        A5        |          |
|            |         VCC         |        5V        |          |
|            |         GND         |        GND       |          |
|LED Vermelho|          +          |         8        | 220 ohms |
|            |          -          |        GND       |          |
| LED Verde  |          +          |         9        | 220 ohms |
|            |          -          |        GND       |          |

## Código em Scratch

![Código em Scratch](imagens/codigo-scratch.png)

## Dependências

*Não não há dependências neste projeto.*