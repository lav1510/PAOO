#include "AlarmList.hpp"
#include <iostream>

namespace AlarmLists {

    void AlarmList::addFirstAlarm(const std::shared_ptr<Alarms::Alarm>& newAlarm, const std::unique_ptr<Alarms::Alarm>& newUniqueAlarm){
        std::cout << "Adding first and second alarms to the list..." << std::endl;
        firstAlarm = newAlarm;
        firstAlarm->setNext(std::move(std::make_unique<Alarms::Alarm>(*newUniqueAlarm)));
        crt = firstAlarm->getNext();
        crt->display();
    }

            
    void AlarmList::addAlarm(const std::unique_ptr<Alarms::Alarm>& newAlarm) {
        std::cout << "Adding alarm to the list..." << std::endl;
        newAlarm->display();
        crt->setNext(std::move(std::make_unique<Alarms::Alarm>(*newAlarm)));
        crt->setFirst(firstAlarm);
        crt = crt->getNext();
    }

    void AlarmList::displayAll() {
        std::cout << "//////////////////////////////////////////////////" << std::endl;
        firstAlarm->display();
        // Start from the first alarm
        std::unique_ptr<Alarms::Alarm> current = firstAlarm->getNext();
        // Loop through the list and display each alarm
        while (current) {
            current->display();
            current = current->getNext();
        }
        std::cout << "//////////////////////////////////////////////////" << std::endl;
    }

} // namespace AlarmLists
