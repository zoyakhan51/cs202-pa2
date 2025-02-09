#include "bst.cpp"
#include <memory>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef __BST_HPP
#define __BST_HPP

// Node of the tree
template <class T, class S, class C>
struct node
{
	S fullName;
	T workExperience;
	string gender;
	shared_ptr<node> left;
	shared_ptr<node> right;
	int height;

	node(T w, S n, C g)	//default constructor
	{
		this->fullName = n;
		this->workExperience = w;
		this->gender = g;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

// BST Class (Binary Search Tree) (This will be used for BST Tree implementation)
template <class T, class S, class C>
class BST
{
	
	shared_ptr<node<T, S, C>> root;

	public:
	// Part 1 Functions
	BST();
	void insertNode(shared_ptr<node<T, S, C>>);
	void deleteNode(T k);
	shared_ptr<node<T, S, C>> deleteNodeHelper(shared_ptr<node<T, S, C>> root, T k);		//helper function for deleteNode();
	shared_ptr<node<T, S, C>> successor(shared_ptr<node<T, S, C>> p);		//helper function to find successor node in delete node function
	shared_ptr<node<T, S, C>> getRoot();
	shared_ptr<node<T, S, C>> searchNode(T k);
	int height(shared_ptr<node<T, S, C>> p);

	void printTree(shared_ptr<node<T, S, C>> x);

	// Part 2 Functions
	int number_to_shortlist(shared_ptr<node<T, S, C>> root);
	vector<T> right_most(shared_ptr<node<T, S, C>> root);
	vector<T> in_order(shared_ptr<node<T, S, C>> root);
	// shared_ptr<node<T, S, C>> in_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys);
	// vector<T> in_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys);
	void in_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys, int &count, int max);

	vector<T> pre_order(shared_ptr<node<T, S, C>> root);
	void pre_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys, int &count, int max);

	vector<T> post_order(shared_ptr<node<T, S, C>> root);
	void post_orderHelper(shared_ptr<node<T, S, C>> p, vector<T> &keys, int &count, int max);
	vector<T> level_order(shared_ptr<node<T, S, C>> root);
};

#endif