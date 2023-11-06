#include "Alarm.hpp"
#include <iostream>
#include <cstring>

////////////////////////////////////////////////////////////
//Constructors
////////////////////////////////////////////////////////////
Alarm::Alarm (){

    std::cout<<"Default constructor called!"<<std::endl;

    this->hour                = 0;
    this->minutes             = 0;

    this->note                = new char[strlen(note) + 1];
    strcpy(this->note, "");

    this->isAlarmSet          = true;            
}

Alarm::Alarm (int hour, 
    int           minutes, 
    char          *note, 
    bool          isAlarmSet){

    std::cout<<"Explicit constructor called!"<<std::endl;

    this->hour                = hour;
    this->minutes             = minutes;

    this->note                = new char[strlen(note) + 1];
    strcpy(this->note, note);

    this->isAlarmSet          = isAlarmSet;            
}

Alarm::Alarm (int hour, int minutes){

    std::cout<<"Constructor with hours and minutes called!"<<std::endl;

    this->hour    = hour;
    this->minutes = minutes;
    
    this->note                = new char[strlen("Note") + 1];
    strcpy(this->note, "Note");
}

////////////////////////////////////////////////////////////
//Copy constructor
////////////////////////////////////////////////////////////
Alarm::Alarm (const Alarm &a){

    std::cout<<"Copy constructor called!"<<std::endl;

    this->hour                = a.hour;
    this->minutes             = a.minutes;

    this->note                = new char[strlen(a.note) + 1];
    if(note) {
        strcpy(this->note, a.note);
    }

    this->isAlarmSet          = a.isAlarmSet;
}

////////////////////////////////////////////////////////////
//Move constructor
////////////////////////////////////////////////////////////
Alarm::Alarm (Alarm &&a){
	std::cout<<"Move constructor called"<<std::endl;
    this->hour                = a.hour;
    this->minutes             = a.minutes;

    strcpy(this->note, a.note);
    

    this->isAlarmSet          = a.isAlarmSet;
}

////////////////////////////////////////////////////////////
//Destructor
////////////////////////////////////////////////////////////
Alarm::~Alarm (){

    std::cout<<"Destructor called!"<<std::endl;

    delete[] this->note;
    note = nullptr;
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

void Alarm::setAlarm (bool isAlarmSet){
    this->isAlarmSet = isAlarmSet;
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

bool Alarm::getAlarm (){
    return isAlarmSet;
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
        && isAlarmSet           == a.isAlarmSet;
}

////////////////////////////////////////////////////////////
//Display
////////////////////////////////////////////////////////////
void Alarm::display(){
    std::cout<<std::endl;
    std::cout << "Rings at " << hour <<":"<< minutes<< std::endl;
    std::cout << "Note: \" " << note << " \" "<< std::endl;
    std::cout << (isAlarmSet?"Alarm is set.":"Alarm is not set.")<< std::endl;
    std::cout<<std::endl;
}

////////////////////////////////////////////////////////////
//interface::setTime
////////////////////////////////////////////////////////////
void Alarm::setTime(int hour, int minutes) {
    this->hour    = (hour) % 60;
    this->minutes = (minutes) % 60;
}

////////////////////////////////////////////////////////////
//interface::ring
////////////////////////////////////////////////////////////
void Alarm::ring() {
    std::cout << "Alarm ringing at " << hour << ":" << minutes << std::endl;
}
