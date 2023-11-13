#pragma once

#include <cstring>
#include <iostream>
#include "../RingTimeDevice.hpp"


class Timer : public RingTimeDevices::RingTimeDevice{

    public:
        Timer(int hour, int   minutes);
        ~Timer();

        void setHour          (int hour) override;
        void setMinutes       (int minutes) override;

        int        getHour    () override;
        int        getMinutes () override;

        void start();
        void stop();
        
        void setTime(int hour, int minutes)override;
        void ring()override;

};
