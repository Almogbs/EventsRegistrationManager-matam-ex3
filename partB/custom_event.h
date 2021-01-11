#ifndef CUSTOM_EVENT_
#define CUSTOM_EVENT_
#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "base_event.h"
#include "linked_list.h"

using mtm::BaseEvent;

namespace mtm { 
    template<class CanRegister>
    class CustomEvent : public BaseEvent {
    public:
        CanRegister* statement_function;
        CustomEvent(const DateWrap&, const string&, const CanRegister&);
        ~CustomEvent();
        void registerParticipant(int participant_num);
        void unregisterParticipant(int participant_num);
        BaseEvent* clone();
    };
}
#endif  /**  CUSTOM_EVENT_  */