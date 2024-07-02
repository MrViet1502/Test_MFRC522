#include "blink.h"

void blinkLed(int times, int duration) // test function blink led pin 13 or on board
{
    pinMode(13, OUTPUT); // Đặt chân 13 là OUTPUT
    for (int i = 0; i < times; i++)
    {
        digitalWrite(13, HIGH);
        delay(duration);
        digitalWrite(13, LOW);
        delay(duration);
    }
}
