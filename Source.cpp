#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
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
	cout << "������ ������� �������� N: "; cin >> N;
	Route* p = new Route[N];
	double proc = 0, avg = 0, Kurs = 0, average = 0;
	string prizv;
	int found = 0;
	char filename[100]{};
	int menuItem;
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� ����� �� �������" << endl;
		cout << " [3] - ������������� ����� �� ������� ��������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "�� ����� ��������� ��������!"<<
				"��� ������ ����� - ����� ��������� ������ ����" << endl;

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
		cout << " ���������� ����� : "; getline(cin, p[i].sname);
		cout << " ʳ������ ����� : "; cin >> p[i].ename;
		cout << " ����� �������� : "; cin >> p[i].rnum;
		cout << endl;
	}
}
void Print(Route* p, const int N)
{
	int routenumber, count = 0;
	cout << "������ ����� ��������: "; cin >> routenumber;
	for (int i = 0; i < N; i++) {
		if (routenumber == p[i].rnum)
			count++;
	}
	if (count > 0) {
		cout << "=================================="
			<< endl;
		cout << "__________________________________"
			<< endl;
		cout << "|  �������  |  ʳ����  |  �����  |"
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
		cout << "\n�� ����� ������� �����!\n"
		"��� ������ ����� - ����� ��������� ��������" << endl;
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