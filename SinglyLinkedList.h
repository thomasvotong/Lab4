#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "LinkNode.h"

class SinglyLinkedList {

    //Private data 
private:
    int count;
    LinkNode* start;
    LinkNode* end;

public:

    //Member functions and a getter function to access private data (count)
    SinglyLinkedList();
    ~SinglyLinkedList();
    int getCount() const { return count; }

    void createList();
    void destroyList();

    void addCurrency(Currency* currency, int index);
    Currency* removeCurrency(Currency* currency);
    Currency* removeCurrency(int index);

    int findCurrency(Currency* currency);
    Currency* getCurrency(int index);

    std::string printList();
    bool isListEmpty();
    int countCurrency();
};

#endif 