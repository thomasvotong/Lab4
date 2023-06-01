#include <iostream>
#include <fstream>
#include "BST.h"

int main() {
    // Create BST
    BST bst;

    // Insert Krone objects into BST
    bst.insert(new Krone(57.12));
    bst.insert(new Krone(23.44));
    bst.insert(new Krone(87.43));
    bst.insert(new Krone(68.99));
    bst.insert(new Krone(111.22));
    bst.insert(new Krone(44.55));
    bst.insert(new Krone(77.77));
    bst.insert(new Krone(18.36));
    bst.insert(new Krone(543.21));
    bst.insert(new Krone(20.21));
    bst.insert(new Krone(345.67));
    bst.insert(new Krone(36.18));
    bst.insert(new Krone(48.48));
    bst.insert(new Krone(101.00));
    bst.insert(new Krone(11.00));
    bst.insert(new Krone(21.00));
    bst.insert(new Krone(51.00));
    bst.insert(new Krone(1.00));
    bst.insert(new Krone(251.00));
    bst.insert(new Krone(151.00));

    // Create output file
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Error creating output file!" << std::endl;
        return 1;
    }

    // Print traversals to screen and output file
    std::cout << "Breadth-First Traversal:" << std::endl;
    outputFile << "Breadth-First Traversal:" << std::endl;
    bst.printTree();

    std::cout << "In-Order Traversal:" << std::endl;
    outputFile << "In-Order Traversal:" << std::endl;
    bst.printTree();

    std::cout << "Pre-Order Traversal:" << std::endl;
    outputFile << "Pre-Order Traversal:" << std::endl;
    bst.printTree();

    std::cout << "Post-Order Traversal:" << std::endl;
    outputFile << "Post-Order Traversal:" << std::endl;
    bst.printTree();

    // Interact with the user
    int choice;
    do {
        std::cout << "\n1. Add node\n"
            << "2. Search node\n"
            << "3. Delete node\n"
            << "4. Print tree\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            std::cout << "Enter the amount: ";
            std::cin >> amount;
            bst.insert(new Krone(amount));
            break;
        }
        case 2: {
            double amount;
            std::cout << "Enter the amount: ";
            std::cin >> amount;
            Krone searchKey(amount);
            if (bst.search(&searchKey)) {
                std::cout << "Node found in the tree." << std::endl;
            }
            else {
                std::cout << "Node not found in the tree." << std::endl;
            }
            break;
        }
        case 3: {
            double amount;
            std::cout << "Enter the amount: ";
            std::cin >> amount;
            Krone deleteKey(amount);
            bst.remove(&deleteKey);
            break;
        }
        case 4: {
            std::cout << "Tree Traversals:" << std::endl;
            bst.printTree();
            break;
        }
        case 5: {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 5);

    outputFile.close();
    return 0;
}
