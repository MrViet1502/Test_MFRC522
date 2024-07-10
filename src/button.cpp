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

// button R
bool isHoldForOpen() // check button in 10s
{
    return check_BT_Read;
}

void checkButtonRForOpen() // check button in 4s
{
    if (digitalRead(BUTTON_READ_PIN) == LOW)
    {
        if (buttonPressTime_R == 0)
        {
            buttonPressTime_R = millis();
        }
        if (millis() - buttonPressTime_R >= 2000)
        {
            buttonPressTime_R = 0;
            check_BT_Read = true;
            Serial.println("Opening door...");
            buzzerBeep(1, 2000); // one time beep for 2 seconds
        }
    }
    else
    {
        buttonPressTime_R = 0;
    }
}