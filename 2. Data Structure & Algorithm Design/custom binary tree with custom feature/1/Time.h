#include "Function.h"
using namespace std;
class Time
{
	friend ostream & operator << (ostream &, const Time &);
	friend istream & operator >> (istream &, Time &);
private:
	int date, month, year;
public:
	void setTime(int _date, int _month, int _year)
	{
		date = _date; month = _month; year = _year;
	}
	bool operator == (const Time & right)
	{
		if (this->date == right.date && this->month == right.month && this->year == right.year)
			return true;
		return false;
	}
};
istream & operator >> (istream & in, Time & obj)
{
	in >> obj.date >> obj.month >> obj.year;
	return in;
}
ostream & operator << (ostream & out, const Time & obj)
{
	if (file_flag == true)
		out << obj.date << "\n" << obj.month << "\n" << obj.year;
	else
		out << obj.year << "/" << obj.month << "/" << obj.date;
	return out;
}