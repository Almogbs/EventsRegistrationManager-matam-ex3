#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include "base_event.h"
#include "event_container.h"

using std::string;
using std::ostream;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::EventContainer;

namespace mtm{ 
    class Festival : public EventContainer {
        DateWrap* festival_date;
    public:
        Festival(const DateWrap&);
        ~Festival();
        void add(const BaseEvent&);
    };
}

#endif  /**  FESTIVAL_H_  */
