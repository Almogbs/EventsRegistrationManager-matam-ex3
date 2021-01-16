#include "schedule.h"

using mtm::Schedule;

typedef mtm::EventContainer::EventIterator Iterator;

bool Schedule::haveCommonEvent(const EventContainer& events){
    for (Iterator iter = events.begin(); iter != events.end(); ++iter) {
        mtm::BaseEvent& event = *iter;
        if(event_list->contains(event)){
            return true;
        }
    }
    return false;
}

Schedule::Schedule(){
    event_list = new LinkedList<BaseEvent>(copyEvent);
}

Schedule::~Schedule(){
    delete event_list;
}

void Schedule::addEvents(const EventContainer& events){
    if(haveCommonEvent(events)){
        throw mtm::EventAlreadyExists();
    }
    for (Iterator iter = events.begin(); iter != events.end(); ++iter) {
        mtm::BaseEvent& event = *iter;
        event_list->insert(event);
    }
}

void Schedule::registerToEvent(const DateWrap& date, const string& name, const int& participant_num){
    if(participant_num < MIN_STUDENT_ID || participant_num > MAX_STUDENT_ID){
        throw mtm::InvalidStudent();
    }
    OpenEvent temp_event = OpenEvent(date, name);
    if(!event_list->contains(temp_event)){
        throw mtm::EventDoesNotExist();
    }
    BaseEvent* ptr = event_list->getElement(temp_event);
    ptr->registerParticipant(participant_num);
}

void Schedule::unregisterFromEvent(const DateWrap& date, const string& name, const int& participant_num){
    if(participant_num < MIN_STUDENT_ID || participant_num > MAX_STUDENT_ID){
        throw mtm::InvalidStudent();
    }
    OpenEvent temp_event = OpenEvent(date, name);
    BaseEvent* ptr = event_list->getElement(temp_event);
    ptr->unregisterParticipant(participant_num);
}

void Schedule::printAllEvents() const{
    for(BaseEvent* ptr_iter = event_list->getFirst(); ptr_iter != NULL; ptr_iter = event_list->getNext()){
        ptr_iter->printShort(cout);
        cout << endl;
    }
}

void Schedule::printMonthEvents(const int& month, const int& year) const{ 
    for(BaseEvent* ptr_iter = event_list->getFirst(); ptr_iter != NULL; ptr_iter = event_list->getNext()){
        DateWrap temp_date = ptr_iter->getEventDate();
        if(temp_date.month() == month && temp_date.year()== year){
            ptr_iter->printShort(cout);
            cout << endl;
        }
    }    
}

void Schedule::printEventDetails(const DateWrap& date, const string& name) const{
    OpenEvent temp_event = OpenEvent(date, name);
    if(!event_list->contains(temp_event)){
        throw mtm::EventDoesNotExist(); 
    }
    BaseEvent* ptr = event_list->getElement(temp_event);
    ptr->printLong(cout);
    cout << endl;
}
