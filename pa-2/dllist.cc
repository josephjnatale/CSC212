#include "dllist.h"

DLList::DLList() {

    head=NULL;
    tail=NULL;

}

DLList::~DLList() {
   destroyList();

}

void DLList::destroyList(){
	MemBlock *t = tail;
	while(t) {
		MemBlock *t2 = t;
		t = t->prv;
		delete t2;
	}
	head=NULL;
	tail=NULL;
}

void DLList::addAtHead(MemBlock* node) {

	//set the first memblocks prvious node to new node
	head->prv=node->address;
	//set new nodes next to heads address
	node->nxt=head->address;
	//set head to new node
	head=node;
}

void DLList::addAtTail(MemBlock* node) {

	//sets tails next to node
	tail->nxt=node->address;
	//set nodes prv to tails address
	node->prv=tail->address;
	//set nodes next equal to null
	node->nxt=NULL;
	//set tail to new node
	tail=node->address;
}

void DLList::removeNodeWithAddress(uint32_t address, MemBlock* node) {

	//if the node is not Null go into if, it it is null do nothing.
	if(node){
		if(node->address==adress){
			//prvious nodes nxt equals the next node
			node->prv->nxt=node->nxt;
			//the next nodes prv equals the prvious node
			node->nxt->prv=node->prv;
			delete node;
			break;
		}
		//if current nodes address does not equal the one you are looking for
		//call function again with the next node
		else
			removeNodeWithAddress(address, node->nxt);
	}

}

void DLList::printNodes(MemBlock* node) {

	//when the node does not equal NULL
	if(node) {
		std::cout<<node->get_size()<< "@" << node->get_address << " -> ";
		printNodes(node->nxt);
	}
}

