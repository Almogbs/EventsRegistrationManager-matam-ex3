#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"

/** Constants */
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
        BaseEvent(const BaseEvent&);
        virtual ~BaseEvent();
        virtual void registerParticipant(int participant_num) = 0;
        virtual void unregisterParticipant(int participant_num) = 0;
        void printShort(ostream& os);
        void printLong(ostream& os);
        virtual BaseEvent* clone() const = 0;

        /**
        * participantListContains: Checks if the participant is registered to the event.
        *
        * @param participant_num - the number of the participant.
        * @return
        * 	ture - if the participant is registered to the event.
        * 	Otherwise, returns false.
        */
        bool participantListContains(int participant_num);

        /**
        * isValidparticipant: Checks if the participant's number is legal.
        *
        * @param participant_num - the number of the participant.
        * @return
        * 	ture - if the participant's number is legal.
        * 	Otherwise, returns false.
        */
        bool isValidparticipant(int participant_num);

        /**
        * getEventDate: Returns the date of the event.
        *
        * @return
        * 	const reference to the event's date.
        */ 
        const DateWrap& getEventDate() const;

        /**
        * getEventName: Returns the date of the name.
        *
        * @return
        * 	const reference to the event's name.
        */ 
        const string& getEventName() const;
        friend BaseEvent* copyEvent(const BaseEvent& event);
        friend bool operator==(const BaseEvent& event1, const BaseEvent& event2);
        friend bool operator<(const BaseEvent& event1, const BaseEvent& event2);
    };

    /**
    * copyEvent: Returns copy of the event.
    *
    * @param event - the target event.
    * @return
    * 	pointer to the cloned event.
    */ 
    BaseEvent* copyEvent(const BaseEvent& event);
    bool operator==(const BaseEvent& event1, const BaseEvent& event2);         
    bool operator<(const BaseEvent& event1, const BaseEvent& event2);
    bool operator!=(const BaseEvent& event1, const BaseEvent& event2);
    bool operator<=(const BaseEvent& event1, const BaseEvent& event2);
    bool operator>=(const BaseEvent& event1, const BaseEvent& event2);
    bool operator>(const BaseEvent& event1, const BaseEvent& event2);


    /**
    * copyInt: Allocates and returns new int with the value of num.
    *
    * @param num - the target number.
    * @return
    * 	pointer to the new int.
    */ 
    int* copyInt(const int& num);
}

#endif  /**  BASE_EVENT_H_  */
