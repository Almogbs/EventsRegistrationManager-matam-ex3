#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "base_event.h"
#include "linked_list.h"

using mtm::BaseEvent;

namespace mtm { 
    class OpenEvent : public BaseEvent {
    public:
        OpenEvent(const DateWrap&, const string&);
        void registerParticipant(int participant_num);
        void unregisterParticipant(int participant_num);
        BaseEvent* clone();
    };
}
#endif  /**  OPEN_EVENT_H_  */