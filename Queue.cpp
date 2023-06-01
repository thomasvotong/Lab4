#include "Queue.h"

Queue::Queue() : SinglyLinkedList() {}

//Instantiates list
void Queue::createQueue() {
    createList();
}

//Enqueues currency
void Queue::enqueue(Currency* currency) {
    addCurrency(currency, countCurrency());
}


//Dequeues currency
Currency* Queue::dequeue() {
    if (isListEmpty()) {
        throw std::string("Queue is empty");
    }

    return removeCurrency(0);
}

//Peek front currency
Currency* Queue::peekFront() {
    if (isListEmpty()) {
        throw std::string("Queue is empty");
    }

    return getCurrency(0);
}

//Peek rear
Currency* Queue::peekRear() {
    if (isListEmpty()) {
        throw std::string("Queue is empty");
    }

    return getCurrency(countCurrency() - 1); // replaced count with countCurrency()
}

//Print queue list
std::string Queue::printQueue() {
    return printList();
}

//Delete queue
void Queue::destroyQueue() {
    destroyList();
}


bool Queue::isEmpty() const {
    return (getCount() == 0);
}

