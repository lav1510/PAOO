#include "EnhancedAlarm.hpp"
#include <iostream>
#include <cstring>

////////////////////////////////////////////////////////////
//Constructors
////////////////////////////////////////////////////////////
EnhancedAlarm::EnhancedAlarm() : Alarm (){
    this->sound               = BUZZER;
    this->activeOnWorkingDays = true;
    this->activeSnooze        = true;
    this->minutesSnooze       = 10; 
}

EnhancedAlarm::EnhancedAlarm(int hour, 
    int           minutes, 
    char          *note, 
    AlarmSound    sound, 
    bool          isAlarmSet, 
    bool          activeOnWorkingDays, 
    bool          activeSnooze,
    int           minutesSnooze): Alarm( hour, minutes, note, isAlarmSet){

    std::cout<<"Constructor called!"<<std::endl;

    this->sound               = sound;
    this->activeOnWorkingDays = activeOnWorkingDays;
    this->activeSnooze        = activeSnooze;
    this->minutesSnooze       = minutesSnooze;             
}

////////////////////////////////////////////////////////////
//Destructor
////////////////////////////////////////////////////////////
EnhancedAlarm::~EnhancedAlarm (){

    std::cout<<"Destructor called!"<<std::endl;
}

////////////////////////////////////////////////////////////
//Setters
////////////////////////////////////////////////////////////

void EnhancedAlarm::setSound (AlarmSound sound){
    this->sound = sound;
}

void EnhancedAlarm::setWorkingDays(bool activeOnWorkingDays){
    this->activeOnWorkingDays = activeOnWorkingDays;
}

void EnhancedAlarm::setSnooze (bool activeSnooze){
    this->activeSnooze = activeSnooze;
}

void EnhancedAlarm::setMinutesSnooze (int minutesSnooze){
    this->minutesSnooze = minutesSnooze;
}

////////////////////////////////////////////////////////////
//Getters
////////////////////////////////////////////////////////////
AlarmSound EnhancedAlarm::getSound (){
    return sound;
}

bool EnhancedAlarm::getWorkingDays (){
    return activeOnWorkingDays;
}
bool EnhancedAlarm::getSnooze (){
    return activeSnooze;
}
int EnhancedAlarm::getMinutesSnooze (){
    return minutesSnooze;
}

void EnhancedAlarm::display(){
    Alarm::display();
    std::cout << (activeOnWorkingDays?"Alarm is set on working days.":"Alarm is not set on working days.")<< std::endl;
    std::cout << (activeSnooze?"Snooze is active.":"Snooze is not active.")<< std::endl;
    std::cout << "Minutes for snooze: " << minutesSnooze << " ."<< std::endl;
    std::cout<<std::endl;

}