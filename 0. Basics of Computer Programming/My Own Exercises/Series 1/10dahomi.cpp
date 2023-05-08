#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c, d, sum, avg, pro;

	
	cout << "\n Pls Enter A: ";
	cin >> a;
	cout << "\n Pls Enter B: ";
	cin >> b;
	cout << "\n Pls Enter C: ";
	cin >> c;
	cout << "\n Pls Enter D: ";
	cin >> d;

	sum = a + b + c + d;
	avg = sum / 4;
	pro = a * b * c * d;

	cout << "\n {" << "\n Sum: " << sum << "\n Aeragevg: " << avg << "\n Product: " << pro << "\n }" << "\n";

	return 0;
}