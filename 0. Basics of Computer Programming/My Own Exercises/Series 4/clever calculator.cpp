#include<iostream>
using namespace std;
int main()
{
	int n, a, s[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		a = ((((((a * 567) / 9) + 7492) * 235) / 47) - 498);
		a = a % 100;
		a = a / 10;
		s[i] = a % 10;
	}
	for (int i = 0; i < n; i++)
	{
		cout << abs(s[i]) << endl;
	}
	return 0;
}