#include <cstring>
#include <iostream>
#include "../RingTimeDevice.cpp"


class Alarm: public RingTimeDevice{ 
        char *note;
        bool isAlarmSet;

    public:
        Alarm();
        Alarm(int      hour, 
            int        minutes, 
            char       *note,  
            bool       isAlarmSet
        );
        Alarm(int hour, 
            int   minutes
        );
        Alarm(const Alarm &a);
        Alarm(Alarm &&a);
        ~Alarm();

        void setHour          (int hour);
        void setMinutes       (int minutes);
        void setNote          (char *note);
        void setAlarm         (bool isAlarmSet);

        int        getHour          ();
        int        getMinutes       ();
        char*      getNote          ();
        bool       getAlarm         ();

        bool compare(Alarm a);

        void display();

        void setTime(int hour, int minutes)override;
        void ring()override;
};