#ifndef __dllist_h__
#define __dllist_h__

#include <cstdint>

// this class represents each memory block ... it can be used for representing a
// node in a doubly linked list.
// You wiil have to give 'friend' access to the class that implements the doubly
// linked list, so the pointers can be accessed (adjusted) from outside the class.
class MemBlock {

    private:
        uint32_t address;
        uint32_t size;

        MemBlock *nxt;
        MemBlock *prv;

    public:
        MemBlock(uint32_t a, uint32_t s) { address = a; size = s; }
        ~MemBlock() {}

        void shrink_by(uint32_t s) { size -= s; }
        uint32_t get_addr() { return address; }
        uint32_t get_size() { return size; }

    friend class DLList;

};

class DLList {

    private:
        MemBlock *head;
        MemBlock *tail;

    public:
        DLList();
        ~DLList();

        // insert your functions here
};

#endif
