#include <iostream>
#include <Windows.h>
#include<string>
#include "Header.h"

using namespace std;

void print(Stack a, Queue b, Queue d, Dqueue c) {

	int* current = a.getItems(); // возвращает указатель на  вершину стека
	cout << "\nГрязная:\n";
	for (int i = 0; i < a.getN(); i++) {
		cout << current[i] << " ";
	}

	current = b.getItems(); //возвращает указатель на начало очереди
	cout << "\nПосудомойка:\n";
	for (int i = 0; i < b.getN(); i++) {
		cout << current[i] << " ";
	}

	current = d.getItems(); // возвращает указатель на начало очереди
	cout << "\nВторая очередь: \n";
	for (int i = 0; i < d.getN(); i++)
	{
		cout << current[i] << " ";
	}

	current = c.getItems(); // возвращает указатель на начало дека
	cout << "\nЧистая:\n";
	for (int i = 0; i < c.getN(); i++) {
		cout << current[i] << " ";
	}
	cout << endl << endl;
}

int main() {
	setlocale(0, "");
	Stack dish; // тарелка
	Dqueue shelf; // полка
	Queue mashin1, mashin2; //машина
	int temp;
	int n;
	cout << "N: ";
	cin >> n;
	cout << "Посуда: ";
	for (int i = 0; i < n; i++) {
		cin >> temp;
		dish.push(temp); // поставили грязные тарелки
	}

	print(dish, mashin1, mashin2, shelf); // функция для работы со стеком/деком/очередями

	int g; 
	do {
		g = rand() % 5;
		switch (g) {
		case 1:   // единица закидывает грязную посуду в 1 посудомойку
			if (dish.getN() != 0) {
				mashin1.push(dish.top());
				dish.pop();
			}
			break;
		case 2: // двойка закидывает посуду из 2-й очереди в чистую
			if (mashin2.getN() != 0) {
				shelf.add(mashin2.top());
				mashin2.pop();
			}
			break;
		case 3: // тройка из 1 посудомойки ставит на полку чистую посуду
			if (mashin1.getN() != 0) {
				shelf.add(mashin1.top());
				mashin1.pop();
			}
			break;
		case 4: // четверка забирает из чистой в грязную
			if (shelf.getN() != 0) {
				dish.push(shelf.top());
				shelf.popT();
			}
			break;
		case 5: //закидывает во вторую очередь посудомойки
			if (dish.getN() != 0) {
				mashin2.push(dish.top());
				dish.pop();
			}
			break;
		}
		print(dish, mashin1, mashin2, shelf);
	} while (g != 0);
	return 0;
}