#include <iostream>
using namespace std;

int main()
{
start:
    int n, s, a;
    cout << "������� �����, � ����� ����� �� 0 �� 9, ������� ������� ���������" << endl;
    cin >> n >> s;
    if (n <= 0 or s > 0 or s < 9)
    {
        goto start; // �� ���� ������
    }
    else
    {
        while (n)
        {
            a = n % 10;
            if (s == a)
            {
                cout << "����� ������ � ������ �����"; break;
            }
            else
            {
                n = n / 10;
            }
        }
        if (s = !n)
        {
            cout << "����� �� ������ � ������ �����";
        }
    }
    return 0;
}