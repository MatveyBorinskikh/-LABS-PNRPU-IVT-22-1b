#include <iostream>
using namespace std;
int main()
{
    int n, s, max = 0;
    cout << "������� ���������� �����" << endl;
    cin >> n;
    cout << "������� ������������������ �����" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s > max)
        {
            max = s;
        }
    } cout << "���������� ����� ����� " << max << endl;
    return 0;
}