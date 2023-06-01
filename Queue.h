#ifndef QUEUE_H
#define QUEUE_H

//Import header file
#include "SinglyLinkedList.h"

//Define class Queue as a member of SinglyLinkedList
class Queue : public SinglyLinkedList {


public:

    //Queue constructor
    Queue();

    //Initializes a queue
    void createQueue();

    //Adds currency object to the end of the queue
    void enqueue(Currency* currency);

    //Removes currency object from queue
    Currency* dequeue();

    //Returns element at front of queue
    Currency* peekFront();

    //Returns element at back of queue
    Currency* peekRear();

    //Returns contents of queue
    std::string printQueue();

    //Deletes queue and deallocates memory
    void destroyQueue();

    bool isEmpty() const; // Add the isEmpty member function

};

#endif 

