#include <iostream>
using namespace std;
int main()
{
	unsigned long long int n, m, i = 0;
	cin >> n >> m;
	while (n)
	{
		if (n % 10 == m)
		{
			i = i + 1;
		}
		n = n / 10;
	}
	cout << i;
	return 0;
}