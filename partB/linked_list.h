#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../partA/exceptions.h"

namespace mtm {

    template <class T>
    struct Node{
        Node<T>* next;
        T* element;
    };


    template<class T>
    class LinkedList {
        Node<T>* head;
        Node<T>* iterator;
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& list);
        ~LinkedList();
        int size();
        bool contains(const T& element);
        void insert(const T& element);
        void removeElement(const T& element);
        T* getFirst();
        T* getNext();
    };
}

using mtm::Node;
using mtm::LinkedList;

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL ,iterator = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list){
    if(list.head == NULL){
        head = NULL;
        return;
    }
    head = new Node<T>;
    head->element = new T(*list.head->element);
    head->next = NULL;
    Node<T>* to_add = list.head->next;
    Node<T>* temp_head_ptr = head;

    while(to_add){
        Node<T>* new_element = new Node<T>;
        new_element->element = new T(*to_add->element);
        new_element->next = NULL;
        temp_head_ptr->next = new_element;
        temp_head_ptr = temp_head_ptr->next;
        to_add = to_add->next;
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    while(head)
    {
        Node<T>* to_delete = head;
        head = head->next;
        delete to_delete->element;
        delete to_delete;
    }
}

template<class T>
int LinkedList<T>::size(){
    Node<T>* temp = head;
    int counter = 0;
    while(temp){
        temp = temp->next;
        counter++;
    }
    return counter;
}

template<class T>
bool LinkedList<T>::contains(const T& element){
    if(head == NULL){
        return false;
    }
    Node<T>* temp = head;
    while(temp){
        if(*temp->element == element){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::insert(const T& element){
    if(head == NULL){
        head = new Node<T>;
        head->element = new T(element);
        head->next = NULL;
        return;
    }
    if(element < *head->element){
        Node<T>* new_head = new Node<T>;
        new_head->element = new T(element);
        new_head->next = head;
        head = new_head;
        return;
    }
    Node<T>* temp = head;
    while(temp->next && element > *temp->next->element){
            temp = temp->next;
    }
    Node<T>* to_add = new Node<T>;
    to_add->element = new T(element);
    to_add->next = temp->next;
    temp ->next = to_add;
    return;
}

template<class T>
void LinkedList<T>::removeElement(const T& element){
    Node<T>* temp = head;
    if(!temp){
        return;
    }
    if(*temp->element == element)
    {
        head = head->next;
        delete temp->element;
        delete temp;
        return;
    }
    while(temp->next && *temp->next->element != element)
    {
        temp = temp->next;
    }
    if(!temp->next)
    {
        return;
    }
    Node<T>* to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete->element;
    delete to_delete;
    return;
}

template<class T>
T* LinkedList<T>::getFirst(){
    if(!head){
        return NULL;
    }
    iterator = head;
    return head->element;
}

template<class T>
T* LinkedList<T>::getNext(){
    if(!iterator->next){
        return NULL;
    }
    iterator = iterator->next;
    return iterator->element;
}

#define LL_FOREACH(type, iterator, listname) \
    for(type iterator = listname->getFirst() ; \
        iterator ;\
        iterator = listname->getNext())





#endif /**  LINKED_LIST_H  */