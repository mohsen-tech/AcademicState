#include<iostream>
using namespace std;
int main() {
	int x, s = 0;
	int a[10];
	cin >> x;
	for (int i = 0; x > 0; i++)
	{
		a[i] = x % 10;
		x = x / 10;
		s++;
	}
	for (int i = s; i > 0; i--)
	{
		cout << a[i - 1] << ": ";
		for (int j = 1; j <= a[i - 1]; j++)
		{
			cout << a[i - 1];
		}
		cout << endl;
	}
return 0;
}