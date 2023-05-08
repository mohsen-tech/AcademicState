#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE j = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x0c);
	Sleep(400);
	cout << "Red" << endl;
	Sleep(400);
	system("color 0f");
	SetConsoleTextAttribute(h, 0x0e);
	Sleep(200);
	cout << "Yellow" << endl;
	SetConsoleTextAttribute(h, 0x1f);
	Sleep(200);
	cout << "White Over Blue" << endl;
	SetConsoleTextAttribute(h, 0x2e);
	Sleep(200);
	cout << "Yellow Over Green" << endl;
	Sleep(200);
	cout << "Sleep for 2 seconds..." << endl;
	cout << "Continue..." << endl;
	return 0;
}