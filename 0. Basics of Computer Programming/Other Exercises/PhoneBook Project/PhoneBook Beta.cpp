#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;
struct PersonParts
{
	char FirstName[20];
	char LastName[20];
	long long int PhoneNumber;
	char Address[40];
	char Email[30];
	char Note[50];
};
void Menu();
void About();
void Frame();
void Color(int number);
void gotoxy(int x, int y);
PersonParts ScanPersonParts();
int getSize(PersonParts parts[]);
void AddPerson(PersonParts parts[]);
void EditPerson(PersonParts parts[]);
void DeletePerson(PersonParts parts[]);
void SearchPerson(PersonParts parts[]);
int LoadPersonParts(PersonParts parts[]);
void SavePersonParts(PersonParts parts[]);
void PrintPersonParts(PersonParts parts[], int index);
bool Yekta(PersonParts parts[], long long int PhoneNumber, char Email[]);
int getIndex(PersonParts parts[], long long int PhoneNumber, char Email[]);
PersonParts MyParts[100];
/*****************************************************************************************/
void Menu()
{
	Frame();
	char ch;
	int x = 7, y = 4, choose, size;;
	gotoxy(x + 8, y - 1);
	cerr << "PhoneBook";
	gotoxy(x + 2, y + 4);
	cout << "1.Add";
	gotoxy(x + 2, y + 7);
	cout << "2.Edit";
	gotoxy(x + 2, y + 10);
	cout << "3.Delete";
	gotoxy(x + 2, y + 13);
	cout << "4.Show List\n";
	gotoxy(x + 2, y + 16);
	cout << "5.Search\n";
	gotoxy(x + 2, y + 19);
	cout << "6.Save To File\n";
	gotoxy(x + 2, y + 22);
	cout << "7.About";
	gotoxy(x + 2, y + 25);
	cout << "8.Exit\n";
	y += 4;
	while (true)
	{
		gotoxy(x, y);
		cout << char(272);
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 29;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 29)
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
				Frame();
				AddPerson(MyParts);
				_getch();
				system("cls");
				Menu();
			}
			else if (y == 11)
			{
				system("cls");
				Frame();
				EditPerson(MyParts);
				_getch();
				system("cls");
				Menu();
			}
			else if (y == 14)
			{
				system("cls");
				Frame();
				DeletePerson(MyParts);
				_getch();
				system("cls");
				Menu();
			}
			else if (y == 17)
			{
				system("cls");
				size = getSize(MyParts);
				for (size_t i = 0; i < size; i++)
				{
					cout << i + 1 << ":\n";
					PrintPersonParts(MyParts, i);
					cout << "\n";
				}
				_getch();
				system("cls");
				Menu();
			}
			else if (y == 20)
			{
				system("cls");
				Frame();
				SearchPerson(MyParts);
				_getch();
				system("cls");
				Menu();
			}
			else if (y == 23)
			{
				system("cls");
				SavePersonParts(MyParts);
				cout << "Done!\n";
				_getch();
				system("cls");
				Menu();
			}
			else if (y == 26)
			{
				system("cls");
				About();
			}
			else if (y == 29)
			{
				//SavePersonParts(MyParts);
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
/*****************************************************************************************/
int main()
{
	LoadPersonParts(MyParts);
	Menu();

	system("pause>0");
	return 0;
}
/*****************************************************************************************/
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
/*****************************************************************************************/
void Color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
/*****************************************************************************************/
void About()
{
	int x = 2, sw = 0;
	char back;
	Frame();
	gotoxy(x, 10);
	Color(0xF9);
	cout << "PhoneBook | Ver 1.0.0";
	gotoxy(x, 15);
	Color(0xF0);
	cout << "Programmers:";
	gotoxy(x, 17);
	Color(0xF0);
	cout << "None1";
	gotoxy(x, 19);
	Color(0xF0);
	cout << "None2";
	/*gotoxy(x, 21);
	Color(0xF0);
	cout << "None3";*/
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
/*****************************************************************************************/
void Frame()
{
	Color(0xF9);
	int n = 40, m = 40;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
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
	Color(0xF0);
}
/*****************************************************************************************/
PersonParts ScanPersonParts()
{
	int x = 7, y = 4;
	PersonParts temp;
	gotoxy(x, y + 13);
	cout << "First Name: ";
	cin >> temp.FirstName;
	gotoxy(x, y + 16);
	cout << "Last Name: ";
	cin >> temp.LastName;
	gotoxy(x, y + 19);
	cout << "Phone Number: ";
	cin >> temp.PhoneNumber;
	gotoxy(x, y + 22);
	cout << "Address: ";
	cin >> temp.Address;
	gotoxy(x, y + 25);
	cout << "Email: ";
	cin >> temp.Email;
	gotoxy(x, y + 28);
	cout << "Note: ";
	cin >> temp.Note;
	return temp;
}
/*****************************************************************************************/
void PrintPersonParts(PersonParts parts[], int index)
{
	cout << "First Name: " << parts[index].FirstName << "\n";
	cout << "Last Name: " << parts[index].LastName << "\n";
	cout << "Phone Number: " << parts[index].PhoneNumber << "\n";
	cout << "Address: " << parts[index].Address << "\n";
	cout << "Email: " << parts[index].Email << "\n";
	cout << "Note: " << parts[index].Note << "\n";
}
/*****************************************************************************************/
int getSize(PersonParts parts[])
{
	int size, sw = 1;
	for (size_t i = 0; sw; i++)
		if (!parts[i].PhoneNumber)
		{
			sw = 0;
			size = i;
		}
	return size;
}
/*****************************************************************************************/
int getIndex(PersonParts parts[], long long int PhoneNumber, char Email[])
{
	int length = getSize(parts);
	for (size_t i = 0; i < length; i++)
		if (PhoneNumber == parts[i].PhoneNumber && strcmp(Email, parts[i].Email) == 0)
			return i;
	return -1;
}
/*****************************************************************************************/
bool Yekta(PersonParts parts[], long long int PhoneNumber, char Email[])
{
	int length = getSize(parts);
	for (size_t i = 0; i < length; i++)
		if (PhoneNumber == parts[i].PhoneNumber || strcmp(Email, parts[i].Email) == 0)
			return false;
	return true;
}
/*****************************************************************************************/
void AddPerson(PersonParts parts[])
{
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cout << "- Add -";
	PersonParts temp;
	temp = ScanPersonParts();
	if (Yekta(parts, temp.PhoneNumber, temp.Email) == true)
	{
		int index = getSize(parts);
		parts[index] = temp;
	}
	else
	{
		gotoxy(x, y + 22);
		cout << "PhoneNumber or Email Found! Cant Add!\n";
	}
}
/*****************************************************************************************/
void SearchPerson(PersonParts parts[])
{
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cout << "- Search -";
	char FirstName[20];
	char LastName[20];
	gotoxy(x, y + 4);
	cout << "Enter First Name: ";
	cin >> FirstName;
	gotoxy(x, y + 7);
	cout << "Enter Last Name: ";
	cin >> LastName;
	int length = getSize(parts), index = -1;
	for (size_t i = 0; i < length; i++)
		if (strcmp(FirstName, parts[i].FirstName) == 0 && strcmp(LastName, parts[i].LastName) == 0)
			index = i;
	if (index != -1)
	{
		gotoxy(x, y + 10);
		cout << "Found!\n";
		gotoxy(x, y + 13);
		cout << "First Name: " << parts[index].FirstName;
		gotoxy(x, y + 16);
		cout << "Last Name: " << parts[index].LastName;
		gotoxy(x, y + 19);
		cout << "Phone Number: " << parts[index].PhoneNumber;
		gotoxy(x, y + 22);
		cout << "Address: " << parts[index].Address;
		gotoxy(x, y + 25);
		cout << "Email: " << parts[index].Email;
		gotoxy(x, y + 28);
		cout << "Note: " << parts[index].Note;
	}
	else
	{
		gotoxy(x, y + 13);
		cout << "Not Found!\n";
	}
}
/*****************************************************************************************/
void DeletePerson(PersonParts parts[])
{
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cout << "- Delete -\n";
	long long int PhoneNumber;
	char Email[30];
	gotoxy(x, y + 4);
	cout << "Enter Phone Number: ";
	cin >> PhoneNumber;
	gotoxy(x, y + 7);
	cout << "Enter Email: ";
	cin >> Email;
	int index = getIndex(parts, PhoneNumber, Email), size = getSize(parts);
	if (index != -1)
	{
		gotoxy(x, y + 13);
		cout << "Found and Delete!\n";
		for (size_t i = index; i < size; i++)
			parts[i] = parts[i + 1];
	}
	else
	{
		gotoxy(x, y + 16);
		cout << "Not Found and Cant Delete!\n";
	}
}
/*****************************************************************************************/
void EditPerson(PersonParts parts[])
{
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cout << "- Edit -\n";
	long long int PhoneNumber;
	char Email[30];
	gotoxy(x, y + 4);
	cout << "Enter Phone Number: ";
	cin >> PhoneNumber;
	gotoxy(x, y + 7);
	cout << "Enter Email: ";
	cin >> Email;
	int index = getIndex(parts, PhoneNumber, Email);
	if (index != -1)
	{
		gotoxy(x, y + 10);
		cout << "Found and Edit!\n";
		parts[index] = ScanPersonParts();
		gotoxy(x, y + 31);
		cout << "Update!\n";
	}
	else
	{
		gotoxy(x, y + 28);
		cout << "Not Found and Cant Edit!\n";
	}
}
/*****************************************************************************************/
void SavePersonParts(PersonParts parts[])
{
	fstream Output("File.txt", ios::out);
	if (Output.fail())
	{
		cerr << "Error!\n";
		_getch();
		exit(0);
	}
	int size = getSize(parts);
	for (size_t i = 0; i < size; i++)
	{
		Output << i << " " << parts[i].FirstName << " " << parts[i].LastName
			<< " " << parts[i].PhoneNumber << " " << parts[i].Address
			<< " " << parts[i].Email << " " << parts[i].Note << "\n";
	}
}
/*****************************************************************************************/
int LoadPersonParts(PersonParts parts[])
{
	fstream Input("File.txt", ios::in);
	if (Input.fail())
	{
		return 0;
	}
	int j;
	for (size_t i = 0; 1; i++)
	{
		Input >> j >> parts[i].FirstName >> parts[i].LastName
			>> parts[i].PhoneNumber >> parts[i].Address
			>> parts[i].Email >> parts[i].Note;
		if (j != i)
			return i;
	}
}