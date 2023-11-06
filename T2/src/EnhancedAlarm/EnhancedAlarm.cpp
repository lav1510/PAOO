#include "EnhancedAlarm.hpp"
#include <iostream>
#include <cstring>

////////////////////////////////////////////////////////////
//Constructors
////////////////////////////////////////////////////////////
EnhancedAlarm::EnhancedAlarm(int hour, 
    int           minutes, 
    char          *note, 
    AlarmSound    sound, 
    bool          isAlarmSet, 
    bool          activeOnWorkingDays, 
    bool          activeSnooze,
    int           minutesSnooze): Alarm( hour, minutes, note, isAlarmSet){

    setHour(hour);
    setMinutes(minutes);
    setNote(note);
    setAlarm(isAlarmSet);

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