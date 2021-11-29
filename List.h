#ifndef   LIST_H
#define   LIST_H
#include "Iterator.h"
#include "Node.h"

// let the compiler know these classes will be defined
class Node; 
class Iterator;
class List{
    public:
                /* Construcs an empty list; */
                List();
                /*Appends an element to the list.
                @param data the value to append*/
                void push_back(int data);

                /**Inserts an element into the list.
                @param iter the position before which to insert
                @param n the value to append*/
                void insert(Iterator iter, int n);

                /**Removes an element from the list.
                @param iter the position to remove
                @return an iterator pointing to the element after the
                erased element*/
                Iterator erase(Iterator iter);

                /**Gets the beginning position of the list.
                @return an iterator pointing to the beginning of the list*/
                Iterator begin();

                /**Gets the past-the-end position of the list.
                @return an iterator pointing past the end of the list
                */
                Iterator end();

                /**Reverse the nodes*/
                void reverse();

                /**add a value to the beginning of a list
                 @param data the value to append into the list*/
                void push_front(int data);

                /**Sort the elements of the Linked List*/
                void sort();

                /**Merges the two lists into one*/
                void merge (List& l1, List& l2);
    private:
                Node* first;
                Node* last;
                friend class Iterator;
};

#endif //LIST_H