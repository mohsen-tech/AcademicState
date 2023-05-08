#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string makeMinNumber(int len, int sum) 
{
	string number(len, '0');
	number[0] = '1';
	int remain_sum = sum - 1;
	for (int i = len - 1; i >= 0; --i) 
	{
		if (remain_sum > 0) 
		{
			int digit = min(9, remain_sum);
			remain_sum -= digit;
			if (number[i] == '1')
				digit += 1;
			number[i] = digit + '0'; // +'0' for convert char to digit
		}
	}
	return number;
}

string makeMaxNumber(int len, int sum) 
{
	string number(len, '0');
	int remain_sum = sum;
	for (int i = 0; i < len; ++i) 
	{
		if (remain_sum > 0) 
		{
			int digit = min(9, remain_sum);
			remain_sum -= digit;
			number[i] = digit + '0'; // +'0' for convert char to digit
		}
	}
	return number;
}


int main()
{
	int m, s;
	cin >> m >> s;

	if (m == 1 && s == 0)
		cout << "0 0";
	else if (s > m * 9 || s == 0)
		cout << "-1 -1";
	else
		cout << makeMinNumber(m, s) << " " << makeMaxNumber(m, s) << endl;
	return 0;
}