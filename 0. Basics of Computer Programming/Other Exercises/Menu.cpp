//#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <Windows.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include <string>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ios>
#include <vector>
#include <amp_graphics.h>
#include <list>
#define size 100
using namespace std;
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
}
void color(int number)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, number);
}
int main()
{
	int x = 5, y = 3;

	gotoxy(x - 2, y);
	cout << "---------";
	gotoxy(x, y + 2);
	cout << "Start";
	gotoxy(x - 2, y + 4);
	cout << "---------";
	gotoxy(x, y + 6);
	cout << "About";
	gotoxy(x - 2, y + 8);
	cout << "---------";
	gotoxy(x, y + 10);
	cout << "Exit";
	gotoxy(x - 2, y + 12);
	cout << "---------";

	char s = _getch();
	while (true)
	{
		s = _getch();
		if (s == 72)
		{
			y -= 4;
			if (y < 5)
				y = 13;
			gotoxy(x, y);
		}
		else if (s == 80)
		{
			y += 4;
			if (y > 13)
				y = 5;
			gotoxy(x, y);
		}
		if (s == 'o' && y == 13)
		{
			system("cls");
			exit(0);
		}
		else if (s == 'o' && y == 9)
		{
			system("cls");
			cout << "Create By: ...";
		}
		else if (s == 'o' && y == 5)
		{
			system("cls");
			cout << "Playing ...";
		}
	}
	return 0;
}