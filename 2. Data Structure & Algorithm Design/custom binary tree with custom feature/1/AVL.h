#include <stack>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include "TvProgramNode.h"
class AVL
{
private:
	TvProgramNode * root;
	int length;
	TvProgramNode * insert(const TvProgramNode & obj, TvProgramNode * r)
	{
		if (r == nullptr)
		{
			r = new TvProgramNode(obj);
		}
		else if (obj.code <= r->code)
		{
			r->left = insert(obj, r->left);
			if (Height(r->left) - Height(r->right) == 2)
			{
				if (obj.code < r->left->code)
					r = LL(r);
				else
					r = LR(r);
			}
		}
		else if (obj.code > r->code)
		{
			r->right = insert(obj, r->right);
			if (Height(r->left) - Height(r->right) == -2)
			{
				if (obj.code > r->right->code)
					r = RR(r);
				else
					r = RL(r);
			}
		}
		return r;
	}
	//--------------------------------------------------------------------------------------------------------------//
	int Height(TvProgramNode * r)
	{
		if (!r)
			return -1;
		return max(Height(r->left), Height(r->right)) + 1;
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode * RR(TvProgramNode * r)
	{
		TvProgramNode * temp = r->right;
		r->right = temp->left;
		temp->left = r;
		return temp;
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode * RL(TvProgramNode * r)
	{
		TvProgramNode * a = r->right;
		TvProgramNode * b = a->left;
		r->right = b->left;
		a->left = b->right;
		b->right = a;
		b->left = r;
		return b;
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode * LL(TvProgramNode * r)
	{
		TvProgramNode * temp = r->left;
		r->left = temp->right;
		temp->right = r;
		return temp;
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode * LR(TvProgramNode * r)
	{
		TvProgramNode * a = r->left;
		TvProgramNode * b = a->right;
		a->right = b->left;
		r->left = b->right;
		b->right = r;
		b->left = a;
		return b;
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool search(const int & _code, TvProgramNode * r)
	{
		if (r == nullptr)
		{
			return false;
		}
		if (_code == r->code)
		{
			return true;
		}
		else
		{
			if (_code <= r->code)
				return search(_code, r->left);
			else
				return search(_code, r->right);
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(TvProgramNode * r)
	{
		if (r == nullptr)
			return;
		print(r->left);
		cout << *r << "\n\n";
		print(r->right);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void saveFile(TvProgramNode * r, fstream & output)
	{
		if (r == nullptr)
			return;
		print(r->left);
		output << *r;
		print(r->right);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(TvProgramNode * r, const Time & t)
	{
		if (r == nullptr)
			return;
		print(r->left);
		if (r->checkTime(t) == true)
			cout << *r << "\n\n";
		print(r->right);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(TvProgramNode * r, const string & str, const int & s)
	{
		if (r == nullptr)
			return;
		print(r->left);
		if (s == 0 && r->checkChannel(str) == true)
			cout << *r << "\n\n";
		else if (s == 1 && r->checkStr(str) == true)
			cout << *r << "\n\n";
		print(r->right);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(TvProgramNode * r, const int & n)
	{
		if (r == nullptr)
			return;
		print(r->left);
		if (n >= r->numberRepeat)
			cout << *r << "\n\n";
		print(r->right);
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool findNode(const int & _code, TvProgramNode * r, const int & s)
	{
		if (r == nullptr)
		{
			return false;
		}
		if (_code == r->code)
		{
			if (s == 0)
				r->edit();
			if (s == 1)
				r->updateInfo();
			return true;
		}
		else
		{
			if (_code <= r->code)
				return findNode(_code, r->left, s);
			else
				return findNode(_code, r->right, s);
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode * findParent(TvProgramNode * r)
	{
		TvProgramNode  * cur = root;
		while (cur)
		{
			if (cur->left == r || cur->right == r)
			{
				return cur;
			}
			else
			{
				if (r->code > cur->code)
				{
					cur = cur->right;
				}
				else
				{
					cur = cur->left;
				}
			}
		}
		return nullptr;
	}
	//--------------------------------------------------------------------------------------------------------------//
public:
	AVL() { root = nullptr; length = 0; }
	AVL(const TvProgramNode & obj) { root = new TvProgramNode(obj); }
	void insert(const TvProgramNode & obj) { root = insert(obj, root); length++; }
	int getLength() const { return length; }
	//--------------------------------------------------------------------------------------------------------------//
	bool search(const int & _code)
	{
		return search(_code, root);
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool edit(const int & _code, const int & s)
	{
		return findNode(_code, root, s);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print()
	{
		print(root);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void saveFile()
	{
		file_flag = true;
		fstream output("TvProgramFile.txt", ios::out);
		if (output.fail())
		{
			cerr << "Error";
			exit(0);
		}
		output << getLength() << endl;
		saveFile(root, output);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(const Time & t)
	{
		print(root, t);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(const string & str, const int & s)
	{
		print(root, str, s);
	}
	//--------------------------------------------------------------------------------------------------------------//
	void print(const int & n)
	{
		print(root, n);
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool Delete(const int & _code)
	{
		if (search(_code) == true)
		{
			if (!root->left && !root->right)
			{
				root = nullptr;
				delete root;
				return true;
			}
			stack <TvProgramNode *> s;
			TvProgramNode * cur = root;
			TvProgramNode * parent = 0;
			while (cur) // Find Node
			{
				if (_code < cur->code)
				{
					s.push(cur);
					parent = cur;
					cur = cur->left;
				}
				else if (_code > cur->code)
				{
					s.push(cur);
					parent = cur;
					cur = cur->right;
				}
				else
				{
					break;
				}
			}
			if (cur->left && cur->right) // if Node Has 2Child
			{
				s.push(cur);
				TvProgramNode * temp = cur->left;
				TvProgramNode * p = cur;
				while (temp->right)
				{
					s.push(temp);
					p = temp;
					temp = temp->right;
				}
				if (p != cur)
					p->right = temp->left;
				else
					p->left = temp->left;
				cur->code = temp->code;
				temp = nullptr;
				delete temp;
			}
			else if (cur->right && cur->left == nullptr) // if Node Has Right Child
			{
				if (parent->left == cur)
				{
					parent->left = cur->right;
					s.push(parent->left);
				}
				else
				{
					parent->right = cur->right;
					s.push(parent->right);
				}
				delete cur;
			}
			else if (cur->left && cur->right == nullptr) // if Node Has Left Child
			{
				if (parent->left == cur)
				{
					parent->left = cur->left;
					s.push(parent->left);
				}
				else
				{
					parent->right = cur->left;
					s.push(parent->right);
				}
				delete cur;
			}
			else if (cur->left == nullptr && cur->right == nullptr) // if Node HasNot Child
			{
				if (parent->left == cur)
				{
					delete cur;
					parent->left = nullptr;
				}
				else
				{
					delete cur;
					parent->right = nullptr;
				}
			}
			while (!s.empty()) // Fix the Tree After Delete Node
			{
				TvProgramNode  * temp = s.top();
				TvProgramNode  * p = 0;
				s.pop();
				if (Height(temp->left) - Height(temp->right) == 2)
				{
					if (temp->code > temp->left->code)
					{
						if (temp == root)
						{
							root = LL(temp);
						}
						else
						{
							p = findParent(temp);
							if (p->left == temp)
							{
								p->left = LL(temp);
							}
							else
							{
								p->right = LL(temp);
							}
						}
					}
					else
					{
						if (temp == root)
						{
							root = LR(temp);
						}
						else
						{
							p = findParent(temp);
							if (p->left == temp)
							{
								p->left = LR(temp);
							}
							else
							{
								p->right = LR(temp);
							}
						}
					}
				}
				if (Height(temp->left) - Height(temp->right) == -2)
				{
					if (temp->code < temp->right->code)
					{
						if (temp == root)
						{
							root = RR(temp);
						}
						else
						{
							p = findParent(temp);
							if (p->left == temp)
							{
								p->left = RR(temp);
							}
							else
							{
								p->right = RR(temp);
							}
						}
					}
					else
					{
						if (temp == root)
						{
							root = RL(temp);
						}
						else
						{
							p = findParent(temp);
							if (p->left == temp)
							{
								p->left = RL(temp);
							}
							else
							{
								p->right = RL(temp);
							}
						}
					}
				}
			}
			length--;
			return true;
		}
		else
		{
			return false;
		}
	}
};