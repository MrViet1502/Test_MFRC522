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

void checkButtonRemoveAll()
{
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        if (buttonPressTime == 0)
        {
            buttonPressTime = millis();
            check_millis = true;
        }

        if (millis() - buttonPressTime >= 8000 && isSetupMode)
        {
            isRemoveAll = true;
            check_millis = false;
            Serial.println("Entering remove all...");
            buzzerBeep(4, 500); // Buzzer sounds 3 times for 1 second each time
        }
        if (check_millis)
        {
            buttonPressTime = 0;
            check_millis = false;
        }
    }
    else
    {
        buttonPressTime = 0;
    }
}