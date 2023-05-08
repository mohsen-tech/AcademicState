#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << "Pls Enter a Number: ";
	cin >> a;
	if (a > 0)
	{
		cout << "Result: " << 2 * a + 1 << "\n";
	}
	else if (a == 0)
	{
		cout << "Result: " << 2 << "\n";
	}
	else if (a < 0)
	{
		cout << "Result: " << 3 * a - 5 << "\n";
	}

	return 0;
}