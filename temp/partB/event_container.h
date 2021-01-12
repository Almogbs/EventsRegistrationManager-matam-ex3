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
            void setIteratorToEvent(BaseEvent& event);
            
            BaseEvent* current_event;
            EventContainer* current_container;

        };

        EventContainer();
        virtual ~EventContainer();
        virtual void add(const BaseEvent&) = 0;
        EventIterator& begin();
        EventIterator& end();
        void setIteratorNextEvent();

    protected:
        LinkedList<BaseEvent>* event_list;
        EventIterator* dummy_iterator;
        EventIterator* iterator; 
    };
}

#endif  /**  EVENT_CONTAINER_H_  */
