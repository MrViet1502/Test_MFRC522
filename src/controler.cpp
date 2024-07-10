#include "global.h"

void toggleControl()
{
    if (check_controler)
    {
        digitalWrite(CONTROLER_PIN, HIGH);
        buzzerBeep(1, 1000);
        check_controler = false;
    }
    else
    {
        digitalWrite(CONTROLER_PIN, LOW);
        //digitalWrite(HOLD_PIN, LOW);
        buzzerBeep(1, 1000);
        check_controler = true;
        // holdHigh = false; // hold is low
        // holdTime = 0;     // reset holdTime
    }
}