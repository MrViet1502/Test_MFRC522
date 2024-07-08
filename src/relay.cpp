
#include "global.h"

void toggleRelay() // function to on/off relay
{
    if (check_Relay)
    {
        digitalWrite(RELAY_PIN, HIGH);
        buzzerBeep(1, 1000);
        check_Relay = false;
    }
    else
    {
        buzzerBeep(1, 1000);
        digitalWrite(RELAY_PIN, LOW);
        check_Relay = true;
    }
}
