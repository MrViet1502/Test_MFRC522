#ifndef GLOBAL_H
#define GLOBAL_H

#include <MFRC522.h>

// Pin definitions
#define RST_PIN 9
#define SS_PIN 10    // Pin 10 trên Arduino Mini
#define RELAY_PIN 7  // Pin 7 trên Arduino Mini cho relay
#define BUZZER_PIN 8 // Pin 8 trên Arduino Mini cho buzzer
#define BUTTON_PIN 6 // Pin 6 trên Arduino Mini cho nút nhấn
#define LED_BUILTIN 13
extern MFRC522 mfrc522;
extern bool isSetupMode;
extern unsigned long buttonPressTime;

struct Card
{
    byte uid[4];
};

#define MAX_CARDS 10 // Số lượng thẻ tối đa có thể lưu
extern Card registeredCards[MAX_CARDS];
extern int cardCount;

#endif // GLOBAL_H
