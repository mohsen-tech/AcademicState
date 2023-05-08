#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <fstream>
#define table vector<vector<bool>> 
#define maxInput 10
using namespace std;
struct Inp
{
	string id;
	int i;
};
struct Out
{
	string id;
	int i;
};
struct Res
{
	string id;
	int i;
};
struct Opt
{
	string id;
	char opt;
};
vector<bool> createBinary(int n)
{
	vector<bool> temp(10, 0);
	int i = 9;
	while (n)
	{
		temp[i--] = n % 2;
		n /= 2;
	}
	return temp;
}
vector<bool> findInputFromTable(const table & input, const int & index)
{
	vector<bool> temp;
	for (int i = 0; i < input.size(); i++)
		temp.push_back(input[i][index]);
	return temp;
}
vector<bool> findOutputFromTable(const table & output, const int & index)
{
	return output[index];
}
vector<bool> findResultPerP(const table & result, const int & index)
{
	return result[index];
}
string rmvSpace(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}
bool opt_not(const bool & result)
{
	return (result == true) ? false : true;
}
bool opt_and(const bool & result, const bool & b)
{
	return result & b;
}
bool opt_nand(const bool & result, const bool & b)
{
	return opt_not(opt_and(result, b));
}
bool opt_or(const bool & result, const bool & b)
{
	return result | b;
}
bool opt_nor(const bool & result, const bool & b)
{
	return opt_not(opt_or(result, b));
}
bool opt_xor(const bool & result, const bool & b)
{
	return result ^ b;
}
bool opt_xnor(const bool & result, const bool & b)
{
	return opt_not(opt_xor(result, b));
}
int findOpt(const char & ch, const vector <Opt> & opts, const bool & result, const bool & b)
{
	for (int i = 0; i < opts.size(); i++)
		if (ch == opts[i].opt)
			if (opts[i].id == "and")
				return opt_and(result, b);
			else if (opts[i].id == "nand")
				return opt_nand(result, b);
			else if (opts[i].id == "or")
				return opt_or(result, b);
			else if (opts[i].id == "nor")
				return opt_nor(result, b);
			else if (opts[i].id == "xor")
				return opt_xor(result, b);
			else if (opts[i].id == "xnor")
				return opt_xnor(result, b);
			else if (opts[i].id == "not")
			{
				return -1;
			}
}
vector<bool> createResult(const char & ch, const vector <Opt> & opts, const vector <bool> & result, const vector <bool> & b)
{
	vector<bool> temp;
	for (int i = 0; i < pow(2, maxInput); i++)
	{
		temp.push_back(findOpt(ch, opts, result[i], b[i]));
	}
	return temp;
}
int findIndexInput(const string & str, const  vector <Inp> & inps)
{
	for (int i = 0; i < inps.size(); i++)
		if (inps[i].id == str)
			return inps[i].i;
	return -1;
}
int findIndexOutput(const string & str, const  vector <Out> & outs)
{
	for (int i = 0; i < outs.size(); i++)
		if (outs[i].id == str)
			return outs[i].i;
	return -1;
}
int findIndexResult(const string & str, const  vector <Res> & ress)
{
	for (int i = 0; i < ress.size(); i++)
		if (ress[i].id == str)
			return ress[i].i - 1;
	return -1;
}
void CalcAnswer(const table & input, table & output, string res, const vector <Opt> & opts, const vector <Inp> & inps, vector <Out> & outs)
{
	table result;
	vector <Res> ress;
	vector <bool> a, b, not;
	string temp1, temp2;
	int start, notab = -1;

	for (int i = 0; i < res.size(); i++)
	{
		if (('A' <= res[i] && res[i] <= 'Z') && ('1' <= res[i + 1] && res[i + 1] <= '9'))
		{
			if (temp1.size() == 0)
			{
				start = i;
				temp1 = res.substr(i, 2);
			}
			else if (temp2.size() == 0)
			{
				temp2 = res.substr(i, 2);
			}
			else
			{
				start = i - 2;
				temp1 = res.substr(i, 2);
				swap(temp1, temp2);
			}
			i += 1;
		}
		else
		{
			if (findOpt(res[i], opts, 0, 0) == -1)
			{
				if (res[i + 1] == 'A' || res[i + 1] == 'O' || res[i + 1] == 'R') // a temp1
				{
					if (temp1[0] == 'A')
					{
						int index = findIndexInput(temp1, inps);
						not = findInputFromTable(input, index);
					}
					else if (temp1[0] == 'O')
					{
						int index = findIndexOutput(temp1, outs);
						not = findOutputFromTable(output, index);
					}
					else if (temp1[0] == 'R')
					{
						int index = findIndexResult(temp1, ress);
						// not = findResultPerP(result, index);
						// result.erase(result.begin() + index);
						// ress.erase(ress.begin() + index);
						for (int i = 0; i < result[index].size(); i++)
							if (result[index][i] == true)
								result[index][i] = false;
							else
								result[index][i] = true;
						/*for (int i = 0; i < ress.size(); i++)
							if (index + 1 <= ress[i].i)
								ress[i].i--;*/
					}
					notab = 1;
				}
				else // b temp2
				{
					if (temp2[0] == 'A')
					{
						int index = findIndexInput(temp2, inps);
						not = findInputFromTable(input, index);
					}
					else if (temp2[0] == 'O')
					{
						int index = findIndexOutput(temp2, outs);
						not = findOutputFromTable(output, index);
					}
					else if (temp2[0] == 'R')
					{
						int index = findIndexResult(temp2, ress);
						//not = findResultPerP(result, index);
						for (int i = 0; i < result[index].size(); i++)
							if (result[index][i] == true)
								result[index][i] = false;
							else
								result[index][i] = true;
						//result.erase(result.begin() + index);
						//ress.erase(ress.begin() + index);
					}
					notab = 0;
				}

				if (not.size())
					for (int i = 0; i < not.size(); i++)
						if (not[i] == true)
							not[i] = false;
						else
							not[i] = true;

				res.erase(res.begin() + i);
			}
			else if (notab == 1)
			{
				int indexR;
				temp1.clear();
				if (temp2[0] == 'A')
				{
					int index2 = findIndexInput(temp2, inps);
					b = findInputFromTable(input, index2);
					result.push_back(createResult(res[i], opts, not, b));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
				}
				else if (temp2[0] == 'O')
				{
					int index2 = findIndexOutput(temp2, outs);
					b = findOutputFromTable(output, index2);
					result.push_back(createResult(res[i], opts, not, b));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
				}
				else if (temp2[0] == 'R')
				{
					int index2 = findIndexResult(temp2, ress);
					b = findResultPerP(result, index2);
					temp2.clear();
					result[index2] = createResult(res[i], opts, not, b);
					indexR = index2 + 1;
				}
				string left = res.substr(0, start), right = res.substr(i, res.size());
				string t = left + 'R' + char(indexR + '0') + right;
				res = t;
				notab = -1;
				not.clear();
			}
			else if (temp1[0] == 'A')
			{
				int index1 = findIndexInput(temp1, inps), indexR;
				a = findInputFromTable(input, index1);
				temp1.clear();
				if (notab == 0)
				{
					result.push_back(createResult(res[i], opts, a, not));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
					not.clear();
					notab = -1;
				}
				else if (temp2[0] == 'A')
				{
					int index2 = findIndexInput(temp2, inps);
					b = findInputFromTable(input, index2);
					result.push_back(createResult(res[i], opts, a, b));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
				}
				else if (temp2[0] == 'O')
				{
					int index2 = findIndexOutput(temp2, outs);
					b = findOutputFromTable(output, index2);
					result.push_back(createResult(res[i], opts, a, b));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
				}
				else if (temp2[0] == 'R')
				{
					int index2 = findIndexResult(temp2, ress);
					b = findResultPerP(result, index2);
					temp2.clear();
					result[index2] = createResult(res[i], opts, a, b);
					indexR = index2 + 1;
				}
				string left = res.substr(0, start), right = res.substr(i + 1, res.size());
				string t = left + 'R' + char(indexR + '0') + right;
				res = t;
				i = 0;
			}
			else if (temp1[0] == 'O')
			{
				int index1 = findIndexOutput(temp1, outs), indexR;
				a = findOutputFromTable(output, index1);
				temp1.clear();

				if (notab == 0)
				{
					result.push_back(createResult(res[i], opts, a, not));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
					not.clear();
					notab = -1;
				}
				else if (temp2[0] == 'A')
				{
					int index2 = findIndexInput(temp2, inps);
					b = findInputFromTable(input, index2);
					result.push_back(createResult(res[i], opts, a, b));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
				}
				else if (temp2[0] == 'O')
				{
					int index2 = findIndexOutput(temp2, outs);
					b = findOutputFromTable(output, index2);
					result.push_back(createResult(res[i], opts, a, b));
					Res tempRes;
					tempRes.i = result.size();
					tempRes.id = 'R' + to_string(result.size());
					ress.push_back(tempRes);
					temp2.clear();
					indexR = result.size();
				}
				else if (temp2[0] == 'R')
				{
					int index2 = findIndexResult(temp2, ress);
					b = findResultPerP(result, index2);
					temp2.clear();
					result[index2] = createResult(res[i], opts, a, b);
					indexR = index2 + 1;
				}
				string left = res.substr(0, start), right = res.substr(i + 1, res.size());
				string t = left + 'R' + char(indexR + '0') + right;
				res = t;
				i = 0;
			}
			else if (temp1[0] == 'R')
			{
				int index1 = findIndexResult(temp1, ress), indexR;
				a = findResultPerP(result, index1);
				temp1.clear();

				if (notab == 0)
				{
					result[index1] = createResult(res[i], opts, a, not);
					temp2.clear();
					indexR = result.size();
					not.clear();
					notab = -1;
				}
				else if (temp2[0] == 'A')
				{
					int index2 = findIndexInput(temp2, inps);
					b = findInputFromTable(input, index2);
					temp2.clear();
					result[index1] = createResult(res[i], opts, a, b);
					indexR = index1 + 1;
				}
				else if (temp2[0] == 'O')
				{
					int index2 = findIndexOutput(temp2, outs);
					b = findOutputFromTable(output, index2);
					temp2.clear();
					result[index1] = createResult(res[i], opts, a, b);
					indexR = index1 + 1;
				}
				else if (temp2[0] == 'R')
				{
					int index2 = findIndexResult(temp2, ress);
					b = findResultPerP(result, index2);
					temp2.clear();
					result.erase(result.begin() + index2);
					ress.erase(ress.begin() + index2);
					result[index1] = createResult(res[i], opts, a, b);
					indexR = index1 + 1;
				}
				string left = res.substr(0, start), right = res.substr(i + 1, res.size());
				string t = left + 'R' + char(indexR + '0') + right;
				res = t;
				i = 0;
			}
			i--;
		}
	}
	output.push_back(result[0]);
	Out outTemp;
	outTemp.id = 'O' + to_string(result.size());
	outTemp.i = result.size() - 1;
	if (findIndexOutput(outTemp.id, outs) == -1)
		outs.push_back(outTemp);
}
void createPostFix(const table & input, table & output, const string & str, const vector <Opt> & opts, vector <Inp> & inps, vector <Out> & outs)
{
	stack <char> stk;
	stk.push('N');
	string res;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'O' && ('1' <= str[i + 1] && str[i + 1] <= '9') && str[i + 2] == '=')
		{
			Out temp;
			temp.id = str.substr(i, 2);
			temp.i = int(str[i + 1] - '0') - 1;
			if (findIndexOutput(temp.id, outs) == -1)
				outs.push_back(temp);
			i += 2;
		}
		else if (str[i] == 'A' && ('1' <= str[i + 1] && str[i + 1] <= '9'))
		{
			Inp temp;
			temp.id = str.substr(i, 2);
			temp.i = (str[i + 1] - '0') - 1;
			if (findIndexInput(temp.id, inps) == -1)
				inps.push_back(temp);
			res += str.substr(i, 2);
			i += 1;
		}
		else if (str[i] == 'O' && ('1' <= str[i + 1] && str[i + 1] <= '9'))
		{
			res += str.substr(i, 2);
			i += 1;
		}
		else if (str[i] == '(')
			stk.push(str[i]);
		else if (str[i] == ')')
		{
			while (stk.top() != 'N' && stk.top() != '(')
			{
				char ch = stk.top();
				stk.pop();
				res += ch;
			}
			if (stk.top() == '(')
				stk.pop();
		}
		else
		{
			stk.push(str[i]);
		}
	}
	while (stk.top() != 'N')
	{
		char ch = stk.top();
		stk.pop();
		res += ch;
	}
	CalcAnswer(input, output, res, opts, inps, outs);
}
int main()
{
	table input(pow(2, maxInput), vector<bool>(10));
	table output;
	vector <Inp> inps;
	vector <Out> outs;
	for (int i = 0; i < pow(2, maxInput); i++)
	{
		input[i] = createBinary(i);
	}
	string str;
	bool swOpt = false, swFunc = false;
	vector <Opt> opts;

	ifstream myfile1("input.txt");
	if (myfile1.is_open())
	{
		while (getline(myfile1, str))
		{
			if (swFunc == false)
			{
				if (swOpt == false && str == "Operators:")
					swOpt = true;
				else if (str == "Functions:")
					swFunc = true;
				else if (swOpt == true)
				{
					Opt temp;
					int start;
					for (int i = 0; i < str.size(); i++)
						if (str[i + 1] == ' ')
							temp.opt = str[i];
						else if ('a' <= str[i] && str[i] <= 'z')
						{
							start = i;
							break;
						}
					temp.id = str.substr(start, str.size() - 1);
					opts.push_back(temp);
				}
			}
			else if (swFunc == true)
			{
				str = rmvSpace(str);
				createPostFix(input, output, str, opts, inps, outs);
			}
		}
		myfile1.close();
	}

	table outtrans(output[0].size(), vector<bool>(output.size()));
	for (int i = 0;i < output.size(); i++)
		for (int j = 0;j < output[i].size(); j++)
			outtrans[j][i] = output[i][j];

	ofstream myfil2("output.txt");
	if (myfil2.is_open())
	{
		for (int i = 0; i < input.size(); i++)
		{
			for (int j = 0; j < input[i].size(); j++)
				myfil2 << input[i][j] << " ";

			myfil2 << "\t";
			for (int j = 0;j < outtrans[i].size(); j++)
				myfil2 << outtrans[i][j] << " ";

			myfil2 << endl;
		}
		myfil2.close();
	}

	system("pause>0");
	return 0;
}