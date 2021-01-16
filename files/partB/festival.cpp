#include "festival.h"

using mtm::Festival;
Festival::Festival(const DateWrap& date) : EventContainer(){
    festival_date = new DateWrap(date);
}

Festival::~Festival(){
    delete festival_date;
}

void Festival::add(const BaseEvent& event){
    if(event.getEventDate() != *festival_date){
        throw DateMismatch();
    }
    event_list->insert(event);
}
