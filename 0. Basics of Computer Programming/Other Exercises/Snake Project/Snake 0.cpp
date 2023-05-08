#include <iostream>
#include <Windows.h>
#include <time.h>
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
	srand(time(NULL));
	int i, j, x = 60, y = 20;
	int emt_x = rand() % 60, emt_y = rand() % 20;
	if (emt_x == 0)
	{
		emt_x = emt_x + 1;
	}
	if (emt_y == 0)
	{
		emt_y = emt_y + 1;
	}
	for (i = 0; i <= x; i++)
	{
		gotoxy(i, 0);
		cout << "-";
	}
	for (j = 1; j <= y; j++)
	{
		gotoxy(x, j);
		cout << "|";
	}
	for (i = x; i >= 0; i--)
	{
		gotoxy(i, y);
		cout << "_";
	}
	for (j = y; j >= 1; j--)
	{
		gotoxy(0, j);
		cout << "|";
	}
	gotoxy(emt_x, emt_y);
	cout << "#";

	gotoxy(0, 22);
	cout << "Record: ";
	gotoxy(40, 22);
	cout << "Time: ";
	gotoxy(0, 23);
	system("pause>A");
}