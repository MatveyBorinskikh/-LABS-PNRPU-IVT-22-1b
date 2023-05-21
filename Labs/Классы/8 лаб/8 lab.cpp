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
	//конструкторы
	print(void)//без параметров
	{
		title = "";
		author = "";
	}
	print(string title, string author)//с параметрами
	{
		this->title = title;
		this->author = author;
	}
	print(const print& p)//копирования
	{
		title = p.title;
		author = p.author;
	}

	//деструктор
	~print(void)
	{
	}

	//селекторы
	string Get_title() { return title; }
	string Get_author() { return author; }

	//модификаторы
	void Set_title(string title) { this->title = title; }
	void Set_author(string author) { this->author = author; }

	//перегрузка оператора присваивания
	print& operator= (const print& p)
	{
		title = p.title;
		author = p.author;
		return *this;
	}

	//метод для вывода атрибутов
	void show()
	{
		cout << "Название: " << title << "\n";
		cout << "Автор: " << author << "\n\n";
	}
	void show_title()
	{
		cout << "Название: " << title << "\n";
	}
	//метод для ввода атрибутов
	void input()
	{
		cout << " Введите название >> "; cin >> this->title;
		cout << "Введите автора >> "; cin >> this->author;
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
	//конструкторы
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

	//деструктор
	~magazin(void)
	{
	}

	//селектор
	int Get_pages() { return  pages; }

	//модификатор
	void Set_pages(int  pages) { this->pages = pages; }

	//перегрузка оператора присваивания
	magazin& operator=(const magazin& s)
	{
		title = s.title;
		author = s.author;
		pages = s.pages;
		return *this;
	}

	//метод для вывода атрибутов
	void show()
	{
		cout << "Название: " << title << "\n";
		cout << "Автор: " << author << "\n";
		cout << "Количество страниц: " << pages << "\n\n";
	}

	//метод для ввода атрибутов
	void input()
	{
		cout << "Название >> "; cin >> title;
		cout << "Автор >> "; cin >> author;
		cout << "Количество страниц >> "; cin >> pages;
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
	//конструкторы
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

	//деструктор
	~List(void)
	{
	}

	//добовление объекта на который указывает указатель р в список
	void Add()
	{
		object* p;
		//выбор из объектов 2 возможных классов
		cout << "1.print\n2.magazin\nEnter num type >> ";
		int y;
		cin >> y; cout << "\n";

		if (y == 1)//добавление объекта класса print
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
		else if (y == 2)//добавление объекта класса magazin
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

	//удаление элемента из списка, но при этом память не освобождается
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}


	//просмотр списка
	void Info_All()
	{
		if (cur == 0) cout << "Empty\n";
		object** p = beg;//указатель на указатель типа Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->show();//вызов метода Show() (позднее срабатывание)
			++p;//передвигаем указатель на след объект
		}
	}

	//просмотр элемента из списка
	void Info_title()
	{
		if (cur == 0) cout << "Empty\n";
		object** p = beg;//указатель на указатель типа Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->show_title();//вызов метода Show() (позднее срабатывание)
			++p;//передвигаем указатель на след объект
		}
	}

	//операция возвращающая размер списка
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
	//конструктор
	Dialog(void) :List()
	{
		EndState = 0;
	}

	//деструктор
	~Dialog(void)
	{
	}

	//очищение события
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;//пустое событие
	}

	//проверка EndState
	int Valid()
	{
		if (EndState == 0) return 0;
		else return 1;
	}

	//конец работы
	void EndExec()
	{
		EndState = 1;
	}

	//получения события
	void GetEvent(TEvent& event)
	{
		string OpInt = "m+-s?q";//коды операций
		string s;
		string param;

		char code;
		cout << ">"; cin >> s;
		code = s[0];//первый символ команды

		if (OpInt.find(code) >= 0)//является ли символ кодом операции
		{
			event.what = evMessage;
			switch (code)
			{
			case 'm':
				event.command = cmMake; break;//создать группу
			case '+':
				event.command = cmAdd; break;//добавить объект
			case '-':
				event.command = cmDel; break;//удалить объект
			case 's':
				event.command = cmShow; break;//вывести список
			case 'z':
				event.command = cmGet; break;//вывести атрибуты 1 объекта
			case 'q':
				event.command = cmQuit; break;//выход
			}

			//выделяем параметры команды если они есть
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());//преобразуем параметр в число
				event.a = A;//записываем параметр в сообщение
			}

		}
		else event.what = evNothing;//пустое событие
	}

	//обработчик событий
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

	//главный цикл обработки событий
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
	cout << "Команды:\n+: добавить\n-: удалить\nm: создать лист\ns: Вывод элементов: \nz: Вывод названий элементов\nq: выход\n\n";
	Dialog D;
	D.Execute();
	return 0;
}