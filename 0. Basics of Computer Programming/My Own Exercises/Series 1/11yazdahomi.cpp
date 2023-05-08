#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c, d;

	cout << "\n [ (A^2+B) / C-D ] - [ (B/A) - (A/(D*C)) ]" << "\n";

	cout << "\n Pls Enter A: ";
	cin >> a;
	cout << "\n Pls Enter B: ";
	cin >> b;
	cout << "\n Pls Enter C: ";
	cin >> c;
	cout << "\n Pls Enter D: ";
	cin >> d;

	cout << "\n Answer Is: " << ((a*a + b) / (c - d)) - ((b / a) - (a / (d*c))) << "\n";

	return 0;
}