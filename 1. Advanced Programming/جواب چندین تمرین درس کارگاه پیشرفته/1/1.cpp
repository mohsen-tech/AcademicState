#include <iostream>
#include <string>
#include <vector>
using namespace std;
// <in.txt> out.txt
int main()
{
	ios_base::sync_with_stdio(false);

	string str;
	vector <char> res;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '(' || str[i] == ')')
			res.push_back(str[i]);

	for (int i = 0; i < res.size(); i++)
		cout << res[i];

	system("pause>0");
	return 0;
}