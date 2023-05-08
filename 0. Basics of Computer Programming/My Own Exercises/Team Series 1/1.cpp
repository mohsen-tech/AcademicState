#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;
	int x, y;
	if (b <= 6)
	{
		x = a + ((b - 1) * 31);
	}
	else if (7 <= b <= 12)
	{
		x = a + ((b - 1) * 30) + 6;
	}
	if (d <= 6)
	{
		y = c + ((d - 1) * 31);
	}
	else if (7 <= d <= 12)
	{
		y = c + ((d - 1) * 30) + 6;
	}
	cout << y - x;
	return 0;
}