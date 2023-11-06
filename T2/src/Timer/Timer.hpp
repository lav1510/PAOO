#include <cstring>
#include <iostream>
#include "../RingTimeDevice.cpp"


class Timer : public RingTimeDevice{

    public:
        Timer(int hour, int   minutes);
        ~Timer();

        void setHour          (int hour);
        void setMinutes       (int minutes);

        int        getHour    ();
        int        getMinutes ();

        void start();
        void stop();
        
        void setTime(int hour, int minutes)override;
        void ring()override;

};