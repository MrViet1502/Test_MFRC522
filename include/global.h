#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include <MFRC522.h>
<<<<<<< HEAD
#include <EEPROM.h>
=======
>>>>>>> e657ff699c87e41a4bb8cb35d83680436c940ffb
#include "blink.h"
#include "button.h"
#include "buzzer.h"
#include "card.h"
#include "setup_mode.h"
#include "relay.h"
<<<<<<< HEAD
#include "save_eeprom.h"
=======
>>>>>>> e657ff699c87e41a4bb8cb35d83680436c940ffb

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

<<<<<<< HEAD
#define MAX_CARDS 5 // max number of cards
=======
#define MAX_CARDS 10 // max number of cards
>>>>>>> e657ff699c87e41a4bb8cb35d83680436c940ffb
extern Card registeredCards[MAX_CARDS];
extern int cardCount;
extern bool check_millis;
extern bool check_Relay;
#endif // GLOBAL_H
