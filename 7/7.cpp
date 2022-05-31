#include <iostream>
#include <ctime>
using namespace std;

long int hashTableIndex;// индекс в хеш-таблице
long int* hashTable;// хеш-таблица
bool* used; // массив используемых индексов
long int sizeEl;// кол-во элементов
long int tableSize; // размер таблицы

// хеш-функция
int func(int value) { //функция середины квадрата берет несколько (3) цифры из ключа, возведенного в квадрат
	int long_key = value * value;
	int temp = long_key;
	int count = 0, count2 = 0;

	while (temp != 0) {
		temp /= 10;
		count++;
	}

	if (count <= 3) {
		return (long_key % tableSize);
	}

	while (count != 3) {
		long_key /= 10;//убираем цифру с конца числа
		count--;
		if (count != 3) {//убираем цифру из начала числа
			temp = long_key;
			while (temp>10) {
				temp /= 10;
				count2++;
			}
			long_key -= (temp*pow(10,count2));
			count--;
			count2 = 0;
		}
	}

	return (long_key % tableSize);
}

void vivod()
{
	for (long int i = 0; i < tableSize; i++)
	{
		if (used[i])
		{
			cout << "[" << i << "] = " << hashTable[i] << endl;
		}
		else
		{
			cout << "[" << i << "] = " << endl;
		}
	}

}

bool pushEl(long int value) {
	long int ind = func(value);
	cout << endl << endl << ind << endl << endl;
	long int buf = func(value);
	long int i = 1;
	while (used[ind] && hashTable[ind] != value)
	{
		ind = ind + i +i*i;
		ind %= tableSize;
		i++;
		if (ind == buf) {
			return false;
		}
	}

	if (!used[ind]) {
		used[ind] = true;
		hashTable[ind] = value;
		return true;
	}
	return false;
}

int findEl(int value) {
	long int ind = func(value);
	long int buf = func(value);
	long int i = 1;
	while (used[ind] && hashTable[ind] != value)
	{
		ind = ind + i + i * i;
		ind %= tableSize;
		i++;
		if (ind == buf) {
			return -1;
		}
	}
	if (used[ind] && hashTable[ind] == value)
	{
		return ind;
	}
	else return -1;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Сделайте выбор: \n" <<
		"1 - заполнить массив самостоятельно\n"
		"2 - заполнить массив случайными числами\n";

	long int choise;
	long int t1, t2, t3, t4;
	cin >> choise;
	if (choise == 1)
	{
		while (true) {
			cout << "Введите количество элементов: ";
			cin >> sizeEl;
			cout << "Введите размер хеш-таблицы: ";
			cin >> tableSize;
			if (sizeEl > tableSize) {
				cout << "Размер таблицы меньше чем количество элементов" << endl;
			}
			else {
				break;
			}
		}
		hashTable = new long int[tableSize];
		used = new bool[tableSize];
		for (long int i = 0; i < tableSize; i++) {
			hashTable[i] = 0;
			used[i] = false;
		}
		cout << "Вводите элементы: " << endl;
		long int el;
		for (long int i = 0; i < sizeEl; i++)
		{
			cin >> el;
			pushEl(el);
		}
	}
	else if (choise == 2)
	{
		while (true) {
			cout << "Введите количество элементов: ";
			cin >> sizeEl;
			cout << "Введите размер хеш-таблицы: ";
			cin >> tableSize;
			if (sizeEl > tableSize) {
				cout << "Размер таблицы меньше чем количество элементов" << endl;
			}
			else {
				break;
			}
		}
		hashTable = new long int[tableSize];
		used = new bool[tableSize];
		for (long int i = 0; i < tableSize; i++) {
			hashTable[i] = 0;
			used[i] = false;
		}
		long int m;
		long int* temp = new long int[sizeEl];
		for (int i = 0; i < sizeEl; i++)
		{
			if (i == 0) t1 = clock();
			m = rand() % 1000000;
			pushEl(m);
			temp[i] = m;
			if (i == 1000) t2 = clock();
			if (i == sizeEl - 1001) t3 = clock();
			if (i == sizeEl - 1) t4 = clock();
		}

		//cout << "Время добавления первых 1000 элементов равно " << t2 - t1 << endl << "Время добавления последних 1000 элементов равно " << t4 - t3;
		cout << endl;
		t1 = clock();
		for (long int i = 0; i < sizeEl; i++)
		{
			findEl(temp[i]);
		}
		t2 = clock();
		cout << endl << "время поиска всех элементов равно равно " << t2 - t1 << endl;

	}
	else {
		system("pause");
		return 0;
	}

	while (true)
	{
		cout << "Сделайте выбор: \n" <<
			"1 - поиск элемента\n"
			"2 - добавить элемент\n"
			"3 - вывод таблицы\n";
		cin >> choise;
		if (choise == 1)
		{
			long int ser;
			cout << "Введите элемент \n";
			cin >> ser;
			long int k = findEl(ser);
			if (k != -1)
			{
				cout << "Такой элемент существует в таблице\nЕго индекс: " << k << endl;
			}
			else cout << "такого элемента не существует\n";

		}
		else if (choise == 2)
		{
			if (sizeEl >= tableSize)
			{
				cout << "Таблица заполнена" << endl;
			}
			else {
				long int ser;
				cout << "Введите элемент \n";
				cin >> ser;
				if (pushEl(ser)) {
					sizeEl++;
					cout << "Элемент добавлен!\n";
				}
				else
				{
					cout << "Элемент не добавлен!\n";
				}
			}
		}
		else if (choise == 3)
		{
			vivod();
		}
	}

	system("pause");
	return 0;
}
