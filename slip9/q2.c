#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main() {
    struct node* root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert\n");
        printf("2. Postorder traversal\n");
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
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
