#include<iostream>
#include "BinaryTree.h"
#include <Windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	BinaryTree tree;
	int n, value;
	int buf[10] = { 50,40,60,30,45,55,70,20,43,65 };
	int n1;
	start:
	cout << "Ввести дерево вручную(1) или автоматически(2)?\n";
	cin >> n1;

	switch (n1) {
	case 1:
		cout << "Введите количество элементов:";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> value;
			tree.add(value);
		}
		break;
	case 2:
		n = 10;
		for (int i = 0; i < n; i++) {
			tree.add(buf[i]);
		}
		break;
	default:
		cout << "Неверное значение. Введите заново\n";
		goto start;
	} 
	cout << "Дерево:" << endl;
	tree.DisplayTheTree();
	cout << endl;

	cout << "Прямой обход:";
	tree.printStraight(tree.getRoot());
	cout << endl;
	cout << "Обратный обход:";
	tree.printReverse(tree.getRoot());
	cout << endl;
	cout << "Симметричный обход:";
	tree.printSymmetrical(tree.getRoot());
	cout << endl;

	tree.task2(tree.getRoot());

	cout << "Дерево:" << endl;
	tree.DisplayTheTree();
	cout << endl;

	cout << "Прямой обход:";
	tree.printStraight(tree.getRoot());
	cout << endl;

	cout << "Введите значение узла для определения его глубины, высоты, уровня: \n";
	cin >> n;
	cout << "\nВысота\n";
	cout << tree.height(tree.search(tree.getRoot(), n), 0);
	cout << "\nГлубина\n";
	cout << tree.depth(n);
	cout << "\nУровень\n";
	cout << tree.level(n) << endl;
	system("pause");
	return 0;
}