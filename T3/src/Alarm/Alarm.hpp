#pragma once

#include <cstring>
#include <iostream>
#include <memory>
#include "../RingTimeDevice.hpp"

namespace Alarms{
    class Alarm: public RingTimeDevices::RingTimeDevice{ 

        protected:
            std::shared_ptr<char> note;
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

            void setHour          (int hour) override;
            void setMinutes       (int minutes) override;
            void setNote          (char *note);
            void setAlarm         (bool isAlarmSet);

            int        getHour          ()override;
            int        getMinutes       ()override;
            char*      getNote          ();
            bool       getAlarm         ();

            bool compare(Alarm a);

            void display();

            void setTime(int hour, int minutes) override;
            void ring() override;
    };
}