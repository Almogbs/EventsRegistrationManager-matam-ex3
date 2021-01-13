#include "base_event.h"

using mtm::BaseEvent;
using std::endl;      

int* copyInt(const int& num){
    return new int(num);
}

BaseEvent::BaseEvent(const DateWrap& event_date, const string& event_name){
    name = new string(event_name);
    date = new DateWrap(event_date);
    participant_list = new LinkedList<int>(copyInt);
}

BaseEvent::~BaseEvent(){
    delete name;
    delete date;
    delete participant_list;
}
void BaseEvent::printShort(ostream& os){
    os << *name << SEPERETOR << *date << endl;
}
void BaseEvent::printLong(ostream& os){
    os << *name << SEPERETOR << *date << endl;
    LL_FOREACH(int*, iter, participant_list){
        os << *iter << endl;
    }
}

bool BaseEvent::participantListContains(int participant_num){
    if(participant_list->contains(participant_num)) {
        return true;
    }
    return false;
}

bool BaseEvent::isValidparticipant(int participant_num){
    if(participant_num < MIN_STUDENT_ID || participant_num > MAX_STUDENT_ID){
        return false;
    }
    return true;
}

const DateWrap& BaseEvent::getEventDate() const {
    return *date;
}

const string& BaseEvent::getEventName() const {
    return *name;
}


bool mtm::operator==(const BaseEvent& event1, const BaseEvent& event2){
    return  event1.getEventDate() == event2.getEventDate() &&
            event1.getEventName() == event2.getEventName();
}

bool mtm::operator<(const BaseEvent& event1, const BaseEvent& event2){
    if(event1.getEventDate() == event2.getEventDate()){
        return event1.getEventName() <= event2.getEventName();
    }
    return event1.getEventDate() < event2.getEventDate();
}

bool mtm::operator!=(const BaseEvent& event1, const BaseEvent& event2){
    return !(event1 == event2);
}

bool mtm::operator<=(const BaseEvent& event1, const BaseEvent& event2){
    return event2 >= event1;
}

bool mtm::operator>=(const BaseEvent& event1, const BaseEvent& event2){
    return !(event1 < event2);
}

bool mtm::operator>(const BaseEvent& event1, const BaseEvent& event2){
    return event2 < event1;
}

BaseEvent* mtm::copyEvent(const BaseEvent& event){
    return event.clone();
}

