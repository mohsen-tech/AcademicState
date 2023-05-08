#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;
	int e, f;
	cin >> e >> f;
	if (a == c)
	{
		if (b == d)
		{
			cout << e << " " << f;
		}
		else if (b == f)
		{
			cout << e << " " << d;
		}
		else if (d == f)
		{
			cout << e << " " << b;
		}
	}
	else if (a == e)
	{
		if (b == d)
		{
			cout << c << " " << f;
		}
		else if (b == f)
		{
			cout << c << " " << d;
		}
		else if (d == f)
		{
			cout << c << " " << b;
		}
	}
	else if (c == e)
	{
		if (b == d)
		{
			cout << a << " " << f;
		}
		else if (b == f)
		{
			cout << a << " " << d;
		}
		else if (d == f)
		{
			cout << a << " " << b;
		}
	}
	return 0;
}