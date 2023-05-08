#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << "Pls Enter X: ";
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "Result Of 2X+5: " << 2 * a + 5 << "\n";
	}
	else if (a % 2 == 1)
	{
		cout << "Result Of 2X-5: " << 2 * a - 5 << "\n";
	}

	return 0;
}