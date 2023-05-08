#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[100][100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int k, l;
			for (k = 0; s[i][k]; k++);
			for (l = 0; s[j][l]; l++);
			if (l > k)
				swap(s[i], s[j]);
		}
	}
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	return 0;
}