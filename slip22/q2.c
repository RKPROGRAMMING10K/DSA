#include <stdio.h>
#include <stdlib.h>
#include "q2.h"
int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &data);
                createNode(data);
                printf("Node crerated successfully!\n");
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully!\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
