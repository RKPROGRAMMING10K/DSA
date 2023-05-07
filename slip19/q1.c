// Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, in order. Write a menu driven program that performs the above operations.


#include <stdio.h>
#include <stdlib.h>
#include "q1.h"
// Menu-driven program to perform BST operations
int main() {
    Node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
