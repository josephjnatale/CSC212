#include "dllist.h"

#include <iostream>

MemBlock::MemBlock(uint32_t a, uint32_t s) {
    address = a;
    size = s;
    nxt = NULL;
    prv = NULL;
}

MemBlock::~MemBlock() {
}

void MemBlock::shrink_by(uint32_t s) {
    size -= s;
}

uint32_t MemBlock::get_addr() {
    return address;
}

uint32_t MemBlock::get_size() {
    return size;
}

DLList::DLList() {

    head=NULL;
    tail=NULL;

}

DLList::~DLList() {
     // destroy the list
    MemBlock *p = head;
    while (p) {
        head = p->nxt;
        delete p;
        p = head;
    }

}

// this function will return a pointer to the first block in the list
// that has size >= than the input parameter b
// if no such a block exists, then NULL is returned 
MemBlock *DLList::find_first_by_size(uint32_t b) {
    MemBlock *p = head;
    while (p) {
        if (b <= p->size) {
            return p;
        }
        p = p->nxt;
    }
    return NULL;
}

MemBlock *DLList::find_best_fit(uint32_t b) {
	
	MemBlock *best_fit=NULL;
	//find if any equal the size
	MemBlock *p = head;
    while (p) {
        if (b == p->size) {
            return p;
        }
        p = p->nxt;
    }
    //start back at the beginning
    p=head;

    //find smallest used block that would work
    while(p) {
    	//if b is larger than p->size and p->size is smaller than best_fit-> then p is a better fit then best_fit
    	if(b < p->size){
    		if(best_fit==NULL)
    			best_fit=p; 
    		else if(best_fit->size < p->size) 
    			best_fit=p;
    	}

    	p=p->nxt;
    }

    return best_fit;

}

// remove the node pointed by parameter p from the list
// function assumes that there is a node in the list pointed by p
// (that means the list has at least 1 node)
// this method should be easier for DLList
void DLList::remove(MemBlock *p) {
    // use a double pointer for traversing the list
    MemBlock **q = &head;
    while (*q != p) {
        q = &((*q)->nxt);
    }
    // remove node p from list
    *q = p->nxt;
    delete p;
    // take care of tail
    tail = head;
    while (tail && tail->nxt) {
        tail = tail->nxt;
    }
}

void DLList::display() {
    // traverse the list displaying information of every node
    MemBlock *p = head;
    while (p) {
        std::cout << p->size << "@" << p->address << " -> ";
        p = p->nxt;
    }
    std::cout << "|" << std::endl;
}



// this function will return a pointer to the block in the list
// that has address equal to parameter a
// if no such a block exists, then NULL is returned 
MemBlock *DLList::find_by_address(uint32_t a) {
    MemBlock *p = head;
    while (p) {
        if (a == p->address) {
            return p;
        }
        p = p->nxt;
    }
    return NULL;
}

// create and insert a new node into the list
// insertion happens in ascending order of address
// I am using double pointers to write less code.
// You dont have to -- insertions in order are easier
// to implement when you deal with doubly linked lists
void DLList::insert(uint32_t a, uint32_t s) {
    // find insertion point using double pointers
    MemBlock **p = &head;
    while (*p && (*p)->address < a) {
        p = &((*p)->nxt);
    }
    // create the node
    MemBlock *q = new MemBlock(a, s);
    // adjust pointers -- make the actual insertion
    q->nxt = *p;
    *p = q;
    // update tail
    if (tail == NULL || tail->nxt ) {
        tail = q;
    } 
} 

// create a new node and append it to the end of the list
void DLList::push_back(uint32_t a, uint32_t s) {
    MemBlock *p = new MemBlock(a, s);
    if (!head) {
        head = tail = p;
    } else {
        tail->nxt = p;
        tail = p;
    }
}

