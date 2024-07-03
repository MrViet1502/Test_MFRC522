#include "global.h"

void handleSetupMode() // function when call setup mode
{
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
        // check and read new card

        if (!isCardRegistered(mfrc522.uid.uidByte))
        {
            storeCard(mfrc522.uid); // insert card
            mfrc522.PICC_HaltA();
            Serial.println("Card stored. Press the button to exit setup mode.");
        }
        else
        {
            if (removeCard(mfrc522.uid.uidByte))
                mfrc522.PICC_HaltA(); // remove card
        }
    }

    checkButtonRemoveAll();

    if (digitalRead(BUTTON_PIN) == LOW && buttonPressTime == 0) // Setup mode ends when the button is pressed again
    {
        delay(100); // Debounce delay
        while (digitalRead(BUTTON_PIN) == LOW)
        {
        } // Chờ nút được thả ra
        isSetupMode = false;
        Serial.println("Exiting setup mode...");
        buzzerBeep(2, 1000); // Buzzer kêu 2 lần
    }

    if (isRemoveAll)
    {
        removeAll();
        isSetupMode = false;
        isRemoveAll = false;
        Serial.println("All cards removed successfully!");
    }
}
