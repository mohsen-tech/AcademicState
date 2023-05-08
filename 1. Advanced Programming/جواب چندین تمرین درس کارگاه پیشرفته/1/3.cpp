#include <iostream>
#include <string>
using namespace std;
// <in.txt> out.txt
int main()
{
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
		if (str[i] == ' ')
			str[i] = '*';

	cout << str;

	system("pause>0");
	return 0;
}