#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int n;
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cin >> n;
	for (int i = 1, j = 2; i <= n, j <= n + 1; i++, j++)
	{
		pos.X = i;
		pos.Y = j;
		SetConsoleCursorPosition(hConsole, pos);
		cout << "*";
	}
	for (int i = n, j = n + 2; i >= 1, j <= 2 * n + 1; i--, j++)
	{
		pos.X = i;
		pos.Y = j;
		SetConsoleCursorPosition(hConsole, pos);
		cout << "*";
	}
	for (int i = 1; i <= 2 * (n + 1); i++)
	{
		pos.X = 0;
		pos.Y = i;
		SetConsoleCursorPosition(hConsole, pos);
		cout << "*\n";
	}
	return 0;
}