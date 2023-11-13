#pragma once

#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include "../Alarm/Alarm.hpp"

namespace EnhancedAlarms{
    enum AlarmSound {
        BEEP,
        BUZZER,
        RADIO
    };

    template<typename T>
    class EnhancedAlarm : public Alarms::Alarm{
            std::shared_ptr<char> enhancedNote;
            T sound;
            bool activeOnWorkingDays;
            bool activeSnooze;
            int minutesSnooze;
            std::vector<int> activeDays; // 0 = Sunday, 1 = Monday, ..., 6 = Saturday

        public:
            EnhancedAlarm();
            EnhancedAlarm(int      hour, 
                int        minutes, 
                char       *note, 
                T          sound, 
                bool       isAlarmSet, 
                bool       activeOnWorkingDays, 
                bool       activeSnooze, 
                int        minutesSnooze
            );
            ~EnhancedAlarm();

            void setWorkingDays   (bool activeOnWorkingDays);
            void setSound         (const T& newSound);
            void setSnooze        (bool activeSnooze);
            void setMinutesSnooze (int minutesSnooze);

            bool       getWorkingDays   (); 
            bool       getSnooze        ();
            int        getMinutesSnooze ();

            void display();

            void addActiveDay(int day);
            bool isAlarmActive(int day);
    };
}