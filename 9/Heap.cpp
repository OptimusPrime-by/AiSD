#include "Heap.h"
using namespace std;

Heap* Heap::Create(int key)
{
	Heap* temp = new Heap;
	temp->data = key;
	temp->degree = NULL;
	temp->child = temp->parent = temp->sibling = NULL;
	return temp;
}


list<Heap*> Heap::SortDegree(list<Heap*> l1, list<Heap*> l2)
{
	list<Heap*> _new;
	list<Heap*>::iterator it = l1.begin();
	list<Heap*>::iterator ot = l2.begin();
	while (it != l1.end() && ot != l2.end()) {
		if ((*it)->degree <= (*ot)->degree) {
			_new.push_back(*it);
			it++;
		}

		else {
			_new.push_back(*ot);
			ot++;
		}
	}
	while (it != l1.end()) {
		_new.push_back(*it);
		it++;
	}
	while (ot != l2.end()) {
		_new.push_back(*ot);
		ot++;
	}

	return _new;
}


Heap* Heap::Merge(Heap* b1, Heap* b2)
{
	if (b1->data > b2->data) {
		Heap* temp;
		temp = b1;
		b1 = b2;
		b2 = temp;
	}
	b2->parent = b1;
	b2->sibling = b1->child;
	b1->child = b2;
	b1->degree++;
	return b1;
}

//если добавляем элемент его приоритет 0. Когда присоединяем элемент к меньшему, приоритет того, к кому присоединили возрастает на 1
//если есть два элемента с максимальным приоритетом вызываем функцию merge ( cлияние )
list<Heap*> Heap::Invariant(list<Heap*> heap)
{
	if (heap.size() == 1) {
		return heap;
	}
	list<Heap*> newheap;
	list<Heap*>::iterator it1, it2, it3;
	it1 = it2 = it3 = heap.begin();
	if (heap.size() == 2) {
		it2++;
		it3 = heap.end();
	}
	else {
		it2++;
		it3 = it2;
		it3++;
	}
	while (it1 != heap.end()) {
		if (it2 == heap.end()) {
			it1++;
		}
		else if ((*it1)->degree < (*it2)->degree) {
			it1++;
			it2++;
			if (it3 != heap.end())
				it3++;
		}
		else if (it3 != heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree) {
			it1++;
			it2++;
			it3++;
		}
		else if ((*it1)->degree == (*it2)->degree) {
			*it1 = Merge(*it1, *it2);
			it2 = heap.erase(it2);
			if (it3 != heap.end()) {
				it3++;
			}
		}
	}
	return heap;
}


list<Heap*> Heap::insertInHeap(list<Heap*> heap, Heap* tree)
{
	list<Heap*> temp;
	temp.push_back(tree);
	temp = SortDegree(heap, temp);
	list<Heap*> _temp = Invariant(temp);
	return _temp;
}


list<Heap*> Heap::Insert(list<Heap*> _head, int key)
{
	Heap* temp = Create(key);
	list<Heap*> _temp = insertInHeap(_head, temp);
	return _temp;
}


list<Heap*> Heap::RemoveMaxPriority(Heap* tree)
{
	list<Heap*> heap;
	Heap* temp = tree->child;
	Heap* lo;
	while (temp) {
		lo = temp;
		temp = temp->sibling;
		lo->sibling = NULL;
		heap.push_front(lo);
	}
	return heap;
}


Heap* Heap::GetMaxPriority(list<Heap*> heap)
{
	list<Heap*>::iterator it = heap.begin();
	Heap* temp = *it;
	while (it != heap.end()) {
		if ((*it)->data < temp->data) {
			temp = *it;
		}
		it++;
	}
	return temp;
}

//Получаем элемент с максимальным приоритетом и удаляем его и составляем новую кучу из оставшихся элементов (с их имеющимися приоритетами)
list<Heap*> Heap::DeleteMaxPriority(list<Heap*> heap)
{
	list<Heap*> newheap, lo;
	Heap* temp;
	temp = GetMaxPriority(heap);
	list<Heap*>::iterator it;
	it = heap.begin();
	while (it != heap.end()) {
		if (*it != temp) {
			newheap.push_back(*it);
		}
		it++;
	}
	lo = RemoveMaxPriority(temp);
	newheap = SortDegree(newheap, lo);
	list<Heap*> _temp = Invariant(newheap);
	return _temp;
}


void Heap::PrintBinomialHeap(const string& probel, const Heap* top, bool childs, bool viv, int l)
{
	bool ghg = false;
	while (top != 0) {
		if (top != 0) {
			if (top->child != 0 || top->sibling != 0) {
				viv = true;
			}
			else {
				viv = false;
			}
			cout << probel;
			if (childs) {
				cout << "|----:" << top->data << endl;
			}
			else {
				if (l == 1) {
					cout << "------" << top->data << endl;
					l++;
					if (top->child == 0 && top->parent == 0) {
						ghg = true;
					}
				}
			}
			if (childs) {
				PrintBinomialHeap(probel + "|     ", top->child, true, viv, l);
			}
			else {
				PrintBinomialHeap(probel + "      ", top->child, true, viv, l);
			}
			top = top->sibling;
		}
	}
}
