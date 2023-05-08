#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int month, day, chandomin_roz;

	cout << "\n Pls Enter Month: ";
	cin >> month;
	cout << "\n Pls Enter Day: ";
	cin >> day;

	if (day <= 0)
	{
		cout << "\n Dadach Dari Eshtebah Mizni -_- ";
	}
	else if (day<=30)
	{

	
	if (month <= 0)
	{
		cout << "\n Dadach Dari Eshtebah Mizni -_- ";
	}
	else if (month == 1){
		chandomin_roz = (month - 1) * 30 + day;
	cout << "\n Shoma Dar Roze "<<chandomin_roz<<" Sal Va Dar Mahe Farvardin Hasti";
	}
	else if (month == 2) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Ordibehesht Hasti";
	}
	else if (month == 3) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Khordad Hasti";
	}
	else if (month == 4) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Tir Hasti";
	}
	else if (month == 5) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Mordad Hasti";
	}
	else if (month == 6) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Shahrivar Hasti";
	}
	else if (month == 7) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Mehr Hasti";
	}
	else if (month == 8) {
		chandomin_roz = (month - 1) * 30 + day; 
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Aban Hasti";
	}
	else if (month == 9) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Azar Hasti";
	}
	else if (month == 10) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Dey Hasti";
	}
	else if (month == 11) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Bahman Hasti";
	}
	else if (month == 12) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " Sal Va Dar Mahe Esfand Hasti";
	}
	else if (month >= 2) {
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Shoma Dar Roze " << chandomin_roz << " hasti";
	}
	}
	else if (day>30)
	{
		chandomin_roz = (month - 1) * 30 + day;
		cout << "\n Bara Bishtar Az 30 Roz Dorost Tarif Nashode Vali " << chandomin_roz << " Bfrma";
	}

	cout << "\n\n";

	return 0;
}