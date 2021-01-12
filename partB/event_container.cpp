#include "event_container.h"

using mtm::EventContainer;

EventContainer::EventIterator::EventIterator(){
    current_event = NULL;
}

EventContainer::EventIterator::EventIterator(const EventIterator& ev){
    current_event = ev.current_event;
}

EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& ev){
    current_event = ev.current_event;
    return *this;
}

BaseEvent& EventContainer::EventIterator::operator*(){
    return *current_event;
}

bool EventContainer::EventIterator::operator==(const EventIterator& ev){
    return current_event == ev.current_event;
}

bool EventContainer::EventIterator::operator!=(const EventIterator& ev){
    return current_event != ev.current_event;
}

EventContainer::EventIterator& EventContainer::EventIterator::operator++(){
}


EventContainer::EventContainer(){
    event_list = new LinkedList<BaseEvent>;
    dummy_iterator = new EventIterator;
    iterator = new EventIterator;
}

EventContainer::~EventContainer(){
    delete event_list;
    delete dummy_iterator;
    delete iterator;
}

void EventContainer::setIteratorNextEvent(){
    bool is_next = false;
    LL_FOREACH(BaseEvent*, iterr, event_list){
        if(is_next == true){
            iterator->setIteratorToEvent(*iterr);
            return;
        }
        if(&iterator->operator*() == iterr){
            is_next = true;
        }
    }
    delete iterator;
    iterator = dummy_iterator;
}

void EventContainer::EventIterator::setIteratorToEvent(BaseEvent& event){
    current_event = &event;
}

EventContainer::EventIterator& EventContainer::begin(){
    iterator->setIteratorToEvent(*event_list->getFirst());
    return *iterator;
}

EventContainer::EventIterator& EventContainer::end(){
    return *dummy_iterator;
}
