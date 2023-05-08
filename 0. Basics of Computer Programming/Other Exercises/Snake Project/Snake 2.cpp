//Snake //Amir ArasNezhad
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;
//////////////////////////////////////////
void gotoxy(int x, int y);
void move(int dx, int dy);
char getvalue(int value);
void produce();
void option();
void start();
//////////////////////////////////////////
int food = 1;
int hx;
int hy;
int d;
const int w = 20;
const int h = 35;
const int len = w * h;
int a[len];
bool r;
//////////////////////////////////////////
int main()
{
	option();
	system("pause>0");
	return 0;
}
//////////////////////////////////////////
void option()
{
	for (int x = 0; x < w; ++x)
	{
		for (int y = 0; y < h; ++y)
			if (x == 0)
				cout << getvalue(-1);
			else if (y == 0 || y == h - 1)
				cout << getvalue(-1);
			else if (x == w - 1)
				cout << getvalue(-1);
			else
				cout << " ";
		cout << endl;
	}
	gotoxy(13, 3);
	cout << "- Snake -";
	gotoxy(13, 6);
	cout << "1. Play";
	gotoxy(13, 8);
	cout << "2. Exit";
	gotoxy(2, w - 3);
	cout << "CopyRight Amir ArasNezhad";
	int n;
	gotoxy(10, 11);
	cout << "Choose One: ";
	gotoxy(22, 11);
	cin >> n;
	if (n == 1)
	{
		food = 1;
		hx = 0;
		hy = 0;
		d = 0;
		int a[len] = { 0 };
		start();
		system("cls");
		option();
	}
	else exit(0);
}
//////////////////////////////////////////
void start()
{
	hx = w / 2;
	hy = h / 2;
	a[hx + hy * w] = 1;
	for (int x = 0; x < w; ++x)
	{
		a[x] = -1;
		a[x + (h - 1) * w] = -1;
	}
	for (int y = 0; y < h; y++)
	{
		a[0 + y * w] = -1;
		a[(w - 1) + y * w] = -1;
	}
	produce();
	r = true;
	while (r)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (d != 2)
					d = 0;
				break;
			case 'd':
				if (d != 3)
					d = 1;
				break;
			case 's':
				if (d != 4)
					d = 2;
				break;
			case 'a':
				if (d != 5)
					d = 3;
				break;
			}
		}
		switch (d)
		{
		case 0:
			move(-1, 0);
			break;
		case 1:
			move(0, 1);
			break;
		case 2:
			move(1, 0);
			break;
		case 3:
			move(0, -1);
			break;
		}
		for (int i = 0; i < len; i++)
			if (a[i] > 0)
				a[i]--;
		system("cls");
		for (int x = 0; x < w; ++x)
		{
			for (int y = 0; y < h; ++y)
				cout << getvalue(a[x + y * w]);

			cout << endl;
		}
		Sleep(150);
	}
	cout << "\n   Game over!\t\tscore= " << food;
	_getch();
}
//////////////////////////////////////////
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
//////////////////////////////////////////
void produce()
{
	int x = 0;
	int y = 0;
	do {
		x = rand() % (w - 2) + 1;
		y = rand() % (h - 2) + 1;
	} while (a[x + y * w] != 0);
	a[x + y * w] = -2;
}
//////////////////////////////////////////
char getvalue(int v)
{
	if (v > 0)
		return 'o';

	switch (v)
	{
	case -1:
		return char(177);
	case -2:
		return '*';
	}
}
//////////////////////////////////////////
void move(int dx, int dy)
{
	int x = hx + dx;
	int y = hy + dy;
	if (a[x + y * w] == -2)
	{
		food++;
		produce();
	}
	else if (a[x + y * w] != 0)
	{
		r = false;
	}
	hx = x;
	hy = y;
	a[hx + hy * w] = food + 1;
}