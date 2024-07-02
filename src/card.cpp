#include <Arduino.h>
#include "card.h"
#include "global.h"

bool isCardRegistered(byte *uid)
{
    for (int i = 0; i < cardCount; i++)
    {
        bool match = true;
        for (int j = 0; j < 4; j++)
        {
            if (registeredCards[i].uid[j] != uid[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return true;
        }
    }
    return false;
}

void storeCard(MFRC522::Uid uid)
{
    if (cardCount < MAX_CARDS)
    {
        for (int i = 0; i < 4; i++)
        {
            registeredCards[cardCount].uid[i] = uid.uidByte[i];
        }
        cardCount++;
        Serial.print("New Card UID:");
        for (byte i = 0; i < uid.size; i++)
        {
            Serial.print(registeredCards[cardCount - 1].uid[i] < 0x10 ? " 0" : " ");
            Serial.print(registeredCards[cardCount - 1].uid[i], HEX);
        }
        Serial.println();
    }
}

bool removeCard(byte *uid)
{
    for (int i = 0; i < cardCount; i++)
    {
        bool match = true;
        for (int j = 0; j < 4; j++)
        {
            if (registeredCards[i].uid[j] != uid[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            // Di chuyển các thẻ còn lại lên trên để lấp chỗ trống
            for (int k = i; k < cardCount - 1; k++)
            {
                for (int j = 0; j < 4; j++)
                {
                    registeredCards[k].uid[j] = registeredCards[k + 1].uid[j];
                }
            }
            cardCount--;
            Serial.print("Card UID removed:");
            for (byte i = 0; i < 4; i++)
            {
                Serial.print(uid[i] < 0x10 ? " 0" : " ");
                Serial.print(uid[i], HEX);
            }
            Serial.println();
            return true;
        }
    }
    return false;
}