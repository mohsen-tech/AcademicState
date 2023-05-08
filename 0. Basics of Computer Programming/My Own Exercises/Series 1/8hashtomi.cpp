#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int i, n, day, saat, min, sec;
	cout << "\n Pls Enter Year: ";
	cin >> n;

	i = n / 4;
	day = n * 365 + i;
	saat = day * 24;
	min = saat * 60;
	sec = min * 60;
	
	cout << "\n " << saat << " Hour  " << min << " Min  " << sec << " Sec  " << "\n";

	return 0;
}