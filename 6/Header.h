#pragma once
using namespace std;

class Queue {
private:
	int* arr; // указатель на массив
	unsigned int size; // максимальное кол-во элементов
public:
	Queue() { // конструктор
		size = 0; // очередь пуста
	}
	int getN() { // переменной передаем значение размера
		return size;
	}
	int* getItems() { //переменной передаем значение массива
		return arr;
	}
	void push(int a) { // добавляем элементы в конец очереди
		int* temp = new int[size + 1]; // выделяем память на 1 больше
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = a;  // считаем размер новой очереди (последний элемент)
		size++;
		delete[] arr; //  удаляем память
		arr = temp; // присваиваем массиву размер очереди
	}
	int top() { // вывод начального элемента
		return arr[0];
	}
	void pop() { // удаление элементов 
		if (size == 0) {
		return;
		}
		int* temp = new int[size - 1]; // выделяем память на один меньше
		for (int i = 1; i < size; i++) {
		temp[i - 1] = arr[i]; 
		}
		size--;
		delete[] arr;
		arr = temp;
	}
};

class Stack {
private:
	int* arr; 
	unsigned int size;
public:
	Stack() {
		size = 0;
	}
	int getN() {
	return size;
	}
	int* getItems() {
	return arr;
	}
	void push( int a) {
		int* temp = new int[size + 1];
		for (int i = 0; i < size; i++) {
	    temp[i] = arr[i];
		}
		temp[size] = a; // считаем размер (последний элемент)
		size++;
		delete[] arr;
		arr = temp; 
	}
	int top() {
		return arr[size - 1];
	}
	void pop() {
		if (size == 0) {
		return;
		}
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
		temp[i] = arr[i];
		}
		size--;
		delete[] arr;
		arr = temp;
	}
};

class Dqueue {
private:
	int* arr;
	unsigned int size;
public:
	Dqueue() {
		size = 0;
	}
	int getN() {
	return size;
	}
	int* getItems() {
	return arr;
	} 
	void push(int a) {  // добавление в начало
		int* temp = new int[size + 1];
		for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
		}
		temp[size] = a;
		size++;
		delete[] arr;
		arr = temp;
	}
	void add(int a) { // добавление в конец
		int* temp = new int[size + 1];
		for (int i = 0; i < size; i++) {
		temp[i + 1] = arr[i];
		}
		temp[0] = a;
		size++;
		delete[] arr;
		arr = temp;
	}
	int top() {
		return arr[size - 1];
	}
	int back() {
		return arr[0];
	}
	void popT() {  // удаление первого элемента
		if (size == 0) {
		return;
		}
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
		temp[i] = arr[i];
		}
		size--;
		delete[] arr;
		arr = temp;
	}
	void popB() { // удаление последнего элемента
		if (size == 0) {
		return;
		}
		int* temp = new int[size - 1];
		for (int i = 1; i < size; i++) {
		temp[i - 1] = arr[i];
		}
		size--;
		delete[] arr;
		arr = temp;
	}
};

