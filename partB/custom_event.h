#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "base_event.h"
#include "linked_list.h"

using mtm::BaseEvent;

namespace mtm { 
    template<class CanRegister>
    class CustomEvent : public BaseEvent {
    public:
        CanRegister statement_function;
        CustomEvent(const DateWrap&, const string&, const CanRegister&);
        void registerParticipant(int participant_num);
        void unregisterParticipant(int participant_num);
        BaseEvent* clone();
    };
}

using mtm::CustomEvent;

template<class CanRegister>
CustomEvent<CanRegister>::CustomEvent(const DateWrap& event_date, const string&event_name , const CanRegister& func) : 
    BaseEvent(event_date, event_name){
    statement_function = func;
}


template<class CanRegister>
void CustomEvent<CanRegister>::registerParticipant(int participant_num){
    if(!isValidparticipant(participant_num)){
        throw mtm::InvalidStudent();
    }
    if(!statement_function(participant_num)){
        throw mtm::RegistrationBlocked();
    }
    if(participantListContains(participant_num)){
        throw mtm::AlreadyRegistered();
    }
    participant_list->insert(participant_num);
}

template<class CanRegister>
void CustomEvent<CanRegister>::unregisterParticipant(int participant_num){
    if(!isValidparticipant(participant_num)){
        throw mtm::InvalidStudent();
    }
    if(!participantListContains(participant_num)){
        throw mtm::NotRegistered();
    }
    participant_list->removeElement(participant_num);
}

template<class CanRegister>
BaseEvent* CustomEvent<CanRegister>::clone(){
    CustomEvent<CanRegister>* new_custom_event = new CustomEvent(getEventDate(), getEventName(), statement_function);
    delete new_custom_event->participant_list;
    new_custom_event->participant_list = new LinkedList<int>(*participant_list);
    return new_custom_event;
}


#endif  /**  CUSTOM_EVENT_H_  */