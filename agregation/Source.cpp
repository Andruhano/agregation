#include<iostream>
#include<string>
using namespace std;
class Cond
{
	string name;
public:
	Cond()
	{
		name = "Midea";
	}
	Cond(const char* N)
	{
		name = N;
	}
	Cond(Cond& obj)
	{
		name = obj.name;
	}
	void Show()
	{
		cout << name << endl;
	}
};
class Engine
{
	double w;
public:
	Engine()
	{
		w = 10000;
	}
	Engine(double d)
	{
		w = d;
	}
	void Show()
	{
		cout << "Engine w = " << w << endl;
	}
};

class Car
{
	Cond* obj;   // Не уничтожается при удалении объекта класса Car!  агрегирование
	int year;
	Engine a; // удаляется приуничтожении объекта класса Car!!! композиция
public:
	Car(Cond* x, double d, int y) : obj(x), a(d)
	{
		year = y;
	}

	void SetCond(Cond* c)
	{
		obj = c;
	}

	void Show()
	{
		cout << year << endl;
		obj->Show();
		a.Show();
	}
	~Car()
	{
		cout << "Destruct\n";
	}
};


int main()
{
	Cond obj{ "Samsung" };

	Car* ptr = new Car(&obj, 20000, 2018);

	ptr->Show();

	Cond obj2{ "JAX" };

	ptr->SetCond(&obj2);

	ptr->Show();
	delete ptr;
	//obj.Show();

	cout << "\n---- obj2 -------------------\n";
	Car new_obj(&obj, 12000, 1999);
	new_obj.Show();


	system("pause");
}