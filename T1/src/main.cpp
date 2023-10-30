#include "Alarm.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Alarm alarm1 (6, 40, (char*)"Good morning", BUZZER, 1, 1, 1, 5);
    Alarm alarm2 (6, 45, (char*)"Get up!",      BUZZER, 1, 1, 0, 0);

    alarm1.display();
    alarm2.display();

    if(alarm1.compare(alarm2)){
        std::cout<<"Alarms are equals."<<std::endl;
    }
    else{
        std::cout<<"Alarms are not equals."<<std::endl;
    }

    alarm1=alarm2;

    alarm1.short_display();
    alarm2.short_display();

    return 0;
}