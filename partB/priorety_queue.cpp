#include "priorety_queue.h"

using mtm::Node;
using mtm::PrioretyQueue;

template <class PQElement, class PQPriorety>
Node<PQElement, PQPriorety>::Node(const Node<PQElement, PQPriorety>& node){
    next(node.next), element(node.element), priorety(node.priorety);
}

template <class PQElement, class PQPriorety>
Node<PQElement, PQPriorety>::Node(PQElement& in_element, PQPriorety& in_priorety){
    next = NULL;
    element(new in_element);
    priorety(new in_priorety);
}

template <class PQElement, class PQPriorety>
Node<PQElement, PQPriorety>::~Node(){
    delete element;
    delete priorety;
}

template <class PQElement, class PQPriorety>
PrioretyQueue<PQElement, PQPriorety>::PrioretyQueue(){
    head = NULL;
}


template <class PQElement, class PQPriorety>
PrioretyQueue<PQElement, PQPriorety>::PrioretyQueue(PrioretyQueue<PQElement, PQPriorety>& pq){
    head(pq.head);
    Node<PQElement, PQPriorety>& temp_head(pq.head.next);
    Node<PQElement, PQPriorety>& new_head(head);
    while(temp_head){
        Node<PQElement, PQPriorety>& node(temp_head);
        new_head.next = node;
        new_head = new_head->next;
        temp_head = temp_head->next;
    }
}



