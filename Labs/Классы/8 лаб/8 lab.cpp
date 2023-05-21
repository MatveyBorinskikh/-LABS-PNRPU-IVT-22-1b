#include<iostream>
#include<string>
const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;
struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};
using namespace std;
class object
{
public:
	virtual void input() = 0;
	virtual void show() = 0;
	virtual void show_title() = 0;
};

class print :public object
{
protected:
	string title;
	string author;

public:
	//������������
	print(void)//��� ����������
	{
		title = "";
		author = "";
	}
	print(string title, string author)//� �����������
	{
		this->title = title;
		this->author = author;
	}
	print(const print& p)//�����������
	{
		title = p.title;
		author = p.author;
	}

	//����������
	~print(void)
	{
	}

	//���������
	string Get_title() { return title; }
	string Get_author() { return author; }

	//������������
	void Set_title(string title) { this->title = title; }
	void Set_author(string author) { this->author = author; }

	//���������� ��������� ������������
	print& operator= (const print& p)
	{
		title = p.title;
		author = p.author;
		return *this;
	}

	//����� ��� ������ ���������
	void show()
	{
		cout << "��������: " << title << "\n";
		cout << "�����: " << author << "\n\n";
	}
	void show_title()
	{
		cout << "��������: " << title << "\n";
	}
	//����� ��� ����� ���������
	void input()
	{
		cout << " ������� �������� >> "; cin >> this->title;
		cout << "������� ������ >> "; cin >> this->author;
		cout << "\n";
	}

	//void HandleEvent(const TEvent& event)
	//{
	//}
};

class magazin : public print
{
protected:
	int pages;
public:
	//������������
	magazin(void) : print()
	{
		pages = 0;
	}
	magazin(string title, string author, int pages) : print(title, author)
	{
		this->pages = pages;
	}
	magazin(const magazin& s)
	{
		title = s.title;
		author = s.author;
		pages = s.pages;
	}

	//����������
	~magazin(void)
	{
	}

	//��������
	int Get_pages() { return  pages; }

	//�����������
	void Set_pages(int  pages) { this->pages = pages; }

	//���������� ��������� ������������
	magazin& operator=(const magazin& s)
	{
		title = s.title;
		author = s.author;
		pages = s.pages;
		return *this;
	}

	//����� ��� ������ ���������
	void show()
	{
		cout << "��������: " << title << "\n";
		cout << "�����: " << author << "\n";
		cout << "���������� �������: " << pages << "\n\n";
	}

	//����� ��� ����� ���������
	void input()
	{
		cout << "�������� >> "; cin >> title;
		cout << "����� >> "; cin >> author;
		cout << "���������� ������� >> "; cin >> pages;
		cout << "\n";
	}
};

class List :public magazin
{
protected:
	object** beg;
	int size;
	int cur;
public:
	//������������
	List(void)
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	List(int n)
	{
		beg = new object * [n];
		size = n;
		cur = 0;
	}
	List(const List& l)
	{
		beg = l.beg;
		size = l.size;
		cur = l.cur;
	}

	//����������
	~List(void)
	{
	}

	//���������� ������� �� ������� ��������� ��������� � � ������
	void Add()
	{
		object* p;
		//����� �� �������� 2 ��������� �������
		cout << "1.print\n2.magazin\nEnter num type >> ";
		int y;
		cin >> y; cout << "\n";

		if (y == 1)//���������� ������� ������ print
		{
			print* a = new (print);
			a->input();
			p = a;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else if (y == 2)//���������� ������� ������ magazin
		{
			magazin* b = new (magazin);
			b->input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
	}

	//�������� �������� �� ������, �� ��� ���� ������ �� �������������
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}


	//�������� ������
	void Info_All()
	{
		if (cur == 0) cout << "Empty\n";
		object** p = beg;//��������� �� ��������� ���� Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->show();//����� ������ Show() (������� ������������)
			++p;//����������� ��������� �� ���� ������
		}
	}

	//�������� �������� �� ������
	void Info_title()
	{
		if (cur == 0) cout << "Empty\n";
		object** p = beg;//��������� �� ��������� ���� Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->show_title();//����� ������ Show() (������� ������������)
			++p;//����������� ��������� �� ���� ������
		}
	}

	//�������� ������������ ������ ������
	int operator() ()
	{
		return cur;
	}

	void HandleEvent(const TEvent& event)
	{
		if (event.what == evMessage)
		{
			object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->show();
				++p;
			}
		}
	}
};

class Dialog :public List
{
protected:
	int EndState;
public:
	//�����������
	Dialog(void) :List()
	{
		EndState = 0;
	}

	//����������
	~Dialog(void)
	{
	}

	//�������� �������
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;//������ �������
	}

	//�������� EndState
	int Valid()
	{
		if (EndState == 0) return 0;
		else return 1;
	}

	//����� ������
	void EndExec()
	{
		EndState = 1;
	}

	//��������� �������
	void GetEvent(TEvent& event)
	{
		string OpInt = "m+-s?q";//���� ��������
		string s;
		string param;

		char code;
		cout << ">"; cin >> s;
		code = s[0];//������ ������ �������

		if (OpInt.find(code) >= 0)//�������� �� ������ ����� ��������
		{
			event.what = evMessage;
			switch (code)
			{
			case 'm':
				event.command = cmMake; break;//������� ������
			case '+':
				event.command = cmAdd; break;//�������� ������
			case '-':
				event.command = cmDel; break;//������� ������
			case 's':
				event.command = cmShow; break;//������� ������
			case 'z':
				event.command = cmGet; break;//������� �������� 1 �������
			case 'q':
				event.command = cmQuit; break;//�����
			}

			//�������� ��������� ������� ���� ��� ����
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());//����������� �������� � �����
				event.a = A;//���������� �������� � ���������
			}

		}
		else event.what = evNothing;//������ �������
	}

	//���������� �������
	void HandleEvent(TEvent& event)
	{
		if (event.what == evMessage)
		{
			switch (event.command)
			{
			case cmMake:
				size = event.a;
				beg = new object * [size];
				cur = 0;
				ClearEvent(event);
				break;
			case cmAdd:
				Add();
				ClearEvent(event);
				break;
			case cmDel:
				Del();
				ClearEvent(event);
				break;
			case cmShow:
				Info_All();
				ClearEvent(event);
				break;
			case cmGet:
				Info_title();
				ClearEvent(event);
				break;
			case cmQuit:
				EndExec();
				ClearEvent(event);
				break;
			default:
				HandleEvent(event);
			}
		}
	}

	//������� ���� ��������� �������
	int Execute()
	{
		TEvent event;
		do
		{
			EndState = 0;
			GetEvent(event);
			HandleEvent(event);
		} while (!Valid());
		return EndState;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "�������:\n+: ��������\n-: �������\nm: ������� ����\ns: ����� ���������: \nz: ����� �������� ���������\nq: �����\n\n";
	Dialog D;
	D.Execute();
	return 0;
}