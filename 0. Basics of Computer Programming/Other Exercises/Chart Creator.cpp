#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cmath>
#include <string>
using namespace std;
const int n = 60;
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
void Bordar()
{
	for (size_t i = 1; i < n; i++)
	{
		gotoxy(n, i);
		if (i == 1)
			cout << char(30);
		else
			cout << char(179);
	}
	for (size_t i = 1; i < 2 * n; i++)
	{
		gotoxy(i, n / 2);
		if (i == n)
			cout << char(197);
		else if (i == 2 * n - 1)
			cout << char(16);
		else
			cout << char(196);
	}
}
int getX(int x)
{
	return x + n;
}
int getY(int y)
{
	return y + n / 2;
}
int fSin(int n)
{
	switch (n)
	{
	case 0:
		return 0;
		break;
	case 90:
		return 1;
		break;
	case 180:
		return 0;
		break;
	case 270:
		return -1;
		break;
	case 360:
		return 0;
		break;
	default:
		return fSin(n - 360);
		break;
	}
}
int fCos(int n)
{
	switch (n)
	{
	case 0:
		return 1;
		break;
	case 90:
		return 0;
		break;
	case 180:
		return -1;
		break;
	case 270:
		return 0;
		break;
	case 360:
		return 1;
		break;
	default:
		return fCos(n - 360);
		break;
	}
}
int fTan(int n)
{
	return fSin(n) / fCos(n);
}
int fCot(int n)
{
	return fCos(n) / fSin(n);
}
int fLog(int n)
{
	if (n == 1 || n == 2)
		return 0;
	else if (3 <= n && n <= 10)
		return 1;
	else if (11 <= n && n <= 30)
		return 2;
	else if (31 <= n && n <= 60)
		return 3;
	else if (61 <= n && n <= 120)
		return 4;
	else if (121 <= n && n <= 1200)
		return 5;
}
void fOne()
{
	int A, B, C, D;
	cout << "f(x) = Ax^3 + Bx^2 + Cx + D\n";
	cout << "A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;
	cout << "D: ";
	cin >> D;
	system("cls");
	Bordar();
	for (int i = -5; i <= 5; i++)
	{
		int x = i;
		int y = (A * pow(x, 3)) + (B * pow(x, 2)) + (C * x) + D;
		x = getX(x);
		y = getY(y);
		if (y >= n / 2)
		{
			int temp = y - n / 2;
			y = n / 2 - temp;
		}
		else if (y < n / 2)
		{
			int temp = y - n / 2;
			y = n / 2 - temp;
		}
		gotoxy(x, y);
		cout << char(46);
	}
}
void fTwo()
{
	int A, B, C, D;
	cout << "f(x) = A + B * sqrt(C * x^D)\n";
	cout << "A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;
	cout << "D: ";
	cin >> D;
	system("cls");
	Bordar();
	for (size_t i = 0; i <= 8; i++)
	{
		int x = i * i;
		int	y = A + B * sqrt(C * pow(x, D));
		x = getX(x), y = getY(y);
		if (y >= n / 2)
		{
			int temp = y - n / 2;
			y = n / 2 - temp;
		}
		else if (y < n / 2)
		{
			int temp = y - n / 2;
			y = n / 2 - temp;
		}
		gotoxy(x, y);
		cout << char(46);
	}
}
void fThree()
{
	int A, B, C, D;
	cout << "f(x) = A + B * log(C * x^D)\n";
	cout << "A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;
	cout << "D: ";
	cin >> D;
	system("cls");
	Bordar();
	int x = 1;
	int	y = A + B * fLog(C * pow(x, D));
	x = getX(x), y = getY(y);
	if (y >= n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	else if (y < n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	gotoxy(x, y);
	cout << char(46);

	x = 10;
	y = A + B * fLog(C * pow(x, D));
	x = getX(x), y = getY(y);
	if (y >= n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	else if (y < n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	gotoxy(x, y);
	cout << char(46);

	x = 30;
	y = A + B * fLog(C * pow(x, D));
	x = getX(x), y = getY(y);
	if (y >= n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	else if (y < n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	gotoxy(x, y);
	cout << char(46);

	x = 60;
	y = A + B * fLog(C * pow(x, D));
	x = getX(x), y = getY(y);
	if (y >= n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	else if (y < n / 2)
	{
		int temp = y - n / 2;
		y = n / 2 - temp;
	}
	gotoxy(x, y);
	cout << char(46);
}
void fFour()
{
	string str;
	cout << "1.sin , 2.cos , 3.tan , 4.cot ?\nChoose One: ";
	cin >> str;
	int A, B, C, D;
	cout << "f(x) = A + B * " << str << "(C * x^D)\n";
	cout << "A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	cout << "C: ";
	cin >> C;
	cout << "D: ";
	cin >> D;
	system("cls");
	Bordar();
	int j = 0;
	if (str == "sin" || str == "cos")
	{
		for (size_t i = 0; i <= 720; i += 90)
		{
			int x = i - (90 * j) + j++;
			int	y;
			if (str == "sin")
			{
				y = A + B * (fSin(C * pow(i, D)));
			}
			else if (str == "cos")
			{
				y = A + B * (fCos(C * pow(i, D)));
			}
			x = getX(x), y = getY(y);
			if (y >= n / 2)
			{
				int temp = y - n / 2;
				y = n / 2 - temp;
			}
			else if (y < n / 2)
			{
				int temp = y - n / 2;
				y = n / 2 - temp;
			}
			gotoxy(x, y);
			cout << char(46);
		}
	}
	else if (str == "tan" || str == "cot")
	{


	}
	else
		exit(0);
}
void Menu()
{
	int choose;
	while (!false)
	{
		cout << "Rasme Nemodare?\n";
		cout << "1. f(x)=Ax^3+Bx^2+Cx+D\n";
		cout << "2. f(x)=A+B*sqrt(C*x^D)\n";
		cout << "3. f(x)=A+B*log(C*x^D)\n";
		cout << "4. f(x)=A+B*sin(C*x^D)\n";
		cout << "Choose One: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			system("cls");
			fOne();
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			fTwo();
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			fThree();
			_getch();
			system("cls");
			break;
		case 4:
			system("cls");
			fFour();
			_getch();
			system("cls");
			break;
		default:
			exit(0);
			break;
		}
	}
}
int main()
{
	Menu();
	system("pause>0");
	return 0;
}