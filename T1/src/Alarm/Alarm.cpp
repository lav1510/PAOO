#include "Alarm.hpp"
#include <iostream>
#include <cstring>

////////////////////////////////////////////////////////////
//Constructors
////////////////////////////////////////////////////////////
Alarm::Alarm (int hour, 
    int           minutes, 
    char          *note, 
    AlarmSound    sound, 
    bool          isAlarmSet, 
    bool          activeOnWorkingDays, 
    bool          activeSnooze,
    int           minutesSnooze){

    std::cout<<"Explicit constructor called!"<<std::endl;

    this->hour                = hour;
    this->minutes             = minutes;

    this->note                = new char[strlen(note) + 1];
    strcpy(this->note, note);

    this->sound               = sound;
    this->isAlarmSet          = isAlarmSet;
    this->activeOnWorkingDays = activeOnWorkingDays;
    this->activeSnooze        = activeSnooze;
    this->minutesSnooze       = minutesSnooze;             
}

Alarm::Alarm (int hour, 
    int           minutes, 
    char          *note){

    std::cout<<"Constructor with hours, minutes and note called!"<<std::endl;

    this->hour    = hour;
    this->minutes = minutes;

    this->note    = new char[strlen(note) + 1];
    strcpy(this->note, note);  
}

Alarm::Alarm (int hour, int minutes){

    std::cout<<"Constructor with hours and minutes called!"<<std::endl;

    this->hour    = hour;
    this->minutes = minutes;
}

Alarm::Alarm (const Alarm &a){

    std::cout<<"Copy constructor called!"<<std::endl;

    this->hour                = a.hour;
    this->minutes             = a.minutes;

    this->note                = new char[strlen(a.note) + 1];
    strcpy(this->note, a.note);

    this->sound               = a.sound;
    this->isAlarmSet          = a.isAlarmSet;
    this->activeOnWorkingDays = a.activeOnWorkingDays;
    this->activeSnooze        = a.activeSnooze;
    this->minutesSnooze       = a.minutesSnooze;
}

////////////////////////////////////////////////////////////
//Destructor
////////////////////////////////////////////////////////////
Alarm::~Alarm (){

    delete[] this->note;
}

////////////////////////////////////////////////////////////
//Setters
////////////////////////////////////////////////////////////
void Alarm::setHour (int hour){
    this->hour = hour;
}

void Alarm::setMinutes (int minutes){
    this->minutes = minutes;
}

void Alarm::setNote(char *newNote){
    if (newNote) {
        if (note) {
            delete[] note;
            note = nullptr;
        }

        note = new char[strlen(newNote) + 1];
        strcpy(note, newNote); 
    }
}

void Alarm::setSound (AlarmSound sound){
    this->sound = sound;
}

void Alarm::setAlarm (bool isAlarmSet){
    this->isAlarmSet = isAlarmSet;
}

void Alarm::setWorkingDays(bool activeOnWorkingDays){
    this->activeOnWorkingDays = activeOnWorkingDays;
}

void Alarm::setSnooze (bool activeSnooze){
    this->activeSnooze = activeSnooze;
}

void Alarm::setMinutesSnooze (int minutesSnooze){
    this->minutesSnooze = minutesSnooze;
}

////////////////////////////////////////////////////////////
//Getters
////////////////////////////////////////////////////////////
int Alarm::getHour (){
    return hour;
}

int Alarm::getMinutes (){
    return minutes;
}

char* Alarm::getNote (){
    return note;
}
AlarmSound Alarm::getSound (){
    return sound;
}
bool Alarm::getAlarm (){
    return isAlarmSet;
}
bool Alarm::getWorkingDays (){
    return activeOnWorkingDays;
}
bool Alarm::getSnooze (){
    return activeSnooze;
}
int Alarm::getMinutesSnooze (){
    return minutesSnooze;
}

////////////////////////////////////////////////////////////
//Compare
////////////////////////////////////////////////////////////
bool Alarm::compare(Alarm a){

    std::cout << "Compare called." << std::endl;

    return 
        hour                    == a.hour
        && minutes              == a.minutes
        && strcmp(note, a.note) == 0
        && sound                == a.sound
        && isAlarmSet           == a.isAlarmSet
        && activeOnWorkingDays  == a.activeOnWorkingDays
        && activeSnooze         == a.activeSnooze
        && minutesSnooze        == a.minutesSnooze;
}

////////////////////////////////////////////////////////////
//Display
////////////////////////////////////////////////////////////
void Alarm::display(){
    std::cout<<std::endl;
    std::cout << "Rings at " << hour <<":"<< minutes<< std::endl;
    std::cout << "Note: \" " << note << " \" "<< std::endl;
    std::cout << (isAlarmSet?"Alarm is set.":"Alarm is not set.")<< std::endl;
    std::cout << (isAlarmSet?"Alarm is set on working days.":"Alarm is not set on working days.")<< std::endl;
    std::cout << (activeSnooze?"Snooze is active.":"Snooze is not active.")<< std::endl;
    std::cout << "Minutes for snooze: " << minutesSnooze << " ."<< std::endl;
    std::cout<<std::endl;
}

void Alarm::short_display(){
    std::cout<<std::endl;
    std::cout << "Rings at " << hour <<":"<< minutes<< std::endl;
    std::cout << "Note: \" " << note << " \" "<< std::endl;
    std::cout << (isAlarmSet?"Alarm is set.":"Alarm is not set.")<< std::endl;
    std::cout<<std::endl;
}