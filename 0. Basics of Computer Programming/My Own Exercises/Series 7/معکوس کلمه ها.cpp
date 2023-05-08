#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[100];
	cin.getline(s, 100);
	int i;
	for (i = 0; s[i]; i++);
	for (int j = i - 1; j >= 0; j--)
	{
		if (s[j] == ' ')
		{
			cout << endl;
		}
		else
		{
			cout << s[j];
		}
	}
	return 0;
}