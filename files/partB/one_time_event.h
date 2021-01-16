#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "base_event.h"
#include "event_container.h"
#include "linked_list.h"

using mtm::BaseEvent;
using mtm::EventContainer;

namespace mtm { 
    template<class EventType>
    class OneTimeEvent : public EventContainer {
        DateWrap* date;
        string* name;
    public:
        OneTimeEvent(const DateWrap& event_date, const string& event_name);
        ~OneTimeEvent();
        void add(const BaseEvent&);
    };
}

using mtm::OneTimeEvent;

template<class EventType>
OneTimeEvent<EventType>::OneTimeEvent(const DateWrap& event_date, const string& event_name) : EventContainer() {
    date = new DateWrap(event_date);
    name = new string(event_name);
    event_list->insert(EventType(*date, *name));
}

template<class EventType>
OneTimeEvent<EventType>::~OneTimeEvent(){
    delete date;
    delete name;
}

template<class EventType>
void OneTimeEvent<EventType>::add(const BaseEvent&){
    throw mtm::NotSupported();
}

#endif  /**  ONE_TIME_EVENT_H_  */
