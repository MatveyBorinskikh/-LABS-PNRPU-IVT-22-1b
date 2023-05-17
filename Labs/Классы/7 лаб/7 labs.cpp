#include<iostream>
#include<ctime>
using namespace std;

template<class T>
class host
{
private:
	T size;
	T* array;
public:
	host(T size)
	{
		this->size = size;
		array = new T[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 100 + 1;
		}
	}
	virtual void show()
	{
		cout << "Множество: ";
		for (int i = 0; i < size; i++){
			cout << " " << array[i];
		}
		cout << endl;
	}
	~host()
	{
	}
	int& operator () () { return size; }
	host operator - (const host& other)
	{
		host<T> tmp(size);
		for (int i = 0; i < size; i++){
			tmp[i] = array[i] - other.array[i];
		}
		delete[]array;
		return tmp;
	}
	T& operator [](int index)
	{
		if (index >= 0 && index < size){
			return array[index];
		}
		else
		{
			cout << endl << "Error" << endl;
		}
	}

};
template<class T, class T2>
class money
{
private:
	T rubles;
	T copeyka;
public:
	money(long rubles, int copeyka)
	{
		this->rubles = rubles;
		this->copeyka = copeyka;
	}
	~money() {};
	void show()
	{
		cout << "Сумма: " << rubles << "," << copeyka << endl;
	}
	money operator - (const money& other)
	{
		money<T, T2> tmp(243421992, 167);
		tmp.rubles = this->rubles - other.rubles;
		tmp.copeyka = this->copeyka - other.copeyka;
		return tmp;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int k = 1;
	int size = 5;
	host<int> a(size);
	a.show();
	cout << endl << "Число с выбранным индексом: " << a[k] << endl;
	cout << "Длина вектора a: " << a() << endl;
	host<int> b(size);
	b.show();
	cout << endl << "Длина вектора b: " << b() << endl;
	host<int> c(size);
	c = a - b;
	cout << "Разность множеств равна - ";
	c.show();

	money<long, int> first(8218866, 99);
	first.show();
	money<long, int> second(7251541, 85);
	second.show();
	money<long, int> third(0, 0);
	third = first - second;
	third.show();
	return 0;
}