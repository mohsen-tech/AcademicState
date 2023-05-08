#include <iostream>
#include <fstream>
#include <conio.h>
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
int main()
{
	LoadPersonParts(MyParts);
	Menu();
	system("pause>0");
	return 0;
}
/*****************************************************************************************/
void Menu()
{
	int choose, size;
	while (true)
	{
		cout << "1.Add\n";
		cout << "2.Edit\n";
		cout << "3.Delete\n";
		cout << "4.Show List\n";
		cout << "5.Search\n";
		cout << "6.Save To File\n";
		cout << "7.Exit\n";
		cout << "Choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			system("cls");
			AddPerson(MyParts);
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			EditPerson(MyParts);
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			DeletePerson(MyParts);
			_getch();
			system("cls");
			break;
		case 4:
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
			break;
		case 5:
			system("cls");
			SearchPerson(MyParts);
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			SavePersonParts(MyParts);
			cout << "Done!\n";
			_getch();
			system("cls");
			break;
		case 7:
			//SavePersonParts(MyParts);
			exit(0);
			break;
		default:
			cerr << "\n:-|";
			_getch();
			system("cls");
			break;
		}
	}
}
/*****************************************************************************************/
PersonParts ScanPersonParts()
{
	PersonParts temp;
	cout << "First Name: ";
	cin >> temp.FirstName;
	cout << "Last Name: ";
	cin >> temp.LastName;
	cout << "Phone Number: ";
	cin >> temp.PhoneNumber;
	cout << "Address: ";
	cin >> temp.Address;
	cout << "Email: ";
	cin >> temp.Email;
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
	cout << "- Add -\n";
	PersonParts temp;
	temp = ScanPersonParts();
	if (Yekta(parts, temp.PhoneNumber, temp.Email) == true)
	{
		int index = getSize(parts);
		parts[index] = temp;
	}
	else cout << "PhoneNumber or Email Found!\tCant Add!\n";
}
/*****************************************************************************************/
void SearchPerson(PersonParts parts[])
{
	cout << "- Search -\n";
	long long int PhoneNumber;
	char Email[30];
	cout << "Enter Phone Number: ";
	cin >> PhoneNumber;
	cout << "Enter Email: ";
	cin >> Email;
	int index = getIndex(parts, PhoneNumber, Email);
	if (index != -1)
	{
		cout << "Found!\n";
		PrintPersonParts(parts, index);
	}
	else cout << "Not Found!\n";
}
/*****************************************************************************************/
void DeletePerson(PersonParts parts[])
{
	cout << "- Delete -\n";
	long long int PhoneNumber;
	char Email[30];
	cout << "Enter Phone Number: ";
	cin >> PhoneNumber;
	cout << "Enter Email: ";
	cin >> Email;
	int index = getIndex(parts, PhoneNumber, Email), size = getSize(parts);
	if (index != -1)
	{
		cout << "Found and Delete!\n";
		for (size_t i = index; i < size; i++)
			parts[i] = parts[i + 1];
	}
	else cout << "Not Found and Cant Delete!\n";
}
/*****************************************************************************************/
void EditPerson(PersonParts parts[])
{
	cout << "- Edit -\n";
	long long int PhoneNumber;
	char Email[30];
	cout << "Enter Phone Number: ";
	cin >> PhoneNumber;
	cout << "Enter Email: ";
	cin >> Email;
	int index = getIndex(parts, PhoneNumber, Email);
	if (index != -1)
	{
		cout << "Found and Edit!\n";
		parts[index] = ScanPersonParts();
		cout << "Update!\n";
	}
	else cout << "Not Found and Cant Edit!\n";
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