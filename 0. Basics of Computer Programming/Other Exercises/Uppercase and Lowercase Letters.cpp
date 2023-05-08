#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
int main() {
	int n, i;
	cin >> n;
	char a[10];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] >= 65 && a[i] <= 90)
		{
			a[i] = a[i] + 32;
		}
		else if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] = a[i] - 32;
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}

	return 0;
}
