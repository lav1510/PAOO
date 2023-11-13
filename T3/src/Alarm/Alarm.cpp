#include "Alarm.hpp"
#include <iostream>
#include <cstring>
#include <memory>

namespace Alarms {
    ////////////////////////////////////////////////////////////
    //Constructors
    ////////////////////////////////////////////////////////////
    Alarm::Alarm() : note(std::make_shared<char>(' ')) {

        std::cout << "Default constructor Alarm called!" << std::endl;
        this->hour                = 0;
        this->minutes             = 0;
        this->isAlarmSet          = true;  

    }


    Alarm::Alarm (int hour, 
        int           minutes, 
        char          *note, 
        bool          isAlarmSet): note(std::make_shared<char>(' ')) {

        setNote(note);
        std::cout<<"Explicit constructor called!"<<std::endl;

        this->hour                = hour;
        this->minutes             = minutes;

        this->isAlarmSet          = isAlarmSet;            
    }

    Alarm::Alarm (int hour, int minutes) : note(std::make_shared<char>(' ')) {

        std::cout<<"Constructor with hours and minutes called!"<<std::endl;

        this->hour    = hour;
        this->minutes = minutes;
    }

    ////////////////////////////////////////////////////////////
    //Copy constructor
    ////////////////////////////////////////////////////////////
    Alarm::Alarm(const Alarm& a) : note(std::make_shared<char>(' ')) {
        std::cout << "Copy constructor called!" << std::endl;
        this->hour = a.hour;
        this->minutes = a.minutes;
        this->isAlarmSet = a.isAlarmSet;
    }

    ////////////////////////////////////////////////////////////
    //Move constructor
    ////////////////////////////////////////////////////////////
    Alarm::Alarm(Alarm&& a) {
        std::cout << "Move constructor called" << std::endl;
        this->hour = a.hour;
        this->minutes = a.minutes;
        this->isAlarmSet = a.isAlarmSet;
    }

    ////////////////////////////////////////////////////////////
    //Destructor
    ////////////////////////////////////////////////////////////
    Alarm::~Alarm (){
        std::cout<<"Destructor called!"<<std::endl;
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
            note = std::make_shared<char>(strlen(newNote) + 1);
            strcpy(note.get(), newNote);
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
        return note.get();
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
            && strcmp(note.get(), a.note.get()) == 0
            && isAlarmSet           == a.isAlarmSet;
    }

    ////////////////////////////////////////////////////////////
    //Display
    ////////////////////////////////////////////////////////////
    void Alarm::display(){
        std::cout<<std::endl;
        std::cout << "Rings at " << hour <<":"<< minutes<< std::endl;
        std::cout << "Note: \" " << note.get() << " \" "<< std::endl;
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
}