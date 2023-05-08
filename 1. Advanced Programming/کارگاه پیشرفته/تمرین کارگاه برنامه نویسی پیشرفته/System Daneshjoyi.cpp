//Mohsen AliMohammadi
//Pouya AliKhanZade
//Hasan Aboyi
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
//------------------------------------------------------------------------------------------------------------//
bool RemoveSelectedCourse();
void gotoxy(int x, int y);
bool AddSelectedCourse();
void Color(int number);
bool MoshahedeDoros();
bool Yekta(int code);
bool AddStudents();
bool AddTeacher();
bool AddCourse();
void About();
void Frame();
void Menu();
//------------------------------------------------------------------------------------------------------------//
class Person
{
public:
	string FirstName;
	string LastName;
	int Age;
	string Gender;
	Person() {}
	Person(string FirstName, string LastNAme, int Age, string Gender)
	{
		FirstName = FirstName;
		LastNAme = LastNAme;
		Age = Age;
		Gender = Gender;
	}
};
//------------------------------------------------------------------------------------------------------------//
class Student : public Person
{
public:
	Student()
	{
		StuId = 0;
	}
	Student(int StuId, string field, float avg, string level)
	{
		StuId = StuId;
		field = field;
		avg = avg;
		level = level;
	}
	int StuId;
	string field;
	float avg;
	string level;
};
//------------------------------------------------------------------------------------------------------------//
class Teacher : public Person
{
public:
	Teacher()
	{
		Hoqoq = 2000000;
	}
	Teacher(int Code, string Madrak, string Reshte, float Hoqoq)
	{
		Code = Code;
		Madrak = Madrak;
		Reshte = Reshte;
		Hoqoq = Hoqoq;
	}
	int Code;
	string Madrak;
	string Reshte;
	float Hoqoq;
};
//------------------------------------------------------------------------------------------------------------//
class Course
{
public:
	Course() {}
	Course(string Name, int TeacherCode, int Code, int Vahed, string Model)
	{
		Name = Name;
		TeacherCode = TeacherCode;
		Code = Code;
		Vahed = Vahed;
		Model = Model;
	}
	string Name;
	int TeacherCode;
	int Code;
	int Vahed;
	string Model;
};
//------------------------------------------------------------------------------------------------------------//
class SelectedCourse
{
public:
	SelectedCourse()
	{
		CourseCode[100] = { 0 };
	}
	SelectedCourse(int StuNumber, int CourseCode[])
	{
		StuNumber = StuNumber;
		CourseCode = CourseCode;
	}
	int StuNumber;
	int CourseCode[100];
};
//------------------------------------------------------------------------------------------------------------//
Student students[10];
Teacher teachers[10];
Course courses[20];
SelectedCourse  selectedCourses[20];
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
void Frame()
{
	int n = 33, m = 50;
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
//------------------------------------------------------------------------------------------------------------//
void About()
{
	int x = 2, sw = 0;
	char back;
	Frame();
	gotoxy(x, 10);
	Color(0xF9);
	cerr << "System Daneshjoyi | Ver 1.0.0";
	gotoxy(x, 15);
	Color(0xF0);
	cerr << "Programmers:";
	gotoxy(x, 17);
	Color(0xF0);
	cerr << "Mohsen AliMohammadi";
	gotoxy(x, 19);
	Color(0xF0);
	cerr << "Pouya AliKhanZade";
	gotoxy(x, 21);
	Color(0xF0);
	cerr << "Hasan Aboyi";
	gotoxy(x, 25);
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
void Menu()
{
	Frame();
	char ch;
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cerr << "System Daneshjoyi";
	gotoxy(x + 2, y + 4);
	cerr << "1. Ezafe Nemodan Daneshjo";
	gotoxy(x + 2, y + 7);
	cerr << "2. Ezafe Nemodan Ostad";
	gotoxy(x + 2, y + 10);
	cerr << "3. Ezafe Nemodan Dars";
	gotoxy(x + 2, y + 13);
	cerr << "4. Entekhab Vahed";
	gotoxy(x + 2, y + 16);
	cerr << "5. Hazf Dars";
	gotoxy(x + 2, y + 19);
	cerr << "6. Moshahede Doros Entekhab Shode";
	gotoxy(x + 2, y + 22);
	cerr << "7. Darbare";
	gotoxy(x + 2, y + 25);
	cerr << "8. Khoroj";
	y += 4;
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
			if (y == 8) // Ezafe Nemodan Daneshjo
			{
				system("cls");
				AddStudents();
				system("cls");
				Menu();
			}
			else if (y == 11) // Ezafe Nemodan Ostad
			{
				system("cls");
				AddTeacher();
				system("cls");
				Menu();
			}
			else if (y == 14) // Ezafe Nemodan Dars
			{
				system("cls");
				AddCourse();
				system("cls");
				Menu();
			}
			else if (y == 17) // Entekhab Vahed
			{
				system("cls");
				AddSelectedCourse();
				system("cls");
				Menu();
			}
			else if (y == 20) // Hazf Dars
			{
				system("cls");
				RemoveSelectedCourse();
				system("cls");
				Menu();
			}
			else if (y == 23) // Moshahede Doros Entekhab Shode
			{
				system("cls");
				MoshahedeDoros();
				system("cls");
				Menu();
			}
			else if (y == 26) // Darbare
			{
				system("cls");
				About();
			}
			else if (y == 29) // Khoroj
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
bool AddStudents()
{
	Frame();
	Student s;
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cerr << "Ezafe Nemodan Daneshjo";
	gotoxy(x + 2, y + 4);
	cerr << "First Name: ";
	gotoxy(x + 2, y + 7);
	cerr << "Last Name: ";
	gotoxy(x + 2, y + 10);
	cerr << "Age: ";
	gotoxy(x + 2, y + 13);
	cerr << "Gender: ";
	gotoxy(x + 2, y + 16);
	cerr << "Shomare Daneshjoyi: ";
	gotoxy(x + 2, y + 19);
	cerr << "MaqtaA: ";
	gotoxy(x + 2, y + 22);
	cerr << "Reshte: ";
	gotoxy(x + 2, y + 25);
	cerr << "Moadel: ";
	gotoxy(x + 22, y + 4);
	cin >> s.FirstName;
	gotoxy(x + 22, y + 7);
	cin >> s.LastName;
	gotoxy(x + 22, y + 10);
	cin >> s.Age;
	gotoxy(x + 22, y + 13);
	cin >> s.Gender;
	gotoxy(x + 22, y + 16);
	cin >> s.StuId;
	gotoxy(x + 22, y + 19);
	cin >> s.level;
	gotoxy(x + 22, y + 22);
	cin >> s.field;
	gotoxy(x + 22, y + 25);
	cin >> s.avg;
	if (Yekta(s.StuId) == false)
	{
		gotoxy(x + 20, y + 18);
		cerr << "Code Already Exists.";
		_getch();
		return false;
	}
	bool sw = false;
	for (size_t i = 0; i < 10; i++)
	{
		if (students[i].StuId == 0)
		{
			students[i] = s;
			sw = true;
			break;
		}
	}
	return sw;
}
//------------------------------------------------------------------------------------------------------------//
bool AddTeacher()
{
	Frame();
	Teacher p;
	int x = 7, y = 4;
	gotoxy(x + 7, y - 1);
	cerr << "Ezafe Nemodan Ostad";
	gotoxy(x + 2, y + 4);
	cerr << "First Name: ";
	gotoxy(x + 2, y + 7);
	cerr << "Last Name: ";
	gotoxy(x + 2, y + 10);
	cerr << "Age: ";
	gotoxy(x + 2, y + 13);
	cerr << "Gender: ";
	gotoxy(x + 2, y + 16);
	cerr << "Code Ostad: ";
	gotoxy(x + 2, y + 19);
	cerr << "Madrak: ";
	gotoxy(x + 2, y + 22);
	cerr << "Reshte: ";
	gotoxy(x + 2, y + 25);
	cerr << "Hoqoq: ";
	gotoxy(x + 14, y + 4);
	cin >> p.FirstName;
	gotoxy(x + 14, y + 7);
	cin >> p.LastName;
	gotoxy(x + 14, y + 10);
	cin >> p.Age;
	gotoxy(x + 14, y + 13);
	cin >> p.Gender;
	gotoxy(x + 14, y + 16);
	cin >> p.Code;
	gotoxy(x + 14, y + 19);
	cin >> p.Madrak;
	gotoxy(x + 14, y + 22);
	cin >> p.Reshte;
	gotoxy(x + 14, y + 25);
	cin >> p.Hoqoq;
	if (Yekta(p.Code) == false)
	{
		gotoxy(x + 20, y + 18);
		cerr << "Code Already Exists.";
		_getch();
		return false;
	}
	bool sw = false;
	for (size_t i = 0; i < 10; i++)
	{
		if (teachers[i].Code == 0)
		{
			teachers[i] = p;
			sw = true;
			break;
		}
	}
	return sw;
}
//------------------------------------------------------------------------------------------------------------//
bool AddCourse()
{
	Frame();
	Course c;
	int x = 7, y = 4;
	gotoxy(x + 8, y - 1);
	cerr << "Ezafe Nemodan Dars";
	gotoxy(x + 2, y + 4);
	cerr << "Code Dars: ";
	gotoxy(x + 2, y + 7);
	cerr << "Name Dars: ";
	gotoxy(x + 2, y + 10);
	cerr << "Tedad Vahed: ";
	gotoxy(x + 2, y + 13);
	cerr << "Omomi Or Khososi: ";
	gotoxy(x + 2, y + 16);
	cerr << "Code Ostad: ";
	gotoxy(x + 20, y + 4);
	cin >> c.Code;
	gotoxy(x + 20, y + 7);
	cin >> c.Name;
	gotoxy(x + 20, y + 10);
	cin >> c.Vahed;
	gotoxy(x + 20, y + 13);
	cin >> c.Model;
	gotoxy(x + 20, y + 16);
	cin >> c.TeacherCode;
	if (Yekta(c.Code) == false)
	{
		gotoxy(x + 20, y + 18);
		cerr << "Code Already Exists.";
		_getch();
		return false;
	}
	int ans = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (teachers[i].Code == c.TeacherCode)
		{
			ans = 1;
			break;
		}
	}
	if (ans == 0)
	{
		gotoxy(x + 20, y + 18);
		cerr << "TeacherCode Not Found.";
		_getch();
		return false;
	}
	bool sw = false;
	for (size_t i = 0; i < 20; i++)
	{
		if (courses[i].Code == 0)
		{
			courses[i] = c;
			sw = true;
			break;
		}
	}
	return sw;
}
//------------------------------------------------------------------------------------------------------------//
bool AddSelectedCourse()
{
	Frame();
	SelectedCourse s;
	int x = 7, y = 4, check = 0;
	gotoxy(x + 9, y - 1);
	cerr << "Entekhab Vahed";
	gotoxy(x + 2, y + 4);
	cerr << "Shomare Daneshjoyi: ";
	gotoxy(x + 22, y + 4);
	cin >> s.StuNumber;
	int ans = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (students[i].StuId == s.StuNumber)
		{
			ans = 1;
			break;
		}
	}
	if (ans == 0)
	{
		gotoxy(x + 20, y + 18);
		cerr << "StudentId Not Found.";
		_getch();
		return false;
	}
	bool flag[20] = { false };
	for (size_t i = 0; i < 20; i++)
	{
		if (selectedCourses[i].StuNumber == s.StuNumber)
		{
			for (size_t j = 0; j < 20; j++)
			{
				for (size_t k = 0; k < 20; k++)
				{
					if (courses[j].Code == selectedCourses[i].CourseCode[k])
					{
						flag[j] = true;
					}
				}
			}
			break;
		}
	}
	int yy = 8;
	for (size_t i = 0; i < 20; i++)
	{
		if (flag[i] == false && courses[i].Code != 0)
		{
			yy += 3;
			gotoxy(x + 2, yy);
			cerr << courses[i].Name << "\t\t" << courses[i].Code;
			check = 1;
		}
	}
	if (check == 0)
	{
		gotoxy(x + 20, y + 18);
		cerr << "Courses Not Found.";
		_getch();
		return false;
	}
	int n;
	gotoxy(x + 2, yy + 3);
	cerr << "Tedad: ";
	gotoxy(x + 10, yy + 3);
	cin >> n;
	yy += 3;
	for (size_t i = 0; i < n; i++)
	{
		yy += 3;
		gotoxy(x + 2, yy);
		cerr << "Enter Code: ";
		gotoxy(x + 14, yy);
		cin >> s.CourseCode[i];
	}
	bool sw = false;
	for (size_t i = 0; i < 20; i++)
	{
		if (selectedCourses[i].StuNumber == 0)
		{
			selectedCourses[i] = s;
			sw = true;
			break;
		}
	}
	return sw;
}
//------------------------------------------------------------------------------------------------------------//
bool RemoveSelectedCourse()
{
	Frame();
	SelectedCourse s;
	int x = 7, y = 4, check = 0;
	gotoxy(x + 12, y - 1);
	cerr << "Hazf Dars";
	gotoxy(x + 2, y + 4);
	cerr << "Shomare Daneshjoyi: ";
	gotoxy(x + 22, y + 4);
	cin >> s.StuNumber;
	int ans = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (students[i].StuId == s.StuNumber)
		{
			ans = 1;
			break;
		}
	}
	if (ans == 0)
	{
		gotoxy(x + 20, y + 18);
		cerr << "StudentId Not Found.";
		_getch();
		return false;
	}
	int yy = 8;
	for (size_t i = 0; i < 20; i++)
	{
		if (s.StuNumber == selectedCourses[i].StuNumber)
		{
			for (size_t j = 0; j < 20; j++)
			{
				if (selectedCourses[i].CourseCode[j] == courses[j].Code && selectedCourses[i].CourseCode[j] != 0)
				{
					yy += 3;
					gotoxy(x + 2, yy);
					cerr << courses[j].Name << "\t\t" << selectedCourses[i].CourseCode[j];
					check = 1;
				}
			}
			break;
		}
	}
	if (check == 0)
	{
		gotoxy(x + 20, y + 18);
		cerr << "Courses Not Found.";
		_getch();
		return false;
	}
	int n;
	gotoxy(x + 2, yy + 3);
	cerr << "Tedad: ";
	gotoxy(x + 10, yy + 3);
	cin >> n;
	yy += 3;
	for (size_t i = 0; i < n; i++)
	{
		yy += 3;
		gotoxy(x - 2, yy);
		cerr << "Enter Code: ";
		gotoxy(x + 10, yy);
		cin >> s.CourseCode[i];
		gotoxy(x + 20, yy);
		cerr << "Aya Hazf Shavad?";
		char ch;
		ch = _getch();
		if (ch == 'y' || ch == 'Y')
			for (size_t j = 0; j < 20; j++)
			{
				if (s.StuNumber == selectedCourses[j].StuNumber)
				{
					for (size_t k = 0; k < 20; k++)
					{
						if (selectedCourses[j].CourseCode[k] == s.CourseCode[i])
						{
							selectedCourses[j].CourseCode[k] = 0;
						}
					}
				}
			}
	}
	return true;
}
//------------------------------------------------------------------------------------------------------------//
bool MoshahedeDoros()
{
	Frame();
	int x = 7, y = 4, check = 0;
	gotoxy(x + 3, y - 1);
	cerr << "Moshahede Doros Entekhab Shode";
	for (size_t i = 0; i < 20; i++)
	{
		if (selectedCourses[i].StuNumber == students[i].StuId)
		{
			for (size_t j = 0; j < 20; j++)
			{
				if (selectedCourses[i].CourseCode[j] != 0)
				{
					for (size_t k = 0; k < 20; k++)
					{
						if (courses[k].Code == selectedCourses[i].CourseCode[j])
						{
							y += 3;
							gotoxy(x, y);
							cerr << students[i].FirstName << " " << students[i].LastName
								<< " " << students[i].StuId << " " << courses[k].Name
								<< " " << selectedCourses[i].CourseCode[j];
							check = 1;
						}
					}
				}
			}
		}
	}
	if (check == 0)
	{
		gotoxy(x + 20, y + 18);
		cerr << "Courses Not Found.";
		_getch();
		return false;
	}
	_getch();
	return true;
}
//------------------------------------------------------------------------------------------------------------//
bool Yekta(int code)
{
	int x = 7, y = 4;
	int ans = 1;
	for (size_t i = 0; i < 10; i++)
	{
		if (teachers[i].Code == code || students[i].StuId == code || courses[i].Code == code)
		{
			ans = 0;
			break;
		}
	}
	if (ans == 0)
	{
		return false;
	}
	return true;
}
//------------------------------------------------------------------------------------------------------------//