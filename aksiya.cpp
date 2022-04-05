#include <iostream>

using namespace std;

int maxDaC(int* arr, int l, int r) {
    if (l == r)
        return l;
    int m = (l + r) / 2;    //9
    int u = maxDaC(arr, l, m);   //идем с нуля до 9, запуская рекурсию
    int v = maxDaC(arr, m + 1, r);  // идем с 9 до 0
    if (arr[u] > arr[v]) return u;  //возвращаем значение наиб. элемента
    else return v;
}

int minDaC(int* arr, int l, int r) {  //как максимальный только минимальный :)
    if (l == r)
        return r;
    int m = (l + r) / 2;
    int u = minDaC(arr, l, m);
    int v = minDaC(arr, m + 1, r);
    if (arr[u] < arr[v]) return u;
    else return v;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int mass[] = {1, 2, 16,3,-27, 20, -3, 16, -30, 18, 19, -7, 12, -5, -28, 25, -14, 7 };
    int size = 18;
    int max1 = maxDaC(mass, 0, size);  // ищем макс. эл-т на всем массиве
    int min1 = minDaC(mass, 0, max1);  // ищем мин. эл-т на массиве до максю

    int min2 = minDaC(mass, 0, size - 1);  //ищем мин эл-т в массивве
    int max2 = maxDaC(mass, min2, size - 1);  //максю эл-т после мин.
    int max, min;                           // мы делаем эти расчеты для случая , когда разница больше (например 18 16 20 3 -20 5 ) то есть при нахождении макс. эл-та мы получим 20 а минимальный до него 16, то есть прибыль 4. Но у нас есть элемент -20, после которого идет 5 с прибылью в 25).

    if (fabs(mass[max2] - mass[min2]) > fabs(mass[max1] - mass[min1])) {
        max = max2; min = min2;
    }
    else {
        max = max1; min = min1;
    }

    cout << "Минимальные акции в день " << min << " равны " << mass[min] << endl;
    cout << "Максимальные акции в день " << max << " равны " << mass[max] << endl;
    cout << "Прибыль: " << mass[max] - mass[min] << endl;
    return 0;
}