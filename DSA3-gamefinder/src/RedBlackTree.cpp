#include "RedBlackTree.h"


/*================================================ FUNCTIONS TO CREATE RED BLACK TREE ==============================================================================*/

// AMF - 4/22/25 
// UPDATES: Some of the more relavent changes to help get the Red Black Tree Working...
// 1. A private varible named currNode is private and can locate the last inserted node, this solves the problem of having helperInsert return the root only. 
// currNode acts like a bookmark
// 2. Fixed the the retrival of the uncle in case_violation, we check what side of the grandparent the parent is on to determine the uncle
// 3. Had rotate_helper be called in the rotation functions
// 4. Cleaned up rotations/a little refactoring


void RedBlackTree::insert(string name, vector<string> genres, string plot, int year, string age_rating, int votes, float rating) {
    
    // HELPER INSERT returns the root of the tree
    // In order to call case_violation, we must get the last inserted node...

    root = helperInsert(root, name, genres, plot, year, age_rating, votes, rating);
    case_violation(currNode);

    // UNCOMMENT ME FOR DEBUG/TEST //

    //cout << root->name << endl;
    //cout << currNode->name << ": ";
    //cout << currNode->rating <<  " ";
    //if (currNode->red == true) {
    //    cout << "red" << endl;
    //}
    //else {
    //    cout << "black" << endl;
    //}

}

// Restored Laurence's Previous Insert

Node* RedBlackTree::helperInsert(Node* curr, string name, vector<string> genres, string plot, int year, string age_rating, int votes, float rating) {

    // Base case

    if (curr == nullptr) {
        Node* node = new Node(name, rating, genres, plot, year, age_rating, votes, true);
        currNode = node;
        node->height = 1;
        if (root == nullptr) {
            root = node;
            root->red = false;
        }
        return node;
    }

    // IF the rating is less than the current rating

    if (rating < curr->rating) {
        curr->left = helperInsert(curr->left, name, genres, plot, year, age_rating, votes, rating);
        curr->left->parent = curr;
    }

    // IF the rating is greater than the current rating

    if (rating > curr->rating) {
        curr->right = helperInsert(curr->right, name, genres, plot, year, age_rating, votes, rating);
        curr->right->parent = curr;
        // if the parent and the child are red, and the uncle is red, recolor the parent and uncle to black and check the grandparent
    }

    // IF the rating equals the current rating, order them alphabetically

    if (rating == curr->rating) {
        if (name > curr->name) {
            curr->left = helperInsert(curr->left, name, genres, plot, year, age_rating, votes, rating);
            curr->left->parent = curr;
        }
        else {
            curr->right = helperInsert(curr->right, name, genres, plot, year, age_rating, votes, rating);
            curr->right->parent = curr;
        }
    }

    return curr;
}

// Restored Laurence's Previous Case Violation
// A recursive appraoch is used to ensure that two consecutive nodes are not red


void RedBlackTree::case_violation(Node* curr) {

    // IF we get to the root, we finish and return nothing

    if (!curr || !curr->parent || !curr->parent->parent) {
        root->red = false; // Make sure that the root is always black
        return;
    }

    // Grab the nodes parent, and grandparent

    Node* parent = curr->parent;
    Node* grandparent = parent->parent;

    // DO THIS only if there is two consecutive red nodes.

    if (curr->red == true && curr->parent->red == true) {

        Node* uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

        // CHECK if the parent and the uncle are the same color...red

        if (uncle && uncle->red == true) {

            uncle->red = false;
            parent->red = false;
            grandparent->red = true;

            // RECURSION CALL
            case_violation(grandparent);
        }

        // The uncle is black here. Based on the case, we rotate and recolor nodes. 

        else {

            if (parent == grandparent->left && curr == parent->right) {// left right case

                curr = rotate_left(parent);
                curr->parent->red = false;
                grandparent->red = true;
                rotate_right(grandparent);
            }

            else if (parent == grandparent->left && curr == parent->left) {// left left case
                parent->red = false;
                grandparent->red = true;
                rotate_right(grandparent);
            }


            else if (parent == grandparent->right && curr == parent->left) { // right left case
                curr = rotate_right(parent);
                curr->parent->red = false;
                grandparent->red = true;
                rotate_left(grandparent);

            }


            else if (parent == grandparent->right && curr == parent->right) { // right right case
                parent->red = false;
                grandparent->red = true;
                rotate_left(grandparent);
            }
            
        }
    }

}

   
Node* RedBlackTree::rotate_left(Node* o_parent) {


    Node* new_parent = o_parent->right;


    // This makes sure that children attached to the new parent get attached to the old parent's right 

    Node* temp = new_parent->left;
    o_parent->right = temp;

    // IF a node exists, we have to establish a valid parent 

    if (temp != nullptr) {
        temp->parent = o_parent;
    }

    // Make the new parent's parent be old parent's parent 

    new_parent->parent = o_parent->parent;

    rotate_helper(o_parent, new_parent);
    
    // rotation occurs

    new_parent->left = o_parent;
    o_parent->parent = new_parent;

    return o_parent;

    // Older Code
    //Node* new_parent = parent->right;
    //Node* temp = new_parent->left;

    //new_parent->left = parent;
    //parent->right = temp;

    //if (temp) {
    //    temp->parent = parent;
    //}
    //// new_parent->parent = parent->parent;
    //parent->parent = new_parent;
    //return new_parent;

}

Node* RedBlackTree::rotate_right(Node* o_parent) {

    // o stands for old,, old parent.


    Node* new_parent = o_parent->left;

    // This makes sure that children attached to the new parent get attached to the old parent's left 

    Node* temp = new_parent->right;
    o_parent->left = temp;

    // IF a node exists, we have to establish a valid parent 

    if (temp != nullptr) {
        temp->parent = o_parent;
    }

    // Make the new_parent's parent be old_parent's parent 

    new_parent->parent = o_parent->parent;
    rotate_helper(o_parent, new_parent);

    // rotation occurs

    new_parent->right = o_parent;
    o_parent->parent = new_parent;

    return o_parent;

    // Older Code
    //Node* new_parent = parent->left;
    //Node* temp = new_parent->right;
    //new_parent->right = parent;
    //parent->left = temp;
    //if (temp) {
    //    temp->parent = parent;
    //}
    //// new_parent->parent = parent->parent;
    //parent->parent = new_parent;
    //return new_parent;


}


void RedBlackTree::rotate_helper(Node* &old_curr, Node* &new_curr) { // reconnect the new root to the rest of the tree

    // This function reconnects the new root to the rest of the tree, and decides which side of the parent the node should attached to...

    // IF the parent is null, make the new root of the whole tree, the new_parent 

    if (old_curr->parent == nullptr) {
        root = new_curr;
    }
    else {
        if (old_curr == old_curr->parent->left) { // IF the old parent was on the grandparents, left, then attach the new parent to the left of the grandparent
            old_curr->parent->left = new_curr;
        } 
        else if (old_curr = old_curr->parent->right) { // IF the old parent was on the grandparents, right, then attach the new parent to the right of the grandparent
            old_curr->parent->right = new_curr;
        }
    }

    // Old Code 
    //if (old_curr->parent == nullptr) {
    //    root = new_curr;
    //} else if (old_curr == old_curr->parent->left) {
    //    old_curr->parent->left = new_curr;
    //} else {
    //    old_curr->parent->right = new_curr;
    //}
    //if (new_curr) {
    //    new_curr->parent = old_curr->parent;
    //}

    // This connects to a parent

}




/*================================================ FUNCTIONS TO OPERATE ON RED BLACK TREE ==============================================================================*/


void RedBlackTree::findTopTen() {
    counter = 0;

    cout << "Top 10 Games by IMBD Rating (found using Red Black Tree data structure): \n\n" << std::endl;
    helperfindTopTen(this->root);
}
void RedBlackTree::findTopTenGenre(string genre) {
    counter = 0;
    string genre_copy = genre;

    // Capitalize the genre input for printing purposes

    for (char& c : genre) {
        c = toupper(c);
        break;
    }

    cout << "Top 10 Games in " << genre << " by IMBD Rating (found using Red Black Tree Data Structure) \n\n" << std::endl;
    helperfindTopTenGenre(this->root, genre_copy);
}
void RedBlackTree::findGame(string name) {

    Node* searchNode = search(this->root, name);

    if (searchNode != nullptr) {

        printGame(searchNode);
    }
    else {

        cout << "Sorry, it looks like we don't have the game here :(" << endl;
    }
}

void RedBlackTree::helperfindTopTen(Node* root) {
 // AMF 4/18/25 - This findTopTen() is based off an inOrder traversal but in 
 // the reverse order (right->root->left) to get the game with the max rating (Since a RBT is also a BST)

    if (root == nullptr || counter == 10) {
        return;
    }
   
    helperfindTopTen(root->right);
    if (counter < 10) {
        printGame(root);
    }
    counter++;
    helperfindTopTen(root->left);

}
void RedBlackTree::helperfindTopTenGenre(Node* root, string genre) {

    // AMF 4/18/25 - findTopTenGenre() is based off a reverse inOrder traversal, 
    // IF selected genre is in the game's vector of genres, print it out

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
        printGame(root);
        counter++;
    }

    helperfindTopTenGenre(root->left, genre);
}
Node* RedBlackTree::search(Node* curr, string name) {
    // AMF 4/18/25 - The search function is implemented as a DFS

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

void RedBlackTree::inOrder() {
    bool current = true;
    helperInorder(this->root, current);
}

void RedBlackTree::printGame(Node* root) {
    cout << counter + 1 << ". " << root->name << " (" << root->year << ")" << " | Certification: " + root->age_rating + " | IMBD rating : " << root->rating << " | IMBD votes : " << root->votes << "\n======================================================================================================\n" << root->plot << "\n" << std::endl;
    cout << "Genres: ";

    for (int i = 0; i < root->genre.size(); i++) {
        if (i == root->genre.size() - 1)
            cout << root->genre[i] << endl;
        else
            cout << root->genre[i] << ", ";
    }

    cout << endl;
}






