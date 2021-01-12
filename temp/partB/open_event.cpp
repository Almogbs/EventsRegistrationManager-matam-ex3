#include "open_event.h"


using mtm::OpenEvent;

OpenEvent::OpenEvent(const DateWrap& event_date, const string& event_name) : BaseEvent(event_date, event_name) {}

void OpenEvent::registerParticipant(int participant_num) {
    if(!isValidparticipant(participant_num)){
        throw mtm::InvalidStudent();
    }
    if(participantListContains(participant_num)){
        throw mtm::AlreadyRegistered();
    }
    participant_list->insert(participant_num);
}

void OpenEvent::unregisterParticipant(int participant_num) {
    if(!isValidparticipant(participant_num)){
        throw mtm::InvalidStudent();
    }
    if(!participantListContains(participant_num)){
        throw mtm::NotRegistered();
    }
    participant_list->removeElement(participant_num);
}

BaseEvent* OpenEvent::clone() const{
    OpenEvent* new_open_event = new OpenEvent(getEventDate(), getEventName());
    delete new_open_event->participant_list;
    new_open_event->participant_list = new LinkedList<int>(*participant_list);
    return new_open_event;
}
