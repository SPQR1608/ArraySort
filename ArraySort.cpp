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
	
	cout << "��������� ��� ���������� ����������� �������" << endl;
	cout << "������� ������ �������: ";
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
				WriteArray("�������� ������: ", Array, n);
				break;
			case SORT_SHELL:
				ShellSort(Array, n);
				WriteArray("��������������� ������� �����", Array, n);
				break;
			case SORT_DIRSEL:
				ShellSort(Array, n);
				WriteArray("��������������� ������� ������� ������", Array, n);
				break;
			case SORT_TIME:
				break;
			case SEARCH_ARRAY:
				break;
			case SHOW_ALL:
				FormArray(Array, n);
				WriteArray("�������� ������: ", Array, n);
				ShellSort(Array, n);
				WriteArray("��������������� ������� �����", Array, n);
				ShellSort(Array, n);
				WriteArray("��������������� ������� ������� ������", Array, n);
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

	cout << endl << "����:" << endl;
	for(;;)
	{
		cout << EXIT << " - �����" << endl;
		cout << FORM_ARRAY << " - ������������ �������" << endl;
		cout << OUTPUT_ARRAY << " - ����� �� ����� ������" << endl;
		cout << SORT_SHELL << " - ���������� ������� �����" << endl;
		cout << SORT_DIRSEL << " - ���������� ������� ������� ������" << endl;
		cout << SORT_TIME << " - ��������� ������� ����������" << endl;
		cout << SEARCH_ARRAY << " - ����� ��������� �������� � �������" << endl;
		cout << SHOW_ALL << " - ��������� ��� �����" << endl;
		cout << CLEAR_CMD << " - ������� ������" << endl;
		cout << "����� ������� ����: ";
		cin >> CmdMenu;
		cout << endl;
		if(CmdMenu < 0 || CmdMenu >= END)
		{
			cout << "������ - ����� ������� ���!" << endl;
			continue;
		}
		else
			return CmdMenu;
	}
}

