// Marble Game
// Mohsen AliMohammadi
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
using namespace std;
char Name[100];
int Score = 0, Undo = 0;
//------------------------------------------------------------------------------------------------------------//
struct Player
{
	char name[100];
	int score;
	int undo;
};
//------------------------------------------------------------------------------------------------------------//
void RemoveMarble(int a[][10], int x, int y, int x_change, int y_change, int &x_rmv, int &y_rmv);
void SaveFile(int a[][10], char name[], int score, int undo);
void DoingAndMoveCursor(int a[][10]);
void SavePlayer(Player b[], int n);
void LoadFile(int a[][10]);
int LoadPlayer(Player b[]);
void gotoxy(int x, int y);
void Marble(int a[][10]);
void Matris(int a[][10]);
int EndGame(int a[][10]);
void Color(int number);
int MokhtasatX(int x);
int MokhtasatY(int y);
void PlayGame();
void LoadGame();
void TableRow();
void Scores();
void About();
void Frame();
void Menu();
//------------------------------------------------------------------------------------------------------------//
int main()
{
	Menu();
	system("pause>0");
	return 0;
}
//------------------------------------------------------------------------------------------------------------//
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
//------------------------------------------------------------------------------------------------------------//
void Color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
//------------------------------------------------------------------------------------------------------------//
void TableRow() // ”«Œ  ÃœÊ· »«“Ì
{
	int x = 33, y = 25;
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			gotoxy(j, i);
			if (i == 0 && j == 0)
			{
				cerr << char(201);
			}
			else if (i == 0 && j == x - 1)
			{
				cerr << char(187);
			}
			else if (i == y - 1 && j == 0)
			{
				cerr << char(200);
			}
			else if (i == y - 1 && j == x - 1)
			{
				cerr << char(188);
			}
			else if (i == 0 && j != 0 && j != x - 1 && j % 4 == 0)
			{
				cerr << char(203);
			}
			else if (i == 0 && j != 0 && j != x - 1 && j % 4)
			{
				cerr << char(205);
			}
			else if (j == 0 && i != 0 && i != y - 1 && i % 3 == 0)
			{
				cerr << char(204);
			}
			else if (j == 0 && i != 0 && i != y - 1 && i % 3)
			{
				cerr << char(186);
			}
			else if (j == x - 1 && i != 0 && i != y - 1 && i % 3 == 0)
			{
				cerr << char(185);
			}
			else if (j == x - 1 && i != 0 && i != y - 1 && i % 3)
			{
				cerr << char(186);
			}
			else if (j % 4 == 0 && j != 0 && j != x - 1 && i != 0 && i != y - 1 && i % 3 == 0)
			{
				cerr << char(206);
			}
			else if (j % 4 && j != 0 && j != x - 1 && i != 0 && i != y - 1 && i % 3 == 0)
			{
				cerr << char(205);
			}
			else if (j % 4 && j != 0 && j != x - 1 && i == y - 1)
			{
				cerr << char(205);
			}
			else if (j % 4 == 0 && j != 0 && j != x - 1 && i == y - 1)
			{
				cerr << char(202);
			}
			else if (i % 3 && i != 0 && i != y - 1 && j % 4 == 0)
			{
				cerr << char(186);
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------//
void Matris(int a[][10]) // ”«Œ  „« —Ì” »«“Ì
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 1)
			{
				a[i][j] = 1;
			}
			else if (i % 2 == 1 && j % 2 == 0)
			{
				a[i][j] = 1;
			}
			else a[i][j] = 0;
		}
	}
}
//------------------------------------------------------------------------------------------------------------//
int MokhtasatX(int x) // x „Œ ’«  „ÕÊ—
{
	return 2 + 4 * x;
}
//------------------------------------------------------------------------------------------------------------//
int MokhtasatY(int y) // y „Œ ’«  „ÕÊ—
{
	return 1 + 3 * y;
}
//------------------------------------------------------------------------------------------------------------//
void Marble(int a[][10]) // ò‘Ìœ‰ „Â—Â Â« »Â Â„—«Â Œ«‰Â Â«Ì‘ œ— ’›ÕÂ
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			Color(0x75);
			if (i % 2 == 0 && j % 2 == 1)
			{
				gotoxy((4 * j) + 1, (3 * i) + 1);
				cerr << "   ";
				gotoxy((4 * j) + 1, (3 * i) + 2);
				cerr << "   ";
			}
			else if (i % 2 == 1 && j % 2 == 0)
			{
				gotoxy((4 * j) + 1, (3 * i) + 1);
				cerr << "   ";
				gotoxy((4 * j) + 1, (3 * i) + 2);
				cerr << "   ";
			}
			if (a[i][j] == 1)
			{
				gotoxy(MokhtasatX(j), MokhtasatY(i));
				cerr << char(4);
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------//
void RemoveMarble(int a[][10], int x, int y, int x_change, int y_change, int &x_rmv, int &y_rmv) // Õ–› ò—œ‰ „Ã«“ „Â—Â Â«
{
	x_rmv = -1, y_rmv = -1;
	if (abs(x - x_change) == 2 && abs(y - y_change) == 2)
	{
		if (x > x_change)
		{
			if (y > y_change)
			{
				if (a[y - 1][x - 1] == 1)
				{
					a[y_change][x_change] = 0;
					a[y][x] = 1;
					a[y - 1][x - 1] = 0;
					x_rmv = x - 1;
					y_rmv = y - 1;
					gotoxy(MokhtasatX(x), MokhtasatY(y));
					cerr << char(4);
					gotoxy(MokhtasatX(x_change), MokhtasatY(y_change));
					cerr << " ";
					gotoxy(MokhtasatX(x - 1), MokhtasatY(y - 1));
					cerr << " ";
				}
			}
			else if (y < y_change)
			{
				if (a[y + 1][x - 1] == 1)
				{
					a[y_change][x_change] = 0;
					a[y][x] = 1;
					a[y + 1][x - 1] = 0;
					x_rmv = x - 1;
					y_rmv = y + 1;
					gotoxy(MokhtasatX(x), MokhtasatY(y));
					cerr << char(4);
					gotoxy(MokhtasatX(x_change), MokhtasatY(y_change));
					cerr << " ";
					gotoxy(MokhtasatX(x - 1), MokhtasatY(y + 1));
					cerr << " ";
				}
			}
		}
		else if (x < x_change)
		{
			if (y > y_change)
			{
				if (a[y - 1][x + 1] == 1)
				{
					a[y_change][x_change] = 0;
					a[y][x] = 1;
					a[y - 1][x + 1] = 0;
					x_rmv = x + 1;
					y_rmv = y - 1;
					gotoxy(MokhtasatX(x), MokhtasatY(y));
					cerr << char(4);
					gotoxy(MokhtasatX(x_change), MokhtasatY(y_change));
					cerr << " ";
					gotoxy(MokhtasatX(x + 1), MokhtasatY(y - 1));
					cerr << " ";
				}
			}
			else if (y < y_change)
			{
				if (a[y + 1][x + 1] == 1)
				{
					a[y_change][x_change] = 0;
					a[y][x] = 1;
					a[y + 1][x + 1] = 0;
					x_rmv = x + 1;
					y_rmv = y + 1;
					gotoxy(MokhtasatX(x), MokhtasatY(y));
					cerr << char(4);
					gotoxy(MokhtasatX(x_change), MokhtasatY(y_change));
					cerr << " ";
					gotoxy(MokhtasatX(x + 1), MokhtasatY(y + 1));
					cerr << " ";
				}
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------//
int EndGame(int a[][10]) //  ‘ŒÌ’ Å«Ì«‰ »«“Ì
{
	int cnta = 0, cntb = 0;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (a[i][j] == 1)
			{
				if (a[i + 1][j + 1] == 1 && a[i + 2][j + 2] == 0)
				{
					cnta++;
				}
				else if (a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 0)
				{
					cnta++;
				}
				else if (a[i - 1][j - 1] == 1 && a[i - 2][j - 2] == 0)
				{
					cnta++;
				}
				else if (a[i - 1][j + 1] == 1 && a[i - 2][j + 2] == 0)
				{
					cnta++;
				}
				/*if (a[i + 1][j + 1] == 1 || a[i + 1][j - 1] == 1 || a[i - 1][j - 1] == 1 || a[i - 1][j + 1] == 1)
				{
				if (a[i + 2][j + 2] == 0 || a[i + 2][j - 2] == 0 || a[i - 2][j - 2] == 0 || a[i - 2][j + 2] == 0)
				{
				cnta++;
				}
				}*/
			}
			/*if (a[i][j] == 0)
			{
			if (a[i + 1][j + 1] == 1 || a[i + 1][j - 1] == 1 || a[i - 1][j - 1] == 1 || a[i - 1][j + 1] == 1)
			{
			if (a[i + 2][j + 2] == 1 || a[i + 2][j - 2] == 1 || a[i - 2][j - 2] == 1 || a[i - 2][j + 2] == 1)
			{
			cntb++;
			}
			}
			}*/
		}
	}
	if (cnta > 0 /*&& cntb > 0*/)
		return 1;
	return 0;
}
//------------------------------------------------------------------------------------------------------------//
void DoingAndMoveCursor(int a[][10]) // Œ·«’Â òÂ Â„Â ò«—«  Ê‘Â
{
	srand(time(NULL));
	char ch = _getch();

	int x = 0, y = 0, x_change, y_change, x_rmv, y_rmv;
	int cnt_score = 0, cnt_undo = 0;
	int sw_change = 0, sw = 0, sw_End = 1, i = 0;

	cnt_score += Score;
	cnt_undo += Undo;

	int CnZ[5];
	int CntrlZ[100][10];

	Color(0xF0);
	gotoxy(3, 27);
	cerr << "Name: ";
	gotoxy(9, 27);
	cerr << Name;

	while (true)
	{
		Color(0xF0);
		gotoxy(23, 27);
		cerr << "Score: ";
		gotoxy(30, 27);
		cerr << cnt_score;

		Color(0x75);
		gotoxy(MokhtasatX(x), MokhtasatY(y));

		ch = _getch();
		if (ch == 72)                                                  /////////////////////
		{
			y--;
			if (y < 0)
			{
				y = 7;
			}
			gotoxy(MokhtasatX(x), MokhtasatY(y));
		}
		else if (ch == 80)
		{
			y++;
			if (y > 7)
			{                                                  // ò·ÌœÂ«Ì ÃÂ  »—«Ì Ã«»Ã«ÌÌ „ò«‰ ‰„«
				y = 0;
			}
			gotoxy(MokhtasatX(x), MokhtasatY(y));
		}
		else if (ch == 77)
		{
			x++;
			if (x > 7)
			{
				x = 0;
			}
			gotoxy(MokhtasatX(x), MokhtasatY(y));
		}
		else if (ch == 75)                                             /////////////////////
		{
			x--;
			if (x < 0)
			{
				x = 7;
			}
			gotoxy(MokhtasatX(x), MokhtasatY(y));
		}
		else if ((ch == 'd' || ch == 'D') && sw == 0 && cnt_score == 0) // Õ–›  Ê”ÿ ò«—»—
		{
			if (a[y][x] == 1)
			{
				a[y][x] = 0;
				CnZ[0] = x;
				CnZ[1] = y;
				gotoxy(MokhtasatX(x), MokhtasatY(y));  //  ÊÃÂ ‘Êœ òÂ ò«—»— ›ﬁÿ Ìò»«— „Ì Ê«‰œ Õ–› ò‰œ*
				cerr << " ";
				sw = 1;
			}
		}
		else if ((ch == 'r' || ch == 'R') && sw == 0 && cnt_score == 0) // Õ–› »Â ’Ê—   ’«œ›Ì
		{
			int Rand_X = rand() % 8, Rand_Y = rand() % 8;
			if (a[Rand_Y][Rand_X] == 0)
			{
				if (Rand_X == 0)
				{                                     //  ÊÃÂ ‘Êœ òÂ ò«—»— ›ﬁÿ Ìò»«— „Ì Ê«‰œ Õ–› ò‰œ*
					Rand_X++;
				}
				else if (Rand_Y == 0)
				{
					Rand_Y++;
				}
				else if (Rand_Y == 7)
				{
					Rand_Y--;
				}
				else if (Rand_X == 7)
				{
					Rand_X--;
				}
				else
				{
					Rand_X++;
				}
			}
			if (a[Rand_Y][Rand_X] == 1)
			{
				a[Rand_Y][Rand_X] = 0;
				CnZ[0] = Rand_X;
				CnZ[1] = Rand_Y;
				gotoxy(MokhtasatX(Rand_X), MokhtasatY(Rand_Y));
				cerr << " ";
				sw = 1;
			}
		}
		else if (ch == 13) // Õ—ò  œ«œ‰ Â«ÌÌ òÂ „Ã«“ «” 
		{

			if (sw_change == 1 && a[y][x] == 0)
			{
				RemoveMarble(a, x, y, x_change, y_change, x_rmv, y_rmv);

				if (x_rmv != -1 && y_rmv != -1)
				{
					CntrlZ[i][0] = x_change;
					CntrlZ[i][1] = y_change;
					CntrlZ[i][2] = x;
					CntrlZ[i][3] = y;
					CntrlZ[i][4] = x_rmv;
					CntrlZ[i][5] = y_rmv;
					i++;
					cnt_score++;
				}
				sw_change = 0;
			}
			else if (sw_change == 0 && a[y][x] == 1)
			{
				x_change = x;
				y_change = y;
				sw_change = 1;
			}
		}
		else if (ch == 'u' || ch == 'U') // »—ê‘ ‰ »Â ⁄ﬁ»
		{
			if (cnt_score == 0 && sw == 1) //«Ì‰ »—«Ì »—ê‘ ‰ »Â ⁄ﬁ» «Ê·ÌÂ
			{
				a[CnZ[1]][CnZ[0]] = 1;
				gotoxy(MokhtasatX(CnZ[0]), MokhtasatY(CnZ[1]));
				cerr << char(4);
				sw = 0;
				cnt_undo++;
			}
			else if (cnt_score > 0) // «Ì‰ »—«Ì »—ê‘ ‰ »Â ⁄ﬁ» »Â Ã“ «Ê·ÌÂ
			{
				i--;
				a[CntrlZ[i][1]][CntrlZ[i][0]] = 1;
				a[CntrlZ[i][5]][CntrlZ[i][4]] = 1;
				a[CntrlZ[i][3]][CntrlZ[i][2]] = 0;
				gotoxy(MokhtasatX(CntrlZ[i][0]), MokhtasatY(CntrlZ[i][1]));
				cerr << char(4);
				gotoxy(MokhtasatX(CntrlZ[i][4]), MokhtasatY(CntrlZ[i][5]));
				cerr << char(4);
				gotoxy(MokhtasatX(CntrlZ[i][2]), MokhtasatY(CntrlZ[i][3]));
				cerr << " ";
				cnt_score--;
				cnt_undo++;
			}
		}
		else if (ch == 27) // Esc ”ÌÊ ‘œ‰ »«“Ì Ê »—ê‘  »Â „‰Ê
		{
			Color(0xF0);
			gotoxy(11, 29);
			cerr << "Save Game...";
			SaveFile(a, Name, cnt_score, cnt_undo);
			_getch();
			system("cls");
			Menu();
		}
		if (cnt_score > 5)
		{
			sw_End = EndGame(a); // «Ì‰Ã«”  òÂ »«“Ì »Â ¬Œ—‘ „Ì—”Â
			if (sw_End == 0)
			{
				int size;
				Player player[100];

				size = LoadPlayer(player); // «Ì‰Ã« »——”Ì „Ì‘Â òÂ ¬Ì« ﬁ»·«  Ê ›«Ì· çÌ“Ì »ÊœÂ Ì« ‰Â
				int i;
				for (i = 0; Name[i]; i++)
				{
					player[size].name[i] = Name[i];
				}
				player[size].name[i] = 0;
				player[size].score = cnt_score;
				player[size].undo = cnt_undo;

				SavePlayer(player, size + 1);  // «Ì‰Ã« „‘Œ’«  »«“Ìò‰ ”ÌÊ „Ì‘Â

				Color(0xF0);
				gotoxy(11, 29);
				cerr << "Finish Game...";
				_getch();
				system("cls");
				Menu();
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------//
void Frame() // ò«œ— Ì« ç«—çÊ»
{
	int n = 33;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			gotoxy(j, i);
			if (i == 0 && j == 0)
			{
				cerr << char(218);
			}
			else if (i == 0 && j == n - 1)
			{
				cerr << char(191);
			}
			else if (i == n - 1 && j == 0)
			{
				cerr << char(192);
			}
			else if (i == n - 1 && j == n - 1)
			{
				cerr << char(217);
			}
			else if (i == 0 || i == n - 1)
			{
				cerr << char(196);
			}
			else if (j == 0 || j == n - 1)
			{
				cerr << char(179);
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------//
void PlayGame() // »«“Ì «“ «Ê· ‘—Ê⁄ „Ì‘Â
{
	Score = 0, Undo = 0;
	int x = 4;
	Frame();
	gotoxy(x, 15);
	cerr << "Player Name: ";
	gotoxy(x, 17);
	cin >> Name;
	system("cls");
	int a[10][10];
	Matris(a);
	TableRow();
	Marble(a);
	DoingAndMoveCursor(a);
}
//------------------------------------------------------------------------------------------------------------//
void LoadGame() // »«“Ì «“ Ã«ÌÌ òÂ ”ÌÊ „Ì‘Â ‘—Ê⁄ „Ì‘Â
{
	int a[10][10];
	LoadFile(a);
	TableRow();
	Marble(a);
	DoingAndMoveCursor(a);
}
//------------------------------------------------------------------------------------------------------------//
void Scores() // «Ì‰Ã« »«“Ìò‰« Ì« «„ Ì«“«‘Ê‰ ‰„«Ì‘ œ«œÂ „Ì‘‰
{
	int x = 2, sw = 0;
	char back;
	Player player[100];
	int n;
	Frame();
	n = LoadPlayer(player); // »——”Ì „Ìò‰Â »«“Ìò‰Ì Â”  Ì« ‰Â

	for (size_t i = 0; i < n; i++) // Sorting
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (player[i].score < player[j].score)
			{
				swap(player[i], player[j]);
			}
			else if (player[i].score == player[j].score)
			{
				if (player[i].undo > player[j].undo)
				{
					swap(player[i], player[j]);
				}
			}
		}
	}

	if (n > 0)
	{                               // «ê— »«“Ìò‰ »Êœ  ⁄œ«œ‘Ê Å«” „ÌœÂ
		Color(0xF9);
		gotoxy(x, 1);
		cerr << "Rank Name\tScore\tUndo";
		if (n >= 5)
			n = 5;
		for (size_t i = 0; i < n; i++)
		{
			Color(0xF0);
			gotoxy(x, i + 3);
			cerr << i << ": " << player[i].name << "\t" << player[i].score << "\t" << player[i].undo;
		}
	}
	else
	{
		Color(0xF9);
		gotoxy(x, 3);
		cerr << "There Is No Player";
	}
	Color(0xF0);
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
//------------------------------------------------------------------------------------------------------------//
void About()
{
	int x = 2, sw = 0;
	char back;
	Frame();
	gotoxy(x, 10);
	Color(0xF9);
	cerr << "Marble Game   Ver 1.0.0";
	gotoxy(x, 15);
	Color(0xF0);
	cerr << "Programmer:";
	gotoxy(x, 17);
	Color(0xF0);
	cerr << "   M O H S E N . T E C H";
	gotoxy(x, 20);
	Color(0xF9);
	cerr << "ID: @mohsen_tech";
	Color(0xF0);
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
//------------------------------------------------------------------------------------------------------------//
void Menu() // „‰Ê
{
	Frame();
	char ch;
	int x = 11, y = 4;
	gotoxy(x - 1, y);
	cerr << "Marble Game";
	gotoxy(x + 2, y + 6);
	cerr << "Play";
	gotoxy(x + 2, y + 9);
	cerr << "Load";
	gotoxy(x + 2, y + 12);
	cerr << "Scores";
	gotoxy(x + 2, y + 15);
	cerr << "About";
	gotoxy(x + 2, y + 18);
	cerr << "Exit";
	y += 6;
	while (true)
	{
		gotoxy(x, y);
		cerr << char(272);
		ch = _getch();
		gotoxy(x, y);
		cerr << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 10)
			{
				y = 22;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 22)
			{
				y = 10;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 10) // Play Game
			{
				system("cls");
				PlayGame();
			}
			else if (y == 13) // Load Game
			{
				system("cls");
				LoadGame();
			}
			else if (y == 16) // Scores
			{
				system("cls");
				Scores();
			}
			else if (y == 19) // About
			{
				system("cls");
				About();
			}
			else if (y == 22) // Exit
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
//------------------------------------------------------------------------------------------------------------//
void SaveFile(int a[][10], char name[], int score, int undo) // ”ÌÊ „Ìò‰Â „« —Ì” »«“ÌÊ »« „‘Œ’«  »«“Ìò‰
{
	fstream Output_file("Load.txt", ios::out);
	if (Output_file.fail())
	{
		system("cls");
		cerr << "Error";
		_getch();
		system("cls");
		Menu();
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8;j++)
		{
			Output_file << a[i][j] << " ";
		}
		Output_file << "\n";
	}
	Output_file << name << " " << score << " " << undo;
}
//------------------------------------------------------------------------------------------------------------//
void LoadFile(int a[][10]) // ·Êœ „Ìò‰Â »«·«ÌÌÊ
{
	char name[100];
	int score, undo;
	fstream Input_file("Load.txt", ios::in);
	if (Input_file.fail())
	{
		system("cls");
		cerr << "Error";
		_getch();
		system("cls");
		Menu();
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8;j++)
		{
			Input_file >> a[i][j];
			a[i][j] = a[i][j];
		}
	}
	Input_file >> name >> score >> undo;
	int i;
	for (i = 0; name[i]; i++)
	{
		Name[i] = name[i];
	}
	Name[i] = 0;
	Score = score;
	Undo = undo;
}
//------------------------------------------------------------------------------------------------------------//
void SavePlayer(Player a[], int n) // ”ÌÊ „Ìò‰Â „‘Œ’«  »«“Ìò‰ Â«—Ê
{
	fstream Output("Player.txt", ios::out);
	if (Output.fail())
	{
		cerr << "Error";
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		Output << i << "\t" << a[i].name << "\t" << a[i].score << "\t" << a[i].undo << "\n";
	}
}
//------------------------------------------------------------------------------------------------------------//
int LoadPlayer(Player a[]) // ·Êœ „Ìò‰Â »«·«ÌÌ—Ê
{
	fstream Input("Player.txt", ios::in);
	if (Input.fail())
	{
		return 0;
	}
	int sw = 1, j, n = 0;
	for (int i = 0; sw; i++)
	{
		Input >> j >> a[i].name >> a[i].score >> a[i].undo;
		if (j != i)
		{
			sw = 0;
		}
		n = i;
	}
	return n;
}
//------------------------------------------------------------------------------------------------------------//