#include "global.h"

MFRC522 mfrc522(SS_PIN, RST_PIN);
bool isSetupMode = false;          // check state setup mode
unsigned long buttonPressTime = 0; // check button press time
Card registeredCards[MAX_CARDS];   // save cards
int cardCount = 0;                 // count number of cards
bool isRemoveAll = false;          // state remove all cards
bool check_millis = false;         // on button.cpp , check millis() function
bool check_Relay = true;           // on relay.cpp , check state relay on/ of