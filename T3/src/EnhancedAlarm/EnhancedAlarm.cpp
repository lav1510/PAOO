#include "EnhancedAlarm.hpp"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <memory>
namespace EnhancedAlarms {
    ////////////////////////////////////////////////////////////
    //Constructors
    ////////////////////////////////////////////////////////////
    template <typename T>
    EnhancedAlarm<T>::EnhancedAlarm() : Alarm (){
        std::cout<<"Default constructor eha called!"<<std::endl;
        this->activeOnWorkingDays = true;
        this->activeSnooze        = true;
        this->minutesSnooze       = 10; 
        for (int i = 0; i < 7; ++i) {
            activeDays.push_back(i);
        }
    }

    template <typename T>
    EnhancedAlarm<T>::EnhancedAlarm(int hour, 
        int           minutes, 
        char          *note, 
        T             sound, 
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
    template <typename T>
    EnhancedAlarm<T>::~EnhancedAlarm (){
       std::cout<<"Destructor called!"<<std::endl;
    }

    ////////////////////////////////////////////////////////////
    //Setters
    ////////////////////////////////////////////////////////////
    template<typename T>
    void EnhancedAlarm<T>::setSound(const T& newSound) {
        std::cout << "Setting sound..." << std::endl;

       sound = newSound;
    }

    template <typename T>
    void EnhancedAlarm<T>::setWorkingDays(bool activeOnWorkingDays){
        this->activeOnWorkingDays = activeOnWorkingDays;
        if(activeOnWorkingDays){
            activeDays.clear();
            for (int i = 1; i < 5; ++i) {
                activeDays.push_back(i);
            }
        }
    }

    template <typename T>
    void EnhancedAlarm<T>::setSnooze (bool activeSnooze){
        this->activeSnooze = activeSnooze;
    }

    template <typename T>
    void EnhancedAlarm<T>::setMinutesSnooze (int minutesSnooze){
        this->minutesSnooze = minutesSnooze;
    }

    ////////////////////////////////////////////////////////////
    //Getters
    ////////////////////////////////////////////////////////////

    template <typename T>
    bool EnhancedAlarm<T>::getWorkingDays (){
        return activeOnWorkingDays;
    }

    template <typename T>
    bool EnhancedAlarm<T>::getSnooze (){
        return activeSnooze;
    }

    template <typename T>
    int EnhancedAlarm<T>::getMinutesSnooze (){
        return minutesSnooze;
    }

    template <typename T>
    void EnhancedAlarm<T>::display(){
        Alarm::display();
        std::cout << (activeOnWorkingDays?"Alarm is set on working days.":"Alarm is not set on working days.")<< std::endl;
        std::cout << (activeSnooze?"Snooze is active.":"Snooze is not active.")<< std::endl;
        std::cout << "Minutes for snooze: " << minutesSnooze << " ."<< std::endl;
        std::cout << "AlarmSound: " << sound << " ."<< std::endl;
        std::cout<<std::endl;
    }

    template <typename T>
    void EnhancedAlarm<T>::addActiveDay(int day) {
        if (std::find(activeDays.begin(), activeDays.end(), day) == activeDays.end()) {
            if (day >= 0 && day < 7) {
                activeDays.push_back(day);
            }
        }
    }

    template <typename T>
    bool EnhancedAlarm<T>::isAlarmActive(int day) {
        for (int activeDay : activeDays) {
            if (day == activeDay) {
                return true;
            }
        }
        return false;
    }
}