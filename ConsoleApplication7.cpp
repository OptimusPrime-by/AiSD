#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const char F1[7] = "g1.txt";
const char F2[7] = "g2.txt";
const char F3[7] = "g3.txt";
int comparesCount = 0;
int filesCount = 0;

void vodrandom(int N) {
	ofstream f;
	f.open(F1, ios::out);
	for (int i = 0; i < N; i++) {
		int j = rand() % N + 1;
		f << j << " ";
	}
	f.close();
}

void vodpovozr(int N) {
	ofstream f;
	f.open(F1, ios::out);
	for (int i = 0; i < N; i++) {
		f << i + 1 << " ";
	}
	f.close();
}

void vodpoybB(int N) {
	ofstream f;
	f.open(F1, ios::out);
	for (int i = 0; i < N; i++) {
		int j = N - i;
		f << j << " ";
	}
	f.close();
}


int fibonachi(int n) {
	if (n == 0) {
		comparesCount++;
		return 0;
	}
	if (n == 1 || n == 2) {
		comparesCount++;
		return 1;
	}
	return fibonachi(n - 1) + fibonachi(n - 2);
}

void nachalnoeraspredelenie(int q, int y, int pust) {
	ifstream f1;
	ofstream f2;
	ofstream f3;
	f1.open(F1, ios::in);
	f2.open(F2, ios::out);
	f3.open(F3, ios::out);
	if (pust != 0) {
		filesCount++;
		for (int i = 0; i < pust; i++) {
			f2 << "-1" << " " << "-2" << " ";
		}
	}
	int c;
	f1 >> c;
	f2 << c << " " << "-2";
	for (int i = 0; i < (y - pust) - 1; i++) {
		filesCount++;
		int a;
		f1 >> a;
		f2 << " " << a << " " << "-2";
	}
	int c1;
	f1 >> c1;
	f3 << c1 << " " << "-2";
	filesCount++;
	for (int i = 0; i < q - 1; i++) {
		int a;
		f1 >> a;
		f3 << " " << a << " " << "-2";
	}
	f2.close();
	f3.close();
	f1.close();
	ofstream f11;
	f11.open(F1, ios::out);
	f1.close();
}

void sort() {
	ifstream f1;
	f1.open(F1, ios::in);
	filesCount++;
	ifstream f2;
	f2.open(F2, ios::in);
	filesCount++;
	ifstream f3;
	f3.open(F3, ios::in);
	filesCount++;
	if (f1.peek() == EOF && f2.peek() == EOF) {
		comparesCount++;
		f1.close();
		f2.close();
		ofstream f11(F1, ios::out);
		while (f3.eof() != true) {
			int a;
			f3 >> a;
			if (a == -2) {
				comparesCount++;
			}
			else {
				if (f3.eof() != true) {
					comparesCount++;
					f11 << a << " ";
				}
			}
		}
		f11.close();
		f3.close();
		ofstream f33;
		filesCount++;
		f33.open(F3, ios::out);
		f33.close();
		return;
	}
	if (f1.peek() == EOF && f3.peek() == EOF) {
		comparesCount++;
		f1.close();
		f3.close();
		ofstream f11(F1, ios::out);
		filesCount++;
		while (f2.eof() != true) {
			int a;
			f2 >> a;
			if (a == -2) {
				comparesCount++;
			}
			else {
				if (f2.eof() != true) {
					f11 << a << " ";
					comparesCount++;
				}
			}
		}
		f2.close();
		f11.close();
		ofstream f22;
		f22.open(F2, ios::out);
		filesCount++;
		f22.close();
		return;
	}
	if (f2.peek() == EOF && f3.peek() == EOF) {
		comparesCount++;
		f3.close();
		f2.close();
		ofstream f22;
		filesCount++;
		f22.open(F2, ios::out);
		while (f1.eof() != true) {
			int a;
			f1 >> a;
			if (a == -2) {
				comparesCount++;
			}
			else {
				if (f1.eof() != true) {
					f22 << a << " ";
					comparesCount++;
				}
			}
		}
		f22.close();
		f1.close();
		ofstream f11;
		f11.open(F1, ios::out);
		filesCount++;
		f11.close();
		return;
	}
	if (f1.peek() != EOF && f2.peek() != EOF) {
		f3.close();
		ofstream f33;
		filesCount++;
		f33.open(F3, ios::out);
		int size = 0;
		f1.seekg(0, ios::end);
		size = (int)f1.tellg();
		int size1 = 0;
		f2.seekg(0, ios::end);
		size1 = (int)f2.tellg();
		if (size > size1) {
			comparesCount;
			f1.close();
			f1.open(F1, ios::in);
			filesCount++;
			f2.close();
			f2.open(F2, ios::in);
			filesCount++;
			int a;
			int b;
			f1 >> a;
			f2 >> b;
			while (f1.eof() != true) {
				if (a == -2 && b == -2) {
					comparesCount++;
					if (f2.eof() == true) {
						comparesCount++;
						f33 << "-2";
						break;
					}
					else {
						f2 >> b;
						f33 << "-2" << " ";
						f1 >> a;
						comparesCount++;
					}
				}
				else {
					if (a == -2 || b == -2) {
						if (a == -2) {
							f33 << b << " ";
							comparesCount++;
							f2 >> b;
						}
						else {
							f33 << a << " ";
							f1 >> a;
							comparesCount++;
						}
					}
					else {
						if (a > b) {
							f33 << b << " ";
							f2 >> b;
							comparesCount++;
						}
						else {
							if (a < b) {
								f33 << a << " ";
								f1 >> a;
								comparesCount++;
							}
							else {
								f33 << a << " " << b << " ";
								f1 >> a;
								f2 >> b;
								comparesCount++;
							}
						}
					}
				}
			}
			f33.close();
			f2.close();
			ofstream f22;
			filesCount++;
			f22.open(F2, ios::out);
			if (f1.eof() != true) {
				int c;
				f1 >> c;
				comparesCount++;
				f22 << c;
				while (f1.eof() != true) {
					int a;
					f1 >> a;
					f22 << " " << a;
				}
			}
			f1.close();
			f22.close();
			ofstream f11;
			filesCount++;
			f11.open(F1, ios::out);
			f11.close();
			return sort();
		}
		else {
			comparesCount++;
			f1.close();
			f1.open(F1, ios::in);
			filesCount++;
			f2.close();
			f2.open(F2, ios::in);
			filesCount++;
			int a;
			int b;
			f1 >> a;
			f2 >> b;
			while (f2.eof() != true) {
				if (a == -2 && b == -2) {
					comparesCount++;
					if (f1.eof() == true) {
						f33 << "-2";
						break;
					}
					else {
						comparesCount++;
						f2 >> b;
						f33 << "-2" << " ";
						f1 >> a;
					}
				}
				else {
					if (a == -2 || b == -2) {
						comparesCount++;
						if (a == -2) {
							f33 << b << " ";
							comparesCount++;
							f2 >> b;
						}
						else {
							f33 << a << " ";
							comparesCount++;
							f1 >> a;
						}
					}
					else {
						if (a > b) {
							comparesCount++;
							f33 << b << " ";
							f2 >> b;
						}
						else {
							if (a < b) {
								comparesCount++;
								f33 << a << " ";
								f1 >> a;
							}
							else {
								comparesCount++;
								f33 << a << " " << b << " ";
								f1 >> a;
								f2 >> b;
							}
						}
					}
				}
			}
			f33.close();
			f1.close();
			ofstream f11;
			filesCount++;
			f11.open(F1, ios::out);
			if (f2.eof() != true) {
				comparesCount++;
				int c;
				f2 >> c;
				f11 << c;
				while (f2.eof() != true) {
					int a;
					f2 >> a;
					f11 << " " << a;
				}
			}
			f2.close();
			f11.close();
			ofstream f22;
			filesCount++;
			f22.open(F2, ios::out);
			f22.close();
			return sort();
		}
	}
	if (f1.peek() != EOF && f3.peek() != EOF) {
		comparesCount++;
		f2.close();
		ofstream f22;
		filesCount++;
		f22.open(F2, ios::out);
		int size = 0;
		f1.seekg(0, ios::end);
		size = (int)f1.tellg();
		int size1 = 0;
		f3.seekg(0, ios::end);
		size1 = (int)f3.tellg();
		if (size > size1) {
			comparesCount++;
			f1.close();
			filesCount++;
			f1.open(F1, ios::in);
			f3.close();
			filesCount++;
			f3.open(F3, ios::in);
			int a;
			int b;
			f1 >> a;
			f3 >> b;
			while (f1.eof() != true) {
				if (a == -2 && b == -2) {
					comparesCount++;
					if (f3.eof() == true) {
						comparesCount++;
						f22 << "-2";
						break;
					}
					else {
						comparesCount++;
						f3 >> b;
						f22 << "-2" << " ";
						f1 >> a;
					}
				}
				else {
					if (a == -2 || b == -2) {
						comparesCount++;
						if (a == -2) {
							comparesCount++;
							f22 << b << " ";
							f3 >> b;
						}
						else {
							comparesCount++;
							f22 << a << " ";
							f1 >> a;
						}
					}
					else {
						if (a > b) {
							comparesCount++;
							f22 << b << " ";
							f3 >> b;
						}
						else {
							if (a < b) {
								comparesCount++;
								f22 << a << " ";
								f1 >> a;
							}
							else {
								comparesCount++;
								f22 << a << " " << b << " ";
								f1 >> a;
								f3 >> b;
							}
						}
					}
				}
			}
			f22.close();
			f3.close();
			ofstream f33;
			filesCount++;
			f33.open(F3, ios::out);
			if (f1.eof() != true) {
				comparesCount++;
				int c;
				f1 >> c;
				f33 << c;
				while (f1.eof() != true) {
					int a;
					f1 >> a;
					f33 << " " << a;
				}
			}
			f1.close();
			f33.close();
			ofstream f11;
			filesCount++;
			f11.open(F1, ios::out);
			f11.close();
			return sort();
		}
		else {
			comparesCount++;
			f1.close();
			f1.open(F1, ios::in);
			filesCount++;
			f3.close();
			f3.open(F3, ios::in);
			filesCount++;
			int a;
			int b;
			f1 >> a;
			f3 >> b;
			while (f3.eof() != true) {
				if (a == -2 && b == -2) {
					comparesCount++;
					if (f1.eof() == true) {
						comparesCount++;
						f22 << "-2";
						break;
					}
					else {
						comparesCount++;
						f3 >> b;
						f22 << "-2" << " ";
						f1 >> a;
					}
				}
				else {
					if (a == -2 || b == -2) {
						if (a == -2) {
							f22 << b << " ";
							f3 >> b;
							comparesCount++;
						}
						else {
							f22 << a << " ";
							f1 >> a;
							comparesCount++;
						}
					}
					else {
						if (a > b) {
							f22 << b << " ";
							f3 >> b;
							comparesCount++;
						}
						else {
							if (a < b) {
								f22 << a << " ";
								f1 >> a;
								comparesCount++;
							}
							else {
								f22 << a << " " << b << " ";
								f1 >> a;
								f3 >> b;
								comparesCount++;
							}
						}
					}
				}
			}
			f22.close();
			f1.close();
			ofstream f11;
			filesCount++;
			f11.open(F1, ios::out);
			if (f3.eof() != true) {
				comparesCount++;
				int c;
				f3 >> c;
				f11 << c;
				while (f3.eof() != true) {
					int a;
					f3 >> a;
					f11 << " " << a;
				}
			}
			f3.close();
			f11.close();
			ofstream f33;
			filesCount++;
			f33.open(F3, ios::out);
			f33.close();
			return sort();
		}
	}
	if (f2.peek() != EOF && f3.peek() != EOF) {
		comparesCount++;
		f1.close();
		ofstream f11;
		filesCount++;
		f11.open(F1, ios::out);
		int size = 0;
		f2.seekg(0, ios::end);
		size = (int)f2.tellg();
		int size1 = 0;
		f3.seekg(0, ios::end);
		size1 = (int)f3.tellg();
		if (size > size1) {
			comparesCount++;
			f2.close();
			f2.open(F2, ios::in);
			filesCount++;
			f3.close();
			f3.open(F3, ios::in);
			filesCount++;
			int a;
			int b;
			f2 >> a;
			f3 >> b;
			while (f2.eof() != true) {
				if (a == -2 && b == -2) {
					comparesCount++;
					if (f3.eof() == true) {
						comparesCount++;
						f11 << "-2";
						break;
					}
					else {
						comparesCount++;
						f3 >> b;
						f11 << "-2" << " ";
						f2 >> a;
					}
				}
				else {
					if (a == -2 || b == -2) {
						comparesCount++;
						if (a == -2) {
							f11 << b << " ";
							f3 >> b;
							comparesCount++;
						}
						else {
							f11 << a << " ";
							f2 >> a;
							comparesCount++;
						}
					}
					else {
						if (a > b && a != -1) {
							f11 << b << " ";
							f3 >> b;
							comparesCount++;
						}
						else {
							if (a < b && a != -1) {
								f11 << a << " ";
								f2 >> a;
								comparesCount++;
								if (f2.eof() == true) {
									f11 << b << " " << "-2";
									comparesCount++;
								}
							}
							else {
								if (a == -1) {
									f2 >> a;
									comparesCount++;
								}
								else {
									f11 << a << " " << b << " ";
									f2 >> a;
									comparesCount++;
									f3 >> b;
								}
							}
						}
					}
				}
			}
			f11.close();
			f3.close();
			ofstream f33;
			filesCount++;
			f33.open(F3, ios::out);
			if (f2.eof() != true) {
				comparesCount++;
				int c;
				f2 >> c;
				f33 << c;
				while (f2.eof() != true) {
					int a;
					f2 >> a;
					f33 << " " << a;
				}
			}
			f2.close();
			f33.close();
			ofstream f22;
			filesCount++;
			f22.open(F2, ios::out);
			f22.close();
			return sort();
		}
		else {
			comparesCount++;
			f2.close();
			filesCount++;
			f2.open(F2, ios::in);
			f3.close();
			filesCount++;
			f3.open(F3, ios::in);
			int a;
			int b;
			f2 >> a;
			f3 >> b;
			while (f3.eof() != true) {
				if (a == -2 && b == -2) {
					comparesCount++;
					if (f2.eof() == true) {
						comparesCount++;
						f11 << "-2";
						break;
					}
					else {
						comparesCount++;
						f3 >> b;
						f11 << "-2" << " ";
						f2 >> a;
					}
				}
				else {
					if (a == -2 || b == -2) {
						comparesCount++;
						if (a == -2) {
							comparesCount++;
							f11 << b << " ";
							f3 >> b;
						}
						else {
							comparesCount++;
							f11 << a << " ";
							f2 >> a;
						}
					}
					else {
						if (a > b) {
							f11 << b << " ";
							f3 >> b;
							comparesCount++;
						}
						else {
							if (a < b) {
								f11 << a << " ";
								f2 >> a;
								comparesCount++;
							}
							else {
								f11 << a << " " << b << " ";
								f2 >> a;
								f3 >> b;
								comparesCount++;
							}
						}
					}
				}
			}
			f11.close();
			f2.close();
			ofstream f22;
			filesCount++;
			f22.open(F2, ios::out);
			if (f3.eof() != true) {
				comparesCount++;
				int c;
				f3 >> c;
				f22 << c;
				while (f3.eof() != true) {
					int a;
					f3 >> a;
					f22 << " " << a;
				}
			}
			f3.close();
			f22.close();
			ofstream f33;
			filesCount++;
			f33.open(F3, ios::out);
			f33.close();
			return sort();
		}
	}
}

int main() {
	setlocale(0, "");
	int N;
	cout << "Введите размер массива" << endl;
	cin >> N;
	int K;
	cout << "Введите как будете заполнять массив 1.По возрастанию 2.По убыванию 3.Рандом" << endl;
	cin >> K;
	if (K == 1) {
		vodpovozr(N);
	}
	if (K == 2) {
		vodpoybB(N);
	}
	if (K == 3) {
		vodrandom(N);
	}
	int j, q, y;
	for (int i = 0; i < 100000; i++) {
		q = fibonachi(i);
		y = fibonachi(i + 1);
		j = q + y;
		if (j >= N) {
			break;
		}
	}
	int pyst = j - N;
	double start_time = clock();
	nachalnoeraspredelenie(q, y, pyst);
	sort();
	double end_time = clock();
	double search_time = end_time - start_time;

	cout << "Колличество сравнений: " << comparesCount << endl;
	cout << "Колличество обращения к файлам:" << filesCount << endl;
	cout << "Время выполнения сортировки: " << search_time << endl;

	system("pause");
	return 0;
}