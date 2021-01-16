#include "event_container.h"

using mtm::EventContainer;
EventContainer::EventIterator::EventIterator(){
    current_event = NULL, current_container = NULL;
}

EventContainer::EventIterator::EventIterator(const EventIterator& ev){
    current_event = ev.current_event;
    current_container = ev.current_container;
}

EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& ev){
    current_event = ev.current_event;
    current_container = ev.current_container;
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
    bool is_next = false;
    if(!current_container->event_list || current_container->event_list->size() == 0)
    {
        return *current_container->dummy_iterator;
    }
    LL_FOREACH(BaseEvent*, iterr, current_container->event_list){
        if(is_next == true){
            current_event = iterr;
            return *this;
        }
        if(current_event == iterr){
            is_next = true;
        }
    }
    current_event = current_container->dummy_iterator->current_event;
    return *current_container->dummy_iterator;
}

/*
EventContainer::EventIterator* EventContainer::EventIterator::copyIterator(){
    ++(*current_container->inner_iterator);
    return current_container->inner_iterator;
}
*/

EventContainer::EventContainer(){
    event_list = new LinkedList<BaseEvent>(mtm::copyEvent);
    event_list->copy_function = mtm::copyEvent;
    dummy_iterator = new EventIterator;
    inner_iterator = new EventIterator;
}

EventContainer::~EventContainer(){
    delete event_list;
    delete inner_iterator;  
    delete dummy_iterator;
}

EventContainer::EventIterator& EventContainer::begin() const{
    if(event_list->size() == 0) {
        return *dummy_iterator;
    }
    inner_iterator->current_event = event_list->getFirst();
    inner_iterator->current_container = this;
    EventIterator iterator;
    iterator.current_event = event_list->getFirst();
    iterator.current_container = this;
    return *inner_iterator;
}

EventContainer::EventIterator& EventContainer::end() const{
    return *dummy_iterator;
}
