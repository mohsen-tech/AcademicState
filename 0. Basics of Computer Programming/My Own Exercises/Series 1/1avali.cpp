#include <iostream>
#include <conio.h>
#define PI 3.1415926536
using namespace std;
int main()
{
	double radius, area, perime;

	cout << "\n Pls Enter Radius Of Circle: ";
	cin >> radius;

	area = PI*radius*radius;
	perime = 2 * PI*radius;

	cout << "\n Area= " << area << "\n Perime= " << perime << "\n";

	return 0;
}