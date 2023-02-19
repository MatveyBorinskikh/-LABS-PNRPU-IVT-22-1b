#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void DelStr(double a[5][5], int StrNum)
{
    if (StrNum < 0 && StrNum >= 5)
        return;

    if (StrNum != 4)
    {
        for (int i = StrNum; i < 4; i++)
            for (int j = 0; j < 5; j++)
                a[i][j] = a[i + 1][j];
    }

    for (int j = 0; j < 5; j++)
        a[4][j] = 0;

}

int main()
{
    double a[5][5];
    int StrNum;
    cout << "Введите числа в массив: " << endl;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];
    cout << "Какую строку удалим?: ";
    cin >> StrNum;
    DelStr(a, StrNum);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << "Ваша матрица" << endl;
            cout << a[i][j] << ' ';
        cout << endl;
    }

    system("Pause");
}