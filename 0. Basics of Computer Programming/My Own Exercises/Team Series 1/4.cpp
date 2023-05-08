#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n / 100 < 10 && n % 100 < 10)
	{
		cout << "saal:" << 0 << n / 100 << endl << "maah:" << 0 << n % 100;
	}
	else if (n / 100 < 10)
	{
		cout << "saal:" << 0 << n / 100 << endl << "maah:" << n % 100;
	}
	else if (n % 100 < 10)
	{
		cout << "saal:" << n / 100 << endl << "maah:" << 0 << n % 100;
	}
	else
	{
		cout << "saal:" << n / 100 << endl << "maah:" << n % 100;
	}
	return 0;
}