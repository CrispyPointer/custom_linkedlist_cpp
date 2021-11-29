#ifndef   NODE_H
#define   NODE_H
#include "List.h"
#include "Iterator.h"

// let the compiler know these classes will be defined
class List;
class Iterator;
class Node{
        public:
                    /** 
                        Constructs a node with a given data value.
                        @param n the data to store in this node
                    */
                    Node(int n);
        private:
                    int data;
                    Node* previous;
                    Node* next;
                    friend class List;
                    friend class Iterator;                    
};

#endif