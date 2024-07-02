#include <Arduino.h>
#include <MFRC522.h>
#include "setup_mode.h"
#include "card.h"
#include "buzzer.h"
#include "global.h"

void handleSetupMode()
{
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
        if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
        {
            if (!isCardRegistered(mfrc522.uid.uidByte))
            {
                storeCard(mfrc522.uid); // insert card

                Serial.println("Card stored. Press the button to exit setup mode.");
            }
            else
            {
                if (removeCard(mfrc522.uid.uidByte)) // remove card
                    Serial.println("Card remove complete!!!");
            }
            mfrc522.PICC_HaltA();
        }
    }

    if (digitalRead(BUTTON_PIN) == LOW && buttonPressTime == 0)
    {
        delay(100); // Debounce delay
        while (digitalRead(BUTTON_PIN) == LOW)
        {
        } // Chờ nút được thả ra
        isSetupMode = false;
        Serial.println("Exiting setup mode...");
        buzzerBeep(2, 1000); // Buzzer kêu 2 lần
    }
}
