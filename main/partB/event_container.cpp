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
    if(current_container->iterator == current_container->dummy_iterator){
        return *current_container->dummy_iterator;
    }
    current_container->setIteratorNextEvent();
    setIteratorToEvent(*current_container->iterator->current_event);
    return *this;
}


EventContainer::EventContainer(){
    event_list = new LinkedList<BaseEvent>(mtm::copyEvent);
    event_list->copy_function = mtm::copyEvent;
    dummy_iterator = new EventIterator;
    iterator = new EventIterator;
}

EventContainer::~EventContainer(){
    delete event_list;
   if(dummy_iterator == iterator){
        delete dummy_iterator;
        return;
   }
        delete dummy_iterator;
        delete iterator;
}

void EventContainer::setIteratorNextEvent(){
    bool is_next = false;
    if(!event_list)
    {
        return;
    }
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
    if(event_list->size() == 0) {
        return *dummy_iterator;
    }
    iterator->setIteratorToEvent(*event_list->getFirst());
    iterator->current_container = this;
    return *iterator;
}

EventContainer::EventIterator& EventContainer::end(){
    return *dummy_iterator;
}
