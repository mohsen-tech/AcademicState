#include <iostream>
using namespace std;
void Cin(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
int main()
{
	int n, a[10000], b[10000], c[10000], cnt = 0;
	cin >> n;
	Cin(a, n);
	Cin(b, n);
	Cin(c, n);
	for (int i = 0; i < n; i++)
	{
		int sw = 1;
		for (int j = 0; j < n && sw; j++)
		{
			if (a[i] == b[j])
				for (int k = 0; k < n; k++)
					if (a[i] == c[k])
					{
						sw = 0;
					}
		}
		if (sw == 1)
		{
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
			cnt++;
			i = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}