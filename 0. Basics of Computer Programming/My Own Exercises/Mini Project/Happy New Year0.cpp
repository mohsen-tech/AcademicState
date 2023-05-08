#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string a = "*";
	cout << "\n\n";
	for (int i = 0; i < 5; i++)
	{
		SetConsoleTextAttribute(h, 0x75);
		cout << "  ";
		for (int j = 0; j < 5; j++)   // H
		{
			if (i == 2 || j == 4 || j == 0)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 5; j < 7; j++)
		{
			cout << " ";
		}
		for (int j = 7; j < 12; j++)  // A
		{
			if (i == 0 || i == 2 || j == 7 || j == 11)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 12; j < 14; j++)
		{
			cout << " ";
		}
		for (int j = 14; j < 19; j++)    // P
		{
			if (i == 0 || i == 2 || j == 14 || j == 18 && i <= 2)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 19; j < 21; j++)
		{
			cout << " ";
		}
		for (int j = 21; j < 26; j++)    // P
		{
			if (i == 0 || i == 2 || j == 21 || j == 25 && i <= 2)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 26; j < 28; j++)
		{
			cout << " ";
		}
		for (int j = 28; j < 33; j++)  // Y
		{
			if (j == 28 && i <= 2 || i == 2 || j == 32 && i <= 2 || j == 30 && i >= 3)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}for (int j = 33; j < 35; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
	for (int k = 0; k < 37; k++)
	{
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "  ";
		for (int j = 0; j < 5; j++)  // N
		{
			if (i == j || j == 4 || j == 0)
			{
				SetConsoleTextAttribute(h, 0x72);
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 5; j < 7; j++)
		{
			cout << " ";
		}
		for (int j = 7; j < 12; j++)  // E
		{
			if (i == 0 || i == 4 || j == 7 || i == 2)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 12; j < 14; j++)
		{
			cout << " ";
		}
		for (int j = 14; j < 19; j++)    // W
		{
			if (j == 14 || j == 18 || j == i && j >= 16 || j == 18 - i && j <= 16 || j == 17 && i == 3)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 19; j < 35; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
	for (int k = 0; k < 37; k++)
	{
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "  ";
		for (int j = 0; j < 5; j++)   // Y
		{
			if (j == 0 && i <= 2 || i == 2 || j == 4 && i <= 2 || j == 2 && i >= 3)
			{
				SetConsoleTextAttribute(h, 0x71);
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 5; j < 7; j++)
		{
			cout << " ";
		}
		for (int j = 7; j < 12; j++)  // E
		{
			if (i == 0 || i == 4 || j == 7 || i == 2)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 12; j < 14; j++)
		{
			cout << " ";
		}
		for (int j = 14; j < 19; j++)    // A
		{
			if (i == 0 || i == 2 || j == 14 || j == 18)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 19; j < 21; j++)
		{
			cout << " ";
		}
		for (int j = 21; j < 26; j++)    // R
		{
			if (i == 0 || i == 2 || j == 21 || j == 25 && i <= 2 || i + 21 == j && i >= 2)
			{
				cout << a;
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 26; j < 35; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(h, 0xf0);
	system("pause>A");
}