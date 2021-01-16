#include "closed_event.h"

using mtm::ClosedEvent;

ClosedEvent::ClosedEvent(const DateWrap& event_date, const string& event_name) : BaseEvent(event_date, event_name) {
    invitee_list = new LinkedList<int>(copyInt);
}

void ClosedEvent::addInvitee(int invitee_num){
    if(!isValidparticipant(invitee_num)){
        throw mtm::InvalidStudent();
    }
    if(inviteeListContains(invitee_num)){
        throw mtm::AlreadyInvited();
    }
    invitee_list->insert(invitee_num);
}

ClosedEvent::~ClosedEvent(){
    delete invitee_list;
}

void ClosedEvent::registerParticipant(int participant_num){
    if(!isValidparticipant(participant_num)){
        throw mtm::InvalidStudent();
    }
    if(!inviteeListContains(participant_num)){
        throw mtm::RegistrationBlocked();
    }
    if(participantListContains(participant_num)){
        throw mtm::AlreadyRegistered();
    }
    participant_list->insert(participant_num);
}

void ClosedEvent::unregisterParticipant(int participant_num){
    if(!isValidparticipant(participant_num)){
        throw mtm::InvalidStudent();
    }
    if(!participantListContains(participant_num)){
        throw mtm::NotRegistered();
    }
    participant_list->removeElement(participant_num);
}

bool ClosedEvent::inviteeListContains(int invitee_num){
    if(invitee_list->contains(invitee_num)) {
        return true;
    }
    return false;
}

BaseEvent* ClosedEvent::clone() const{
    ClosedEvent* new_closed_event = new ClosedEvent(getEventDate(), getEventName());
    delete new_closed_event->participant_list;
    delete new_closed_event->invitee_list;
    new_closed_event->participant_list = new LinkedList<int>(*participant_list);
    new_closed_event->invitee_list = new LinkedList<int>(*invitee_list);
    return new_closed_event;
}
