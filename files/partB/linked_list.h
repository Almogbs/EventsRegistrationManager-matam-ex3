#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../partA/exceptions.h"


/**
* Generic Linked List
*
* Implements a Linked List of generic type.
*
* The following methods are available:
*   size		                - Returns the size of the list
*   contains	                - returns whether or not an element exists inside the list.
*   insert	                    - Insert an element to the list.
*   removeElement		        - Removes specified element from the list
*   GetFirst	                - Sets the internal iterator to the first element in the list and returns it
*   GetNext		                - Advances the internal iterator to the next key and returns it.
*	getElement		            - Returns a pointer to same element within the list
* 	LL_FOREACH	                - A macro for iterating over the list's elements.
*/

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
        T* (*copy_function)(const T&);
        LinkedList(T* (*new_copy_function)(const T&));
        LinkedList(const LinkedList<T>& list);
        ~LinkedList();
        int size();
        bool contains(const T& element);
        void insert(const T& element);
        void removeElement(const T& element);
        T* getFirst();
        T* getNext();
        T* getElement(const T& element);
    };
}

using mtm::Node;
using mtm::LinkedList;

template<class T>
LinkedList<T>::LinkedList(T* (*new_copy_function)(const T&)){
    head = NULL ,iterator = NULL, copy_function = new_copy_function;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list){
    if(list.head == NULL){
        head = NULL ,iterator = NULL, copy_function = list.copy_function;
        return;
    }
    copy_function = list.copy_function;
    head = new Node<T>;
    head->element = copy_function(*list.head->element);
    head->next = NULL;
    Node<T>* to_add = list.head->next;
    Node<T>* temp_head_ptr = head;

    while(to_add){
        Node<T>* new_element = new Node<T>;
        new_element->element = copy_function(*to_add->element);
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

/**
* size: Returns the number of elements in a linked list.
*
* @return
* 	the number of elements in list.
*/
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

/**
* getElement: Returns a pointer to same element within the list.
*
* @param element - the target element.
* @return
* 	NULL - if the element was not found in the list or if the list is empty.
*   Otherwise, pointer to the element.
*/
template<class T>
T* LinkedList<T>::getElement(const T& element){
    if(head == NULL){
        return NULL;
    }
    Node<T>* temp = head;
    while(temp){
        if(*temp->element == element){
            return temp->element;
        }
        temp = temp->next;
    }
    return NULL;
}

/**
* contains: Checks if an element exists in the linked list.
*
* @param element - the target element.
* @return
* 	false - if the key element was not found.
* 	Otherwise, returns true.
*/
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

/**
*   insert: insert the element to the linked list, in the right place.
*
* @param element - the target element
*/
template<class T>
void LinkedList<T>::insert(const T& element){
    if(head == NULL){
        head = new Node<T>;
        head->element = copy_function(element);
        head->next = NULL;
        return;
    }
    if(element < *head->element){
        Node<T>* new_head = new Node<T>;
        new_head->element = copy_function(element);
        new_head->next = head;
        head = new_head;
        return;
    }
    Node<T>* temp = head;
    while(temp->next && element > *temp->next->element){
            temp = temp->next;
    }
    Node<T>* to_add = new Node<T>;
    to_add->element = copy_function(element);
    to_add->next = temp->next;
    temp ->next = to_add;
    return;
}

/**
*   removeElement: Removes element from the linked list which have its value equal to element.
*
* @param element - the target element
*/
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

/**
*	getFirst: set the list iterator to the first element and returns it.
*
* @return
* 	NULL if reached the end of the list(empty list)
* 	Otherwise, The first element on the linked list
*/
template<class T>
T* LinkedList<T>::getFirst(){
    if(!head){
        return NULL;
    }
    iterator = head;
    return head->element;
}

/**
*	getNext: Advances the list iterator to the next element and returns it.
*
* @return
* 	NULL if reached the end of the list
* 	Otherwise, The next element on the linked list
*/
template<class T>
T* LinkedList<T>::getNext(){
    if(!iterator->next){
        return NULL;
    }
    iterator = iterator->next;
    return iterator->element;
}

/**
* Macro for iterating over a linked list.
* Declares a new iterator for the loop.
*/
#define LL_FOREACH(type, iterator, listname) \
    for(type iterator = listname->getFirst() ; \
        iterator ;\
        iterator = listname->getNext())

#endif /**  LINKED_LIST_H  */
