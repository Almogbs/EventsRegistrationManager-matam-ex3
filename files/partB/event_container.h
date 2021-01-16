#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include "base_event.h"


using std::string;
using std::ostream;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::LinkedList;


namespace mtm{ 
    class EventContainer {
    public:
        class EventIterator {
        public:
            EventIterator();
            EventIterator(const EventIterator&);
            EventIterator& operator=(const EventIterator&);
            BaseEvent& operator*();
            bool operator==(const EventIterator&);
            bool operator!=(const EventIterator&);
            EventIterator& operator++();
            
            /**
            * setIteratorToEvent: set iterator event to the specified event.
            *
            * @param event - the target event.
            */ 
            void setIteratorToEvent(BaseEvent& event);
            //EventIterator* copyIterator();
            BaseEvent* current_event;
            const EventContainer* current_container;
        };
        EventContainer();
        virtual ~EventContainer();
        virtual void add(const BaseEvent&) = 0;
        EventIterator& begin() const;
        EventIterator& end() const;
    protected:        
        LinkedList<BaseEvent>* event_list;

        // Pointer to dedicated iterator, which represents the end of list
        EventIterator* dummy_iterator;

        // Pointer to the container's iterator
        EventIterator* inner_iterator; 
    };
}

#endif  /**  EVENT_CONTAINER_H_  */

