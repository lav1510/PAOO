#pragma once

#include <cstring>
#include <iostream>
#include <memory>
#include "../Alarm/Alarm.hpp"

namespace AlarmLists{
    class AlarmList{ 

        std::shared_ptr<Alarms::Alarm> firstAlarm; 
        std::unique_ptr<Alarms::Alarm> crt;       

        public:
            void addFirstAlarm(const std::shared_ptr<Alarms::Alarm>& newAlarm, const std::unique_ptr<Alarms::Alarm>& newUniqueAlarm);
            void addAlarm(const std::unique_ptr<Alarms::Alarm>& newAlarm);
            void displayAll();
    };
}