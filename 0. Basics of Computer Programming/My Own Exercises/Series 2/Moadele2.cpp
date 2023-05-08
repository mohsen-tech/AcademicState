#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c, delta;

	cout << "\n Ax^2+Bx+C=0 " << endl;

	cout << "\n Pls Enter A: ";
	cin >> a;
	cout << "\n Pls Enter B: ";
	cin >> b;
	cout << "\n Pls Enter C: ";
	cin >> c;

	cout << "\n " << a << "x^2+" << b << "x+" << c << "=0" << "\n";

	delta = (b*b) - (4 * a*c);

	cout << "\n Delta= " << delta << "\n";

	if (delta >= 0)
	{
		double x1 = ((-b) + (sqrt(delta))) / (2 * a);
		double x2 = ((-b) - (sqrt(delta))) / (2 * a);
		cout << "\n " << x1 << " va " << x2 << "\n";
	}
	else if (delta < 0)
	{
		delta = abs(delta);
		double x11 = (-b) / (2 * a);
		double x22 = (sqrt(delta)) / (2 * a);
		cout << "\n Ghablan Migoftan Rishe Ndre Vali ==> "
			<< x11 << "+" << x22 << "i" << " va " << x11 << "-" << x22 << "i" "\n";
	}
	cout << "\n";

	return 0;
}