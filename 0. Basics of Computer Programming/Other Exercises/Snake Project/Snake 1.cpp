#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;
//---------------------------------------------------------------------------------------
void gotoxy(int x, int y);
void Color(int number);
void FruitSpawn();
void Setup();
void Input();
void Logic();
void Frame();
void About();
void Play();
void Menu();
void Draw();
//---------------------------------------------------------------------------------------
bool gameover;
bool shutDown;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[400], tailY[400], nTail;
enum eDirection { STOP, LEFT, RIGHT, UP, DOWN };
eDirection dir;
//---------------------------------------------------------------------------------------
int main()
{
	Menu();
	return 0;
}
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
void Color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
//---------------------------------------------------------------------------------------
void FruitSpawn()
{
	fruitX = rand() % width;
	fruitY = rand() % height;
}
//---------------------------------------------------------------------------------------
void Setup()
{
	gameover = false;
	shutDown = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	FruitSpawn();
	score = 0;
	nTail = 0;
}
//---------------------------------------------------------------------------------------
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << char(219);
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << char(219);
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "*";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "+";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << char(219);
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << char(219);
	}
	cout << "\n\nScore: " << score << endl;
}
//---------------------------------------------------------------------------------------
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}
//---------------------------------------------------------------------------------------
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
	{
		gameover = true;
	}
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score++;
		nTail++;
		FruitSpawn();
	}
}
//---------------------------------------------------------------------------------------
void Play()
{
	Setup();
	while (!gameover)
	{
		Draw();
		Input();
		Logic();
		Sleep(170);
	}
	gotoxy(width - 13, height + 3);
	cout << "Game Over!";
	_getch();
}
//---------------------------------------------------------------------------------------
void Frame()
{
	int n = height, m = width;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			gotoxy(j, i);
			if (i == 0 && j == 0)
			{
				cerr << char(218);
			}
			else if (i == 0 && j == m - 1)
			{
				cerr << char(191);
			}
			else if (i == n - 1 && j == 0)
			{
				cerr << char(192);
			}
			else if (i == n - 1 && j == m - 1)
			{
				cerr << char(217);
			}
			else if (i == 0 || i == n - 1)
			{
				cerr << char(196);
			}
			else if (j == 0 || j == m - 1)
			{
				cerr << char(179);
			}
		}
	}
}
//---------------------------------------------------------------------------------------
void About()
{
	int x = 2, sw = 0;
	char back;
	Frame();
	gotoxy(x, 5);
	Color(0xF9);
	cerr << "Snake | Ver 1.0.0";
	gotoxy(x, 10);
	Color(0xF0);
	cerr << "Programmer:";
	gotoxy(x, 12);
	Color(0xF0);
	cerr << "Sajjad Seddighi";
	while (sw == 0)
	{
		back = _getch();
		if (back == 27)
		{
			sw = 1;
			system("cls");
			Menu();
		}
	}
}
//---------------------------------------------------------------------------------------
void Menu()
{
	Frame();
	char ch;
	int x = 7, y = 4;
	gotoxy(x + 2, y - 1);
	cerr << "Welcome to Snake Game!";
	gotoxy(x + 3, y + 4);
	cerr << "1. Play";
	gotoxy(x + 3, y + 7);
	cerr << "2. About";
	gotoxy(x + 3, y + 10);
	cerr << "3. Exit";
	y += 4;
	while (true)
	{
		gotoxy(x + 1, y);
		cerr << char(272);
		ch = _getch();
		gotoxy(x + 1, y);
		cerr << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 14;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 14)
			{
				y = 8;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 8)
			{
				system("cls");
				Play();
				system("cls");
				Menu();
			}
			else if (y == 11)
			{
				system("cls");
				About();
				system("cls");
				Menu();
			}
			else if (y == 14)
			{
				system("cls");
				exit(0);
			}
		}
		else if (ch == 27)
		{
			system("cls");
			exit(0);
		}
	}
}