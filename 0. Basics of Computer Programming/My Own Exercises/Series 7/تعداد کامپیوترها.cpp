#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[100][100], a[10] = { 'c','o','m','p','u','t','e','r' };
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(s[i], a) == 0)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}