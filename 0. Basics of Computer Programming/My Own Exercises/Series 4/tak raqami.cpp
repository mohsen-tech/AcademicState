#include<iostream>
using namespace std;
int main() {
	long long unsigned int adad, s;
	cin >> adad;
	for (int i = 1; adad >= 10; i++)
	{
		s = 0;
		while (adad)
		{
			s = s + adad % 10;
			adad = adad / 10;
		}

		adad = s;

	}
	cout << adad;
	return 0;
}