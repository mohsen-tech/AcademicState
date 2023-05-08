#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int s[10];
	int a, b, c, d;
	double family, amoney, x;
	for (int i = 1; i <= 5; i++)
	{
		cin >> a >> b >> c;
		family = (a + b) / 3.0;
		x = c / family;
		if (a - family >= family)
		{
			amoney = c;
		}
		else
		{
			amoney = (a - family)*(x);
		}
		d = amoney * 10;
		d = d % 10;
		if (d > 5)
		{
			s[i] = round(amoney);
		}
		else if (d <= 5)
		{
			s[i] = floor(amoney);
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (s[i] < 0)
			cout << 0 << endl;
		else
			cout << s[i] << endl;
	}
	return 0;
}