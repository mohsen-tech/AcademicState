//Mahdi Monazzami
#include <cstdio>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>  
#include <locale> 
#include <stack>
#include <sstream>
using namespace std;
//-----------------------------------------------------------------------------------------
class Fix
{
public:
	Fix(char ch[])
	{
		Translate(ch);
	}
	//-----------------------------------------------------------------------------------------
	int Opt(char ch) // Operations 
	{
		if (ch == '^')
			return 3;
		else if (ch == '*' || ch == '/')
			return 2;
		else if (ch == '+' || ch == '-')
			return 1;
		else
			return -1;
	}
	//-----------------------------------------------------------------------------------------
	char * RmvSpace(char *s, int &j) // Remove The Space From Input
	{
		int length = strlen(s);
		j = 0;
		char * result = new char[100];
		for (int i = 0; i < length; i++)
			if (s[i] != ' ')
				result[j++] = s[i];
		result[j] = NULL;
		return result;
	}
	//-----------------------------------------------------------------------------------------
	int Digit(int n) // FindOut DigitSum Of Number
	{
		int sum = 0;
		while (n)
		{
			sum++;
			n /= 10;
		}
		return sum;
	}
	//-----------------------------------------------------------------------------------------
	void CreateNum(char * s, int a[][3], int &j) // Create Number From Input
	{
		int length, start, end;
		j = 0;
		string test = RmvSpace(s, length);
		bool sw = 0;

		for (int i = 0; i <= length; i++)
		{
			if (sw == 0 && '0' <= test[i] && test[i] <= '9')
			{
				start = i;
				sw = 1;
			}
			else if (sw == 1 && !('0' <= test[i] && test[i] <= '9'))
			{
				end = i;
				a[j][0] = stoi(test.substr(start, end));
				if (a[j][0] == 0)
					a[j++][1] = 1;
				else
					a[j++][1] = Digit(a[j][0]);
				sw = 0;
			}
		}
	}
	//-----------------------------------------------------------------------------------------
	void Translate(char * s) // Convert Infix To Postfix And Prefix
	{
		stack <char> st;
		st.push('N');
		int length;
		string test = RmvSpace(s, length), ans;


		for (int i = 0; i < length; i++)
		{
			if (('0' <= test[i] && test[i] <= '9'))
			{
				ans += test[i];
			}
			else if (test[i] == '(')
			{
				st.push('(');
			}
			else if (test[i] == ')')
			{
				while (st.top() != 'N' && st.top() != '(')
				{
					char c = st.top();
					st.pop();
					ans += c;
				}
				if (st.top() == '(')
				{
					char c = st.top();
					st.pop();
				}
			}
			else {
				while (st.top() != 'N' && Opt(test[i]) <= Opt(st.top()))
				{
					char c = st.top();
					st.pop();
					ans += c;
				}
				st.push(test[i]);
			}
		}

		while (st.top() != 'N')
		{
			char c = st.top();
			st.pop();
			ans += c;
		}

		/* Test
		cerr << ans << endl; */

		int a[100][3], j;
		CreateNum(s, a, j);

		/* Test
		for (size_t i = 0; i < j; i++)
		cerr << a[i][0] << " " << a[i][1] << endl; */

		int len = ans.length();

		for (int i = 0; i < len; i++) // Nano String Processing :)
		{
			int cnt = 0, k = 0;

			if (ans[i] == '^')
			{
				while (cnt < i)
				{
					cnt += a[k++][1];
				}
				int start = i - (a[k - 1][1] + a[k - 2][1]);
				int end = i;
				int sum = pow(a[k - 2][0], a[k - 1][0]);
				a[k - 1][0] = sum;
				a[k - 2][2] = -1;
				if (sum < 0)
					sum = -1 * sum;

				if (a[k - 1][0] == 0)
					a[k - 1][1] = 1;
				else
					a[k - 1][1] = Digit(a[k - 1][0]);

				for (int ii = 0; ii < j; ii++)
				{
					if (a[ii][2] == -1)
					{
						for (int jj = ii; jj < j; jj++)
						{
							a[jj][0] = a[jj + 1][0];
							a[jj][1] = a[jj + 1][1];
							a[jj][2] = a[jj + 1][2];
						}
						j--;
					}
				}
				ostringstream convert;
				string Result;
				convert << sum;
				Result = convert.str();

				ans = ans.substr(0, start) + Result + ans.substr(i + 1, length);

				len = ans.length();
				i = 0;
			}

			else if (ans[i] == '*')
			{
				while (cnt < i)
				{
					cnt += a[k++][1];
				}
				int start = i - (a[k - 1][1] + a[k - 2][1]);
				int end = i;
				int sum = a[k - 2][0] * a[k - 1][0];
				a[k - 1][0] = sum;
				a[k - 2][2] = -1;
				if (sum < 0)
					sum = -1 * sum;

				if (a[k - 1][0] == 0)
					a[k - 1][1] = 1;
				else
					a[k - 1][1] = Digit(a[k - 1][0]);

				for (int ii = 0; ii < j; ii++)
				{
					if (a[ii][2] == -1)
					{
						for (int jj = ii; jj < j; jj++)
						{
							a[jj][0] = a[jj + 1][0];
							a[jj][1] = a[jj + 1][1];
							a[jj][2] = a[jj + 1][2];
						}
						j--;
					}
				}
				ostringstream convert;
				string Result;
				convert << sum;
				Result = convert.str();

				ans = ans.substr(0, start) + Result + ans.substr(i + 1, length);

				len = ans.length();
				i = 0;
			}

			else if (ans[i] == '/')
			{
				while (cnt < i)
				{
					cnt += a[k++][1];
				}
				int start = i - (a[k - 1][1] + a[k - 2][1]);
				int end = i;
				int sum = a[k - 2][0] / a[k - 1][0];
				a[k - 1][0] = sum;
				a[k - 2][2] = -1;
				if (sum < 0)
					sum = -1 * sum;

				if (a[k - 1][0] == 0)
					a[k - 1][1] = 1;
				else
					a[k - 1][1] = Digit(a[k - 1][0]);

				for (int ii = 0; ii < j; ii++)
				{
					if (a[ii][2] == -1)
					{
						for (int jj = ii; jj < j; jj++)
						{
							a[jj][0] = a[jj + 1][0];
							a[jj][1] = a[jj + 1][1];
							a[jj][2] = a[jj + 1][2];
						}
						j--;
					}
				}
				ostringstream convert;
				string Result;
				convert << sum;
				Result = convert.str();

				ans = ans.substr(0, start) + Result + ans.substr(i + 1, length);

				len = ans.length();
				i = 0;
			}

			else if (ans[i] == '-')
			{
				while (cnt < i)
				{
					cnt += a[k++][1];
				}
				if (cnt == a[k - 1][1])
				{
					int start = i - a[k - 1][1];
					int end = i;

					a[k - 1][0] = -1 * a[k - 1][0];
					int sum = a[k - 1][0];
					if (sum < 0)
						sum = -1 * sum;

					if (a[k - 1][0] == 0)
						a[k - 1][1] = 1;
					else
						a[k - 1][1] = Digit(a[k - 1][0]);

					ostringstream convert;
					string Result;
					convert << sum;
					Result = convert.str();

					ans = ans.substr(0, start) + Result + ans.substr(i + 1, length);

					len = ans.length();
					i = 0;
				}
				else
				{
					int start = i - (a[k - 1][1] + a[k - 2][1]);
					int end = i;
					int sum = a[k - 2][0] - a[k - 1][0];
					a[k - 1][0] = sum;
					a[k - 2][2] = -1;
					if (sum < 0)
						sum = -1 * sum;

					if (a[k - 1][0] == 0)
						a[k - 1][1] = 1;
					else
						a[k - 1][1] = Digit(a[k - 1][0]);

					for (int ii = 0; ii < j; ii++)
					{
						if (a[ii][2] == -1)
						{
							for (int jj = ii; jj < j; jj++)
							{
								a[jj][0] = a[jj + 1][0];
								a[jj][1] = a[jj + 1][1];
								a[jj][2] = a[jj + 1][2];
							}
							j--;
						}
					}
					ostringstream convert;
					string Result;
					convert << sum;
					Result = convert.str();

					ans = ans.substr(0, start) + Result + ans.substr(i + 1, length);

					len = ans.length();
					i = 0;
				}
			}

			else if (ans[i] == '+')
			{
				while (cnt < i)
				{
					cnt += a[k++][1];
				}
				int start = i - (a[k - 1][1] + a[k - 2][1]);
				int end = i;
				int sum = a[k - 2][0] + a[k - 1][0];
				a[k - 1][0] = sum;
				a[k - 2][2] = -1;
				if (sum < 0)
					sum = -1 * sum;

				if (a[k - 1][0] == 0)
					a[k - 1][1] = 1;
				else
					a[k - 1][1] = Digit(a[k - 1][0]);

				for (int ii = 0; ii < j; ii++)
				{
					if (a[ii][2] == -1)
					{
						for (int jj = ii; jj < j; jj++)
						{
							a[jj][0] = a[jj + 1][0];
							a[jj][1] = a[jj + 1][1];
							a[jj][2] = a[jj + 1][2];
						}
						j--;
					}
				}
				ostringstream convert;
				string Result;
				convert << sum;
				Result = convert.str();

				ans = ans.substr(0, start) + Result + ans.substr(i + 1, length);

				len = ans.length();
				i = 0;
			}
			else if (j == 1)
				break;
		}
		cerr << "<< " << a[j - 1][0] << "\n\n";
	}
};
//-----------------------------------------------------------------------------------------
int main()
{
	// Test
	char ch[100] = "20*2 + (((3 - 42) / 6) * 3 )* 8 ";

	/* Scan Input From Stream
	cerr << ">> ";
	cin.getline(ch, 100); */

	Fix fix(ch);

	// Test
	cerr << 20 * 2 + (((3 - 42) / 6) * 3) * 8 << "\n\n";

	cerr << "Developed By Mahdi Monazzami\n";

	system("pause>0");
	return 0;
}
//-----------------------------------------------------------------------------------------