#include<iostream>
using namespace std;
int main()
{
	int a[100], n, s;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Remove From Array: ";
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == s)
		{
			for (int j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}