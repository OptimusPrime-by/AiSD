#include <iostream>
#include <ctime>
#include <list>
#include <iterator>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

void three_way_merge_sort(string filepath, long long int* Comparison_amount, long long int* Swap_amount) {
	int ways_amount = 3;
	int array_size = 0;

	ifstream fin, fin_temp;
	ofstream fout, fout_temp;
	int temp;
	fin_temp.open(filepath, ios::in);
	fout_temp.open("C:\\Users\\3axap1251\\Desktop\\AiSD\\5\\5\\input_array.txt");
	while (!fin_temp.eof()) {
		fin_temp >> temp;
		fout_temp << temp << " ";
	}
	fout_temp.close();
	fin_temp.close();

	fin.open(filepath, ios::in);
	if (fin.is_open()) {
		int temp_element;
		while (!fin.eof())
		{
			fin >> temp_element;
			array_size++;
		}
		fin.close();
	}
	else {
		cout << GetLastError() << endl;
	}

	ifstream* buffer_fin = new ifstream[ways_amount];
	ofstream* buffer_fout = new ofstream[ways_amount];

	CreateDirectory(L".\\temp\\", NULL);
	for (int i = 0; i < (ways_amount * 2); i++)
	{
		fout.open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 1) + ".txt", ios::trunc | ios::out);
		fout.close();
	}

	bool files_swap = false;

	for (int i = 0; i < ways_amount; i++)
	{
		buffer_fin[i].open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 3 * files_swap + 1) + ".txt", ios::in);
		buffer_fout[i].open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 3 * !files_swap + 1) + ".txt", ios::trunc | ios::out);
	}

	int series_length = 1;

	fin.open(filepath, ios::in);

	for (int i = 0; i < array_size; i++)
	{
		int temp_element;
		fin >> temp_element;
		buffer_fout[i % 3] << temp_element << " ";
	}
	fin.close();

	for (int i = 0; i < ways_amount; i++)
	{
		buffer_fin[i].close();
		buffer_fout[i].close();
	}

	files_swap = !files_swap;
	series_length = pow(ways_amount, 1);
	for (int i = 1; series_length < array_size / ways_amount; i++)
	{
		series_length = pow(ways_amount, i);
		for (int i = 0; i < ways_amount; i++)
		{
			buffer_fin[i].open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 3 * files_swap + 1) + ".txt", ios::in);
			buffer_fout[i].open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 3 * !files_swap + 1) + ".txt", ios::trunc | ios::out);
		}

		int* buffer_numbers = new int[ways_amount];
		int* buffer_numbers_state = new int[ways_amount] {0}; // -2 - EOF, -1 - конец серии, 0 - значение устарело, 1 - значение действительно
		int* buffer_numbers_iteration = new int[ways_amount] {0};

		int statistic_amount_of_eos, statistic_amount_of_eof, statistic_amount_of_negative;

		bool* is_buffer_fout_file_is_empty = new bool[ways_amount] {true};

		int file_index = 0;

		for (int i = 0; i < array_size; i++)
		{
			statistic_amount_of_eos = 0;
			statistic_amount_of_eof = 0;
			statistic_amount_of_negative = 0;
			for (int j = 0; j < ways_amount; j++)
			{
				switch (buffer_numbers_state[j])
				{
				default:
					cout << "error";
					break;
				case -2:
					statistic_amount_of_eof++;
					statistic_amount_of_negative++;
					break;
				case -1:
					statistic_amount_of_eos++;
					statistic_amount_of_negative++;
					break;
				case 0:
					if (buffer_fin[j].eof() || buffer_fin[j].fail()) {
						buffer_numbers_state[j] = -2;
						statistic_amount_of_eof++;
						statistic_amount_of_negative++;
						break;
					}
					if (buffer_numbers_iteration[j] >= series_length / ways_amount) {
						buffer_numbers_state[j] = -1;
						statistic_amount_of_eos++;
						statistic_amount_of_negative++;
						break;
					}
					buffer_fin[j] >> buffer_numbers[j];
					buffer_numbers_state[j] = 1;
					buffer_numbers_iteration[j]++;
					break;
				case 1:
					break;
				}
			}
			if (statistic_amount_of_eof == ways_amount) {
				break;
			}
			if (statistic_amount_of_negative == ways_amount || statistic_amount_of_eos == ways_amount) {
				for (int j = 0; j < ways_amount; j++)
				{
					buffer_numbers_iteration[j] = 0;
					buffer_numbers_state[j] = 0;
				}
				i--;
				//cout << endl;
				file_index = (file_index + 1) % ways_amount;
				continue;
			}

			int min_element_index = -1;
			int index = 0;
			while (index < ways_amount && min_element_index == -1)
			{
				if (buffer_numbers_state[index] == 1) {
					min_element_index = index;
				}
				index++;
			}
			for (int j = min_element_index + 1; j < ways_amount; j++)
			{
				if (buffer_numbers_state[j] == 1) {
					if (buffer_numbers[j] < buffer_numbers[min_element_index]) {
						min_element_index = j;
					}
					(*Comparison_amount)++;
				}
			}
			
			if (!is_buffer_fout_file_is_empty[file_index])
			{
				buffer_fout[file_index] << " ";
			}
			buffer_fout[file_index] << buffer_numbers[min_element_index];
			is_buffer_fout_file_is_empty[file_index] = false;
			//cout << buffer_numbers[min_element_index] << " ";
			buffer_numbers_state[min_element_index] = 0;

		}
		//cout << endl << endl;

		for (int i = 0; i < ways_amount; i++)
		{
			buffer_fin[i].close();
			buffer_fout[i].close();
		}
		files_swap = !files_swap;
	}

	series_length *= series_length;
	for (int i = 0; i < ways_amount; i++)
	{
		buffer_fin[i].open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 3 * files_swap + 1) + ".txt", ios::in);
		//buffer_fout[i].open(".\\temp\\three_way_merge_sort_buffer_array_" + to_string(i + 3 * !files_swap + 1) + ".txt", ios::trunc | ios::out);
	}
	fout.open(filepath, ios::out | ios::trunc);

	int* buffer_numbers = new int[ways_amount];
	int* buffer_numbers_state = new int[ways_amount] {0}; // -1 - EOF, 0 - значение устарело, 1 - значение действительно
	int* buffer_numbers_iteration = new int[ways_amount] {0};

	int statistic_amount_of_eof;

	bool is_buffer_fout_file_is_empty = true;
	for (int i = 0; i < array_size; i++)
	{
		statistic_amount_of_eof = 0;
		for (int j = 0; j < ways_amount; j++)
		{
			switch (buffer_numbers_state[j])
			{
			default:
				cout << "error";
				break;
			case -1:
				statistic_amount_of_eof++;
				break;
			case 0:
				if (buffer_fin[j].eof() || buffer_fin[j].peek() == std::ifstream::traits_type::eof()) {
					buffer_numbers_state[j] = -1;
					statistic_amount_of_eof++;
					break;
				}
				buffer_fin[j] >> buffer_numbers[j];
				buffer_numbers_state[j] = 1;
				buffer_numbers_iteration[j]++;
				break;
			case 1:
				break;
			}
		}
		if (statistic_amount_of_eof == ways_amount) {
			break;
		}

		/*
		for (int j = 0; j < ways_amount; j++)
		{
			cout << buffer_numbers[j] << " " << buffer_numbers_state[j] << " ";
		}
		cout << endl;
		*/

		int min_element_index = -1;
		int index = 0;
		while (index < ways_amount && min_element_index == -1)
		{
			if (buffer_numbers_state[index] == 1) {
				min_element_index = index;
			}
			index++;
		}
		for (int j = min_element_index + 1; j < ways_amount; j++)
		{
			if (buffer_numbers_state[j] == 1) {
				if (buffer_numbers[j] < buffer_numbers[min_element_index]) {
					min_element_index = j;
				}
				(*Comparison_amount)++;
			}
		}

		if (!is_buffer_fout_file_is_empty)
		{
			fout << " ";
		}
		fout << buffer_numbers[min_element_index];
		is_buffer_fout_file_is_empty = false;
		//cout << buffer_numbers[min_element_index] << " ";
		buffer_numbers_state[min_element_index] = 0;
	}

	//cout << endl;
	for (int i = 0; i < ways_amount; i++)
	{
		buffer_fin[i].close();
	}
	fout.close();


	/*for (int i = 0; i < ways_amount * 2; i++)
	{
		DeleteFile((L".\\temp\\three_way_merge_sort_buffer_array_" + to_wstring(i + 1) + L".txt").c_str());
	}
	RemoveDirectory(L".\\temp\\");*/
}

void createFileWithRandomArray(string filepath, int array_size) {
	srand(time(0));
	fstream fout;
	fout.open(filepath, ios::trunc | ios::out);
	if (fout.is_open()) {
		for (int i = 1; i < array_size; i++)
		{
			//fout << rand() % 100000 << " ";
			fout << rand() % 100 << " ";
		}
		fout << rand();
		fout.close();
	}
}

void createFileWithArray(string filepath, int array_size) {
	srand(time(0));
	fstream fout;
	fout.open(filepath, ios::trunc | ios::out);
	if (fout.is_open()) {
		for (int i = 1; i < array_size; i++)
		{
			fout << i << " ";
		}
		fout << rand();
		fout.close();
	}
}

void createFileWithReverseArray(string filepath, int array_size) {
	srand(time(0));
	fstream fout;
	fout.open(filepath, ios::trunc | ios::out);
	if (fout.is_open()) {
		for (int i = 1; i < array_size; i++)
		{
			fout << array_size-i << " ";
		}
		fout << rand();
		fout.close();
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	string filepath_array = "array.txt";
		long long int comparison_amount = 0, swap_amount = 0;
			int time = 0;
			string table_string_comparison, table_string_swap, table_string_time;
			string filepath = "C:\\Users\\3axap1251\\Desktop\\AiSD\\5\\5\\";
		int time_s = 0;
	int arr[3] = { 500,5000,50000 };
	//for (int j = 0; j < 3; j++) {

	//	for (int i = 0; i < 10; i++) {
			/*createFileWithArray(filepath_array, arr[j]);

			comparison_amount = 0, swap_amount = 0;
			time = 0;
			
			time = clock();
			three_way_merge_sort(filepath_array, &comparison_amount, &swap_amount);
			time_s = clock() - time;
			cout << arr[j]<< " Упорядоченный массив:" << endl;
			cout << "Время " << time_s << endl;

			cout << "Обмены " << swap_amount << endl;

			cout << "Сравнения " << comparison_amount << endl;

			createFileWithReverseArray(filepath_array, arr[j]);

			comparison_amount = 0, swap_amount = 0;

			time = clock();
			three_way_merge_sort(filepath_array, &comparison_amount, &swap_amount);
			time_s = clock() - time;
			cout << arr[j]<<" Упорядоченный обратно массив:" << endl;
			cout << "Время " << time_s << endl;
			cout << "Обмены " << swap_amount << endl;
			cout << "Сравнения " << comparison_amount << endl;
			*/
			createFileWithRandomArray(filepath_array, arr[0]);
			comparison_amount = 0, swap_amount = 0;
			time = clock();
			three_way_merge_sort(filepath_array, &comparison_amount, &swap_amount);
			time_s = clock() - time;
			cout <<arr[0]<< " Heyпорядоченный массив:" << endl;
			cout << "Время " << time_s << endl;
			cout << "Обмены " << swap_amount << endl;
			cout << "Сравнения " << comparison_amount << endl;
		//}
	//}
	system("pause");
}

