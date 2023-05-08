#include <iostream>
#include <string>
#include <stack>
using namespace std;
int IsOperator(char ch)
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
string InFixToPostFix(string Form)
{
	string Ans;
	stack <char> temp;
	temp.push('0');
	for (size_t i = 0; i < Form.size(); i++)
	{
		if (('a' <= Form[i] && Form[i] <= 'z') || ('A' <= Form[i] && Form[i] <= 'Z'))
		{
			Ans += Form[i];
		}
		else if (Form[i] == '(')
		{
			temp.push(Form[i]);
		}
		else if (Form[i] == ')')
		{
			while (temp.top() != '0' && temp.top() != '(')
			{
				Ans += temp.top();
				temp.pop();
			}
			if (temp.top() == '(')
			{
				temp.pop();
			}
		}
		else if (Form[i] == '^' && temp.top() == '^')
		{
			temp.push(Form[i]);
		}
		else
		{
			while (temp.top() != '0' && (IsOperator(Form[i]) <= IsOperator(temp.top())))
			{
				Ans += temp.top();
				temp.pop();
			}
			temp.push(Form[i]);
		}
	}
	while (temp.top() != '0')
	{
		Ans += temp.top();
		temp.pop();
	}
	return Ans;
}
string InFixToPreFix(string Form)
{
	string Ans;
	Ans = Form;
	int j = Ans.size() - 1, i = 0;
	while (i < j)
		swap(Ans[i++], Ans[j--]);
	for (size_t k = 0; k < Ans.size(); k++)
	{
		if (Ans[k] == '(')
			Ans[k] = ')';
		else if (Ans[k] == ')')
			Ans[k] = '(';
	}
	Ans = InFixToPostFix(Ans);
	j = Ans.size() - 1, i = 0;
	while (i < j)
		swap(Ans[i++], Ans[j--]);
	return Ans;
}
string PostFixToInFix(string Form)
{
	string Ans;
	stack <string> temp;
	temp.push("0");
	for (size_t i = 0; i < Form.size(); i++)
	{
		if (('a' <= Form[i] && Form[i] <= 'z') || ('A' <= Form[i] && Form[i] <= 'Z'))
		{
			string a(1, Form[i]);
			temp.push(a);
		}
		else if (IsOperator(Form[i]) != -1)
		{
			string a, b;
			a = temp.top();
			temp.pop();
			b = temp.top();
			temp.pop();
			temp.push("(" + b + Form[i] + a + ")");
		}
	}
	while (temp.top() != "0")
	{
		Ans += temp.top();
		temp.pop();
	}
	return Ans;
}
string PostFixToPreFix(string Form)
{
	Form = PostFixToInFix(Form);
	return InFixToPreFix(Form);
}
string PreFixToInFix(string Form)
{
	string Ans;
	stack <string> temp;
	temp.push("0");
	for (int i = Form.size() - 1; i >= 0; i--)
	{
		if (('a' <= Form[i] && Form[i] <= 'z') || ('A' <= Form[i] && Form[i] <= 'Z'))
		{
			string a(1, Form[i]);
			temp.push(a);
		}
		else if (IsOperator(Form[i]) != -1)
		{
			string a, b;
			a = temp.top();
			temp.pop();
			b = temp.top();
			temp.pop();
			temp.push("(" + a + Form[i] + b + ")");
		}
	}
	while (temp.top() != "0")
	{
		Ans += temp.top();
		temp.pop();
	}
	return Ans;
}
string PreFixToPostFix(string Form)
{
	Form = PreFixToInFix(Form);
	return InFixToPostFix(Form);
}