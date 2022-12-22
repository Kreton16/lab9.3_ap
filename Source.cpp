#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

struct Route
{
	string sname;
	string ename;
	int rnum{};
};
void Create(Route* p, const int N);
void Print(Route* p, const int N);
void Sort(Route* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть кількість маршрутів N: "; cin >> N;
	Route* p = new Route[N];
	double proc = 0, avg = 0, Kurs = 0, average = 0;
	string prizv;
	int found = 0;
	char filename[100]{};
	int menuItem;
	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран за номером" << endl;
		cout << " [3] - впорядкування даних за номером маршрутів" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;

		case 2:
			Print(p, N);
			break;

		case 3:
			Sort(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення!"<<
				"Слід ввести число - номер вибраного пункту меню" << endl;

		}
	} while (menuItem != 0);
	return 0;
}
void Create(Route* p, const int N)
{
	int Predmet = 0;
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		cin.get();
		cin.sync();
		cout << " Початковий пункт : "; getline(cin, p[i].sname);
		cout << " Кінцевий пункт : "; cin >> p[i].ename;
		cout << " Номер маршруту : "; cin >> p[i].rnum;
		cout << endl;
	}
}
void Print(Route* p, const int N)
{
	int routenumber, count = 0;
	cout << "Введіть номер маршруту: "; cin >> routenumber;
	for (int i = 0; i < N; i++) {
		if (routenumber == p[i].rnum)
			count++;
	}
	if (count > 0) {
		cout << "=================================="
			<< endl;
		cout << "__________________________________"
			<< endl;
		cout << "|  Початок  |  Кінець  |  Номер  |"
			<< endl;
		cout << "----------------------------------"
			<< endl;
		for (int i = 0; i < N; i++)
		{
			if (routenumber == p[i].rnum) {
				cout << "| " << setw(10) << left << p[i].sname
					<< "| " << setw(10) << left << p[i].ename
					<< "| " << setw(6) << left << p[i].rnum << "|" << endl;
			}
		}
		cout << "=================================="
			<< endl;
		cout << endl;
	}
	else
		cout << "\nВи ввели невірний номер!\n"
		"Слід ввести число - номер існуючого маршруту" << endl;
}

void Sort(Route* p, const int N)
{
	Route tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if (p[i1].rnum < p[i1+1].rnum)
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
		}
}