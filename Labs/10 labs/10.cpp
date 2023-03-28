#include<iostream>
using namespace std;

int main()
{
	int a[1000], n, k, l, s;
	cin >> n >> m >> k; //m - заданный номер
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> l >> s; //l - index, s - число

	for (int i = m; i < n - k; i++)
		for (int j = i + k; i < n; i++)
			a[i] = a[j];
	n -= k;

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;

	for (int i = n - 1; i >= l; i--)
		a[i + 1] = a[i];
	n++;
	a[l] = s;


	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}