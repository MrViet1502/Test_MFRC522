#include <Arduino.h>
#include "button.h"
#include "buzzer.h"
#include "global.h"

bool isSetupModeActive()
{
    return isSetupMode;
}

void checkButtonForSetupMode()
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
            buzzerBeep(3, 1000); // Buzzer kêu 3 lần mỗi lần 1s
        }
    }
    else
    {
        buttonPressTime = 0;
    }
}
