#include <iostream>
using namespace std;
int main()
{
	int n, s, f;
	cout << "Введите количество чисел" << endl;
	cin >> n;
	cout << "Введите число" << endl;
	cin >> f;
	cout << "Введите последовательность чисел" << endl;
	for (int i = 1; i < n; i++)
	{
		cin >> s;
	}
	if (f > 0)
	{
		cout << "Положительное число первое";
	}
	else if (f < 0)
	{
		cout << "Отрицательное число первое";
	}
	else if (f == 0)
	{
		cout << "Только нули";
	}
	return 0;
}