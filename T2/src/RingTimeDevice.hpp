#pragma once
namespace RingTimeDevices{
class RingTimeDevice {
    protected:
    int hour;
    int minutes;
    
    public:
        virtual ~RingTimeDevice() = default;
        virtual void setHour    (int hour)= 0;
        virtual void setMinutes (int minutes) = 0; 
        virtual int  getHour    () = 0; 
        virtual int  getMinutes () = 0; 
        virtual void setTime    (int hour, int minutes) = 0; 
        virtual void ring       ()= 0; 
};
}
