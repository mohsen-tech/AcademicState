#include <iostream>
using namespace std;
int main()
{
	int n, a[100], s = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1 && s; i++)
	{
		if (a[0] < a[1])
			if (a[i] > a[i + 1])
				s = 0;
			else
				s = 2;
		if (a[0] > a[1])
			if (a[i] < a[i + 1])
				s = 0;
			else
				s = 1;
	}
	if (s == 0)
		cout << "Irregular";
	else if (s == 1)
		cout << "Descending";
	else if (s == 2)
		cout << "Ascending";
	return 0;
}