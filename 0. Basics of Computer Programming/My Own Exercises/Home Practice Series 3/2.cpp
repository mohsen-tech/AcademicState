#include <iostream>
using namespace std;
int main()
{
	int n, a[100], imax, sw, cnta = 0, cntb = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sw = 1;
	for (int i = 0; i < n - 1 && sw; i++)
	{
		if (a[0] < a[1])
			if (a[i] > a[i + 1])
			{
				sw = 0;
				imax = i;
				cnta++;
			}
	}
	sw = 1;
	for (int i = n - 1; i > imax && sw; i--)
	{
		if (a[n - 2] > a[n - 1])
			if (a[i] < a[i - 1])
			{
				sw = 0;
				cntb++;
			}
	}
	if (cnta == 1 && cntb == 1)
		cout << "Yes";
	else cout << "No";
	return 0;
}