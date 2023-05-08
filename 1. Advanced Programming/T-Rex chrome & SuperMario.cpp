#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <time.h>
#include <thread>
#include <vector>
using namespace std;
//-----------------------------------------------------------------------------------------
class Player
{
public:
	int score, ptime;
	string name, id;
};
vector <Player> players;
//-----------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------
void color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
//-----------------------------------------------------------------------------------------
void frame()
{
	color(0xF9);
	int n = 30, m = 80;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			gotoxy(j, i);
			if (i == 0 && j == 0)
			{
				cout << char(218);
			}
			else if (i == 0 && j == m - 1)
			{
				cout << char(191);
			}
			else if (i == n - 1 && j == 0)
			{
				cout << char(192);
			}
			else if (i == n - 1 && j == m - 1)
			{
				cout << char(217);
			}
			else if (i == 0 || i == n - 1)
			{
				cout << char(196);
			}
			else if (j == 0 || j == m - 1)
			{
				cout << char(179);
			}
		}
	}
	color(0xF0);
}
//-----------------------------------------------------------------------------------------
Player Run()
{
	Player temp;
	cout << "Name: ";
	cin >> temp.name;
	cout << "ID: ";
	cin >> temp.id;
	_getch();
	system("cls");
	frame();
	srand(time(NULL));
	int x = 15, y = 19, length = 0, xCoin, yCoin, xBomb, yBomb, randomNumber, score = 0, ptime = 0;
	bool jump = false, turn = false, swCoin = false, swBomb = false;
	while (true)
	{
		while (!_kbhit())
		{
			ptime++;
			gotoxy(3, 2);
			cout << "Score: ";
			gotoxy(10, 2);
			cout << score;
			gotoxy(20, 2);
			cout << "Time: ";
			gotoxy(26, 2);
			cout << ptime;
			randomNumber = rand() % 20;
			if (swCoin == false && randomNumber == 3)
			{
				swCoin = true;
				xCoin = 77, yCoin = 17;
			}
			else if (swBomb == false && randomNumber == 5)
			{
				swBomb = true;
				xBomb = 76, yBomb = 19;
			}
			if (swBomb == true && (y == yBomb || y - 1 == yBomb) && (x == xBomb))
			{
				swBomb = false;
				gotoxy(40, 15);
				cout << "Game Over!";
				temp.score = score;
				temp.ptime = ptime;
				return temp;
			}
			else if (swBomb == true && xBomb == 2)
			{
				score += 5;
				swBomb = false;
				gotoxy(xBomb, yBomb);
				cout << "   ";
			}
			if (swCoin == true && (y == yCoin || y - 1 == yCoin || y + 1 == yCoin) && (x == xCoin || x + 1 == xCoin || x - 1 == xCoin))
			{
				score += 10;
				swCoin = false;
				gotoxy(xCoin, yCoin);
				cout << " ";
			}
			else if (swCoin == true && xCoin == 2)
			{
				swCoin = false;
				gotoxy(xCoin, yCoin);
				cout << " ";
			}
			for (int i = 1; i < 80 - 1; i++)
			{
				gotoxy(i, 20);
				if (y == 19)
					if (i != 16 && i != 15)
						cout << char(196);
			}
			gotoxy(1, 21);
			cout << "  -  _  .  -  .  _  -  ~  -  _  .  -  .  _  -  ~  -  _  .  -  .  _  -  ~  .  ";
			if (swCoin == true)
			{
				gotoxy(xCoin, yCoin);
				cout << "C";
			}
			if (swBomb == true)
			{
				gotoxy(xBomb, yBomb);
				cout << "<O>";
			}
			Sleep(100);
			if (swCoin == true)
			{
				xCoin--;
				gotoxy(xCoin + 1, yCoin);
				cout << " ";
				gotoxy(xCoin, yCoin);
				cout << "C";
			}
			if (swBomb == true)
			{
				xBomb--;
				gotoxy(xBomb + 1, yBomb);
				cout << "   ";
				gotoxy(xBomb, yBomb);
				cout << "<O>";
			}
			gotoxy(1, 21);
			cout << "-  _  .  -  .  _  -  ~  -  _  .  -  .  _  -  ~  -  _  .  -  .  _  -  ~  .  - ";
			Sleep(100);
			if (turn == false && jump == true)
			{
				Sleep(25);
				gotoxy(x, y);
				cout << "  ";
				gotoxy(x, y + 1);
				cout << "  ";
				y -= 3;
				if (y < 10)
				{
					y = 10; turn = true;
				}
			}
			if (turn == true && jump == true)
			{
				Sleep(25);
				gotoxy(x, y);
				cout << "  ";
				gotoxy(x, y + 1);
				cout << "  ";
				y += 3;
				if (y > 19)
				{
					y = 19; jump = false; turn = false;
				}
			}
			gotoxy(x, y);
			cout << char(219) << char(219);
			gotoxy(x, y + 1);
			cout << char(219) << char(219);
		}
		char ch;
		ch = _getch();
		gotoxy(x, y);
		cout << "  ";
		gotoxy(x, y + 1);
		cout << "  ";
		if (jump == false && ch == ' ') jump = true;
		else if (ch == 27)
		{
			temp.score = score;
			temp.ptime = ptime;
			return temp;
		}
		//if (ch == 72)
		//{
		//	y -= 3;
		//	if (y < 13)
		//		y = 13;
		//	//upFlag = true;
		//	gotoxy(x + 2, y);
		//}
		///*else if (ch == 75)
		//{
		//	x--;
		//	length--;
		//	gotoxy(x + 2, y);
		//}
		//else if (ch == 77)
		//{
		//	length++;
		//	x++;
		//	gotoxy(x + 2, y);
		//}*/
		//else if (ch == 80)
		//{
		//	y += 3;
		//	if (y > 19)
		//		y = 19;
		//	gotoxy(x + 2, y);
		//}
	}
}
//-----------------------------------------------------------------------------------------
void ranking()
{
	cout << "ID\tName\tScore\tTime\n";
	for (int i = 0; i < players.size(); i++)
		cout << players[i].id << " " << players[i].name << " " << players[i].score << " " << players[i].ptime << "\n";
}
//-----------------------------------------------------------------------------------------
void Menu()
{
	color(0xF0);
	while (true)
	{
		int n;
		cout << "1. Play\n";
		cout << "2. Ranking\n";
		cout << "3. About\n";
		cout << "4. Exit\n";
		cout << "[1-4]? ";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			players.push_back(Run());
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			ranking();
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			//

			//
			_getch();
			system("cls");
			break;
		case 4:
			return;
			break;
		default:
			system("cls");
			break;
		}
	}
}
//-----------------------------------------------------------------------------------------
int main()
{
	system("cls");
	color(0xF9);

	Menu();

	system("pause>0");
	return 0;
}