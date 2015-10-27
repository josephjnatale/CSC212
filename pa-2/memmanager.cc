#include "memmanager.h"

#include <iostream>

MemManager::MemManager(uint32_t m) {
    // makes an insertion into the 'free list'
    // this is the first memory block
    free_list.push_back(new MemBlock(0,m));
}

MemManager::~MemManager() {
    // traverse the free list and remove nodes
    for (int i = 0 ; i < free_list.size() ; i++) {
        delete free_list[i];
    }
    // traverse the used list and remove nodes
    for (int i = 0 ; i < used_list.size() ; i++) {
        delete used_list[i];
    }
}

void MemManager::coalesce() {
    // if you implement this function you earn bonus points
}

void MemManager::display() {
    // traverse and print details of the list of free blocks
    for (int i = 0 ; i < free_list.size() ; i++) {
        std::cout << free_list[i]->get_size() << "@" << free_list[i]->get_addr() << " -> ";
    }
    std::cout << "|" << std::endl;
    // traverse and print details of the list of used blocks
    for (int i = 0 ; i < used_list.size() ; i++) {
        std::cout << used_list[i]->get_size() << "@" << used_list[i]->get_addr() << " -> ";
    }
    std::cout << "|" << std::endl;
}

bool MemManager::alloc_first_fit(uint32_t b, uint32_t &address) {
    // this function implements allocation using the first fit strategy
    // first we traverse the list of free blocks ...
    for (int i = 0 ; i < free_list.size() ; i++) {
        // we check the size and find the first where a new block can be allocated
        if (b < free_list[i]->get_size()) {
            // this case occurs when the free memory block is greater than the
            // requested amount of bytes. Steps:
            // 1) decrease the amount of available bytes
            free_list[i]->shrink_by(b);
            // 2) create a new block and insert it into the used list
            used_list.push_back(new MemBlock(free_list[i]->get_addr()+free_list[i]->get_size(),b));
            // 3) remember to update the output argument 'address'
            address = used_list.back()->get_addr();
            // returns that allocation was OK
            return true;
        } else if (b == free_list[i]->get_size()) {
            // this case happens when the free memory block has the exact same
            // size as the requested amount of bytes. Steps:
            // 1) move the entire memory block from the free list to the used list
            used_list.push_back(free_list[i]);
            // 2) release the memory from the free list
            free_list.erase(free_list.begin()+i);
            // 3) remember to update the output argument "address"
            address = used_list.back()->get_addr();
            // returns that allocation was OK
            return true;
        }
    }
    return false;
}

bool MemManager::alloc_best_fit(uint32_t b, uint32_t &address) {
    // you will have to complete this function

    //address of smallest memory block
    uint32_t smallestBlock=10000000000;
    uint32_t &addressOfSmallestBlock;

    //search every block in free list, if one fits the bytes requested then swap them, if not find the smallest block that fits b.
    for(int i=0; i < free_list.size(); i++) {

        //byes requested is the same size as the memory block, always best fit
        if(b==free_list[i]->get_size()) {
            //move block memory from free list to used list
            used_list.push_back(free_list[i]);
            //release memory from free list
            free_list.erase(free_list.begin()+i);
            //update address
            address= used_list.back()->get_addr();

            //allocation successful
            reutrn true;
        }

        //if not exact size find the smallest block that could house b
        //if the block at i is smaller than the smallestblock found so far set the block at i to smallest block
        else if(free_list[i]->get_size() < smallestBlock && free_list[i]->get_size() > b) {

            smallestBlock = free_list[i]->get_size();
            addressOfSmallestBlock=free_list[i];       
        }
    }

    //if it made it to here then there are no block that fit it exactly, however it has found the smallest block that could houses the requested bytes
    
    return false;
}

bool MemManager::alloc_memory(uint32_t b, uint32_t &address, const std::string algo) {
    // this function only determines which algorithm to use for allocating a new blocks
    // then calls the proper function to handle the request
    if ( ! algo.compare("aff") ) {
        return alloc_first_fit(b, address);
    }
    if ( ! algo.compare("abf") ) {
        return alloc_best_fit(b, address);
    }
    // any other type different from 'aff' and 'abf' will not be processed
    return false;
}

bool MemManager::free_memory(uint32_t address) {
    // traverse the list of used memory blocks
    for (int i = 0 ; i < used_list.size() ; i++) {
        // if the address is found ...
        if (used_list[i]->get_addr() == address) {
            // first we need to find the index of the insertion point
            // we want to keep the free list in ascending order by memory address
            int idx = free_list.size();
            for (int j = 0 ; j < free_list.size() ; j++) {
                if (free_list[j]->get_addr() >= used_list[i]->get_addr()) {
                    idx = j;
                    break;
                }
            }
            // once we have the right index, we may proceed with insertion in the
            // free list.  Please note that we are just moving the block from one
            // list to the other
            free_list.insert(free_list.begin()+idx, used_list[i]);
            // then we can delete the node from the used list
            used_list.erase(used_list.begin()+i);
            return true;
        }
    }
    return false;
}
