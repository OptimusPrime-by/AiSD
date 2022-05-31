#pragma once
using namespace std;

class Queue {
private:
	int* arr; // ��������� �� ������
	unsigned int size; // ������������ ���-�� ���������
public:
	Queue() { // �����������
		size = 0; // ������� �����
	}
	int getN() { // ���������� �������� �������� �������
		return size;
	}
	int* getItems() { //���������� �������� �������� �������
		return arr;
	}
	void push(int a) { // ��������� �������� � ����� �������
		int* temp = new int[size + 1]; // �������� ������ �� 1 ������
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = a;  // ������� ������ ����� ������� (��������� �������)
		size++;
		delete[] arr; //  ������� ������
		arr = temp; // ����������� ������� ������ �������
	}
	int top() { // ����� ���������� ��������
		return arr[0];
	}
	void pop() { // �������� ��������� 
		if (size == 0) {
		return;
		}
		int* temp = new int[size - 1]; // �������� ������ �� ���� ������
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
		temp[size] = a; // ������� ������ (��������� �������)
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
	void push(int a) {  // ���������� � ������
		int* temp = new int[size + 1];
		for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
		}
		temp[size] = a;
		size++;
		delete[] arr;
		arr = temp;
	}
	void add(int a) { // ���������� � �����
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
	void popT() {  // �������� ������� ��������
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
	void popB() { // �������� ���������� ��������
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

