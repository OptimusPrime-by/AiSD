#pragma once
#pragma once
#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>
using namespace std;

class Heap {

private:
	int data;
	int degree;
	Heap* child;
	Heap* sibling;
	Heap* parent;

public:

	Heap* Create(int key);
	list<Heap*> SortDegree(list<Heap*> l1, list<Heap*> l2);
	Heap* Merge(Heap* b1, Heap* b2);
	list<Heap*> Invariant(list<Heap*> heap);
	list<Heap*> insertInHeap(list<Heap*> heap, Heap* tree);
	list<Heap*> Insert(list<Heap*> _head, int key);
	list<Heap*> RemoveMaxPriority(Heap* tree);
	Heap* GetMaxPriority(list<Heap*> heap);
	list<Heap*> DeleteMaxPriority(list<Heap*> heap);
	void PrintBinomialHeap(const string& probel, const Heap* top, bool childs, bool viv, int l);

};
