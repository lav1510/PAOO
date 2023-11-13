#include "Alarm/Alarm.hpp"
#include "AlarmList/AlarmList.hpp"
#include "Timer/Timer.hpp"
#include"EnhancedAlarm/EnhancedAlarm.hpp"
#include"EnhancedAlarm/EnhancedAlarm.cpp"
#include <iostream>



int main(int argc, char* argv[])
{

    EnhancedAlarms::EnhancedAlarm<int> eh1;
    eh1.setSound(1);
    eh1.display();

    EnhancedAlarms::EnhancedAlarm<std::string> eh2;
    eh2.setSound("BUZZ");
    eh2.display();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    auto alarm1 = std::make_shared<Alarms::Alarm>(8, 0);
    auto alarm2 = std::make_unique<Alarms::Alarm>(12, 30);
    auto alarm3 = std::make_unique<Alarms::Alarm>(18, 0);

    AlarmLists::AlarmList alarmList;

    alarmList.addFirstAlarm(alarm1, alarm2);
    alarmList.addAlarm(alarm3);

    alarmList.displayAll();

    return 0;
}