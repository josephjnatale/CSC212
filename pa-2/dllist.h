#ifndef __dllist_h__
#define __dllist_h__

#include <cstdint>

// this class represents each memory block ... it can be used for representing a
// node in a doubly linked list.
// You wiil have to give 'friend' access to the class that implements the doubly
// linked list, so the pointers can be accessed (adjusted) from outside the class.
class MemBlock {

    public:
        uint32_t address;
        uint32_t size;

        MemBlock *nxt;
        MemBlock *prv;

    
        MemBlock(uint32_t a, uint32_t s);
        ~MemBlock();

        void shrink_by(uint32_t s);
        uint32_t get_addr();
        uint32_t get_size();

    friend class DLList;
    //

};

class DLList {

    public:
        MemBlock *head;
        MemBlock *tail;

    
        DLList();
        ~DLList();

        // insert your functions here
        void push_back(uint32_t a, uint32_t s);
        void insert(uint32_t a, uint32_t s);
        void display();
        MemBlock *find_first_by_size(uint32_t b);
        void remove(MemBlock *p);
        MemBlock *find_by_address(uint32_t a);
        MemBlock *find_best_fit(uint32_t b);

};

#endif
