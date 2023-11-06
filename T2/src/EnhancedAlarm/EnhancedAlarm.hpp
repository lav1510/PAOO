#include <cstring>
#include <iostream>
#include "../Alarm/Alarm.hpp"

enum AlarmSound {
    BEEP,
    BUZZER,
    RADIO
};

class EnhancedAlarm : public Alarm{
        AlarmSound sound;
        bool activeOnWorkingDays;
        bool activeSnooze;
        int minutesSnooze;

    public:
        EnhancedAlarm(int      hour, 
            int        minutes, 
            char       *note, 
            AlarmSound sound, 
            bool       isAlarmSet, 
            bool       activeOnWorkingDays, 
            bool       activeSnooze, 
            int        minutesSnooze
        );
        ~EnhancedAlarm();

        void setWorkingDays   (bool activeOnWorkingDays);
        void setSound         (AlarmSound sound);
        void setSnooze        (bool activeSnooze);
        void setMinutesSnooze (int minutesSnooze);

        bool       getWorkingDays   (); 
        AlarmSound getSound         ();
        bool       getSnooze        ();
        int        getMinutesSnooze ();
};