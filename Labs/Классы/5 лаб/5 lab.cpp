#include<iostream>
using namespace std;
class abstract
{
public:
	virtual void show() = 0;
};

class triad : public abstract
{
protected:
	int first;
	int second;
	int third;
public:

	triad()
	{
		first = 0;
		second = 0;
		third = 0;
	}
	triad(int Valuefirst, int Valuesecond, int Valuethird)
	{
		first = Valuefirst;
		second = Valuesecond;
		third = Valuethird;
	}
	triad(const triad& other)
	{
		this->first = other.first;
		this->second = other.second;
		this->third = other.third;
	}

	void setfirst(long int Valuefirst)
	{
		first = Valuefirst;
	}
	int getfirst()
	{
		return first;
	}
	void setsecond(int Valuesecond)
	{
		second = Valuesecond;
	}
	int getsecond()
	{
		return second;
	}
	int getthird()
	{
		return third;
	}
	void setthird(int Valuethird)
	{
		third = Valuethird;
	}
	triad& operator++()
	{
		this->first += 1;
		this->second += 1;
		this->third += 1;
		return *this;
	}
	triad& operator++(int)
	{
		this->first += 1;
		this->second += 1;
		this->third += 1;
		return *this;
	}
	friend istream& operator>>(istream& in, triad& tmp);
	friend ostream& operator<<(ostream& out, const triad& tmp);
	void show() override
	{
		cout << " Числа: " << first << "." << second << "." << third << endl;
	}
	virtual ~triad()
	{
		cout << "Вызван деструктор для обьекта " << this << endl;
	}
};
istream& operator>>(istream& in, triad& tmp)
{
	cout << "Введите первое число: "; in >> tmp.first;
	cout << "Введите второе число: "; in >> tmp.second;
	cout << "Введите третье число: "; in >> tmp.third;
	return in;
}

ostream& operator<<(ostream& out, const triad& tmp)
{
	return (out << "Числа: " << tmp.first << "." << tmp.second << "." << tmp.third << endl);
}

class date : public triad
{
public:
	void show() override
	{
		cout << " Date: " << first << "." << second << "." << third << endl;
	}
	void Future(date& other, int n)
	{
		int day; int month; int year; int countM = 0; int countY = 0;
		day = other.first + n;
		while (day > 31)
		{
			day = day - 31;
			countM++;
		}
		month = other.second + countM;
		while (month > 12)
		{
			month = month - 12;
			countY++;
		}
		year = other.third + countY;;
		other.first = day; other.second = month; other.third = year;
	}
	date()
	{
		first = 0;
		second = 0;
		third = 0;
	}
	date(int Valuefirst, int Valuesecond, int Valuethird)
	{
		first = Valuefirst;
		second = Valuesecond;
		third = Valuethird;
	}
	date(const  date& other)
	{
		this->first = other.first;
		this->second = other.second;
		this->third = other.third;
	}
	date& operator++()
	{
		this->first += 1;
		this->second += 1;
		this->third += 1;
		return *this;
	}
	date& operator++(int)
	{
		this->first += 1;
		this->second += 1;
		this->third += 1;
		return *this;
	}
	friend istream& operator>>(istream& in, date& tmp);
	friend ostream& operator<<(ostream& out, const date& tmp);
	~date()
	{
		cout << "Удалили date..." << endl << endl;
	}

};

istream& operator>>(istream& in, date& tmp)
{
	cout << "Введите дни: "; in >> tmp.first;
	cout << "Введите месяцы: "; in >> tmp.second;
	cout << "Введите годы: "; in >> tmp.third;
	return in;
}

ostream& operator<<(ostream& out, const date& tmp)
{
	return (out << "Дата: " << tmp.first << "." << tmp.second << "." << tmp.third << endl);
}

class Vector
{
private:
	abstract** beg;
	int size;
	int cur;
public:
	Vector()
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	Vector(int n)
	{
		beg = new abstract * [n];
		cur = 0;
		size = n;
	}
	void add(abstract* tmp)
	{
		if (cur < size)
		{
			beg[cur] = tmp;
			cur++;
		}
	}
	~Vector()
	{
		if (beg != 0)
		{
			delete[] beg;
		}
		beg = 0;
	}
	friend ostream& operator<<(ostream& out, const Vector& v);
};
ostream& operator<<(ostream& out, const Vector& v)
{
	cout << "Вектор:" << endl;
	if (v.size == 0){
		out << "Empty" << endl;
	}
	abstract** tmp = v.beg;
	for (int i = 0; i < v.cur; i++){
	 	(*tmp)->show();
		tmp++;
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Vector v(2);
	triad a;
	cin >> a;
	cout << a;
	date b;
	cin >> b;
	cout << b;
	abstract* tmp = &a;
	v.add(tmp);
	tmp = &b;
	b.Future(b, 1500);
	tmp->show();
	v.add(tmp);
	cout << v;
	return 0;
}