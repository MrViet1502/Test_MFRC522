#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include <MFRC522.h>
#include "blink.h"
#include "button.h"
#include "buzzer.h"
#include "card.h"
#include "setup_mode.h"
#include "relay.h"

// Pin definitions
#define RST_PIN 9
#define SS_PIN 10    // Pin 10 Arduino Mini
#define RELAY_PIN 7  // Pin 7 Arduino Mini relay
#define BUZZER_PIN 8 // Pin 8  Arduino Mini buzzer
#define BUTTON_PIN 6 // Pin 6 Arduino Mini button
#define LED_BUILTIN 13
extern MFRC522 mfrc522;
extern bool isSetupMode;
extern unsigned long buttonPressTime;
extern bool isRemoveAll;
struct Card
{
    byte uid[4];
};

#define MAX_CARDS 10 // max number of cards
extern Card registeredCards[MAX_CARDS];
extern int cardCount;
extern bool check_millis;
extern bool check_Relay;
#endif // GLOBAL_H
