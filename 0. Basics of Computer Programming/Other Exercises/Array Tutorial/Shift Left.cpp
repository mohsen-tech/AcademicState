#include <iostream>
using namespace std;
int main()
{
	int n, a[100], s, k = -10;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << " :";
	cin >> s;

	for (int i = 0; i < n; i++)
		if (a[i] == s)
		{
			k = i;
			n -= 1;
		}

	if (k != -10)
		for (int i = k; i < n; i++)
			a[i] = a[i + 1];

	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";

	return 0;
}