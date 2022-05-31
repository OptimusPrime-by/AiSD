#include "BinaryTree.h"

#include <iostream>
#include <Windows.h>
#include<vector>
#include<iterator>
using namespace std;


vector<int> res;

int i = 0;

enum Colors {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
	DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

template<Colors txt = LightGray, Colors bg = Black>
ostream& color(ostream& text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}



Node::Node()
{
	this->left = NULL;
	this->right = NULL;
	this->parentPointer = NULL;
	this->value = 0;
}

Node::Node(int value)
{
	this->left = NULL;
	this->right = NULL;
	this->parentPointer = NULL;
	this->value = value;
}

void Node::setValue(int value)
{
	this->value = value;
}

int Node::getValue()
{
	return this->value;
}

void Node::setLeft(Node* left)
{
	this->left = left;
}

void Node::setRight(Node* right)
{
	this->right = right;
}

Node* Node::getLeft()
{
	return this->left;
}

Node* Node::getRight()
{
	return this->right;
}

void Node::setParentPointer(Node* parentPointer)
{
	this->parentPointer = parentPointer;
}

Node* Node::getParentPointer()
{
	return this->parentPointer;
}





BinaryTree::BinaryTree()
{
	root = NULL;
}

void BinaryTree::add(int new_node_value) {//добавление вершины  по значению 
	Node* new_node = new Node(new_node_value);
	add(this->root, new_node);
}

void BinaryTree::add(Node* node, Node* new_node)// добавление узла
{
	if (root == NULL) {
		new_node->setParentPointer(NULL);
		root = new_node;
		return;
	}
	if (node == NULL) {
		new_node->setParentPointer(NULL);
		node = new_node;
		return;
	}
	if (node->getValue() == new_node->getValue()) {
		//TODO: throw exception
		return;
	}
	if (node->getValue() > new_node->getValue()) {
		if (node->getLeft() != NULL) {
			add(node->getLeft(), new_node);
		}
		else {
			node->setLeft(new_node);
			new_node->setParentPointer(node);
		}
		return;
	}
	if (node->getValue() < new_node->getValue()) {
		if (node->getRight() != NULL) {
			add(node->getRight(), new_node);
		}
		else {
			node->setRight(new_node);
			new_node->setParentPointer(node);
		}
		return;
	}
}

Node* BinaryTree::getRoot()
{
	return root;
}

void BinaryTree::DisplayTheTree() {
	DisplayTheTree(this->root, string(""), string("  "));
}

void BinaryTree::DisplayTheTree(Node* subTreeNode, string position, string previousPicture) {// вывод
	if (subTreeNode == NULL) {
		cout << previousPicture.substr(0, previousPicture.length() - 1) + "|=";
		if (position == "L:")
			cout << color<LightMagenta, Black> << position << color<White, Black>;
		else
			cout << color < LightGreen, Black> << position << color<White, Black>;

		cout << color<LightRed, Black> << "-\n" << color<White, Black>;
		return;
	}
	cout << previousPicture.substr(0, previousPicture.length() - 1) + "|=";
	if (position == "L:")
		cout << color<LightMagenta, Black> << position << color<White, Black> << subTreeNode->getValue() << endl;
	else
		cout << color < LightGreen, Black> << position << color<White, Black> << subTreeNode->getValue() << endl;
	previousPicture += " |";
	DisplayTheTree(subTreeNode->getRight(), string("R:"), previousPicture);
	previousPicture = previousPicture.substr(0, previousPicture.length() - 1) + " ";
	DisplayTheTree(subTreeNode->getLeft(), string("L:"), previousPicture);

}



void BinaryTree::printStraight(Node* node)// обход 
{
	if (node != NULL) {
		cout << node->getValue() << " ";
		printStraight(node->getLeft());
		printStraight(node->getRight());
	}
}

void BinaryTree::printReverse(Node* node)
{
	if (node != NULL) {
		printReverse(node->getLeft());
		printReverse(node->getRight());
		cout << node->getValue() << " ";
	}
}

void BinaryTree::printSymmetrical(Node* node)
{
	if (node != NULL) {
		printSymmetrical(node->getLeft());
		cout << node->getValue() << " ";
		printSymmetrical(node->getRight());
	}
}

Node* BinaryTree::search(Node* current, int value)// поиск 
{
	if (current != NULL) {
		if (current->getValue() == value) {
			return current;
		}
		else if (current->getValue() < value) {
			return search(current->getRight(), value);
		}
		else {
			return search(current->getLeft(), value);
		}
	}
	else {
		return NULL;
	}
}

int BinaryTree::depth(int value)// глубина
{
	Node* temp_node = this->search(this->root, value);
	if (temp_node == NULL) {
		return -1;
	}
	int depth = 0;
	while (temp_node != this->root)
	{
		depth++;
		temp_node = temp_node->getParentPointer();
	}
	return depth;
}

int BinaryTree::depth(Node* current, int value, int* depth)
{
	if (current != nullptr) {
		if (current->getValue() == value) {
			return *depth;
		}
		else if (current->getValue() < value) {
			(*depth)++;
			return this->depth(current->getRight(), value, depth);
		}
		else {
			(*depth)++;
			return this->depth(current->getLeft(), value, depth);
		}
	}
	else {
		return -1;
	}
}


void BinaryTree::task2_1(Node* node) {
	i++;
	res.push_back(node->getValue());//путь
	if (node->getLeft() != NULL && node->getRight() != NULL) {
		if (height(node->getLeft(), i) > height(node->getRight(), i)) {
			task2_1(node->getLeft());
		}
		else if (height(node->getLeft(), i) < height(node->getRight(), i)) {
			task2_1(node->getRight());
		}
		else { // если слева и справа одинаковое количество вершин, т.е. самые длинные пути равны, то идем влево, т.к. сумма конечных вершин должна быть минимальной 
			task2_1(node->getLeft());
		}
	}
	else if (node->getLeft() != NULL) { // если справа нет вершин, то идем влево
		task2_1(node->getLeft());
	}
	else if (node->getRight() != NULL) {// если слева - идем вправо. Если вершин не осталось, то прекращается.
		task2_1(node->getRight());
	}
}

void BinaryTree::task2(Node* node) {
	task2_1(node);// удаляем среднюю по значению
	//вывод пути
	for (int q = 0; q < res.size()-1; q++) {
		cout << res[q] << " -> ";
	}
	cout << res[res.size() - 1] << endl;
	//сортируем массив с вершинами пути для того, чтобы удалить среднюю по значению вершину
	int temp;
	for (int q = 0; q < res.size() - 1; q++) {
		for (int j = 0; j < res.size() - q - 1; j++) {
			if (res[j] > res[j + 1]) {
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
			}
		}
	}
	int n = res.size() / 2;
	rightErase(res[n]);
}

int find_index_of(vector<Node*> vect, Node* element) {
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i] == element) {
			return i;
		}
	}
	return -1;
}

int BinaryTree::height(Node* current, int height)// высота
{
	if (current != nullptr) {
		return max(this->height(current->getLeft(), height + 1), this->height(current->getRight(), height + 1));
	}
	else {
		return height - 1;
	}
}

int BinaryTree::level(int value)//уровень
{
	int temp = 0;
	return height(root, 0) - depth(root, value, &temp);
}

Node* findMaxNode(Node* current) {
	if (current->getRight() != NULL) {
		return findMaxNode(current->getRight());
	}
	else {
		return current;
	}
};

Node* findMinNode(Node* current) {
	if (current->getLeft() != NULL) {
		return findMinNode(current->getLeft());
	}
	else {
		return current;
	}
};

bool BinaryTree::rightErase(int value)
{
	return rightErase(search(this->root, value));
}

bool BinaryTree::rightErase(Node* current)
{
	if (current == NULL) {
		return 0;
	}

	if (current->getRight() == NULL && current->getLeft() == NULL) {
		if (current->getParentPointer()->getRight() == current) {
			current->getParentPointer()->setRight(NULL);
		}
		else {
			current->getParentPointer()->setLeft(NULL);
		}
		delete current;
	}
	else if (current->getRight() != NULL && current->getLeft() != NULL) {
		Node* new_elemet = findMinNode(current->getRight());
		current->setValue(new_elemet->getValue());
		rightErase(new_elemet);
	}
	else {
		if (current->getRight() != NULL) {
			current->getRight()->setParentPointer(current->getParentPointer());
			if (current->getParentPointer() != NULL) {
				if (current->getParentPointer()->getRight() == current) {
					current->getParentPointer()->setRight(current->getRight());
				}
				else {
					current->getParentPointer()->setLeft(current->getRight());
				}
			}
			if (current == this->root) {
				this->root = current->getRight();
			}
		}
		else {
			current->getLeft()->setParentPointer(current->getParentPointer());
			if (current->getParentPointer() != NULL) {
				if (current->getParentPointer()->getRight() == current) {
					current->getParentPointer()->setRight(current->getLeft());
				}
				else {
					current->getParentPointer()->setLeft(current->getLeft());
				}
			}
if (current == this->root) {
			this->root = current->getLeft();
		}
		}
		
		delete current;
	}
	return 1;
}

bool BinaryTree::leftErase(int value)
{
	return leftErase(search(this->root, value));
}

bool BinaryTree::leftErase(Node* current)
{
	if (current == NULL) {
		return 0;
	}

	if (current->getRight() == NULL && current->getLeft() == NULL) {
		if (current->getParentPointer()->getRight() == current) {
			current->getParentPointer()->setRight(NULL);
		}
		else {
			current->getParentPointer()->setLeft(NULL);
		}
		delete current;
	}
	else if (current->getRight() != NULL && current->getLeft() != NULL) {
		Node* new_elemet = findMaxNode(current->getLeft());
		current->setValue(new_elemet->getValue());
		leftErase(new_elemet);
	}
	else {
		if (current->getRight() != NULL) {
			current->getRight()->setParentPointer(current->getParentPointer());
			if (current->getParentPointer() != NULL) {
				if (current->getParentPointer()->getRight() == current) {
					current->getParentPointer()->setRight(current->getRight());
				}
				else {
					current->getParentPointer()->setLeft(current->getRight());
				}
			}
			if (current == this->root) {
				this->root = current->getRight();
			}
		}
		else {
			current->getLeft()->setParentPointer(current->getParentPointer());
			if (current->getParentPointer() != NULL) {
				if (current->getParentPointer()->getRight() == current) {
					current->getParentPointer()->setRight(current->getLeft());
				}
				else {
					current->getParentPointer()->setLeft(current->getLeft());
				}
			}
			if (current == this->root) {
				this->root = current->getLeft();
			}
		}

		delete current;
	}
	return 1;
}
