#include "linked_list.h"
#include "base_event.h"
#include "open_event.h"
#include "closed_event.h"
#include "event_container.h"
#include "festival.h"
#include "custom_event.h"
#include "../partA/exceptions.h"
#include "../partA/date_wrap.h"
#include<iostream>
using mtm::LinkedList;
using mtm::OpenEvent;
using mtm::BaseEvent;
using mtm::ClosedEvent;
using mtm::CustomEvent;
using mtm::DateWrap;
using mtm::EventContainer;
using mtm::Festival;
using namespace std;


typedef mtm::EventContainer::EventIterator Iter;

void printEventsShort(mtm::EventContainer& events) {
    for (Iter iter = events.begin(); iter != events.end(); ++iter) {
        mtm::BaseEvent& event = *iter;
        event.printShort(std::cout);
    }
}


struct StudentFilter {
    bool operator()(int student) {
        return student == 1 || student == 3 || student == 20000;
    }
};


int main() {
    
    /*
    LinkedList<int> listi;
    cout << listi.size() << endl;
    listi.insert(20);
    cout << listi.size() << endl;
    for(int i=3;i<22;i++){
        listi.insert(i);
    }
    cout << listi.size() << endl;

    LinkedList<int> list2(listi);
    cout << list2.size() << endl;
        list2.insert(44);
    list2.insert(7);


    cout << list2.contains(8) << endl;
    cout << list2.contains(32) << endl;
    cout << list2.contains(20) << endl;

    list2.removeElement(20);
    list2.removeElement(20);
    cout << list2.size() << endl;
    cout << list2.contains(20) << endl;    

    cout << list2.size() << endl;
    cout << list2.contains(20) << endl;

    LinkedList<int>* plist2 = &list2;

    LL_FOREACH(int*, iter, plist2){
    cout << *iter << endl;
    }

    LinkedList<DateWrap> list1();
    DateWrap date1(1,1,1);
    list1.insert(date1);
    LinkedList<DateWrap>* plist1 = &list1;

    LL_FOREACH(DateWrap*, iter, plist1){
        cout << *iter << endl;
    }
    */

    OpenEvent oe(DateWrap(5,12,-235325), "mamam");
    oe.registerParticipant(4);
    oe.registerParticipant(7);
    try{ 
        oe.registerParticipant(7);
    } catch(mtm::AlreadyRegistered) {
            cout << "AlreadyRegistered" << endl;
    }
    try{ 
        oe.registerParticipant(-1);
    } catch(mtm::InvalidStudent) {
            cout << "InvalidStudent" << endl;
    }    
    try{ 
        oe.registerParticipant(1234567899);
    } catch(mtm::InvalidStudent) {
            cout << "InvalidStudent" << endl;
    }

    BaseEvent* oe2 = oe.clone();
    oe2->registerParticipant(1);
    oe2->registerParticipant(43535);
    oe2->registerParticipant(4353);

    cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
    oe.printLong(std::cout);
    oe.printShort(std::cout);
    cout << "!!!!!!!!!!!!!!!!!!!" << endl;

    oe2->printShort(std::cout);
    oe2->printLong(std::cout);
    //delete oe2;
    cout << "$$$$$$$$$$$$$$$$$$$$$" << endl;
    
    ClosedEvent ce1(DateWrap(5,12,-235325), "I am Date!");
    ce1.addInvitee(55);
    ce1.addInvitee(12);
    ce1.addInvitee(33);
    ce1.addInvitee(22);
    try{ 
        ce1.registerParticipant(55);
    } catch(mtm::InvalidStudent) {
            cout << "will not print" << endl;
    }    
    try{ 
        ce1.registerParticipant(56);
    } catch(mtm::RegistrationBlocked) {
            cout << "RegistrationBlocked" << endl;
    }

    BaseEvent* ce2 = ce1.clone();
    ce2->unregisterParticipant(55);
    ce2->registerParticipant(33);
    ce2->registerParticipant(12);

    cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
    ce1.printLong(std::cout);
    ce1.printShort(std::cout);
    cout << "!!!!!!!!!!!!!!!!!!!" << endl;
    
    ce2->printShort(std::cout);
    ce2->printLong(std::cout);
    //delete ce2;
    cout << "&&&&&&&&&&&&&&&&&&&&" << endl;

    CustomEvent<StudentFilter> cc1(DateWrap(5,12,-235325), "I am Almog!", StudentFilter());
    cc1.registerParticipant(1);
    cc1.registerParticipant(3);

    try{ 
        cc1.registerParticipant(55);
    } catch(mtm::RegistrationBlocked) {
            cout << "RegistrationBlocked" << endl;
    }    
    try{ 
        cc1.registerParticipant(56);
    } catch(mtm::RegistrationBlocked) {
            cout << "RegistrationBlocked" << endl;
    }

    cc1.printLong(std::cout);
    cc1.printShort(std::cout);
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;

    Festival festi(DateWrap(5,12,-235325));
    festi.add(cc1);
    festi.add(ce1);
    festi.add(*ce2);
    festi.add(oe);
    try{
        festi.add(*oe2);
    } catch(mtm::DateMismatch){
        cout << "never gonna see me!" << endl;
    }
    ClosedEvent ce3(DateWrap(5,11,-235325), "I am Date, too!");
    try{
        festi.add(ce3);
    } catch(mtm::DateMismatch){
        cout << "me on the other hand..." << endl;
    }
    printEventsShort(festi);

    delete oe2;
    delete ce2;


    return 0;
}