#ifndef CARD_H
#define CARD_H

#include "global.h"

bool isCardRegistered(byte *uid);
void storeCard(MFRC522::Uid uid);
bool removeCard(byte *uid);
void removeAll();
#endif // CARD_H
