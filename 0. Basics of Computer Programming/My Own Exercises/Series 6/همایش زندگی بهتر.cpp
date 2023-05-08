#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a[100][100], r, c;
	cin >> r >> c;

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 20; j++)
			a[i][j] = j;

	for (int i = 1, ii = 10; i <= 10, ii > 0; i++, ii--)
		for (int j = 1, jj = 20; j <= 20, jj > 0; j++, jj--)
			if (i == r && j == c)
				if (j <= 10)
					cout << "Right " << ii << " " << j;
				else
					cout << "Left " << ii << " " << jj;

	return 0;
}