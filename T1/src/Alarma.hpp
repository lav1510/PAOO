#include <cstring>
#include <iostream>

enum AlarmSound {
    BEEP,
    BUZZER,
    RADIO
};

class Alarm{
        int hour;
        int minutes; //separate class(hour, minutes) in the future with proper bounds on members

        char *note;

        AlarmSound sound;

        bool isAlarmSet;
        bool activeOnWorkingDays;

        bool activeSnooze;
        int minutesSnooze;

    public:
        Alarm(int      hour, 
            int        minutes, 
            char       *note, 
            AlarmSound sound, 
            bool       isAlarmSet, 
            bool       activeOnWorkingDays, 
            bool       activeSnooze, 
            int        minutesSnooze
        );
        Alarm(int  hour, 
            int    minutes, 
            char   *note
        );
        Alarm(int hour, 
            int   minutes
        );
        Alarm(const Alarm &a);
        ~Alarm();

        void setHour          (int hour);
        void setMinutes       (int minutes);
        void setNote          (char *note);
        void setSound         (AlarmSound sound);
        void setAlarm         (bool isAlarmSet);
        void setWorkingDays   (bool activeOnWorkingDays);
        void setSnooze        (bool activeSnooze);
        void setMinutesSnooze (int minutesSnooze);

        int        getHour          ();
        int        getMinutes       ();
        char*      getNote          ();
        AlarmSound getSound         ();
        bool       getAlarm         ();
        bool       getWorkingDays   ();
        bool       getSnooze        ();
        int        getMinutesSnooze ();

        bool compare(Alarm a);

        void display();
};