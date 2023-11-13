#include "Alarm/Alarm.hpp"
#include "Timer/Timer.hpp"
#include"EnhancedAlarm/EnhancedAlarm.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
    Alarm alarm1 (6, 40);
    Alarm alarm2(std::move(alarm1));

    alarm2.display();

    EnhancedAlarm eh1;
    eh1.display();

    Timer timer1(0,5);

    alarm1.setTime(10, 5);
    timer1.setTime(0, 5);

    alarm1.ring();
    timer1.ring();

    return 0;
}