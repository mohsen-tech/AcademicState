#include <iostream>
using namespace std;
int main()
{
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j])
			{
				for (int k = j; k < n; k++)
					a[k] = a[k + 1];
				n--;
				i--;
			}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}