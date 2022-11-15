#include <iostream>
using namespace std;
int main()
{
	int n, s, m;
	cout << "Введите количество чисел" << endl;
	cin >> n;
	cout << "Введите последовательность чисел" << endl;
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
		cout << "Положительное число первое";
	}
	else if (m < 0)
	{
		cout << "Отрицательное число первое";
	}
	else if (m == 0)
	{
		cout << "Только нули";
	}
	return 0;
}