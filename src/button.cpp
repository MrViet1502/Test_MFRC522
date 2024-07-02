#include <Arduino.h>
#include "button.h"
#include "buzzer.h"
#include "global.h"

bool isSetupModeActive() // enter mode Setup
{
    return isSetupMode;
}

void checkButtonForSetupMode() // Check button is 3s
{
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        if (buttonPressTime == 0)
        {
            buttonPressTime = millis();
        }
        if (millis() - buttonPressTime >= 3000 && !isSetupMode)
        {
            isSetupMode = true;
            Serial.println("Entering setup mode...");
            buzzerBeep(3, 1000); // Buzzer sounds 3 times for 1 second each time
        }
    }
    else
    {
        buttonPressTime = 0;
    }
}
