#include<iostream>
using namespace std;
class money
{
	long rubles;
	int copeyka;
public:
	money()
	{
		rubles = 560;
		copeyka = 23;
		cout << "������ ����������� ��� ���������� ��� ������� " << this << " � ����� � " << rubles << "," << copeyka << endl;
	}
	money(long ValueRubles, int ValueCopeyka)
	{
		rubles = ValueRubles;
		copeyka = ValueCopeyka;
		cout << "������ ����������� � ����������� ��� ������� " << this << " � ����� � " << rubles << "," << copeyka << endl;
	}
	money(const money& other)
	{
		this->rubles = other.rubles;
		this->copeyka = other.copeyka;
		cout << "������ ����������� ����������� ��� ������� " << this << " � ����� � " << rubles << "," << copeyka << endl;
	}
	~money()
	{
		cout << "������ ���������� ��� ������� " << this << endl;
	}
	void setRubles(long ValueRubles)
	{
		rubles = ValueRubles;
	}
	long getRubles()
	{
		return rubles;
	}
	void setCopeyka(int ValueCopeyka)
	{
		copeyka = ValueCopeyka;
	}
	int getCopeyka()
	{
		return copeyka;
	}
	void show()
	{
		cout << "������� ������� ��� �������  " << this << " � ����� � " << rubles << "," << copeyka << endl;
	}
	bool operator==(const money& other)
	{
		return (this->rubles == other.rubles && this->copeyka == other.copeyka);
	}
	bool operator!=(const money& other)
	{
		return !(this->rubles == other.rubles && this->copeyka == other.copeyka);
	}
	money& operator--()
	{
		this->copeyka -= 1;
		return *this;
	}
	money& operator--(int ValueCopeyka)
	{
		this->copeyka -= 1;
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	money first;
	money second(54912, 8332);
	money third(second);
	money fourth;
	money fifth;
	fourth.setRubles(999);
	fourth.setCopeyka(73);
	fourth.getRubles();
	fourth.getCopeyka();
	fourth.show();
	--first;
	fifth--;
	fifth.show();
	first.show();
	bool result = second == third;
	cout << "��������� ����������? " << result << endl;
	bool result_2 = second != third;
	cout << "����������� ����������? " << result_2 << endl;
	return 0;
}