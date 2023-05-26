#pragma once

template <class T>
struct QueueNode {
	T item;
	QueueNode *next;

	QueueNode(T const &item) {
		this->item = item;
		this->next = NULL;
	}
};

template <class T>
class Queue {
private:
	QueueNode<T> *head, *tail;
	int NOElement;
public:
	Queue();
	~Queue();
	void Enqueue(T const &item);
	T Front();
	T Dequeue();
	bool IsEmpty();
	int Size();
};

// Constructor
template <class T>
Queue<T>::Queue() {
	printf("LIST BASED QUEUE!!!\n");
	this->head = this->tail = NULL;
	this->NOElement = 0;
}

// Destructor
template <class T>
Queue<T>::~Queue() {
	while (this->head) {
		QueueNode<T> *node = this->head;
		this->head = this->head->next;
		delete node;
	}
}

// Add an item to the queue
template <class T>
void Queue<T>::Enqueue(T const& item) {
	QueueNode<T> *node = new QueueNode<T>(item);

	if (this->tail == NULL) {
		this->head = this->tail = node;
	}
	else {
		this->tail->next = node;
		this->tail = node;
	}
	this->NOElement++;
}

// Return value of the first item
template <class T>
T Queue<T>::Front() {
	if (this->head == NULL) throw std::exception("Queue<T>::Dequeue: Empty queue");
	return this->head->item;
}

// Remove & Return value of the first item
template <class T>
T Queue<T>::Dequeue() {
	if (this->head == NULL) throw std::exception("Queue<T>::Dequeue: Empty queue");

	T item = this->head->item;
	QueueNode<T> *node = this->head;
	this->head = this->head->next;
	if (this->head == NULL) this->tail = NULL;
	delete node;
	this->NOElement--;
	return item;
}

// Check if the queue is empty
template <class T>
bool Queue<T>::IsEmpty() {
	if (this->head == NULL) return true;
	else return false;
}

// Returns size of the queue
template <class T>
int Queue<T>::Size() {
	return this->NOElement;
}