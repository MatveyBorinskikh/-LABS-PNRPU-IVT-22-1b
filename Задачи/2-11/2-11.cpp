#include <iostream>
using namespace std;
int main()
{
	int n, s, m;
	cout << "������� ���������� �����" << endl;
	cin >> n;
	cout << "������� ������������������ �����" << endl;
	for (int i = 1; i < n; i++)
	{
		cin >> s;
		if (m == 0)
		{
			m = s;
		}
	}
	if (m > 0)
	{
		cout << "������������� ����� ������";
	}
	else if (m < 0)
	{
		cout << "������������� ����� ������";
	}
	else if (m == 0)
	{
		cout << "������ ����";
	}
	return 0;
}