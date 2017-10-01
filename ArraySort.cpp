// ArraySort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "FuncSort.h"

using namespace std;

enum Menu {EXIT, FORM_ARRAY, OUTPUT_ARRAY, SORT_SHELL, SORT_DIRSEL, SORT_TIME, SEARCH_ARRAY, SHOW_ALL, CLEAR_CMD, END};
int Menu();

void _tmain()
{
	setlocale(LC_CTYPE, ".1251");
	system("color F0");

	int CmdMenu;
	int *Array;
	int n;
	
	cout << "Программа для сортировки одномерного массива" << endl;
	cout << "Введите размер массива: ";
	cin >> n;

	Array = new int[n];

	for(;;)
	{
		CmdMenu = Menu();
		switch(CmdMenu)
		{
			case EXIT:
				return;
				break;
			case FORM_ARRAY:
				FormArray(Array, n);
				break;
			case OUTPUT_ARRAY:
				WriteArray("Исходный массив: ", Array, n);
				break;
			case SORT_SHELL:
				ShellSort(Array, n);
				WriteArray("Отсортированный методом Шелла", Array, n);
				break;
			case SORT_DIRSEL:
				ShellSort(Array, n);
				WriteArray("Отсортированный методом прямого выбора", Array, n);
				break;
			case SORT_TIME:
				break;
			case SEARCH_ARRAY:
				break;
			case SHOW_ALL:
				FormArray(Array, n);
				WriteArray("Исходный массив: ", Array, n);
				ShellSort(Array, n);
				WriteArray("Отсортированный методом Шелла", Array, n);
				ShellSort(Array, n);
				WriteArray("Отсортированный методом прямого выбора", Array, n);
				break;
			case CLEAR_CMD:
				system("cls");
				break;
		}
	}
	
	delete Array;
}

int Menu()
{
	int CmdMenu;

	cout << endl << "МЕНЮ:" << endl;
	for(;;)
	{
		cout << EXIT << " - выход" << endl;
		cout << FORM_ARRAY << " - формирование массива" << endl;
		cout << OUTPUT_ARRAY << " - вывод на экран массив" << endl;
		cout << SORT_SHELL << " - сортировка методом Шелла" << endl;
		cout << SORT_DIRSEL << " - сортировка методом прямого выбора" << endl;
		cout << SORT_TIME << " - сравнение времени сортировки" << endl;
		cout << SEARCH_ARRAY << " - поиск заданного элемента в массиве" << endl;
		cout << SHOW_ALL << " - проделать все этапы" << endl;
		cout << CLEAR_CMD << " - очистка экрана" << endl;
		cout << "Номер команды меню: ";
		cin >> CmdMenu;
		cout << endl;
		if(CmdMenu < 0 || CmdMenu >= END)
		{
			cout << "ОШИБКА - такой команды нет!" << endl;
			continue;
		}
		else
			return CmdMenu;
	}
}

