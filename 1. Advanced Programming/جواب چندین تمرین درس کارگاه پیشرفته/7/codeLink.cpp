#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// <in.txt> out.txt
class Student
{
	friend istream & operator >> (istream &, Student &);
	friend ostream & operator << (ostream &, const Student &);
public:
	Student()
	{
		this->avgs.resize(4);
	}
	~Student()
	{
		this->name.clear();
		this->family.clear();
		this->collegeName.clear();
		this->reshte.clear();
		this->avgs.clear();
	}
	float calcAvg() const
	{
		float sum = 0;
		for (int i = 0; i < this->avgs.size(); i++)
			sum += this->avgs[i];
		return sum / this->avgs.size();
	}
	bool checkID() const
	{
		int temp = this->ID / (pow(10, this->lenOfNumber(this->ID) - 2));
		if (95 <= temp && temp <= 99)
			return true;
		return false;
	}
	string getReshte() const
	{
		return this->reshte;
	}
	string getCollegeName() const
	{
		return this->collegeName;
	}
	bool A() const
	{
		if (this->term == 8 && this->calcAvg() >= 17.0)
			return true;
		return false;
	}
	bool B() const
	{
		if (this->calcAvg() >= 19.0 && this->year % 100 >= 97)
			return true;
		return false;
	}
	bool C() const
	{
		if (this->reshte == "computer" && this->year == 1399 && this->calcAvg() >= 19.0)
			return true;
		return false;
	}
private:
	string name, family, collegeName, reshte;
	int ID, year, term;
	vector <float> avgs;
	int lenOfNumber(int n) const
	{
		int cnt = 0;
		while (n)
		{
			cnt++;
			n /= 10;
		}
		return cnt;
	}
};
istream & operator >> (istream & in, Student & _obj)
{
	cout << "name: ";
	in >> _obj.name;
	cout << "family: ";
	in >> _obj.family;
	cout << "shomare daneshjoei: ";
	in >> _obj.ID;
	cout << "name daneshkade: ";
	in >> _obj.collegeName;
	cout << "reshte: ";
	in >> _obj.reshte;
	cout << "sale vorod: ";
	in >> _obj.year;
	cout << "term tahsili: ";
	in >> _obj.term;
	cout << "moAdele 4term akhir:\n";
	for (int i = 0; i < _obj.avgs.size(); i++)
	{
		cout << i << ": ";
		in >> _obj.avgs[i];
	}
	cout << "-------------------------------------------------------------\n";
	return in;
}
ostream & operator << (ostream & out, const Student & _obj)
{
	out << "name: " << _obj.name << "\n";
	out << "family: " << _obj.family << "\n";
	out << "shomare daneshjoei: " << _obj.ID << "\n";
	out << "reshte: " << _obj.reshte << "\n";
	return out;
}
//-------------------------------------------------------------------------------------------------
bool compare1(const Student & i1, const Student & i2)
{
	return (i1.getReshte() > i2.getReshte());
}
bool compare2(const Student & i1, const Student & i2)
{
	return (i1.getCollegeName() > i2.getCollegeName());
}
//-------------------------------------------------------------------------------------------------
void A(const vector <Student> & students)
{
	int startIdx = 0;
	string a = students[0].getReshte(), b;
	for (int i = 0; i < students.size(); i++)
	{
		b = students[i].getReshte();
		if (a != b)
		{
			auto start = students.begin() + startIdx;
			auto end = students.begin() + i + 1;
			vector <Student> result(i - startIdx + 1);
			copy(start, end, result.begin());

			sort(result.begin(), result.end(), compare2);

			for (int j = 0; j < result.size(); j++)
				if (result[i].A() == true)
					cout << result[i] << "\n";
			cout << "-------------------------------------------------------------\n";

			startIdx = i;
			a = b;
		}
	}
}
void B(const vector <Student> & students)
{
	for (int i = 0; i < students.size(); i++)
		if (students[i].B() == true)
			cout << students[i] << "\n";
}
void C(const vector <Student> & students)
{
	for (int i = 0; i < students.size(); i++)
		if (students[i].C() == true)
			cout << students[i] << "\n";
}
//-------------------------------------------------------------------------------------------------
int main()
{
	ios_base::sync_with_stdio(false);

	vector <Student> students;
	int n;
	cout << "tedad daneshjoyan: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Student temp;
		cin >> temp;
		if (temp.checkID() == true)
			students.push_back(temp);
		else
		{
			cout << "< !Invalid ID > | try again . . .\n";
			i--;
		}
	}
	sort(students.begin(), students.end(), compare1);
	cout << "A:\n";
	A(students);
	cout << "-------------------------------------------------------------\n";
	cout << "B:\n";
	B(students);
	cout << "-------------------------------------------------------------\n";
	cout << "C:\n";
	C(students);

	system("pause>0");
	return 0;
}