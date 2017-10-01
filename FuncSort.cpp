
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void FormArray(int *Array, int n)
{
	int i;
	int max;
	int min;

	cout << endl << "Введите диапазон целых чисел массива:" << endl	<< "От ";
	cin >> min;
	cout << "до ";
	cin >> max;

	for(i=0; i<n; i++)
		Array[i] = rand()%max + min;

	cout << "Массив сформирован!" << endl;
}

void WriteArray(char *pText, int *Array, int n)
{
	int i;

	cout << pText << endl;
	for(i=0; i<n; i++)
		cout << setw(5) << Array[i];

	cout << endl;
}

void ShellSort(int *Array, int n)
{
	int i, j;
	int buff;
	int inc;

	for(inc = n >> 1; inc > 0; inc >>= 1)
	{
		for(i = inc; i < n; i++)
			for(j = i-inc; j >= 0; j -= inc)
			{
				if(Array[j] <= Array[j+inc])
					break;
				buff = Array[j];
				Array[j] = Array[j+inc];
				Array[j+inc] = buff;
			}
	}
}

void DirSelSort(int *Array, int n)
{
	int i, j, buf;

	for(j=0; j<n;j++)
	{
		for(i = j+1; i < n; i++)
		{
			if(Array[j]>Array[i])
			{
				buf = Array[j];
				Array[j] = Array[i];
				Array[i]= buf;
			}
		}
	}
}

