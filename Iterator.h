#ifndef   ITERATOR_H
#define   ITERATOR_H
#include "Node.h"
#include "List.h"

// let the compiler know these classes will be defined
class Node;
class List;
class Iterator{
    public:
               /**Constructs an iterator that does not point to any list.*/
                Iterator();

                /** Looks up the value at a position.
                @return the value of the node to which the iterator points */
                int operator*() const;

                /** Advances the iterator to the next node.*/
                Iterator& operator++(int);

                // /** Moves the iterator to the previous node. */
                Iterator& operator--(int);

                // /** Compares two iterators
                // @param b the iterator to compare with this iterator
                // @return true if this iterator and b are equal
                // */
                bool operator==(const Iterator& b) const;
                bool operator!=(const Iterator& b) const;
    private:
                Node* position;
                List* container;
                friend class List;                
};

#endif