#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "Pls Enter a,b,c \n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	if (a + b > c && a + c > b && c + b > a)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";

	}

	return 0;
}