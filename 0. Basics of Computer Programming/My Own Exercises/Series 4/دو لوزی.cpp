#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	n = (n + 1) / 2;
	int a = n - 1, b = n - 1, c = n - 1;
	for (int i = 1;i <= 2 * n - 1;i += 2) {
		for (int i = 1;i <= a;i++)
			cout << " ";
		for (int j = 1;j <= i;j++)
			cout << "*";
		for (int i = 1;i <= b;i++)
			cout << " ";
		for (int i = 1;i <= c;i++)
			cout << " ";
		for (int k = 1;k <= i;k++)
			cout << "*";
		cout << endl;
		a--;
		b--;
		c--;
	}
	int d = 1, e = 1, f = 1;
	for (int i = 2 * n - 3;i >= 1;i -= 2) {
		for (int i = 1;i <= d;i++)
			cout << " ";
		for (int j = 1;j <= i;j++)
			cout << "*";
		for (int i = 1;i <= e;i++)
			cout << " ";
		for (int i = 1;i <= f;i++)
			cout << " ";
		for (int k = 1;k <= i;k++)
			cout << "*";
		cout << endl;
		e++;
		f++;
		d++;
	}
	return 0;
}