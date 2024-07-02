#include <Arduino.h>
#include "buzzer.h"
#include "global.h"

void buzzerBeep(int times, int duration) // The buzzer function sounds times and duration seconds
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(BUZZER_PIN, LOW);
        delay(duration);
        digitalWrite(BUZZER_PIN, HIGH);
        delay(200); // Delay between calls
    }
}
