#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : count(0), start(nullptr), end(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    destroyList();
}

void SinglyLinkedList::createList() {
    count = 0;
    start = nullptr;
    end = nullptr;
}

void SinglyLinkedList::destroyList() {
    LinkNode* current = start;
    while (current != nullptr) {
        LinkNode* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
    count = 0;
    start = nullptr;
    end = nullptr;
}

void SinglyLinkedList::addNode(BSTNode* node, int position) {
    if (position < 0 || position > count) {
        throw std::string("Invalid position");
    }

    LinkNode* newNode = new LinkNode(node);
    if (start == nullptr) {
        start = newNode;
        end = newNode;
    }
    else if (position == 0) {
        newNode->next = start;
        start = newNode;
    }
    else if (position == count) {
        end->next = newNode;
        end = newNode;
    }
    else {
        LinkNode* current = start;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    count++;
}

BSTNode* SinglyLinkedList::removeNode(int position) {
    if (start == nullptr) {
        throw std::string("List is empty");
    }

    if (position < 0 || position >= count) {
        throw std::string("Invalid position");
    }

    LinkNode* current = start;
    LinkNode* previous = nullptr;

    for (int i = 0; i < position; i++) {
        if (current == nullptr) {
            throw std::string("Invalid position");
        }
        previous = current;
        current = current->next;
    }

    if (previous == nullptr) {
        start = current->next;
    }
    else {
        previous->next = current->next;
    }

    if (current == end) {
        end = previous;
    }

    BSTNode* removedNode = current->data;
    delete current;
    count--;
    return removedNode;
}

BSTNode* SinglyLinkedList::getNode(int position) const {
    if (position < 0 || position >= count) {
        throw std::string("Invalid position");
    }

    LinkNode* current = start;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

int SinglyLinkedList::countNodes() const {
    return count;
}

bool SinglyLinkedList::isListEmpty() const {
    return (start == nullptr);
}
