//1521 2021 1114 - Talha Yılmam
//1521 2020 1076 - Ahmet Kuddusi Albayrak

#include <iostream>
#include "Deque.h"

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	//queue is empty at creation:
	head = NULL;
	tail = NULL;
	noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	//start from head and delete until the end
	while(!this->IsEmpty()){
		this->RemoveFront();
	}
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	//create a new node:
	DequeNode* newNode = new DequeNode(item);

	//if this is a new element, set it as both head and tail
	//node's previous and next will stay as null:
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	//if there is an already existing element on queue,
	//set newNode's next to head
	//set the previous head's previous to newNode 
	//also set newNode as new head 
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	//increment element count
	noOfItems++;
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	//create a new node:
	DequeNode* newNode = new DequeNode(item);

	//if this is a new element, set it as both head and tail
	//node's previous and next will stay as null:
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	//if there is an already existing element on queue,
	//set newNode's previous to tail
	//set the tail's next to newNode 
	//also set newNode as new tail
	else{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	//increment element count
	noOfItems++;	
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	//if deque is empty:
	if (head == NULL) {
		throw std::exception("Empty Dequeue");
	}

	//store the value that will be deleted
	int num = head->item;

	//create a temp node to delete head
	DequeNode* temp = head;

	//move the head pointer to next element
	head = head->next;

	//if there are no items left after removing,
	//also set the tail as NULL
	if(head == NULL) {tail = NULL;}

	//delete the head (which is temp):
	delete temp;

	//decrement element count
	noOfItems--;

	return num;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	//if deque is empty:
	if (tail == NULL) {
		throw std::exception("Empty Dequeue");
	}

	//store the value that will be deleted
	int num = tail->item;

	//create a temp node to delete tail
	DequeNode* temp = tail;

	//move the tail pointer to previous element
	tail = tail->prev;

	//if there are no items left after removing,
	//also set the head as NULL
	if(tail == NULL) {head = NULL;}

	//delete the tail (which is temp):
	delete temp;

	//decrement element count
	noOfItems--;

	return num;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	//if deque is empty:
	if (tail == NULL) {
		throw std::exception("Empty Dequeue");
	}

	return head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	//if deque is empty:
	if (tail == NULL) {
		throw std::exception("Empty Dequeue");
	}

	return tail->item;
} //end-Rear
