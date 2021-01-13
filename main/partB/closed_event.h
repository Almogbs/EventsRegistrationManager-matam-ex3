#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "base_event.h"
#include "linked_list.h"

using mtm::BaseEvent;

namespace mtm { 
    class ClosedEvent : public BaseEvent {
        LinkedList<int>* invitee_list;
    public:
        ClosedEvent(const DateWrap&, const string&);
        ~ClosedEvent();
        void addInvitee(int invitee_num);
        void registerParticipant(int participant_num);
        void unregisterParticipant(int participant_num);
        bool inviteeListContains(int invitee_num);
        BaseEvent* clone() const;
    };
}
#endif  /**  CLOSED_EVENT_H_  */