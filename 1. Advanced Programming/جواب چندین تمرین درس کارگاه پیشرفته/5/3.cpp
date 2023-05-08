#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// <in.txt> out.txt

class Student
{
	friend istream & operator >> (istream &, Student &);
	friend ostream & operator << (ostream &, const Student &);
	friend bool compare(const Student &, const  Student &);
public:
	bool fired()
	{
		if (this->year % 100 < 95 && this->avg < 14)
			return true;
		return false;
	}
private:
	string name, family;
	int ID, year;
	float avg;
};
istream & operator >> (istream & in, Student & _obj)
{
	in >> _obj.name >> _obj.family >> _obj.ID >> _obj.avg >> _obj.year;
	return in;
}
ostream & operator << (ostream & out, const Student & _obj)
{
	out << _obj.name << "\n" << _obj.family << "\n" << _obj.ID << "\n" << _obj.avg << "\n" << _obj.year << "\n";
	return out;
}
bool compare(const Student & i1, const Student & i2)
{
	return (i1.avg > i2.avg);
}
int main()
{
	ios_base::sync_with_stdio(false);

	vector <Student> students;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Student temp;
		cin >> temp;
		students.push_back(temp);
	}
	sort(students.begin(), students.end(), compare);
	cout << "A:\n";
	for (int i = 0; i < students.size(); i++)
		if (students[i].fired() == true)
			cout << students[i] << "\n";

	cout << "\nB:\n";
	for (int i = 0; i < 3 && i < students.size(); i++)
		cout << students[i] << "\n";

	system("pause>0");
	return 0;
}