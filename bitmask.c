#include <stdio.h>
#include <stdint.h>
#include <time.h>

uint8_t PORT_A = 0x00;

typedef enum{
    GPIO_PIN_0 = 0x01,
    GPIO_PIN_1 = 0x01 << 1,
    GPIO_PIN_2 = 0x01 << 2,
    GPIO_PIN_3 = 0x01 << 3,
    GPIO_PIN_4 = 0x01 << 4,
    GPIO_PIN_5 = 0x01 << 5,
    GPIO_PIN_6 = 0x01 << 6,
    GPIO_PIN_7 = 0x01 << 7,
    GPIO_PIN_8 = 0x01 << 8
}GPIO_PIN;

typedef enum{
    LOW,
    HIGH
}STATUS;


void digitalWrite(GPIO_PIN PIN, STATUS STATE){
    if(STATE)
    {
        PORT_A |= PIN;
    }
    else
    {
        PORT_A ^= PIN;
    }
}


void blinkLED(GPIO_PIN PIN){
    PORT_A = PORT_A ^ PIN;
}




void delay(int time){
    clock_t start, end;
    start = clock();
    while (clock() - start <= time);
    end = clock();
  
}

int main(int argc, char const *argv[])
{
    digitalWrite(GPIO_PIN_0, HIGH);
    printf("%d\n", PORT_A);
    digitalWrite(GPIO_PIN_0, LOW);
    printf("%d\n", PORT_A);
    digitalWrite(GPIO_PIN_1, HIGH);
    printf("%d\n", PORT_A);
    digitalWrite(GPIO_PIN_1, LOW);
    printf("%d\n", PORT_A);
    blinkLED(GPIO_PIN_0);
    printf("%d\n", PORT_A);
    delay(10);
    blinkLED(GPIO_PIN_0);
    printf("%d\n", PORT_A);
    delay(10);
    return 0;
}