#include "global.h"

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Lectura del UID");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(HOLD_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(READ_CONTROLER_PIN, INPUT_PULLUP);
  pinMode(CONTROLER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Nút nhấn sử dụng điện trở kéo lên nội bộ
  pinMode(BUTTON_READ_PIN, INPUT_PULLUP);
  digitalWrite(HOLD_PIN, LOW);    // Khởi tạo relay ở trạng thái tắt
  digitalWrite(BUZZER_PIN, HIGH); // Khởi tạo buzzer ở trạng thái tắt
  digitalWrite(CONTROLER_PIN, LOW);
  loadCardsFromEEPROM();
  lastSignalTime_hold = millis();
  // holdTime = millis();
}

void loop()
{

  // check_status_hold();
  checkButtonRForOpen(); // check button R for open

  if (isHoldForOpen()) // check button_read in 4s
  {
    if (!hold_first_time)
    {
      toggleHold();
    }
    }
  checkButtonForSetupMode(); // check call setup mode

  if (isSetupModeActive())
  {

    handleSetupMode(); // case setup mode
  }
  else
  {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) // check and read new card
    {
      Serial.print("Card UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++)
      {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
      }
      Serial.println();
      mfrc522.PICC_HaltA();

      if (isCardRegistered(mfrc522.uid.uidByte)) // if real card then relay on
      {
        toggleControl(); // on/off relay
      }
      else
      {
        Serial.println("Unauthorized card.");
      }
    }
  }

  if (holdHigh && !isSetupModeActive() && over10s()) // over 10s (holdHigh = 1 and isSetupModeActive = 0) -> off
  {
    toggleHold(); // on/off Hold
  }
}
//============================================================================
//============================================================================

//  Blue and white of relay//
// red and black big VCC(48V) - GND//

//====//
// yellow -> TX
//  green -> RX
//  black -> GND
// gray of  PIN RESET
// white of Button