#include "global.h"

void blinkLed(int times, int duration) // test function blink led pin 13 or on board
{
    pinMode(LED_BUILTIN, OUTPUT); // Đặt chân 13 là OUTPUT
    for (int i = 0; i < times; i++)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(duration);
        digitalWrite(LED_BUILTIN, LOW);
        delay(duration);
    }
}
