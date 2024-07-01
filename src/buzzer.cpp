#include <Arduino.h>
#include "buzzer.h"
#include "global.h"

void buzzerBeep(int times, int duration)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(duration);
        digitalWrite(BUZZER_PIN, LOW);
        delay(200); // Độ trễ giữa các tiếng kêu
    }
}
