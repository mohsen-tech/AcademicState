#include <iostream>
#include <stack>
#include <string>
using namespace std;
// <in.txt> out.txt


//---------------------------------------
char getSymmetricalDNA(const char & _ch)
{
	if (_ch == 'T')
		return 'A';
	if (_ch == 'A')
		return 'T';
	if (_ch == 'G')
		return 'C';
	if (_ch == 'C')
		return 'G';
}
bool isSymmetricalDNA(stack <char> & _DNA)
{
	stack <char> temp;
	int DNA_size = _DNA.size();
	for (int i = 0; i < DNA_size; i++)
	{
		int j = 0;
		for (j = 0; j < i; j++)
		{
			temp.push(_DNA.top());
			_DNA.pop();
		}
		char ch = getSymmetricalDNA(_DNA.top());
		while (j--)
		{
			_DNA.push(temp.top());
			temp.pop();
		}
		temp.push(ch);
	}
	bool flag = false;
	if (temp.size() == _DNA.size())
	{
		flag = true;
		while (temp.empty() == false)
		{
			if (temp.top() != _DNA.top())
			{
				flag = false;
				return false;
			}
			temp.pop();
			_DNA.pop();
		}
	}
	if (flag == true)
		return true;
	return false;
}
//---------------------------------------


int main()
{
	//ios_base::sync_with_stdio(false);
	//ios::sync_with_stdio(false), cin.tie(0);
	string input;
	while (cin >> input)
	{
		stack <char> DNA;
		if (input == "0")
		{
			cout << "End\n";
			return 0;
		}
		for (int i = 0; i < input.size(); i++)
			DNA.push(input[i]);

		if (isSymmetricalDNA(DNA) == true)
			cout << "True\n";
		else
			cout << "False\n";
	}
	//system("pause>0");
	return 0;
}