#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a, b, i = 0, c = 0, sum1 = 0, sum2 = 0, c1, c2, j = 0;
	cin >> a >> b;
	while (a > 0)
	{
		c = c + pow(10, i)*(a % b);
		a = a / b;
		i++;
	}
	c1 = c;
	c2 = c;
	while (c)
	{
		j++;
		c = c / 10;
	}
	if (j % 2 == 0)
	{
		c1 = c1 / 10;
		while (c1)
		{
			sum1 = sum1 + c1 % 10;
			c1 = c1 / 100;
		}
		while (c2)
		{
			sum2 = sum2 + c2 % 10;
			c2 = c2 / 100;
		}
	}
	else if (j % 2 == 1)
	{

		while (c1)
		{
			sum1 = sum1 + c1 % 10;
			c1 = c1 / 100;
		}
		c2 = c2 / 10;
		while (c2)
		{
			sum2 = sum2 + c2 % 10;
			c2 = c2 / 100;
		}
	}
	if (sum1 == sum2)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}