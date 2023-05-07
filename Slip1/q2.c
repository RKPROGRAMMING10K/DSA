#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert node\n");
        printf("2. Preorder traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}
