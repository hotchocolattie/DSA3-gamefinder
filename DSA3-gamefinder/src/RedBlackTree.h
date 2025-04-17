#pragma once
#include <string>
#include <iostream>
using namespace std;


// AMF 4/16/25 - RedBlackTree Class is based on https://www.onlinegdb.com/BygDgQCjI

class RedBlackTree {
private:

	struct Node {
		// TO-DO: for Laurence, the other attributes 
		Node* left;
		Node* right;
		string _name;
		Node(string x) : _name(x), left(nullptr), right(nullptr) {}

	};
	Node* root = nullptr;
	Node* helperInsert(Node* root, string name);
	void inOrderHelper(Node* root);

public:
	void insert(string name);
	void inOrder();
	void findTopTen();
	void findTopTenGenre();
	void findGame();
};

