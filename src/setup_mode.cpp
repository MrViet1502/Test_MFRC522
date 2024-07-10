// #include "global.h"

// void handleSetupMode() // function when call setup mode
// {

//     if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() && cardCount == 0)
//     {

//         storeCard(mfrc522.uid);
//         buzzerBeep(2, 500);
//         mfrc522.PICC_HaltA();
//     }

//     if (!masterCardConfirmed) // Chưa xác nhận thẻ master
//     {
//         if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
//         {
//             // check and read new card
//             if (isMasterCard(mfrc522.uid.uidByte))
//             {
//                 masterCardConfirmed = true;
//                 buzzerBeep(1, 1000); // Buzzer kêu 1 bip
//                 mfrc522.PICC_HaltA();
//                 Serial.println("Master card confirmed. You can now add or remove cards.");
//             }
//             else
//             {
//                 buzzerBeep(1, 3000); // Buzzer kêu hồi chuông 3s
//                 mfrc522.PICC_HaltA();
//                 Serial.println("Unauthorized card. Exiting setup mode...");
//                 isSetupMode = false;
//             }
//         }
//     }
//     else // Đã xác nhận thẻ master
//     {
//         if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
//         {
//             if (!isCardRegistered(mfrc522.uid.uidByte))
//             {
//                 storeCard(mfrc522.uid); // insert card
//                 mfrc522.PICC_HaltA();
//                 Serial.println("Card stored. Press the button to exit setup mode.");
//             }
//             else
//             {
//                 if (removeCard(mfrc522.uid.uidByte))
//                 {
//                     mfrc522.PICC_HaltA(); // remove card
//                     Serial.println("Card removed. Press the button to exit setup mode.");
//                 }
//             }
//         }

//         checkButtonRemoveAll();

//         if (digitalRead(BUTTON_PIN) == LOW && buttonPressTime == 0) // Setup mode ends when the button is pressed again
//         {
//             delay(100); // Debounce delay
//             while (digitalRead(BUTTON_PIN) == LOW)
//             {
//             } // Chờ nút được thả ra
//             isSetupMode = false;
//             masterCardConfirmed = false; // Reset trạng thái xác nhận thẻ master
//             Serial.println("Exiting setup mode...");
//             buzzerBeep(2, 1000); // Buzzer kêu 2 lần
//         }

//         if (isRemoveAll)
//         {
//             removeAll();
//             isSetupMode = false;
//             isRemoveAll = false;
//             masterCardConfirmed = false; // Reset trạng thái xác nhận thẻ master
//             Serial.println("All cards removed successfully!");
//         }
//     }

//     /// =================================================================
// }

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
