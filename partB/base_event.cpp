#include "base_event.h"

using mtm::BaseEvent;
using std::endl;      
        
BaseEvent::BaseEvent(const DateWrap& event_date, const string& event_name){
    name = new string(event_name);
    date = new DateWrap(event_date);
    participant_list = new LinkedList<int>();
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

const DateWrap& BaseEvent::getEventDate(){
    return *date;
}

const string& BaseEvent::getEventName(){
    return *name;
}


