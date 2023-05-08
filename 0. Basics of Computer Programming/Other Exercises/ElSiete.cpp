#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;
string ch = "$";
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != h)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(h, pos);
	}
}
void color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
void Zero(int size, int x, int y)
{
	int sizeX = size, sizeY = size * 2;
	for (int i = x + 1; i < sizeX + x + 1; i++)
	{
		gotoxy(i, y);
		cout << ch;
		gotoxy(i, y + sizeY - 1);
		cout << ch;
	}
	for (int i = y + 1; i < sizeY + 1; i++)
	{
		gotoxy(x, i);
		cout << ch;
		gotoxy(x + sizeX + 1, i);
		cout << ch;
	}
}
void One(int size, int x, int y)
{
	size *= 2;
	for (int k = y; k < size + y; k++)
	{
		gotoxy(x, k);
		cout << ch;
	}
	for (int k = x, p = y; p < (size / 2) + y; k--, p++)
	{
		gotoxy(k, p);
		cout << ch;
	}
}
void Two(int size, int x, int y)
{
	int sizeX = size + 2, sizeY = size * 2;

	for (size_t i = x; i < sizeX + x + 1; i++)
	{
		gotoxy(i, y + sizeY);
		cout << ch;
	}
	for (size_t i = x + 1; i < sizeX + x; i++)
	{
		gotoxy(i, y);
		cout << ch;
	}
	gotoxy(x, y + 1);
	cout << ch;
	for (int k = sizeX + x, p = y + 1; x != k; k--, p++)
	{
		gotoxy(k, p);
		cout << ch;
	}
}
void Nine(int size, int x, int y)
{
	for (int i = x; i < x + 4; i++)
	{
		gotoxy(i, y);
		cout << ch;
		gotoxy(i, y + 3);
		cout << ch;
	}
	for (int i = y + 1; i < y + 3; i++)
	{
		gotoxy(x - 1, i);
		cout << ch;
		gotoxy(x + 4, i);
		cout << ch;
	}
	for (int k = x + 3, p = y + 4; x - 1 != k; k--, p++)
	{
		gotoxy(k, p);
		cout << ch;
	}
}
void Dot(int x, int y)
{
	gotoxy(x, y);
	cout << ch << ch;
	gotoxy(x, y + 1);
	cout << ch << ch;
}
void Run()
{
	color(0xF3);
	Two(3, 4, 3);
	Zero(4, 11, 2);
	Zero(4, 18, 2);
	One(4, 28, 2);
	color(0xF9);
	Dot(30, 8);
	color(0xF3);
	Nine(4, 33, 2);
	color(0xF9);
	Dot(38, 8);
	color(0xF3);
	One(4, 43, 2);
	One(4, 48, 2);
}
int main()
{
	color(0xF0);
	system("cls");
	Run();
	system("pause>0");
	return 0;
}