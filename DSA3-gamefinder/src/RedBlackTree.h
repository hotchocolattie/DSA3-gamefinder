//
// Created by lrncg on 4/17/2025.
//
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>
#include <string>
using namespace std;

	struct Node {
		// TO-DO: for Laurence, the other attributes
		Node* left;
		Node* right;
		Node* parent;
		string name;
		int rating;
		int height;
		bool red; // each time we insert a node in a red black tree, it's red
		Node(string x, int r, bool color = true, int h = 0) : name(x), rating(r),height(h), red(color),left(nullptr), right(nullptr) {}

	};
// AMF 4/16/25 - RedBlackTree Class is based on https://www.onlinegdb.com/BygDgQCjI

class RedBlackTree {
public:
	Node* root = nullptr;
	// void node_color_fix(Node* node);
	Node* helperInsert(Node* curr, string name, int rating);
	Node* rotate_left(Node* parent);
	Node* search(Node* curr,string name);
	Node* rotate_right(Node* parent);
	void inOrder(Node* root, bool& first);
	void case_violation(Node* curr);
	void rotate_helper(Node* old_curr,Node* new_curr);
	void insert(string name, int rating);
	// void inOrder();
	void findTopTen();
	void findTopTenGenre();
	void findGame();
};
//



#endif //REDBLACKTREE_H
