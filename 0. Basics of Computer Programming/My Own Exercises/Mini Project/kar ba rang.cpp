#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;
void setTextColor(int textColor, int backColor = 0)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
void main() {
	int a;
	char state[100];
	cout << "please enter a statement:" << endl;
	cout << "please enter a number between 0 and 15:" << endl;
	cin >> a;
	setTextColor(a, 0);
	puts(state);
}