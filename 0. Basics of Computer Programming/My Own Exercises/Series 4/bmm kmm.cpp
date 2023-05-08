#include<iostream>
using namespace std;
int main()
{
	long long int a, b, c, n, m;
	cin >> a >> b;
	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	n = a;
	m = b;
	while (b > 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	cout << a << " " << n*m / a;
	return 0;
}