#include "pch.h"
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;

struct Mystruct
{
	string name;
	int room_number;
	string room_name;
	int data;
	int begin_time[3];
	int time_end[3];
};

void Input(vector<Mystruct>& user, int n)
{
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "Имя врача:  ";
		cin >> user[i].name;
		cout << endl;

		cout << "День приема - ";
		cin >> user[i].data;
		cout << endl;

		cout << "Введите время начало работы: (через Enter ч/м/с) -  ";
		for (int j = 0; j < 3; j++)
		{
			cin >> user[i].begin_time[j];
		}
		cout << endl;
		cout << "Введите время окончания работы: (через Enter ч/м/с) - ";
		for (int j = 0; j < 3; j++)
		{
			cin >> user[i].time_end[j];
		}
		cout << endl;

		cout << "Название кабинета - ";
		cin >> user[i].room_name;
		cout << endl;

		cout << "Номер кабинета - ";
		cin >> user[i].room_number;
		cout << endl;
	}
}

void Print(vector<Mystruct>& user, int n)
{
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "Имя " << user[i].name << endl;

		cout << "Дата работы: ";
		cout << user[i].data;
		cout << endl;

		cout << "Dремя начало сеанса: ";
		for (int j = 0; j < 3; j++)
		{
			cout << user[i].begin_time[j] << ":";
		}
		cout << endl;
		cout << "Время окончания сеанса: ";
		for (int j = 0; j < 3; j++)
		{
			cout << user[i].time_end[j] << ":";
		}
		cout << endl << endl;
	}
	system("pause");
}

void Out(vector<Mystruct>& user, int n, ofstream &out)
{
	out.open("Doctors.txt");
	if (!out.is_open())
		cout << "Error open!\n";
	else
	{
		for (int i = 0; i < n; i++)
		{
			out << user[i].name << endl;

			for (int j = 0; j < 3; j++)
			{
				out << user[i].data << " ";
			}
			out << endl;
			for (int j = 0; j < 3; j++)
			{
				out << user[i].begin_time[j] << " ";
			}
			out << endl;
			for (int j = 0; j < 3; j++)
			{
				out << user[i].time_end[j] << " ";
			}
			out << endl << endl;
		}
	}
	cout << "Данные успешно сохранены в файл" << endl;
	system("pause");
}

void Fin(vector<Mystruct>& user, int n, ifstream &fin)
{
	fin.open("Doctors.txt");
	if (!fin.is_open())
		cout << "Error open!\n";
	else
	{
		for (int i = 0; i < n; i++)
		{
			fin >> user[i].name;
			fin >> user[i].data;
			for (int j = 0; j < 3; j++)
			{
				fin >> user[i].begin_time[j];
			}
			for (int j = 0; j < 3; j++)
			{
				fin >> user[i].time_end[j];
			}
		}
		cout << "Данные успешно импортированы\n";
	}
	system("pause");
}

void After12(vector<Mystruct>& user, int n)
{
	system("cls");
	vector <int> index;
	bool find = false;
	int month, amount_online = 0;
	for (int i = 0; i < n; i++)
	{
		if (user[i].begin_time[2] >= 12)
		{
			cout << "Имя " << user[i].name << endl;
			cout << "Дата работы: ";
			cout << user[i].data;
			cout << endl;

			cout << "Dремя начало сеанса: ";
			for (int j = 0; j < 3; j++)
			{
				cout << user[i].begin_time[j] << ":";
			}
			cout << endl;
			cout << "Время окончания сеанса: ";
			for (int j = 0; j < 3; j++)
			{
				cout << user[i].time_end[j] << ":";
			}
			cout << endl << endl;
		}
		system("pause");
	}
}

void Best_Doctors_Ever(vector<Mystruct>& user, int n)
{
	system("cls");
	vector <int> index;
	bool find = false;
	int month, amount_online = 0;
	for (int i = 0; i < n; i++)
	{
		if (user[i].begin_time[2] <= 12 && user[i].time_end[2] >= 12)
		{
			cout << "Имя " << user[i].name << endl;
			cout << "Дата работы: ";
			cout << user[i].data;
			cout << endl;

			cout << "Dремя начало сеанса: ";
			for (int j = 0; j < 3; j++)
			{
				cout << user[i].begin_time[j] << ":";
			}
			cout << endl;
			cout << "Время окончания сеанса: ";
			for (int j = 0; j < 3; j++)
			{
				cout << user[i].time_end[j] << ":";
			}
			cout << endl << endl;
		}
	}
	system("pause");
}

void Last_Doctor(vector<Mystruct>& user, int n)
{
	system("cls");
	vector<Mystruct> index(1);
	index[0] = user[0];
	for (int i = 0; i < n; i++)
	{
		if (user[i].room_name == "Терапевт" && (user[i].time_end[2] * 60 + user[i].time_end[1]) < index[0].time_end[2] * 60 + index[0].time_end[1])
			index[0] = user[i];
	}
	if (index[0].room_name == "Терапевт")
	{
		cout << "Имя" << index[0].name << endl;
		cout << "Дата работы: ";
		cout << index[0].data << "/ ";
		cout << endl;

		cout << "Dремя начало сеанса: ";
		for (int j = 0; j < 3; j++)
		{
			cout << index[0].begin_time << ":";
		}
		cout << endl;
		cout << "Время окончания сеанса: ";
		for (int j = 0; j < 3; j++)
		{
			cout << index[0].time_end[j] << ":";
		}
		cout << endl << endl;
	}
	system("pause");
}

void Menu(vector<Mystruct>& user, int n, ofstream &out, ifstream &fin)
{
link:
	system("cls");
	int selection = 0;
	cout << "Выберете раздел:\n" <<
		"1. Посмотреть данные о пользователях.\n" <<
		"2. Записать пользователей в файл.\n" <<
		"3. Импортировать данные.\n" <<
		"4. Работающие после 12:00.\n" <<
		"5. Последний терапевт.\n" <<
		"6. Начинают до, заканчивают после 12.\n" <<
		"7. Выход.\n";
	cin >> selection;
	switch (selection)
	{
	case 1:
		Print(user, n);
		goto link;
		break;
	case 2:
		Out(user, n, out);
		goto link;
		break;
	case 3:
		Fin(user, n, fin);
		goto link;
		break;
	case 4:
		After12(user, n);
		goto link;
		break;
	case 5:
		Last_Doctor(user, n);
		goto link;
		break;
	case 6:
		Best_Doctors_Ever(user, n);
		goto link;
		break;
	case 7:
		exit(0);
		break;
	default:
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	ofstream out;
	ifstream fin;
	int n, selection = 0;
	cout << "Введите количество пользователей:" << endl;
	cin >> n;
	vector<Mystruct> user(n);
	vector<int> time_online(n);


	cout << "Вы хотите добавить заполнить или импортировать готовые данные? ( 1 - Заполнить | 2 - Импортировать)\n";
	cin >> selection;

	switch (selection)
	{
	case 1:
		Input(user, n);
		Out(user, n, out);
		Menu(user, n, out, fin);
		break;
	case 2:
		Fin(user, n, fin);
		Menu(user, n, out, fin);
		break;
	default:
		exit(0);
		break;
	}

	system("pause");
	return 0;
}