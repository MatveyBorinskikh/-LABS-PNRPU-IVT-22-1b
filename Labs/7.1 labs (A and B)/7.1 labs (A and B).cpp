#include <stdio.h>
#include <iostream>

using namespace std;

void Cel(int x, int y)
{
    cout << "������� ��� ��������� ����� �����" << endl;
    cout << x << " - " << y << " = " << (x - y) << endl;

}

void Compleks(int x, int xi, int y, int yi)
{
    cout << "������� ��� ��������� ����������� �����" << endl;
    cout << "(" << x << " + " << xi << "i) - (" << y << " + " << yi << "i) = " << x + y << " - " << xi + yi << "i" << endl;

}

int main()
{
    int x, y;
    cout << "������� �������� ��� ��������� ����� �����" << endl;
    cin >> x >> y;
    Cel(x, y);

    Compleks(2, 3, 4, 5);
    return 0;
}