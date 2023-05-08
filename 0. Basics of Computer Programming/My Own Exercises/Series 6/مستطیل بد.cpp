#include <iostream>
using namespace std;
int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j++)
			for (int k = j; k < n; k++)
				if (i + j + k == n && i + j > k && i + k > j && k + j > i)
					cnt++;
	cout << cnt << endl;
	return 0;
}