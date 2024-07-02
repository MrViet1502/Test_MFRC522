#ifndef CARD_H
#define CARD_H

#include <MFRC522.h>

bool isCardRegistered(byte *uid);
void storeCard(MFRC522::Uid uid);
bool removeCard(byte *uid);
#endif // CARD_H
