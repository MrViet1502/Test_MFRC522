
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include "buzzer.h"
#include "card.h"
#include "setup_mode.h"
#include "button.h"
#include "global.h"
#include "blink.h"

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Lectura del UID");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Nút nhấn sử dụng điện trở kéo lên nội bộ
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, HIGH); // Khởi tạo relay ở trạng thái tắt
}

void loop()
{

  checkButtonForSetupMode();

  if (isSetupModeActive())
  {
    handleSetupMode();
  }
  else
  {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
      Serial.print("Card UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++)
      {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
      }
      Serial.println();
      mfrc522.PICC_HaltA();

      if (isCardRegistered(mfrc522.uid.uidByte))
      {
        if (digitalRead(RELAY_PIN) == LOW)
        {
          digitalWrite(RELAY_PIN, HIGH);
          buzzerBeep(1, 1000);
        }
        else
        {
          buzzerBeep(1, 1000);
          digitalWrite(RELAY_PIN, LOW);
        }
      }
      else
      {
        Serial.println("Unauthorized card.");
      }
    }
  }
}

// #include <Arduino.h>
// #include <SPI.h>
// #include <MFRC522.h>

// #define RST_PIN 9
// #define SS_PIN 10    // Pin 10 trên Arduino Mini
// #define RELAY_PIN 7  // Pin 7 trên Arduino Mini cho relay
// #define BUZZER_PIN 8 // Pin 8 trên Arduino Mini cho buzzer
// #define BUTTON_PIN 6 // Pin 6 trên Arduino Mini cho nút nhấn

// MFRC522 mfrc522(SS_PIN, RST_PIN);

// bool isSetupMode = false;                         // Biến để theo dõi trạng thái chế độ cài đặt
// unsigned long buttonPressTime = 0;                // Biến để theo dõi thời gian nhấn nút
// byte masterCardUID[4] = {0x00, 0x00, 0x00, 0x00}; // Mảng để lưu UID của thẻ đã đăng ký

// struct Card
// {
//   byte uid[4];
// };

// #define MAX_CARDS 10 // Số lượng thẻ tối đa có thể lưu
// Card registeredCards[MAX_CARDS];
// int cardCount = 0; // Số lượng thẻ đã lưu

// bool isCardRegistered(byte *uid)
// {
//   for (int i = 0; i < cardCount; i++)
//   {
//     bool match = true;
//     for (int j = 0; j < 4; j++)
//     {
//       if (registeredCards[i].uid[j] != uid[j])
//       {
//         match = false;
//         break;
//       }
//     }
//     if (match)
//     {
//       return true;
//     }
//   }
//   return false;
// }

// void buzzerBeep(int times, int duration) // Điều khiển thời gian loa buzzer kêu số lần , bao nhiêu s
// {
//   for (int i = 0; i < times; i++)
//   {
//     digitalWrite(BUZZER_PIN, HIGH);
//     delay(duration);
//     digitalWrite(BUZZER_PIN, LOW);
//     delay(200); // Độ trễ giữa các tiếng kêu
//   }
// }
// void setup()
// {
//   Serial.begin(9600);
//   SPI.begin();
//   mfrc522.PCD_Init();
//   Serial.println("Lectura del UID");
//   pinMode(LED_BUILTIN, OUTPUT);
//   pinMode(RELAY_PIN, OUTPUT);
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(BUTTON_PIN, INPUT_PULLUP); // Nút nhấn sử dụng điện trở kéo lên nội bộ
//   digitalWrite(RELAY_PIN, LOW);      // Khởi tạo relay ở trạng thái tắt
// }

// void loop()
// {
//   if (digitalRead(BUTTON_PIN) == LOW)
//   {
//     if (buttonPressTime == 0)
//     {
//       buttonPressTime = millis();
//     }
//     if (millis() - buttonPressTime >= 3000 && !isSetupMode)
//     {
//       isSetupMode = true;
//       Serial.println("Entering setup mode...");
//       buzzerBeep(3, 1000); // Buzzer kêu 3 lần mỗi lần 1s
//     }
//   }
//   else
//   {
//     buttonPressTime = 0;
//   }

//   if (isSetupMode)
//   {
//     if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
//     {
//       if (!isCardRegistered(mfrc522.uid.uidByte) && cardCount < MAX_CARDS)
//       {
//         for (int i = 0; i < 4; i++)
//         {
//           registeredCards[cardCount].uid[i] = mfrc522.uid.uidByte[i];
//         }
//         cardCount++;
//         Serial.print("New Card UID:");
//         for (byte i = 0; i < mfrc522.uid.size; i++)
//         {
//           Serial.print(registeredCards[cardCount - 1].uid[i] < 0x10 ? " 0" : " ");
//           Serial.print(registeredCards[cardCount - 1].uid[i], HEX);
//         }
//         Serial.println();
//         mfrc522.PICC_HaltA();
//         Serial.println("Card stored. Press the button to exit setup mode.");
//       }
//       else
//       {
//         Serial.println("Card is already registered or memory is full.");
//       }
//     }
//     if (digitalRead(BUTTON_PIN) == LOW && buttonPressTime == 0)
//     {
//       delay(100); // Debounce delay
//       while (digitalRead(BUTTON_PIN) == LOW)
//       {
//       } // Chờ nút được thả ra
//       isSetupMode = false;
//       Serial.println("Exiting setup mode...");
//       buzzerBeep(2, 1000); // Buzzer kêu 2 lần
//     }
//   }
//   else
//   {
//     if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
//     {
//       Serial.print("Card UID:");
//       for (byte i = 0; i < mfrc522.uid.size; i++)
//       {
//         Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//         Serial.print(mfrc522.uid.uidByte[i], HEX);
//       }
//       Serial.println();
//       mfrc522.PICC_HaltA();

//       if (isCardRegistered(mfrc522.uid.uidByte))
//       {
//         if (digitalRead(RELAY_PIN) == LOW)
//         {
//           digitalWrite(RELAY_PIN, HIGH);
//           buzzerBeep(1, 1000);
//         }
//         else
//         {
//           buzzerBeep(1, 1000);
//           digitalWrite(RELAY_PIN, LOW);
//         }
//       }
//       else
//       {
//         Serial.println("Unauthorized card.");
//       }
//     }
//   }
// }
