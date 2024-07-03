#include "global.h"

bool isCardRegistered(byte *uid) // function check card is registered
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

void storeCard(MFRC522::Uid uid) // function store card
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

bool removeCard(byte *uid) // function remove card
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
            // Move the remaining cards up to fill the empty space
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

void removeAll()
{
    cardCount = 0;
    for (int i = 0; i < MAX_CARDS; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            registeredCards[i].uid[j] = 0;
        }
    }
    Serial.println("All cards removed");
}