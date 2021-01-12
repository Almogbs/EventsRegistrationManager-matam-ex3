#ifndef PARTICIPANT_H_
#define PARTICIPANT_H_

namespace mtm {
    class Participant {
    public:
        int num;
        Participant(int participant_num);
        Participant* clone();
    };
}

using mtm::Participant;

Participant::Participant(int participant_num){
    num = participant_num;
}

Participant* Participant::clone(){
    Participant* new_participant = new Participant(num);
    return
}


#endif /**  PARTICIPANT_H_  */