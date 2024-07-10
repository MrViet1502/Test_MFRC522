// #include "global.h"

// bool isCardRegistered(byte *uid) // function check card is registered
// {

//     for (int i = 0; i < cardCount; i++)
//     {
//         bool match = true;
//         for (int j = 0; j < 4; j++)
//         {
//             if (registeredCards[i].uid[j] != uid[j])
//             {
//                 match = false;
//                 break;
//             }
//         }
//         if (match)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void storeCard(MFRC522::Uid uid) // function store card
// {
//     buzzerBeep(3, 500);
//     // loadCardsFromEEPROM();
//     if (cardCount < MAX_CARDS)
//     {
//         for (int i = 0; i < 4; i++)
//         {
//             registeredCards[cardCount].uid[i] = uid.uidByte[i];
//         }
//         cardCount++;
//         Serial.print("New Card UID:");
//         for (byte i = 0; i < uid.size; i++)
//         {
//             Serial.print(registeredCards[cardCount - 1].uid[i] < 0x10 ? " 0" : " ");
//             Serial.print(registeredCards[cardCount - 1].uid[i], HEX);
//         }

//         saveCardsToEEPROM();
//         Serial.println();
//     }
// }

// bool removeCard(byte *uid) // function remove card
// {
//     // loadCardsFromEEPROM();
//     for (int i = 1; i < cardCount; i++)
//     {
//         bool match = true;
//         for (int j = 0; j < 4; j++)
//         {
//             if (registeredCards[i].uid[j] != uid[j])
//             {
//                 match = false;
//                 break;
//             }
//         }
//         if (match)
//         {
//             // Move the remaining cards up to fill the empty space
//             for (int k = i; k < cardCount - 1; k++)
//             {
//                 for (int j = 0; j < 4; j++)
//                 {
//                     registeredCards[k].uid[j] = registeredCards[k + 1].uid[j];
//                 }
//             }
//             cardCount--;
//             Serial.print("Card UID removed:");
//             for (byte i = 0; i < 4; i++)
//             {
//                 Serial.print(uid[i] < 0x10 ? " 0" : " ");
//                 Serial.print(uid[i], HEX);
//             }
//             saveCardsToEEPROM();
//             Serial.println();
//             return true;
//         }
//     }
//     return false;
// }

// void removeAll()
// {

//     cardCount = 1;
//     for (int i = 1; i < MAX_CARDS; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             registeredCards[i].uid[j] = 0;
//         }
//     }
//     saveCardsToEEPROM();
//     Serial.println("All cards removed");
// }

// bool isMasterCard(byte *uid)
// {
//     for (int j = 0; j < 4; j++)
//     {
//         if (registeredCards[0].uid[j] != uid[j])
//         {
//             return false;
//         }
//     }
//     return true;
// }

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
    buzzerBeep(1, 2000);
    // loadCardsFromEEPROM();
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

        saveCardsToEEPROM();
        Serial.println();
    }
}

bool removeCard(byte *uid) // function remove card
{
    // loadCardsFromEEPROM();
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
            saveCardsToEEPROM();
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
    saveCardsToEEPROM();
    Serial.println("All cards removed");
}