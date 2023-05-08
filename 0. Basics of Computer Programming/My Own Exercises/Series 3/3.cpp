#include <iostream>
using namespace std;
int main()
{
	int n, a = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			a = a + i;
		}
	}
	if (n == a - n)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}