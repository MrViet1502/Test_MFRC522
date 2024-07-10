#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include <MFRC522.h>
#include <EEPROM.h>
#include "blink.h"
#include "button.h"
#include "buzzer.h"
#include "card.h"
#include "setup_mode.h"
#include "save_eeprom.h"
#include "hold.h"
#include "controler.h"

// Pin definitions
#define RST_PIN 9
#define SS_PIN 10         // Pin 10 Arduino Mini
#define HOLD_PIN 7        // Pin 7 Arduino Mini relay
#define BUZZER_PIN 8      // Pin 8  Arduino Mini buzzer
#define BUTTON_PIN 6      // Pin 6 Arduino Mini button
#define BUTTON_READ_PIN 5 // Pin 5 Arduino Mini
#define LED_BUILTIN 13
#define CONTROLER_PIN 0
#define READ_CONTROLER_PIN 1
extern MFRC522 mfrc522;
extern bool isSetupMode;
extern unsigned long buttonPressTime;
extern unsigned long buttonPressTime_R;
extern bool isRemoveAll;
struct Card
{
    byte uid[4];
};

#define MAX_CARDS 5 // max number of cards
extern Card registeredCards[MAX_CARDS];
extern int cardCount;
extern bool check_millis;

extern bool check_BT_Read;
extern bool hold_first_time;
extern bool holdHigh;
extern int btReadTime;
extern int holdTime;
extern bool check_controler;
extern bool masterCardConfirmed; // Biến cờ để xác nhận thẻ master
// extern int cardMaster;
extern unsigned long lastSignalTime_hold;
#endif // GLOBAL_H
