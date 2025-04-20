#include "RedBlackTree.h"


// AMF 4/16/25 - Implemented a basic insertion for BST, will change  into a RedBlack Tree


// void RedBlackTree::node_color_fix(Node *node) {
//     if (node == root) {
//         node->red = false;
//     }
// }

Node* RedBlackTree::helperInsert(Node* curr, string name, vector<string> genres, string plot, float rating) {
    if (curr == nullptr) {
        Node* node = new Node(name,rating, genres, plot, true);
        node->height = 1;
        if (root == nullptr) {
            root = node;
            root->red = false;
        }
        return node;
    }
    if (rating < curr->rating) {
        curr->left = helperInsert(curr->left, name, genres, plot, rating);
        curr->left->parent = curr;
        curr->left->red = true;
    }

    if (rating > curr->rating) {
        curr->right = helperInsert(curr->right, name, genres, plot, rating);
        curr->right->parent = curr;
        curr->right->red = true;
        // if the parent and the child are red, and the uncle is red, recolor the parent and uncle to black and check the grandparent
    }
    if (rating == curr->rating) {
        if (name > curr->name) {
            curr->left = helperInsert(curr->left, name, genres, plot, rating);
            curr->left->parent = curr;
            curr->left->red = true;
        }
        else {
            curr->right = helperInsert(curr->right, name, genres, plot, rating);
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

 void RedBlackTree::insert(string name, float rating, string plot, vector<string> genres) {
     root = helperInsert(root, name, genres, plot, rating);
 }

//
// // AMF 4/16/25 - Basic Inorder function for debugging
////
 //void RedBlackTree::inOrderHelper(Node* root) {
 //    if (root == nullptr) {
 //        cout << "";
 //    }
 //    else {
 //        inOrderHelper(root->left);
 //        cout << root->_name << endl;
 //        inOrderHelper(root->right);
 //    }
 //}

void RedBlackTree::helperInorder(Node* curr, bool& first) {
    first = true;
    if (curr == nullptr) {
        return;
    }
    helperInorder(curr->left,first);
    if (!first) {
        cout<<", ";
    }
    cout<<curr->name << " : " << curr->rating << endl;
    first = false;
    helperInorder(curr->right,first);

}

Node* RedBlackTree::search(Node* curr, string name) {
    if (curr == nullptr) {
        return nullptr;
    }
    if (curr->name == name) {
        return curr;
    }

    // If it is found on the left, return the node
    if (search(curr->left, name) != nullptr) {
        return search(curr->left, name);
    }

    // if its not in the left subtree check the right subtree
    else {
        return search(curr->right, name);
    }

}


void RedBlackTree::inOrder() {
    bool current = true;
    helperInorder(this->root, current);
}

// AMF 4/18/25 - The search function is implemented as a DFS

void RedBlackTree::findGame(string name) {

    Node* searchNode = search(this->root, name);

    if (searchNode != nullptr) {

        // printing out game information...
        cout << "\n" << "Name: " << searchNode->name << endl;
        cout << "Rating: " << searchNode->rating << endl;
        cout << "Genres: ";

        for (int i = 0; i < searchNode->genre.size(); i++) {
            if (i == searchNode->genre.size() - 1)
                cout << searchNode->genre[i] << endl;
            else 
                cout << searchNode->genre[i] << ", ";
        }
        cout << "Plot: " << searchNode->plot << endl << "\n";
    }
    else {

        cout << "Sorry, it looks like we don't have the game here :(" << endl;
    }
}

// AMF 4/18/25 - This findTopTen() is based off an inOrder traversal but in 
// the reverse order (right->root->left) to get the game with the max rating (Since a RBT is also a BST)

void RedBlackTree::findTopTen() {
    counter = 0;

    cout << "--------------- TOP TEN GAMES BASED ON RATING ---------------" << "\n" << endl;
    helperfindTopTen(this->root);
    cout << "\n" << endl;
}

void RedBlackTree::helperfindTopTen(Node* root) {

    if (root == nullptr || counter == 10) {
        return;
    }
   
    helperfindTopTen(root->right);
    if (counter < 10) {
        cout << counter + 1 <<". " <<  root->name << " : " << root->rating << endl;
    }
    counter++;
    helperfindTopTen(root->left);

}


// AMF 4/18/25 - findTopTenGenre() is based off a reverse inOrder traversal, 
// IF selected genre is in the game's vector of genres, print it out

void RedBlackTree::findTopTenGenre(string genre) {
    counter = 0;
    string genre_copy = genre;

    // Capitalize the genre input for printing purposes

    for (char& c : genre) {
        c = toupper(c);
    }

    cout << "--------------- TOP TEN GAMES FOR " << genre << " ---------------" << "\n" << endl;
    helperfindTopTenGenre(this->root, genre_copy);
    cout << "\n" << endl;
}

void RedBlackTree::helperfindTopTenGenre(Node* root, string genre) {

    bool genreFound = false;


    if (root == nullptr || counter == 10) {
        return;
    }

    helperfindTopTenGenre(root->right, genre);

    for (int i = 0; i < root->genre.size(); i++) {
        if (root->genre[i] == genre) {
            genreFound = true;
        }
    }

    if (counter < 10 && genreFound == true) {
        cout << counter + 1 << ". " << root->name << " : " << root->rating << endl;
        counter++;
    }

    helperfindTopTenGenre(root->left, genre);
}
