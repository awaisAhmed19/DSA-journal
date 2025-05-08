#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height = 1;
} Node;

int getHeight(Node* curr) {
    if curr
        == NULL { return 0; }
    return curr->height;
}

int getBalance(Node* curr) {
    if curr
        == NULL { return 0; }
    return getHeight(curr->left) - getHeight(curr->right);
}

Node* rotateRight(Node* curr) {
    printf("rotate right on node %d", curr->data);
    Node* temp = (Node*)malloc(sizeof(Node*));
    Node* x = (Node*)malloc(sizeof(Node*));
    x = curr->left;
    temp = x->right;
    x->right = curr;
    curr->left = temp;
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}

Node* rotateLeft(Node* curr) {
    printf("rotate left on node %d", curr->data);
    Node* temp = (Node*)malloc(sizeof(Node*));
    Node* x = (Node*)malloc(sizeof(Node*));
    x = curr->right;
    temp = x->left;
    x->left = curr;
    curr->right = temp;
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}
struct Node* node(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bal = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }
    return root;
}

struct Node** binarytree(int arr[], int size) {
    int i = 0;
    struct Node** outarr = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++) {
        outarr[i] = node(arr[i]);
    }
    for (int i = 0; i < size; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size) {
            outarr[i]->left = outarr[left];
            if (right < size) {
                outarr[i]->right = outarr[right];
            }
        }
    }
    return outarr;
}

void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Node** output = binarytree(arr, size);
    int n = sizeof(output) / sizeof(output[0]);

    Node* root = NULL;
    for (int j = 0; j < size; j++) {
        root = insert(root, arr[j]);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(output[0]);
    printf("\n");
    preorder(output[0]);
    printf("\n");
    postorder(output[0]);
    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);
    return 0;
}
