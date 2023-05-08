#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int p, d;
	cin >> p >> d;
	int sw = 1, d1 = d;
	for (int i = 0;sw; i++)
	{
		if (0 <= d%p && d%p <= p / 2)
			sw = 0;
		else
			d = d + d1;
	}
	cout << d;
	return 0;
}