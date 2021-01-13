#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "../partB/base_event.h"
#include "../partB/event_container.h"
#include "../partB/linked_list.h"

using mtm::BaseEvent;
using mtm::LinkedList;
using mtm::EventContainer;
using mtm::DateWrap;

namespace mtm { 
    class Schedule {

    public:
        Schedule();
        ~Schedule();
    };
}
#endif  /**  SCHEDULE_H_  */