#ifndef BSTNODE_H
#define BSTNODE_H

#include "Krone.h"

class BSTNode {
private:
    Krone* data;
    BSTNode* left;
    BSTNode* right;

public:
    BSTNode(Krone* value);
    Krone* getData() const;
    void setData(Krone* value);
    BSTNode* getLeft() const;
    void setLeft(BSTNode* node);
    BSTNode* getRight() const;

    void setRight(BSTNode* node);
};

#endif
