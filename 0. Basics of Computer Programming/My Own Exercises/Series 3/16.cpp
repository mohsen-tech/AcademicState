#include <iostream>
using namespace std;
int main()
{
	int a = 0, n, m;
	cin >> n;
	m = n;
	while (n)
	{
		a = a * 10 + (n % 10);
		n = n / 10;
	}
	if (a == m)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}