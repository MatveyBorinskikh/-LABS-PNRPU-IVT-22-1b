#include<iostream>
#include<string>
using namespace std;
class exam
{
public:
	string SNP;
	string subject;
	int mark;
	exam()
	{
		SNP = "������ ������� Ը�������";
		subject = "����������";
		mark = 5;
		cout << "����������� ��� ���������� ��� ������� ->" << this << endl;
	}
	exam(string VolSNP, string VolSubject, int VolMark)
	{
		SNP = VolSNP;
		subject = VolSubject;
		mark = VolMark;
		cout << "����������� � ����������� ��� ������� ->" << this << endl;
	}
	exam(const exam& third)
	{
		SNP = third.SNP;
		subject = third.subject;
		mark = third.mark;
		cout << "������ ����������� ����������� ->" << this << endl;
	}
	~exam()
	{
		cout << "������ ���������� ��� ->" << this << endl;
	}
	string GetSNP()
	{
		cout << "��� �������: " << SNP << endl;
		return SNP;
	}
	void SetSNP(string ValueSNP)
	{
		SNP = ValueSNP;
	}
	string GetSubject()
	{
		cout << "��� �������: " << subject << endl;
		return subject;
	}
	void SetSubject(string ValueSubject)
	{
		subject = ValueSubject;
	}
	int GetMark()
	{
		cout << "��� ������: " << mark << endl;
		return mark;
	}
	void SetMark(int ValueMark)
	{
		mark = ValueMark;
	}
	void show()
	{
		cout << "��� �������: " << SNP << endl << "��� �������: " << subject << endl << "��� ������: " << mark << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	exam first;
	first.show();
	exam second("������� ������� �������������", "����������", 5);
	second.show();
	exam third(*&first);
	third.show();
	exam dop;
	dop.SetSNP("������� ����� ���������");
	dop.GetSNP();
	dop.SetSubject("�����������");
	dop.GetSubject();
	dop.SetMark(2);
	dop.GetMark();
	return 0;
}