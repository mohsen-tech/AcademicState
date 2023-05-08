#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cmath>
using namespace std;
//-------------------------------------------------------------------------------------------------
class Personal
{
private:
	string Name, Family;
	int NationalCode;
public:
	void set(string name, string family, int nationalCode)
	{
		Name = name;
		Family = family;
		NationalCode = nationalCode;
	}
	string getName() const
	{
		return Name;
	}
	string getFamily() const
	{
		return Family;
	}
	int getNationalCode() const
	{
		return NationalCode;
	}
};
//-------------------------------------------------------------------------------------------------
class Lesson
{
	friend istream & operator >> (istream &, Lesson &);
	friend ostream & operator << (ostream &, const Lesson &);
private:
	string Name;
	int Mark, Vahed;
public:
	string getName() const
	{
		return Name;
	}
	int getMark() const
	{
		return Mark;
	}
	int getVahed() const
	{
		return Vahed;
	}
};
istream & operator >> (istream & in, Lesson & Obj)
{
	cout << "Enter Name Dars: ";
	in >> Obj.Name;
	cout << "Enter Tedad Vahed Dars: ";
	in >> Obj.Vahed;
	cout << "Enter Nomre Dars: ";
	in >> Obj.Mark;
	return in;
}
ostream & operator << (ostream & out, const Lesson & Obj)
{
	out << Obj.Name << "\t\t" << Obj.Mark << "\t\t" << Obj.Vahed << "\n";
	return out;
}
//-------------------------------------------------------------------------------------------------
class Student : public Personal
{
	friend istream & operator >> (istream &, Student &);
	friend ostream & operator << (ostream &, const Student &);
private:
	int Id, n;
	float Avg;
	vector <Lesson> lessons;
public:
	float CalcAvg()
	{
		float sumLesson = 0, sumVahed = 0;
		for (int i = 0; i < lessons.size(); i++)
		{
			sumLesson += lessons[i].getMark() * lessons[i].getVahed();
			sumVahed += lessons[i].getVahed();
		}
		return sumLesson / sumVahed;
	}
	void RemoveLessons()
	{
		lessons.clear();
	}
	void setId(int id)
	{
		Id = id;
	}
	int getId() const
	{
		return Id;
	}
	float getAvg() const
	{
		return Avg;
	}
};
istream & operator >> (istream & in, Student & Obj)
{
	string Name, Family;
	int NationalCode;
	cout << "Enter Name: ";
	in >> Name;
	cout << "Enter Family: ";
	in >> Family;
	cout << "Enter NationalCode: ";
	in >> NationalCode;
	Obj.set(Name, Family, NationalCode);
	cout << "\n";
	cout << "Enter Tedad Dars: ";
	in >> Obj.n;
	cout << "\n";
	Lesson temp;
	for (int i = 0; i < Obj.n; i++)
	{
		in >> temp;
		Obj.lessons.push_back(temp);
		cout << "\n";
	}
	Obj.Avg = Obj.CalcAvg();
	return in;
}
ostream & operator << (ostream & out, const Student & Obj)
{
	out << "Name: " << Obj.getName() << "\n";
	out << "Family: " << Obj.getFamily() << "\n";
	out << "NationalCode: " << Obj.getNationalCode() << "\n";
	out << "StudentNumber: " << Obj.getId() << "\n";
	out << "Tedad Dars: " << Obj.lessons.size() << "\n";
	out << "Name Dars" << "\t" << "Nomre Dars" << "\t" << "Tedad Vahed Dars" << "\n";
	for (int i = 0; i < Obj.lessons.size(); i++)
	{
		out << Obj.lessons[i] << "\n";
	}
	out << "Avg: " << Obj.getAvg() << "\n";
	return out;
}
//-------------------------------------------------------------------------------------------------
class Uni
{
private:
	vector <Student> students;
	//-------------------------------------------------------------------------------------------------
	int getIndex(int id)
	{
		for (int i = 0; i < students.size(); i++)
			if (students[i].getId() == id)
				return i;
		return -1;
	}
	//-------------------------------------------------------------------------------------------------
	int getIndex(string family)
	{
		for (int i = 0; i < students.size(); i++)
			if (students[i].getFamily() == family)
				return i;
		return -1;
	}
public:
	//-------------------------------------------------------------------------------------------------
	void Add()
	{
		int id;
		cout << "Enter StudentNumber: ";
		cin >> id;
		if (getIndex(id) == -1)
		{
			Student temp;
			temp.setId(id);

			cin >> temp;
			students.push_back(temp);
			cout << "Ok!\n";
		}
		else
		{
			cout << "StudentNumber Tekrari!\n";
		}
	}
	//-------------------------------------------------------------------------------------------------
	void Show()
	{
		string str;
		cout << "Enter StudentNumber or Fname: ";
		cin >> str;
		if ('a' <= str[0] && str[0] <= 'z' || 'A' <= str[0] && str[0] <= 'Z')
		{
			if (getIndex(str) != -1)
				cout << students[getIndex(str)] << "\n";
			else
				cout << "StudentNumber Not Found!\n";
		}
		else if ('0' <= str[0] && str[0] <= '9')
		{
			if (getIndex(stoi(str)) != -1)
				cout << students[getIndex(stoi(str))] << "\n";
			else
				cout << "StudentNumber Not Found!\n";
		}
		else
			cout << "StudentNumber Not Found!\n";
	}
	//-------------------------------------------------------------------------------------------------
	void Del()
	{
		int id;
		cout << "Enter StudentNumber: ";
		cin >> id;
		if (getIndex(id) != -1)
		{
			students.erase(students.begin() + getIndex(id));
			cout << "Student Removed!\n";
		}
		else
		{
			cout << "StudentNumber Not Found!\n";
		}
	}
	//-------------------------------------------------------------------------------------------------
	void Sort()
	{
		for (int i = 0; i < students.size(); i++)
			for (int j = i + 1; j < students.size(); j++)
				if (students[i].getAvg() < students[j].getAvg())
					swap(students[i], students[j]);
				else if (students[i].getAvg() == students[j].getAvg())
					if (students[i].getId() > students[j].getId())
						swap(students[i], students[j]);
	}
	//-------------------------------------------------------------------------------------------------
	void Print()
	{
		Sort();
		cout << "  \tName" << "\t" << "Family" << "\t" << "NationalCode" << "\t" << "Id" << "\t" << "Avg" << "\n\n";
		for (int i = 0; i < students.size(); i++)
		{
			cout << i + 1 << "\t" << students[i].getName() << "\t" << students[i].getFamily() << "\t" << students[i].getNationalCode() << "\t" << students[i].getId() << "\t" << students[i].getAvg() << "\n\n";
		}
	}
	//-------------------------------------------------------------------------------------------------
	void Edit()
	{
		int id, index;
		cout << "Enter StudentNumber: ";
		cin >> id;
		index = getIndex(id);
		if (index != -1)
		{
			students[index].RemoveLessons();
			cout << "StudentNumber: ";
			cin >> id;
			students[index].setId(id);
			cin >> students[index];
			cout << "Student Update!\n";
		}
		else
		{
			cout << "StudentNumber Not Found!\n";
		}
	}
};
//-------------------------------------------------------------------------------------------------
void Menu()
{
	Uni uni;
	while (true)
	{
		cout << "1. Add Student\n\n";
		cout << "2. Show Student Information\n\n";
		cout << "3. Delete Student\n\n";
		cout << "4. Print All Students\n\n";
		cout << "5. Edit Student Information\n\n";
		cout << "6. Exit\n\n\n";
		cout << "Choose One: ";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			uni.Add();
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			uni.Show();
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			uni.Del();
			_getch();
			system("cls");
			break;
		case 4:
			system("cls");
			uni.Print();
			_getch();
			system("cls");
			break;
		case 5:
			system("cls");
			uni.Edit();
			_getch();
			system("cls");
			break;
		case 6:
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}
}
//-------------------------------------------------------------------------------------------------
int main()
{
	Menu();
	system("pause>0");
	return 0;
}