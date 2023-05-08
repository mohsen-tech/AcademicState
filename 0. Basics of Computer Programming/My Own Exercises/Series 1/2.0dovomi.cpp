#include <iostream>
using namespace std;
int main()
{
	int month, day, chandomin_roz;

	cout << "\n Pls Enter Month: ";
	cin >> month;
	cout << "\n Pls Enter Day: ";
	cin >> day;

	if (day <= 0 || month <= 0)
	{
		cout << "\n Dadach Dari Eshtebah Mizni -_- " << "\n";
	}
	else
	{
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Hasti" << "\n";
	}

	return 0;
	}