#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "Queue.h"

class BST {
private:
    BSTNode* root;

    void destroyTree(BSTNode* node);
    void insert(BSTNode*& node, Krone* value);
    bool search(BSTNode* node, Krone* value) const;
    BSTNode* remove(BSTNode*& node, Krone* value);
    BSTNode* findMin(BSTNode* node) const;
    void breadthFirstTraversal(BSTNode* node) const;
    void inOrderTraversal(BSTNode* node) const;
    void preOrderTraversal(BSTNode* node) const;
    void postOrderTraversal(BSTNode* node) const;

public:
    BST();
    ~BST();

    void insert(Krone* value);
    bool search(Krone* value) const;
    void remove(Krone* value);
    void printTree() const;
};

#endif
