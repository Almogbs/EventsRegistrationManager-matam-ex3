#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "../partB/base_event.h"
#include "../partB/open_event.h"
#include "../partB/event_container.h"
#include "../partB/linked_list.h"

using mtm::BaseEvent;
using mtm::OpenEvent;
using mtm::LinkedList;
using mtm::EventContainer;
using mtm::DateWrap;
using std::endl;
using std::cout;

namespace mtm { 
    class Schedule {
        LinkedList<BaseEvent>* event_list;
    public:
        Schedule();
        ~Schedule();
        void addEvents(const EventContainer&);
        void registerToEvent(const DateWrap&, const string&, const int& participant_num);
        void unregisterFromEvent(const DateWrap&, const string&, const int& participant_num);
        void printAllEvents() const;
        void printMonthEvents(const int& month, const int& year) const;
        template<class T>
        void printSomeEvents(T predicate, bool verbose = false) const;
        //void printSomeEvents(bool predicate(const BaseEvent&), bool verbose = false) const;
        void printEventDetails(const DateWrap&, const string&) const;
        bool haveCommonEvent(const EventContainer&);
    };
}

using mtm::Schedule;

template<class T>
void Schedule::printSomeEvents(T predicate, bool verbose) const{
     for(BaseEvent* ptr_iter = event_list->getFirst(); ptr_iter != NULL; ptr_iter = event_list->getNext()){
        if(predicate(*ptr_iter)){
            verbose ? ptr_iter->printLong(cout) : ptr_iter->printShort(cout);   
        }
     }
}

#endif  /**  SCHEDULE_H_  */