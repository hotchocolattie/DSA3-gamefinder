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
		string age_rating;
		float rating;
		int height;
		int year;
		int votes;
		bool red; // each time we insert a node in a red black tree, it's red
		vector<string> genre;
		Node(string x, float r, vector<string> g, string p, int y, string a, int v, bool color = true, int h = 0) : 
			name(x), rating(r), genre(g), plot(p), year(y), age_rating(a), votes(v), height(h), red(color),left(nullptr), right(nullptr) {}

	};

class RedBlackTree {

private:
	int counter = 0;
	Node* root = nullptr;

	/*================================================ FUNCTIONS TO OPERATE ON RED BLACK TREE ==============================================================================*/

	Node* helperInsert(Node* curr, string name, vector<string> genres, string plot, int year, string age_rating, int votes, float rating);
	Node* rotate_left(Node* parent);
	Node* rotate_right(Node* parent);
	void helperInorder(Node* root, bool& first);
	void case_violation(Node* curr);
	void helperfindTopTenGenre(Node* root, string genre);
	void helperfindTopTen(Node* root);
	void printGame(Node* game);
	void rotate_helper(Node* old_curr,Node* new_curr);
	void inOrder();

public:

	/*================================================ FUNCTIONS TO CREATE RED BLACK TREE ==============================================================================*/

	void insert(string name, vector<string> genres, string plot, int year, string age_rating, int votes, float rating);
	Node* search(Node* curr,string name);

	/*================================================ FUNCTIONS TO OPERATE ON RED BLACK TREE ==============================================================================*/

	void findTopTen();
	void findTopTenGenre(string genre);
	void findGame(string name);

};




#endif //REDBLACKTREE_H
