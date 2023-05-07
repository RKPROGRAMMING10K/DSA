#ifndef BTREE_H
#define BTREE_H

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->data) {
        root->left = insert_node(root->left, value);
    } else if (value > root->data) {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void preorder_traversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

#endif
