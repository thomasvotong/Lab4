#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    destroyTree(root);
}

void BST::destroyTree(BSTNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BST::insert(Krone* value) {
    insert(root, value);
}

void BST::insert(BSTNode*& node, Krone* value) {
    if (node == nullptr) {
        node = new BSTNode(value);
    }
    else if (*value < *(node->data)) {
        insert(node->left, value);
    }
    else {
        insert(node->right, value);
    }
}

bool BST::search(Krone* value) const {
    return search(root, value);
}

bool BST::search(BSTNode* node, Krone* value) const {
    if (node == nullptr) {
        return false;
    }
    else if (*value == *(node->data)) {
        return true;
    }
    else if (*value < *(node->data)) {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}

void BST::remove(Krone* value) {
    root = remove(root, value);
}

BSTNode* BST::remove(BSTNode*& node, Krone* value) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (*value < *(node->data)) {
        node->left = remove(node->left, value);
    }
    else if (*value > *(node->data)) {
        node->right = remove(node->right, value);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        else {
            BSTNode* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
    }

    return node;
}

BSTNode* BST::findMin(BSTNode* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BST::printTree() const {
    std::cout << "Breadth-First Traversal: ";
    breadthFirstTraversal(root);
    std::cout << std::endl;

    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;
}

void BST::breadthFirstTraversal(BSTNode* node) const {
    if (node == nullptr) {
        return;
    }

    Queue breadthQueue;
    breadthQueue.createQueue();
    breadthQueue.enqueue(node->data);

    while (!breadthQueue.isEmpty()) {
        BSTNode* current = breadthQueue.dequeue();
        current->data->print();

        if (current->left != nullptr) {
            breadthQueue.enqueue(current->left);
        }
        if (current->right != nullptr) {
            breadthQueue.enqueue(current->right);
        }
    }
}

void BST::inOrderTraversal(BSTNode* node) const {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->left);
    node->data->print();
    inOrderTraversal(node->right);
}

void BST::preOrderTraversal(BSTNode* node) const {
    if (node == nullptr) {
        return;
    }

    node->data->print();
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void BST::postOrderTraversal(BSTNode* node) const {
    if (node == nullptr) {
        return;
    }

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    node->data->print();
}
