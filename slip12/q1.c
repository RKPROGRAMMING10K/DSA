#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary search tree node
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to traverse the tree in preorder
void preorder(Node* node) {
    if (node != NULL) {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, key;
    do {
        printf("Menu:\n");
        printf("1. Insert a key\n");
        printf("2. Preorder traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}
