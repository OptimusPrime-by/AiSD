#include <iostream>
#include <list>
#include <string>
#include "Heap.h"
#include <stdlib.h>
using namespace std;

int main() {
	list<Heap*> heap;
	Heap tm;
	int num = 1;
	while (num != 0) {
		system("cls");
		cout << "1.Add.\n2.Delete min.\n3.Print.\n0-Exit.\n";
		cin >> num;
		switch (num) {
		case 1: {
			int val;
			string value;
			while (true) {
				system("cls");
				cout << "Enter value (press \"q\" to stop): ";
				cin >> value;
				if (value == "q") {
					break;
				}
				val = atoi(value.c_str());
				heap = tm.Insert(heap, val);
			}
			break;
		}
		case 2: {
			heap = tm.DeleteMaxPriority(heap);
			break;
		}
		case 3:
		{
			system("cls");
			list<Heap*>::iterator it;
			for (it = heap.begin(); it != heap.end(); it++) {
				tm.PrintBinomialHeap("", *it, false, false, 1);
				cout << endl << endl << endl;
			}

			break;
		}
		}
		system("pause");
	}
	system("pause");
	return 0;
}
