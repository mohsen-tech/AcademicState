#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	int n, a[3000], b[3000], jolly, s;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
			b[i - 1] = abs(a[i] - a[i - 1]);
		jolly = 1;
		for (int i = 1; i <= n - 1 && jolly; i++)
		{
			s = 1;
			for (int j = 0; j < n - 1 && s; j++)
				if (b[j] == i)
					s = 0;
			if (s == 1)
				jolly = 0;
		}
		if (jolly == 1)
			cout << "Jolly";
		else if (jolly == 0)
			cout << "Not jolly";
	}
	return 0;
}