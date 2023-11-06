#include "Alarm/Alarm.hpp"
#include "Timer/Timer.hpp"
#include"EnhancedAlarm/EnhancedAlarm.hpp"
#include <iostream>

namespace alarmMain {
    int minutes = 10;
    int hour = 7;
}

namespace timerMain {
    int minutes = 5;
    int hour = 0;
}

int main(int argc, char* argv[])
{
    Alarm alarm1 (6, 40);
    Alarm alarm2(std::move(alarm1));

    alarm2.display();

    EnhancedAlarm eh1;
    eh1.display();

    Timer timer1(0,5);

    alarm1.setTime(alarmMain::hour, alarmMain::minutes);
    timer1.setTime(timerMain::hour, timerMain::minutes);

    alarm1.ring();
    timer1.ring();

    return 0;
}