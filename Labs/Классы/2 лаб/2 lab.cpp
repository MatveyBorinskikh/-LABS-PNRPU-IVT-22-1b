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
		SNP = "Прокин Евгений Фёдорович";
		subject = "Математика";
		mark = 5;
		cout << "Конструктор без параметров для обьекта ->" << this << endl;
	}
	exam(string VolSNP, string VolSubject, int VolMark)
	{
		SNP = VolSNP;
		subject = VolSubject;
		mark = VolMark;
		cout << "Конструктор с параметрами для обьекта ->" << this << endl;
	}
	exam(const exam& third)
	{
		SNP = third.SNP;
		subject = third.subject;
		mark = third.mark;
		cout << "Вызван конструктор копирования ->" << this << endl;
	}
	~exam()
	{
		cout << "Вызван деструктор для ->" << this << endl;
	}
	string GetSNP()
	{
		cout << "ФИО ученика: " << SNP << endl;
		return SNP;
	}
	void SetSNP(string ValueSNP)
	{
		SNP = ValueSNP;
	}
	string GetSubject()
	{
		cout << "Его предмет: " << subject << endl;
		return subject;
	}
	void SetSubject(string ValueSubject)
	{
		subject = ValueSubject;
	}
	int GetMark()
	{
		cout << "Его оценка: " << mark << endl;
		return mark;
	}
	void SetMark(int ValueMark)
	{
		mark = ValueMark;
	}
	void show()
	{
		cout << "ФИО ученика: " << SNP << endl << "Его предмет: " << subject << endl << "Его оценка: " << mark << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	exam first;
	first.show();
	exam second("Баранов Алексей Александрович", "Математика", 5);
	second.show();
	exam third(*&first);
	third.show();
	exam dop;
	dop.SetSNP("Дроздин Антон Антонович");
	dop.GetSNP();
	dop.SetSubject("Информатика");
	dop.GetSubject();
	dop.SetMark(2);
	dop.GetMark();
	return 0;
}