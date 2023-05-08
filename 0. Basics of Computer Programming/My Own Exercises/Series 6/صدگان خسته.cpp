#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, m, nn, mm, cnt = 0, swa = 1, swb = 1;
	cin >> n >> m;
	nn = n;
	mm = m;
	while (nn && mm)
	{
		if (nn % 10 == mm % 10)
			cnt++;
		else if (nn % 10 > mm % 10)
		{
			swa = 0;
			break;
		}
		else if (nn % 10 < mm % 10)
		{
			swb = 0;
			break;
		}
		nn = nn / 10;
		mm = mm / 10;
	}
	if (cnt == 3)
	{
		cout << m << " = " << n;
	}
	else if (swa == 0)
	{
		cout << m << " < " << n;
	}
	else if (swb == 0)
	{
		cout << n << " < " << m;
	}
	return 0;
}