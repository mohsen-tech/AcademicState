#include <iostream>
#include <algorithm>
using namespace std;
int A[100001], B[100001], C[100001], a[100001], b[100001], c[100001], Index[100001];
int main()
{
	int n, cnt = 0;
	//cin >> n;
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		//cin >> a[i];
		A[a[i]]++;
		Index[a[i]] = i;
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		//cin >> b[i];
		B[b[i]]++;
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		//cin >> c[i];
		C[c[i]]++;
	}
	for (size_t i = 1; i <= n; i++)
	{
		if (A[i])
		{
			if (!(C[i] && B[i]))
			{
				int index = Index[i];
				A[a[index]]--;
				B[b[index]]--;
				C[c[index]]--;
				i = min(a[index], min(b[index], c[index])) - 1;
				a[index] = 0;
				b[index] = 0;
				c[index] = 0;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	//cout << cnt;
	return 0;
}