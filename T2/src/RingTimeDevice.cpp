class RingTimeDevice {
    protected:
    int hour;
    int minutes;
    
    public:
        virtual void setTime(int hour, int minutes);
        virtual void ring();
};
