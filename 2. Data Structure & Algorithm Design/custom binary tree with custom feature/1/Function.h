#include <iostream>
#include <conio.h>
using namespace std;
bool file_flag;
bool a()
{
	char ch;
	cout << "vaqean edit shavad? (Y / n) ";
	cin >> ch;
	if (ch == 'Y')
		return true;
	return false;
}
void z()
{
	cout << endl << "enter something to continue . . .\n";
	_getch();
	system("cls");
}
