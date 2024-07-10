#include "global.h"

bool over10s()
{
    if (millis() - holdTime >= 30000)
    {
        return true;
    }
    else
        return false;
}

void toggleHold() // function to on/off relay
{
    if (check_BT_Read)
    {
        buzzerBeep(1, 1000);
        // check_BT_Read = false;
        holdHigh = true;     // hold is high
        holdTime = millis(); // begin time for hold
        hold_first_time = true;
        digitalWrite(HOLD_PIN, HIGH); // for next time Hold_PWR: off
    }
    else
    {
        buzzerBeep(1, 1000);
        // check_BT_Read = true;
        // holdHigh = false; // hold is low
        // holdTime = 0;
        // // check_BT_Read = false;       // reset holdTime
        digitalWrite(HOLD_PIN, LOW); // for next time Hold_PWR: on
    }
}

void check_status_hold()
{
    // Kiểm tra tín hiệu từ controller
    if (digitalRead(READ_CONTROLER_PIN) == HIGH)
    {
        lastSignalTime_hold = millis(); // Cập nhật thời gian nhận tín hiệu cuối cùng
    }

    // Kiểm tra nếu đã quá 3 phút không nhận được tín hiệu
    if (millis() - lastSignalTime_hold >= 120000)
    {
        digitalWrite(HOLD_PIN, LOW); // Tắt chân hold
        holdHigh = false;            // hold is low
        holdTime = 0;
    }
}