#include "global.h"
#include <EEPROM.h>

void loadCardsFromEEPROM() // Load cards from EEPROM to array of cards
{
    int numCards = EEPROM.read(0); // Read number cards from EEPROM
    if (numCards > MAX_CARDS)
    {
        numCards = MAX_CARDS; // 
    }

    cardCount = numCards; // Cập nhật số lượng thẻ
    int address = 1;      // Địa chỉ bắt đầu lưu trữ UID

    for (int i = 0; i < numCards; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            registeredCards[i].uid[j] = EEPROM.read(address++); // Đọc từng byte UID từ EEPROM
        }
    }
}
void saveCardsToEEPROM() // save cards to EEPROM
{
    int numCards = cardCount;
    if (numCards > MAX_CARDS)
    {
        numCards = MAX_CARDS; // 
    }

    EEPROM.write(0, numCards); // Lưu số lượng thẻ vào EEPROM
    int address = 1;           // Địa chỉ bắt đầu lưu trữ UID

    for (int i = 0; i < numCards; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            EEPROM.write(address++, registeredCards[i].uid[j]); // Ghi từng byte UID vào EEPROM
        }
    }
}
