#include <iostream>
using namespace std;
int main()
{
	int n, m, a = 0, i = 0;
	cin >> m >> n;
	while (m)
	{
		a = m % 10;
		m = m / 10;

		if (a == n)
		{
			i = i + 1;
		}

	}
	cout << i;
	return 0;
}