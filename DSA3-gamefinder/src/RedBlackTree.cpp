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
    if (rating == curr->rating) {
        if (name<curr->name) {
            curr->left = helperInsert(curr->left, name, rating);
            curr->left->parent = curr;
            curr->left->red = true;
        }
        else {
            curr->right = helperInsert(curr->right, name, rating);
            curr->right->parent = curr;
            curr->right->red = true;
        }
    }
     return curr;

}

Node* RedBlackTree::rotate_left(Node* parent) {
    Node* new_parent = parent->right;
    Node* temp = new_parent->left;
    new_parent->left = parent;
    parent->right = temp;
    if (temp) {
        temp->parent = parent;
    }
    new_parent->parent = parent->parent;
    parent->parent = new_parent;
    return new_parent;

}

Node* RedBlackTree::rotate_right(Node* parent) {
    Node* new_parent = parent->left;
    Node* temp = new_parent->right;
    new_parent->left = parent;
    parent->left = temp;
    if (temp) {
        temp->parent = parent;
    }
    new_parent->parent = parent->parent;
    parent->parent = new_parent;
    return new_parent;

}

void RedBlackTree::case_violation(Node* curr) {
    if (!curr || !curr->parent || !curr->parent->parent) {
        return;
    }
    Node* parent = curr->parent;
    Node* grandparent = parent->parent;
    if (curr->red == true && parent->red == true) {
        Node* uncle = (grandparent->left) ? grandparent->left : grandparent->right;
        if (uncle && uncle->red == true) { // when the uncle is red
            uncle->red = false;
            curr->red = false;
            grandparent->red = true;
            case_violation(grandparent);
        }
        if (uncle && uncle->red == false) { // when the uncle is black
            if (parent == grandparent->left && curr == parent->right) {// left right case
                curr = rotate_left(parent);
                curr->parent->red = false;
                grandparent->red =true;
                grandparent = rotate_right(grandparent);
                rotate_helper(curr->parent,grandparent);
            }
            else if (parent == grandparent->right && curr == parent->left) { // right left case
                curr = rotate_right(parent);
                curr->parent->red = false;
                grandparent->red = true;
                grandparent = rotate_left(grandparent);
                rotate_helper(curr->parent,grandparent);
            }
            else if (parent == grandparent->left && curr == parent->left) {// left left case
                 parent->red = false;
                 grandparent->red = true;
                 grandparent = rotate_right(grandparent);
                rotate_helper(curr->parent,grandparent);
            }
            else if (parent == grandparent->right && curr == parent->right) { // right right case
                parent->red = false;
                grandparent->red = true;
                grandparent = rotate_left(parent);
                rotate_helper(curr->parent,grandparent);
            }
        }
    }
}

void RedBlackTree::rotate_helper(Node* old_curr, Node* new_curr) { // reconnect the new root to the rest of the tree
    if (old_curr->parent == nullptr) {
        root = new_curr;
    } else if (old_curr == old_curr->parent->left) {
        old_curr->parent->left = new_curr;
    } else {
        old_curr->parent->right = new_curr;
    }
    if (new_curr) {
        new_curr->parent = old_curr->parent;
    }
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

void RedBlackTree::inOrder(Node* curr, bool& first) {
    first = true;
    if (curr == nullptr) {
        return;
    }
    inOrder(curr->left,first);
    if (!first) {
        cout<<", ";
    }
    cout<<curr->rating;
    first = false;
    inOrder(curr->right,first);

}

Node* RedBlackTree::search(Node* curr, string name) {
    if (curr == nullptr || curr->name == name) {
        return curr;
    }
    if (name<curr->name){
    return search(curr->left, name);
    }
    if (name>curr->name) {
        return search(curr->right, name);
    }
}

