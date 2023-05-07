#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

void insert(node** root, int data) {
    if (*root == NULL) {
        node* new_node = (node*) malloc(sizeof(node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        *root = new_node;
    } else {
        if (data < (*root)->data) {
            insert(&((*root)->left), data);
        } else if (data > (*root)->data) {
            insert(&((*root)->right), data);
        }
    }
}

void display(node* root, int level, int* count) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
        (*count)++;
    } else if (level > 1) {
        display(root->left, level - 1, count);
        display(root->right, level - 1, count);
    }
}

void print_level_order(node* root) {
    if (root == NULL) {
        return;
    }
    int height = 0;
    node* current = root;
    while (current != NULL) {
        height++;
        current = current->left;
    }
    int i;
    for (i = 1; i <= height; i++) {
        int count = 0;
        display(root, i, &count);
        printf(" (Count: %d)\n", count);
    }
}

int main() {
    node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    print_level_order(root);
    return 0;
}
