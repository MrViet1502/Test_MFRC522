#include "global.h"

MFRC522 mfrc522(SS_PIN, RST_PIN);
bool isSetupMode = false;            // check state setup mode
unsigned long buttonPressTime = 0;   // check button press time
unsigned long buttonPressTime_R = 0; // check button release time
Card registeredCards[MAX_CARDS];     // save cards
// int cardMaster = 0;
int cardCount = 0;         // count number of cards
bool isRemoveAll = false;  // state remove all cards
bool check_millis = false; // on button.cpp , check millis() function

int btReadTime = 0; // time for read button: 4s to enable divice
int holdTime = 0;   // time for hold: 10s to use divice

bool check_BT_Read = false; // on relay.cpp , check state relay on/ of
bool hold_first_time = false;
bool holdHigh = false; // on relay.cpp , check state relay on/ of
bool check_controler = true;
bool masterCardConfirmed = false;
unsigned long lastSignalTime_hold = 0;
