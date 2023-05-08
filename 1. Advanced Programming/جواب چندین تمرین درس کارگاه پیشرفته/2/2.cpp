#include <iostream>
#include <string>
using namespace std;
// <in.txt> out.txt
void f(const string & str, string ans, int index)
{
	if (index == str.size())
	{
		cout << "{ ";
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
			if (i < ans.size() - 1)
				cout << " , ";
		}
		cout << " }\n";
		return;
	}
	f(str, ans, index + 1);
	f(str, ans + str[index], index + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;
	f(str, "", 0);

	system("pause>0");
	return 0;
}