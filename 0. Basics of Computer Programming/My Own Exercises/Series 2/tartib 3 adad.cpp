#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "Pls Enter Number1: ";
	cin >> a;
	cout << "Pls Enter Number2: ";
	cin >> b;
	cout << "Pls Enter Number3: ";
	cin >> c;

	if (a > b&&b > c)
	{
		cout << c << "\t" << b << "\t" << a << "\n";
	}
	else if (c > b&&b > a)
	{
		cout << a << "\t" << b << "\t" << c << "\n";

	}
	else if (b > a&&a > c)
	{
		cout << c << "\t" << a << "\t" << b << "\n";
	}
	else if (a > c&&c > b)
	{
		cout << b << "\t" << c << "\t" << a << "\n";
	}
	else if (c > a&&a > b)
	{
		cout << b << "\t" << a << "\t" << c << "\n";
	}
	else if (b > c&&c > a)
	{
		cout << a << "\t" << c << "\t" << b << "\n";
	}


	return 0;
}