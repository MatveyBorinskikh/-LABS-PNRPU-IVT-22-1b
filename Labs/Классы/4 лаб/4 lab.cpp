#include<iostream>
using namespace std;
class triad
{
public:
	int first;
	int second;
	int third;

	triad()
	{
		first = 10;
		second = 06;
		third = 2003;
		cout << "Вызван конструктор без параметров для обьекта " << this << " с числами " << first << "." << second << "." << third << endl;
	}
	triad(int Valuefirst, int Valuesecond, int Valuethird)
	{
		first = Valuefirst;
		second = Valuesecond;
		third = Valuethird;

		cout << "Вызван конструктор с параметрами для обьекта " << this << " с числами " << first << "." << second << "." << third << endl;
	}
	triad(const triad& other)
	{
		this->first = other.first;
		this->second = other.second;
		this->third = other.third;
		cout << "Вызван конструктор копирования для обьекта " << this << " с числами " << first << "." << second << "." << third << endl;
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
	void show()
	{
		cout << "Вызван иной способ инициализации обьекта  " << this << " с числами " << first << "." << second << "." << third << endl;
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
	return (out << "(" << tmp.first << "." << tmp.second << "." << tmp.third);
}
class date : public triad
{
public:

	void Future(triad& other, int n)
	{
		int day; int month; int year; int countM = 0; int countY = 0;
		day = other.first + n;
		while (day > 31) {
			day = day - 31;
			countM++;
		}
		month = other.second + countM;
		while (month > 12) {
			month = month - 12;
			countY++;
		}
		year = other.third + countY;;
		other.first = day; other.second = month; other.third = year;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	triad first;
	triad second(05, 02, 2002);
	triad third(second);
	triad fourth;
	fourth.setfirst(19);
	fourth.setsecond(12);
	fourth.setthird(1999);
	fourth.getfirst();
	fourth.getsecond();
	fourth.getthird();
	fourth.show();
	date birth;
	birth++;
	birth.show();
	birth.Future(birth, 1500);
	birth.show();
	return 0;
}
}