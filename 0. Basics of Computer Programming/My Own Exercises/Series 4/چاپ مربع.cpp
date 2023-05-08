#include<iostream>
using namespace std;
int main() {
	int x, s = 0;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == x - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}

		}
		cout << endl;
	}
return 0;

}