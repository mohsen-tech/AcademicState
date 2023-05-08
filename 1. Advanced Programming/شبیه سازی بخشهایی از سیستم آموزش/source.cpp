#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;
struct AdminInfo
{
	string username, password;
};
struct Score
{
	double mabani, andishe, azFizik;
};
struct StuInfo
{
	string id, name, family, password;
	int age;
	Score scores{ 0,0,0 };
	double avg;
};
vector <StuInfo> studentsInfo;
vector <AdminInfo> adminsInfo;
string getUsername()
{
	string str;
	cout << "username: ";
	cin >> str;
	return str;
}
string getPassword()
{
	string str;
	cout << "password: ";
	cin >> str;
	return str;
}
int getAdminIndex(string username, string pass)
{
	for (int i = 0; i < adminsInfo.size(); i++)
		if (username == adminsInfo[i].username)
			if (pass == adminsInfo[i].password)
				return i;
			else
			{
				cout << "password nadorost!\n";
				return -1;
			}
	cout << "chenin admini mojod nist!\n";
	return -1;
}
int getStudentIndex(string id, string pass)
{
	for (int i = 0; i < studentsInfo.size(); i++)
		if (id == studentsInfo[i].id)
			if (pass == studentsInfo[i].password)
				return i;
			else
			{
				cout << "password nadorost!\n";
				return -1;
			}
	cout << "chenin daneshjoyi mojod nist!\n";
	return -1;
}
int checkStuId(string Id)
{
	for (int i = 0; i < studentsInfo.size(); i++)
		if (studentsInfo[i].id == Id)
			return i;
	return -1;
}
string checksumPass()
{
	string str;
	while (cin >> str)
	{
		if (str.size() == 6)
			return str;
		else
		{
			cout << "password bayad 6 raqami bashad!\n";
			cout << "dobare vared konid: ";
		}
	}
}
double checkScore()
{
	double d;
	while (cin >> d)
	{
		if (0 <= d && d <= 20)
			return d;
		else
		{
			cout << "mage chenin nomre ham darim :|\n";
			cout << "dobare vared konid: ";
		}
	}
}
bool avgSort(StuInfo i, StuInfo j)
{
	return (i.avg > j.avg);
}
double calAvg(int index)
{
	return (studentsInfo[index].scores.mabani * 3 + studentsInfo[index].scores.andishe * 2 + studentsInfo[index].scores.azFizik * 1) / 6;
}
void calAvgStu()
{
	for (int i = 0; i < studentsInfo.size(); i++)
		studentsInfo[i].avg = calAvg(i);
}
void sortAvgStu()
{
	sort(studentsInfo.begin(), studentsInfo.end(), avgSort);
}
void showScoreList(int index)
{
	system("cls");
	cout << "Mabani: " << studentsInfo[index].scores.mabani << "\n";
	int Max = -1, Min = 21;
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		if (studentsInfo[i].scores.mabani > Max)
			Max = studentsInfo[i].scores.mabani;
		if (studentsInfo[i].scores.mabani < Min)
			Min = studentsInfo[i].scores.mabani;
	}
	cout << "Max: " << Max << "\nMin: " << Min << "\n";

	cout << "Andishe: " << studentsInfo[index].scores.andishe << "\n";
	Max = -1, Min = 21;
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		if (studentsInfo[i].scores.andishe > Max)
			Max = studentsInfo[i].scores.andishe;
		if (studentsInfo[i].scores.andishe < Min)
			Min = studentsInfo[i].scores.andishe;
	}
	cout << "Max: " << Max << "\nMin: " << Min << "\n";

	cout << "AzFizik: " << studentsInfo[index].scores.azFizik << "\n";
	Max = -1, Min = 21;
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		if (studentsInfo[i].scores.azFizik > Max)
			Max = studentsInfo[i].scores.azFizik;
		if (studentsInfo[i].scores.azFizik < Min)
			Min = studentsInfo[i].scores.azFizik;
	}
	cout << "Max: " << Max << "\nMin: " << Min << "\n";
	_getch();
}
void showAvg(int index)
{
	system("cls");
	calAvgStu();
	cout << "Average: " << studentsInfo[index].avg << "\n";
	cout << "Mabani: " << studentsInfo[index].scores.mabani << "Unit:3\n";
	cout << "Andishe: " << studentsInfo[index].scores.andishe << "Unit:2\n";
	cout << "AzFizik: " << studentsInfo[index].scores.azFizik << "Unit:1\n";
	_getch();
}
void editInfo(int index)
{
	system("cls");
	cout << "name: ";
	cin >> studentsInfo[index].name;
	cout << "family: ";
	cin >> studentsInfo[index].family;
	cout << "age: ";
	cin >> studentsInfo[index].age;
	cout << endl << "edit shod!\n";
	_getch();
}
void studentMenu(int index)
{
	while (1)
	{
		system("cls");
		int choose;
		cout << "1. moshahedeye list nomarat\n";
		cout << "2. moshahedeye avg\n";
		cout << "3. virayeshe moshakhasat\n";
		cout << "4. bazgasht\n";
		cout << "vared konid: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			showScoreList(index);
			break;
		case 2:
			showAvg(index);
			break;
		case 3:
			editInfo(index);
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}
void student()
{
	system("cls");
	string id, pass;
	id = getUsername();
	pass = getPassword();
	int index = getStudentIndex(id, pass);
	if (index != -1)
		studentMenu(index);
	else
	{
		_getch();
		system("cls");
		return;
	}
}
void addStudent()
{
	system("cls");
	StuInfo temp;
	cout << "shomare daneshjoyi: ";
	cin >> temp.id;
	if (checkStuId(temp.id) != -1)
	{
		cout << "shomare daneshjoyi tekrari!\n";
		_getch();
		return;
	}
	cout << "name: ";
	cin >> temp.name;
	cout << "family: ";
	cin >> temp.family;
	cout << "age: ";
	cin >> temp.age;
	cout << "password: ";
	temp.password = checksumPass();
	studentsInfo.push_back(temp);
	_getch();
}
void removeStudent()
{
	system("cls");
	string id;
	cout << "shomare daneshjoyi ra vared konid: ";
	cin >> id;
	int index = checkStuId(id);
	if (index != -1)
	{
		char ch;
		cout << "vaqean hazf beshe? (age are 'Y' vared kon) ";
		cin >> ch;
		if (ch == 'Y')
		{
			studentsInfo.erase(studentsInfo.begin() + index);
			cout << "hazf shod!\n";
		}
		else
			cout << "grfti maro :|\n";
	}
	else
		cout << "chenin daneshjoyi nist!\n";
	_getch();
}
void getScores()
{
	system("cls");
	string id;
	cout << "shomare daneshjoyi ra vared konid: ";
	cin >> id;
	int index = checkStuId(id);
	if (index != -1)
	{
		cout << "nomre mabani: ";
		studentsInfo[index].scores.mabani = checkScore();
		cout << "nomre andishe: ";
		studentsInfo[index].scores.andishe = checkScore();
		cout << "nomre az fizik: ";
		studentsInfo[index].scores.azFizik = checkScore();
		cout << "sabt shod!\n";
	}
	else
		cout << "chenin daneshjoyi nist!\n";
	_getch();
}
void showStuAvgSort()
{
	system("cls");
	calAvgStu();
	sortAvgStu();
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		cout << studentsInfo[i].id << " ";
		cout << studentsInfo[i].name << " " << studentsInfo[i].family << " ";
		cout << studentsInfo[i].avg << "\n";
	}
	_getch();
}
void showStuTopAvg()
{
	system("cls");
	calAvgStu();
	double sum = 0, Avg;
	for (int i = 0; i < studentsInfo.size(); i++)
		sum += studentsInfo[i].avg;
	Avg = sum / studentsInfo.size();
	cout << "Average: " << Avg << "\n";
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		if (studentsInfo[i].avg > Avg)
		{
			cout << studentsInfo[i].id << " ";
			cout << studentsInfo[i].name << " " << studentsInfo[i].family << " ";
			cout << studentsInfo[i].avg << "\n";
		}
	}
	_getch();
}
void adminMenu()
{
	while (1)
	{
		system("cls");
		int choose;
		cout << "1. ijade daneshjo\n";
		cout << "2. hazfe daneshjo\n";
		cout << "3. vared krdn nomre\n";
		cout << "4. daryaft list sort shode bar asase avg\n";
		cout << "5. daryaft list daneshjoyani ba avg balatar az avg kol\n";
		cout << "6. bazgasht\n";
		cout << "vared konid: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			addStudent();
			break;
		case 2:
			removeStudent();
			break;
		case 3:
			getScores();
			break;
		case 4:
			showStuAvgSort();
			break;
		case 5:
			showStuTopAvg();
			break;
		case 6:
			return;
		default:
			break;
		}
	}
}
void admin()
{
	system("cls");
	string username, pass;
	username = getUsername();
	pass = getPassword();
	int index = getAdminIndex(username, pass);
	if (index != -1)
		adminMenu();
	else
	{
		_getch();
		system("cls");
		return;
	}
}
void run()
{
	while (1)
	{
		system("cls");
		int choose;
		cout << "1. Login as Admin\n";
		cout << "2. Login as Student\n";
		cout << "3. Exit\n";
		cout << "vared konid: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			admin();
			break;
		case 2:
			student();
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
	}
}
void readFromFile()
{
	AdminInfo temp0;
	StuInfo temp1, temp2;
	fstream file0, file1, file2, file3;
	file0.open("Admin.txt", ios::in);
	file1.open("StuInfo.txt", ios::in );
	file2.open("StuUserPass.txt", ios::in );
	file3.open("StuScores.txt", ios::in );
	if (file0.fail() || file1.fail() || file2.fail() || file3.fail())
	{
		cout << "File Error!\n";
		_getch();
		exit(0);
	}
	while (file0 >> temp0.username >> temp0.password)
		adminsInfo.push_back(temp0);
	while (file1 >> temp1.id >> temp1.name >> temp1.family >> temp1.age)
		studentsInfo.push_back(temp1);
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		file2 >> temp1.id >> temp1.password;
		file3 >> temp2.id >> temp2.scores.mabani >> temp2.scores.andishe >> temp2.scores.azFizik >> temp2.avg;
		if (studentsInfo[i].id == temp1.id && studentsInfo[i].id == temp2.id)
		{
			studentsInfo[i].password = temp1.password;
			studentsInfo[i].scores.mabani = temp2.scores.mabani;
			studentsInfo[i].scores.andishe = temp2.scores.andishe;
			studentsInfo[i].scores.azFizik = temp2.scores.azFizik;
			studentsInfo[i].avg = temp2.avg;
		}
	}
	file0.close(); file1.close(); file2.close(); file3.close();
}
void writeFromFile()
{
	calAvgStu();
	sortAvgStu();
	fstream file0, file1, file2, file3;
	file0.open("Admin.txt", ios::out);
	file1.open("StuInfo.txt", ios::out );
	file2.open("StuUserPass.txt", ios::out);
	file3.open("StuScores.txt", ios::out );
	if (file0.fail() || file1.fail() || file2.fail() || file3.fail())
	{
		cout << "File Error!\n";
		_getch();
		exit(0);
	}
	for (int i = 0; i < adminsInfo.size(); i++)
	{
		file0 << adminsInfo[i].username << " " << adminsInfo[i].password << "\n";
	}
	for (int i = 0; i < studentsInfo.size(); i++)
	{
		file1 << studentsInfo[i].id << " " << studentsInfo[i].name << " " << studentsInfo[i].family << " " << studentsInfo[i].age << "\n";
		file2 << studentsInfo[i].id << " " << studentsInfo[i].password << "\n";
		file3 << studentsInfo[i].id << " " << studentsInfo[i].scores.mabani << " " << studentsInfo[i].scores.andishe << " " << studentsInfo[i].scores.azFizik << " " << studentsInfo[i].avg << "\n";
	}
	file0.close(); file1.close(); file2.close(); file3.close();
}
int main()
{
	readFromFile();
	run();
	writeFromFile();
	return 0;
}