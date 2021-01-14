#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "base_event.h"
#include "event_container.h"
#include "linked_list.h"

using mtm::BaseEvent;
using mtm::EventContainer;

namespace mtm { 
    template<class EventType>
    class RecurringEvent : public EventContainer {
        DateWrap* init_date;
        string* name;
        int* occurrences_num;
        int* interval;
    public:
        RecurringEvent(  const DateWrap& first_date, const string& event_name,
                         const int& num_occurrences, const int& interval_days);
        ~RecurringEvent();
        void add(const BaseEvent&);
    };
}

using mtm::RecurringEvent;

template<class EventType>
RecurringEvent<EventType>::RecurringEvent(  const DateWrap& first_date, const string& event_name,
                                            const int& num_occurrences, const int& interval_days) : EventContainer() {
    if(num_occurrences < 0){
        throw mtm::InvalidNumber();
    }
    if(interval_days < 0 ){
        throw mtm::InvalidInterval();
    }
    init_date = new DateWrap(first_date);
    name = new string(event_name);
    occurrences_num = new int(num_occurrences);
    interval = new int(interval_days);
    for(int i = 0; i < *occurrences_num; i++){
        event_list->insert(EventType(*init_date + i*(*interval), *name));
    }
}

template<class EventType>
RecurringEvent<EventType>::~RecurringEvent(){
    delete init_date;
    delete name;
    delete occurrences_num;
    delete interval;
}

template<class EventType>
void RecurringEvent<EventType>::add(const BaseEvent&){
    throw mtm::NotSupported();
}



#endif  /**  RECURRING_EVENT_H_  */