#include "Alarm/Alarm.hpp"
#include "Timer/Timer.hpp"
#include"EnhancedAlarm/EnhancedAlarm.hpp"
#include"EnhancedAlarm/EnhancedAlarm.cpp"
#include <iostream>

template class EnhancedAlarms::EnhancedAlarm<int>;

int main(int argc, char* argv[])
{

    EnhancedAlarms::EnhancedAlarm<int> eh1;
    eh1.setSound(1);
    eh1.display();

    EnhancedAlarms::EnhancedAlarm<std::string> eh2;
    eh2.setSound("BUZZ");
    eh2.display();

    Alarm alarm1(0,5);
    alarm1.ring();

    return 0;
}