#include "List.h"
#include <iostream>
#include <cassert>


List::List(){
    first = NULL;
    last = NULL;
}

void List::push_back(int data){
    Node* new_node = new Node(data);
    if(last == NULL) //list is empty
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}

void List::insert(Iterator iter, int n){
    if (iter.position == NULL){
        push_back(n);
        return;
    }

    Node* after = iter.position;
    Node* before = after->previous;
    Node* new_node = new Node(n);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;

    if(before == NULL) first = new_node;//Insert at beginning
    else before->next=new_node;
}

Iterator List::erase(Iterator iter){
    assert(iter.position != NULL);
    Node* remove = iter.position;
    Node* before = remove->previous;
    Node* after = remove->next;

    if(remove == first) first = after;
    else before->next = after;
    if(remove == last) last = before;
    else after->previous = before;
    delete remove;
    Iterator r;
    r.position = after;
    r.container = this;
    return r;
}

Iterator List::begin(){
    Iterator iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

Iterator List::end(){
    Iterator iter;
    iter.position = NULL;
    iter.container = this;
    return iter;
}

void List::reverse(){
    Node* current = first;
    Node* previous = NULL;
    Node* next = first->next;
    next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    first = previous;
}

void List::push_front(int data){
    Node* new_node = new Node(data);
    if(last == NULL) //list is empty
    {
        first = new_node;
        last = new_node;
    }
    else
    {
        new_node->next = first;
        first->previous = new_node;
        first = new_node;
    }
}

void List::sort(){
    //Node current will point to first
    Iterator iter;
    iter.position = NULL;
    Node* current = first;
    int tmp;

    if(first == NULL) return;
    else{
        while(current != NULL){
            //Iterator will point to node next to current
            iter.position = current->next;
            while(iter.position != NULL){
                //If current node's data is greater than iterator data, swap the data between them
                if(current->data > iter.position->data){
                    tmp = current->data;
                    current->data = iter.position->data;
                    iter.position->data = tmp;
                }
                iter.position = iter.position->next;
            }
            current = current->next;
        }
    }
}

void List::merge(List& l1, List& l2){
    Node* list1 = l2.first;
    Node* list2 = l1.first;
    Iterator iter;
    do{
        if(list1 != NULL) {
            push_back(list1->data);
            list1 = list1->next;
            iter.position = list2->next;
        } 
        if(list2 != NULL) {
            push_back(list2->data);
            list2 = list2->next;
            iter.position = list2;
        }
    } while(iter.position != nullptr);
}