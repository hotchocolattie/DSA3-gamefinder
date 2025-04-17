#include "RedBlackTree.h"

// AMF 4/16/25 - Implemented a basic insertion for BST, will change  into a RedBlack Tree


// void RedBlackTree::node_color_fix(Node *node) {
//     if (node == root) {
//         node->red = false;
//     }
// }

Node* RedBlackTree::helperInsert(Node* curr, string name, int rating) {
    if (curr == nullptr) {
        Node* node = new Node(name,rating,true);
        node->height = 1;
        if (root == nullptr) {
            root = node;
            root->red = false;
        }
        return node;
    }
    if (rating<curr->rating) {
        curr->left = helperInsert(curr->left, name, rating);
        curr->left->parent = curr;
        curr->left->red = true;

    } else{
        curr->right = helperInsert(curr->right, name, rating);
        curr->right->parent = curr;
        curr->right->red = true;
        // if the parent and the child are red, and the uncle is red, recolor the parent and uncle to black and check the grandparent

    }
     return curr;

}

void RedBlackTree::case_violation(Node* curr) {
    Node* parent  = curr->parent;
    Node* grandparent = parent->parent;
    if (parent->red == true && curr->red ==true) {
        parent->red = false;
        if (curr == parent->left) {
            grandparent->right->red = false;
        } else if(curr == parent->right) {
            grandparent->left->red = false;
        }
        grandparent->red = true;
    }
    case_violation(grandparent);
}


// void RedBlackTree::insert(string name) {
//     root = helperInsert(root, name);
// }
//
// // AMF 4/16/25 - Basic Inorder function for debugging
//
// void RedBlackTree::inOrderHelper(Node* root) {
//     if (root == nullptr) {
//         cout << "";
//     }
//     else {
//         inOrderHelper(root->left);
//         cout << root->_name << endl;
//         inOrderHelper(root->right);
//     }
// }

void RedBlackTree::inOrder() {
    inOrderHelper(this->root);
}