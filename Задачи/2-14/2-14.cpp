#include <iostream>
using namespace std;
int main()
{
start:
    int s, sum = 0;
    cout << "������� ����� ������� 0" << endl;
    cin >> s;
    if (s <= 0)
    {
        goto start; // ����� �� ���� ������
    }
    {
        while (s)
        {
            sum += s % 10;
            s = s / 10;
        }
    } cout << sum;
    return 0;
}