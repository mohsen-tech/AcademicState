#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <Windows.h>
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
int main()
{
	int x = 0, y = 0;
	char s = _getch();
	while (true)
	{
		s = _getch();
		if (s == 72)
		{
			y--;
			if (y < 0)
				y = 10;
			gotoxy(x, y);
		}
		else if (s == 75)
		{
			x--;
			if (x < 0)
				x = 10;
			gotoxy(x, y);
		}
		else if (s == 77)
		{
			x++;
			if (x > 11)
				x = 0;
			gotoxy(x, y);
		}
		else if (s == 80)
		{
			y++;
			if (y > 11)
				y = 0;
			gotoxy(x, y);
		}
	}
	return 0;
}