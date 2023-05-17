#include<iostream>
#include<ctime>
using namespace std;

class Iterator
{
private:
	friend class  host;
	int* elem;
public:
	Iterator() { elem = 0; }
	void operator++() { ++elem; }
	void operator--() { --elem; }
	int& operator *() const { return*elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }
}

class host
{
private:
	int size;
	int* array;
	Iterator beg;
	Iterator end;
public:
	host(int size)
	{
		this->size = size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 100 + 1;
		}
		beg.elem = &array[0];
		end.elem = &array[size];
	}
	~host()
	{
	}
	int& operator () () { return size; }
	host operator - (const host& other)
	{
		host tmp(size);
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = array[i] - other.array[i];
		}
		for (int i = 0; i < size; i++)
		{
			tmp.array[i] = temp[i];
		}
		tmp.beg.elem = &(tmp.array[0]);
		tmp.end.elem = &(tmp.array[size]);
		delete[] temp;
		delete[]array;
		return tmp;
	}
	int& operator [](int index)
	{
		if (index >= 0 && index < size)
		{
			return array[index];
		}
		else
		{
			cout << endl << "Error" << endl;
		}
	}
	Iterator first() { return beg; }
	Iterator last() { return end; }

};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int k = 1;
	int size = 5;
	host a(size);
	Iterator iter;
	for (iter = a.first(); iter != a.last(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << "Число с выбранным индексом: " << a[k] << endl;
	--iter;
	cout << "Предыдущий элемент: " << *iter << endl;
	--iter;
	cout << "Предыдущий элемент: " << *iter << endl;
	cout << "Длина вектора a: " << a() << endl;

	host b(size);
	for (iter = b.first(); iter != b.last(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << "Длина вектора b: " << b() << endl;

	host c = a - b;
	cout << "Разность множеств равна - ";
	for (iter = c.first(); iter != c.last(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}