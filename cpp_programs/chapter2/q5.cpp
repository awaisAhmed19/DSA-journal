// Build a binary tree (manual linking or via insert).
#include <iostream>

using namespace std;
struct Tree {
    int data;
    Tree* left = nullptr;
    Tree* right = nullptr;
    Tree(int i) : data(i), left(nullptr), right(nullptr) {}
};

void preorder(Tree* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Tree* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Tree* root = new Tree(10);
    root->left = new Tree(20);
    root->right = new Tree(30);

    cout << "preorder";
    preorder(root);

    cout << "inorder";
    inorder(root);

    cout << "postorder";
    postorder(root);
    delete root;
    return 0;
}
