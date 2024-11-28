#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }
    return root;
}


Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data > root->data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}


void printSubtree(Node* root) {
    if (root == NULL) {
        return;
    }
    printSubtree(root->left);
    printf("%d ", root->data);
    printSubtree(root->right);
}

int main() {
    Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);

    int value = 2;

    // Search for the node with the given value
    Node* result = search(root, value);

    if (result) {
        printf("Subtree rooted at node with value %d: ", value);
        printSubtree(result);
        printf("\n");
    } else {
        printf("Node with value %d not found in the BST.\n", value);
    }

    return 0;
}
