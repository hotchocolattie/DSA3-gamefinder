#include "RedBlackTree.h"

// AMF 4/16/25 - Implemented a basic insertion for BST, will change  into a RedBlack Tree

RedBlackTree::Node* RedBlackTree::helperInsert(Node* root, string name) {

    // AMF 4/16/26 - If the root is null, meaning the tree is empty, return a new node.

    if (root == nullptr)
        return new Node(name);

    if (name < root->_name)
        root->left = helperInsert(root->left, name);
    else
        root->right = helperInsert(root->right, name);

    return root;
}

void RedBlackTree::insert(string name) {
    root = helperInsert(root, name);
}

// AMF 4/16/25 - Basic Inorder function for debugging

void RedBlackTree::inOrderHelper(Node* root) {
    if (root == nullptr) {
        cout << "";
    }
    else {
        inOrderHelper(root->left);
        cout << root->_name << endl;
        inOrderHelper(root->right);
    }
}

void RedBlackTree::inOrder() {
    inOrderHelper(this->root);
}