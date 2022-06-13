#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <Windows.h> // підключаємо бібліотеку, яка забезпечує відображення кирилиці
using namespace std;

struct Train
{
	string startPoint;
	string endPoint;
	int number;
};

void add(map<int, Train>& c)
{
	int pos = c.size(); int tmp2;
	Train tmp;
	cout << "Start point : ";
	cin >> tmp.startPoint;

	cout << "End point : ";
	cin >> tmp.endPoint;

	cout << "Number : ";
	cin >> tmp.number;
	c.insert({ pos, tmp });
}

void display(map<int, Train> c)
{
	for (int i = 0; i < c.size(); i++)
	{
		cout << "Start point : " << c[i].startPoint << endl;
		cout << "End point : " << c[i].endPoint << endl;
		cout << "Number : " << c[i].number << endl;
	}
}
void displayWithNumber(map<int, Train> c, int n)
{
	bool check = false;
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i].number == n) {
			check = true;
			cout << "Start point : " << c[i].startPoint << endl;
			cout << "End point : " << c[i].endPoint << endl;
			cout << "Number : " << c[i].number << endl;
		}
	}
	if (!check)
		cout << "Wrong number!" << endl;
}

int main()
{
	// забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення кодової сторінки win-cp1251
	// (кирилиця) в потік вводу
	SetConsoleOutputCP(1251); // встановлення кодової сторінки win-cp1251
	// (кирилиця) в потік виводу
	map<int, Train> rozklad;
	int tmp2, tmp3;
	do
	{
		cout << "[1] Додати запис" << endl;
		cout << "[2] Відобразити записи" << endl;
		cout << "[3] Вивести відповідно до номеру" << endl;
		cout << "[0] Вийти" << endl;
		do
		{
			cin >> tmp2;
		} while (tmp2 < 0 || tmp2 > 3);
		switch (tmp2)
		{
		case 1:
			add(rozklad);
			break; 
		case 2:
			display(rozklad);
			break;
		case 3:
			cout << "Number : ";
			do
			{
				cin >> tmp3;
			} while (tmp3 < 0);
			displayWithNumber(rozklad, tmp3);
			break;
		default:
			break;
		}
	} while (tmp2 != 0);
	return 0;
}