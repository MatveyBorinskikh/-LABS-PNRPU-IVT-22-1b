#include <iostream>
using namespace std;
int main()
{
	int n, s, f;
	cout << "������� ���������� �����" << endl;
	cin >> n;
	cout << "������� �����" << endl;
	cin >> f;
	cout << "������� ������������������ �����" << endl;
	for (int i = 1; i < n; i++)
	{
		cin >> s;
	}
	if (f > 0)
	{
		cout << "������������� ����� ������";
	}
	else if (f < 0)
	{
		cout << "������������� ����� ������";
	}
	else if (f == 0)
	{
		cout << "������ ����";
	}
	return 0;
}