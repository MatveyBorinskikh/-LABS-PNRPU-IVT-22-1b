#include <stdio.h>
#include <iostream>

using namespace std;

void Cel(int x, int y)
{
    cout << "Функция для вычитания целых чисел" << endl;
    cout << x << " - " << y << " = " << (x - y) << endl;

}

void Compleks(int x, int xi, int y, int yi)
{
    cout << "Функция для вычитания комплексных чисел" << endl;
    cout << "(" << x << " + " << xi << "i) - (" << y << " + " << yi << "i) = " << x + y << " - " << xi + yi << "i" << endl;

}

int main()
{
    int x, y;
    cout << "Введите значения для вычитания целых чисел" << endl;
    cin >> x >> y;
    Cel(x, y);

    Compleks(2, 3, 4, 5);
    return 0;
}