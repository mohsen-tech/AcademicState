#include <iostream>
using namespace std;
int main()
{
	int month, day, chandomin_roz;
	cout << "Pls Enter Month: ";
	cin >> month;
	cout << "\nPls Enter Day: ";
	cin >> day;
	if (day <= 0 || month <= 0)
	{
		cout << "\nDadach Dari Eshtebah Mizni -_- " << "\n";
	}
	else
	{
		chandomin_roz = (month - 1) * 31 + day;
		cout << "\nShoma Dar Roze " << chandomin_roz << " Sal Hasti" << "\n";
	}
	return 0;
}