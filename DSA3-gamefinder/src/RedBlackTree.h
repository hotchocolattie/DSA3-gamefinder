//
// Created by lrncg on 4/17/2025.
//
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

	struct Node {

		Node* left;
		Node* right;
		Node* parent;
		string name;
		string plot;
		float rating;
		int height;
		bool red; // each time we insert a node in a red black tree, it's red
		vector<string> genre;
		Node(string x, float r, vector<string> g, string p, bool color = true, int h = 0) : name(x), rating(r), genre(g), plot(p), height(h), red(color),left(nullptr), right(nullptr) {}

	};
// AMF 4/16/25 - RedBlackTree Class is based on https://www.onlinegdb.com/BygDgQCjI

class RedBlackTree {

private:
	int counter = 0;

public:
	Node* root = nullptr;
	// void node_color_fix(Node* node);
	Node* helperInsert(Node* curr, string name, vector<string> genre, string plot, float rating);
	Node* rotate_left(Node* parent);
	Node* search(Node* curr,string name);
	Node* rotate_right(Node* parent);
	void inOrder();
	void helperInorder(Node* root, bool& first);
	void case_violation(Node* curr);
	void rotate_helper(Node* old_curr,Node* new_curr);
	void insert(string name, float rating, string plot, vector<string>);
	void findTopTen();
	void helperfindTopTen(Node* root);
	void helperfindTopTenGenre(Node* root, string genre);
	void findTopTenGenre(string genre);
	void findGame(string name);
};




#endif //REDBLACKTREE_H
