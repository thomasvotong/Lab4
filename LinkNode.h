#ifndef LINKNODE_H
#define LINKNODE_H

//Import header files
#include "Currency.h"

//Declares LinkNode structure that creates pointers for currency object and the next pointer
struct LinkNode {
    Currency* data;
    LinkNode* next;

    //Constructor initializing currency pointer and setting next pointer to null
    LinkNode(Currency* currency) : data(currency), next(nullptr) {}
};

#endif 
