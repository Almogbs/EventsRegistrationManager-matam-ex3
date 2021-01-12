#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"


#define MIN_STUDENT_ID 1
#define SEPERETOR " "
#define MAX_STUDENT_ID 1234567890

using std::string;
using std::ostream;
using mtm::DateWrap;
using mtm::LinkedList;


namespace mtm{ 
    class BaseEvent {
        string* name;
        DateWrap* date;
    protected:
        LinkedList<int>* participant_list;
    public:
        BaseEvent(const DateWrap&, const string&);
        virtual ~BaseEvent();
        virtual void registerParticipant(int participant_num) = 0;
        virtual void unregisterParticipant(int participant_num) = 0;
        void printShort(ostream& os);
        void printLong(ostream& os);
        virtual BaseEvent* clone() = 0;
        bool participantListContains(int participant_num);
        bool isValidparticipant(int participant_num);
        const DateWrap& getEventDate() const;
        const string& getEventName() const;
        friend bool operator==(const BaseEvent& event1, const BaseEvent& event2);
        friend bool operator<(const BaseEvent& event1, const BaseEvent& event2);
    };
    bool operator==(const BaseEvent& event1, const BaseEvent& event2);         
    bool operator<(const BaseEvent& event1, const BaseEvent& event2);
    bool operator!=(const BaseEvent& event1, const BaseEvent& event2);
    bool operator<=(const BaseEvent& event1, const BaseEvent& event2);
    bool operator>=(const BaseEvent& event1, const BaseEvent& event2);
    bool operator>(const BaseEvent& event1, const BaseEvent& event2);
}

#endif  /**  BASE_EVENT_H_  */