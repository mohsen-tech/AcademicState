#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int l, w, h, a[100];
	for (int i = 1; i <= t; i++)
	{
		cin >> l >> w >> h;
		if (l <= 20 && w <= 20 && h <= 20)
		{
			a[i] = 1;
		}
		else
		{
			a[i] = 0;
		}
	}
	for (int i = 1; i <= t; i++)
	{
		if (a[i] == 1)
		{
			cout << "Case " << i << ": " << "good" << endl;
		}
		else if (a[i] == 0)
		{
			cout << "Case " << i << ": " << "bad" << endl;
		}
	}
	return 0;
}