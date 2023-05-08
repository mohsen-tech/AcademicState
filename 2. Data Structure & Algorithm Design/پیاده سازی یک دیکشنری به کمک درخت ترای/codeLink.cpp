#include <iostream>
#include <string>
#include <conio.h>
#define letterSize 27
#define dashIdx 26
using namespace std;
class TrieNode;
class TrieTree;
class TrieNode
{
	friend class TrieTree;
private:
	string meaning;
	bool endOfWord;
	TrieNode * letter[letterSize];
public:
	TrieNode()
	{
		for (int i = 0; i < letterSize; i++)
			this->letter[i] = nullptr;
		this->meaning = "";
		this->endOfWord = false;
	}
};
class TrieTree
{
private:
	TrieNode * root;
	bool check(TrieNode const * temp)
	{
		for (int i = 0; i < letterSize; i++)
			if (temp->letter[i])
				return true;
		return false;
	}
	bool remove(TrieNode *& temp, const string & str)
	{
		if (temp == nullptr)
			return false;
		if (str.size() && temp != nullptr)
		{
			int index;
			if (str[0] == '-')
				index = dashIdx;
			else
				index = str[0] - 'a';
			if (temp->letter[index] != nullptr && remove(temp->letter[index], str.substr(1)) && temp->endOfWord == false)
			{
				if (!check(temp))
				{
					delete temp;
					temp = nullptr;
					return true;
				}
				else
					return false;
			}
		}
		if (str.size() == 0 && temp->endOfWord)
		{
			if (!check(temp))
			{
				delete temp;
				temp = nullptr;
				return true;
			}
			else
			{
				temp->meaning.clear();
				temp->endOfWord = false;
				return false;
			}
		}
		return false;
	}
public:
	TrieTree()
	{
		this->root = new TrieNode();
	}
	void insert(const string & str, const string & _meaning)
	{
		TrieNode * temp = this->root;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '-' && temp->letter[dashIdx] == nullptr)
				temp->letter[dashIdx] = new TrieNode();
			else if (temp->letter[str[i] - 'a'] == nullptr)
				temp->letter[str[i] - 'a'] = new TrieNode();

			if (str[i] == '-')
				temp = temp->letter[dashIdx];
			else
				temp = temp->letter[str[i] - 'a'];
		}
		temp->meaning = _meaning;
		temp->endOfWord = true;
	}
	bool search(const string & str, string & _meaning)
	{
		_meaning = "";
		if (this->root == nullptr)
			return false;
		TrieNode * temp = this->root;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '-')
				temp = temp->letter[dashIdx];
			else
				temp = temp->letter[str[i] - 'a'];
			if (temp == nullptr)
				return false;
		}
		if (temp->endOfWord == true)
			_meaning = temp->meaning;
		return temp->endOfWord;
	}
	bool remove(const string & str)
	{
		return this->remove(this->root, str);
	}
};
void insert(TrieTree & arg)
{
	string str, word, meaning;
	cout << "enter your sentence: ";
	cin.ignore();
	getline(cin, str);
	int start = -1;
	for (int i = 0; i < str.size(); i++)
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	for (int i = 0; i < str.size(); i++)
	{
		if (start == -1)
			start = i;
		else if (str[i] == ':')
		{
			word = str.substr(start, i - start);
			start = -1;
		}
		else if (str[i] == '_')
		{
			meaning = str.substr(start, i - start);
			start = -1;
			arg.insert(word, meaning);
			word.clear();
			meaning.clear();
		}
	}
	meaning = str.substr(start, str.size() - start);
	if (word != "")
		arg.insert(word, meaning);
}
void search(TrieTree & arg)
{
	string word, meaning;
	cout << "enter your word: ";
	cin >> word;
	bool flag = arg.search(word, meaning);
	if (flag == true)
		cout << meaning << endl;
	else
		cout << "not found!\n";
}
void remove(TrieTree & arg)
{
	string word, meaning;
	cout << "enter your word: ";
	cin >> word;
	if (arg.search(word, meaning) == true)
	{
		arg.remove(word);
		cout << "ok!\n";
	}
	else
		cout << "not found!\n";
}
int main()
{
	TrieTree test;
	while (true)
	{
		int n;
		cout << "1. insert\n";
		cout << "2. search\n";
		cout << "3. delete\n";
		cout << "4. exit\n";
		cout << ": ";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			insert(test);
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			search(test);
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			remove(test);
			_getch();
			system("cls");
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}
	}
}