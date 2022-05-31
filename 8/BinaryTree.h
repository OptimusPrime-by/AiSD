#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Node {
private:
	Node* parentPointer;
	int value;
	Node* right;
	Node* left;
public:
	Node();
	Node(int value);
	void setValue(int value);
	int getValue();
	void setLeft(Node* left);
	void setRight(Node* right);
	Node* getLeft();
	Node* getRight();
	void setParentPointer(Node* parentPointer);
	Node* getParentPointer();
};

class BinaryTree {
private:
	Node* root; //корень дерева
public:
	BinaryTree();
	void add(int new_node_value);
	void add(Node* node, Node* new_node);
	Node* getRoot();

	void DisplayTheTree();
	void DisplayTheTree(Node* subTreeNode, string position, string previousPicture);
	void printStraight(Node* node);
	void printReverse(Node* node);
	void printSymmetrical(Node* node);

	Node* search(Node* current, int value);

	int depth(int value);
	int depth(Node* current, int value, int* depth);
	void task2_1(Node* node);
	void task2(Node* node);
	int height(Node* current, int height);
	int level(int value);

	bool rightErase(int value);
	bool rightErase(Node* current);
	bool leftErase(int value);
	bool leftErase(Node* current);
};

int find_index_of(vector<Node*> vect, Node* element);
