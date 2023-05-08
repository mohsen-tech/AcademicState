#include <iostream>
#include <string>
using namespace std;
// <in.txt> out.txt
class PersonnelInfo
{
public:
	PersonnelInfo() { }
	void setIncome(const double & _income)
	{
		if (_income < 2000000)
			this->income = _income + (_income / 5);

		this->income = _income - ((15 / 100) * _income);
	}
	void setName(const string & _name)
	{
		this->name = _name;
	}
	void setFamily(const string & _family)
	{
		this->family = _family;
	}
	void setMelliCode(const int & _melliCode)
	{
		this->melliCode = _melliCode;
	}
	void setYear(const int & _year)
	{
		this->year = _year;
	}
	double getIncome() const
	{
		return this->income;
	}
private:
	string name, family;
	int melliCode, year;
	double income;
};
int main()
{
	ios_base::sync_with_stdio(false);

	PersonnelInfo temp;
	string name, family;
	int melliCode, year;
	double income;
	cin >> name >> family >> melliCode >> year >> income;
	temp.setName(name);
	temp.setFamily(family);
	temp.setMelliCode(melliCode);
	temp.setYear(year);
	temp.setIncome(income);
	cout << temp.getIncome() << "\n";

	system("pause>0");
	return 0;
}