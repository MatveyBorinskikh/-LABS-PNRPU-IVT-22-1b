#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, s, m;
	cout << "Ââåäèòå êîëè÷åñòâî ÷èñåë" << endl;
	cin >> n;
	cout << "Ââåäèòå ïîñëåäîâàòåëüíîñòü ÷èñåë" << endl;
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
		cout << "Ïîëîæèòåëüíîå ÷èñëî ïåðâîå";
	}
	else if (m < 0)
	{
		cout << "Îòðèöàòåëüíîå ÷èñëî ïåðâîå";
	}
	else if (m == 0)
	{
		cout << "Òîëüêî íóëè";
	}
	return 0;
}
