#include <iostream>
using namespace std;
int main()
{
    int n, num, min = 32767, max = -32768;
    cout << "������� ���������� ����� � ������������������" << endl;
    cin >> n;
    cout << "������� ������������������ �����" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num < min and num != 0)
        {
            min = num;
        }
        if (num > max and num > min)
        {
            max = num;
        }
    } cout << min + max;
    return 0;
}