// Mohsen AliMohammadi 96440296
// Ali Heravi 96440249
// Seyede farkhonde anboub 96440172
// Mahdie javdani 96440178
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Token
{
	string data;
	int Ln, Ch;
};
class DFA
{
private:
	vector <string> reserved;
	vector <Token> res;
	string reserved2;
public:
	DFA(const vector <string> & _a)
	{
		this->reserved = _a;
	}
	DFA(const string & _a)
	{
		this->reserved2 = _a;
	}
	int match(const string & _str, const int & _state)
	{
		if (!this->reserved.empty())
		{
			for (int i = 0; i < this->reserved.size(); i++)
				if (_str[_state] == this->reserved[i][0])
				{
					int idx = _state, cnt = 0;
					for (int j = 0; j < this->reserved[i].size() && idx < _str.size(); j++, idx++)
						if (_str[idx] == this->reserved[i][j])
							cnt++;
					if (cnt == this->reserved[i].size())
						return idx;
				}
		}
		else if (!this->reserved2.empty())
		{
			int idx = this->reserved2.find('.');
			if (idx != -1)
			{
				for (int i = 0; i < idx; i++)
					if (this->reserved2[i] == _str[_state])
					{
						bool flag = false;
						int index;
						for (int j = _state; j < _str.size(); j++)
						{
							flag = false;
							for (int k = 0; k < this->reserved2.size(); k++)
								if (k != idx && _str[j] == this->reserved2[k])
								{
									flag = true;
									index = j;
								}
							if (flag == false)
								return j;
						}
						if (flag == true)
							return index + 1;
					}
			}
			else
			{
				if (_str[_state] == '"')
				{
					for (int i = _state + 1; i < _str.size(); i++)
						if (_str[i] == '"')
							return i + 1;
				}
				else
				{
					for (int i = 0; i < this->reserved2.size(); i++)
						if (this->reserved2[i] == _str[_state])
						{
							bool flag = false;
							int index;
							for (int j = _state; j < _str.size(); j++)
							{
								flag = false;
								for (int k = 0; k < this->reserved2.size(); k++)
									if (k != idx && _str[j] == this->reserved2[k])
									{
										flag = true;
										index = j;
									}
								if (flag == false)
									return j;
							}
							if (flag == true)
								return index + 1;
						}
				}
			}
		}
		return _state;
	}
	void save(const string & _str, const int & _ln, const int & _ch)
	{
		Token temp;
		temp.data = _str;
		temp.Ln = _ln;
		temp.Ch = _ch;
		this->res.push_back(temp);
	}
	void output(const string & _title, ofstream & _out)
	{
		if (!this->res.empty())
		{
			_out << "result of \"" << _title << "\"\n";
			for (int i = 0; i < this->res.size(); i++)
			{
				_out << "token ({ \"" << this->res[i].data << "\" }) \t";
				_out << "at Ch" << this->res[i].Ch << "\t";
				_out << "in Ln" << this->res[i].Ln << "\n";
			}
			_out << "----------------------------------------------------------------------------------\n\n";
		}
	}
};
int main()
{
	vector <string> sample_keyWord = { "int", "void", "if" , "while" , "return" , "read" , "write" , "print" , "continue" , "break" , "binary" , "decimal" , "char" , "string" };
	vector <string> sample_symbol = { "(", ")", "{", "}", "[", "]", ",", ";", "+", "-", "*", "/", "==", "!=", ">", ">=", "<", "<=", "=", "&&", "||" , "%" };
	vector <string> sample_metaStatement = { "#", "//" };
	string letter, digit;

	for (int i = 0; i < 256; i++)
		if ('a' <= char(i) && char(i) <= 'z' || 'A' <= char(i) && char(i) <= 'Z')
			letter += char(i);
		else if ('0' <= char(i) && char(i) <= '9')
			digit += char(i);

	string sample_identifier = letter + "." + digit, sample_number = digit, sample_str("\"");

	DFA keyWord(sample_keyWord),
		metaStatement(sample_metaStatement),
		symbol(sample_symbol),
		identifier(sample_identifier),
		number(sample_number),
		str(sample_str);

	string inp;
	int line = 0;
	ifstream infile;
	infile.open("1.txt", ios::in);
	if (!infile)
		exit(0);
	while (getline(infile, inp))
	{
		for (int i = 0; i < inp.size(); i++)
		{
			int temp = keyWord.match(inp, i);
			if (temp != i)
			{
				string _str = inp.substr(i, temp - i);
				keyWord.save(_str, line, i);
				i = temp - 1;
				continue;
			}
			temp = metaStatement.match(inp, i);
			if (temp != i)
			{
				string _str = inp.substr(i, inp.size() - i);
				metaStatement.save(_str, line, i);
				i = inp.size() - 1;
				continue;
			}
			temp = symbol.match(inp, i);
			if (temp != i)
			{
				string _str = inp.substr(i, temp - i);
				symbol.save(_str, line, i);
				i = temp - 1;
				continue;
			}
			temp = identifier.match(inp, i);
			if (temp != i)
			{
				string _str = inp.substr(i, temp - i);
				identifier.save(_str, line, i);
				i = temp - 1;
				continue;
			}
			temp = str.match(inp, i);
			if (temp != i)
			{
				string _str = inp.substr(i, temp - i);
				str.save(_str, line, i);
				i = temp - 1;
				continue;
			}
			temp = number.match(inp, i);
			if (temp != i)
			{
				string _str = inp.substr(i, temp - i);
				number.save(_str, line, i);
				i = temp - 1;
				continue;
			}
		}
		line++;
	}
	infile.close();

	ofstream outfile;
	outfile.open("2.txt", ios::out);
	keyWord.output("reserved word", outfile);
	metaStatement.output("meta statement", outfile);
	symbol.output("symbol", outfile);
	identifier.output("identifier", outfile);
	number.output("number", outfile);
	str.output("string", outfile);
	outfile.close();

	return 0;
}