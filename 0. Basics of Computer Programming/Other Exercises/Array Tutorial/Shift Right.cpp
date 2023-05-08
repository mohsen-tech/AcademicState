#include <iostream>
using namespace std;
int main()
{
	int n, a[100], s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << " :";
	cin >> s;
	int i;
	for (i = 0; a[i] <= s &&i < n; i++);

	for (int j = n + 1; j >= i; j--)
	{
		a[j + 1] = a[j];
	}

	a[i] = s;

	for (int i = 0; i < n + 1; i++)
	{
		cout << a[i] << "\t";
	}
	return 0;
}