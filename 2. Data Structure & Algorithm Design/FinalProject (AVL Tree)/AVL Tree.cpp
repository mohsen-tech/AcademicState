#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <stack>
#include <time.h>
using namespace std;
template <typename Var>
class AVL;
//--------------------------------------------------------------------------------------------------------------//
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != h)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(h, pos);
	}
}
//--------------------------------------------------------------------------------------------------------------//
void color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
//--------------------------------------------------------------------------------------------------------------//
template <typename Var>
class AVLNode
{
	friend class AVL <Var>;
private:
	Var Data;
	AVLNode *Left, *Right;
public:
	AVLNode()
	{
		Left = Right = nullptr;
	}
	AVLNode(Var data) : Data(data)
	{
		Left = Right = nullptr;
	}
};
//--------------------------------------------------------------------------------------------------------------//
template <typename Var>
class AVL
{
private:
	AVLNode <Var> * Root;

	AVLNode <Var> * Insert(const Var & data, AVLNode <Var> * r)
	{
		if (r == nullptr)
		{
			r = new AVLNode <Var>(data);
		}
		else if (data <= r->Data)
		{
			r->Left = Insert(data, r->Left);
			if (Height(r->Left) - Height(r->Right) == 2)
			{
				if (data < r->Left->Data)
					r = LL(r);
				else
					r = LR(r);
			}
		}
		else if (data > r->Data)
		{
			r->Right = Insert(data, r->Right);
			if (Height(r->Left) - Height(r->Right) == -2)
			{
				if (data > r->Right->Data)
					r = RR(r);
				else
					r = RL(r);
			}
		}
		return r;
	}
	//--------------------------------------------------------------------------------------------------------------//
	int Height(AVLNode <Var> * r)
	{
		if (!r)
			return -1;
		return max(Height(r->Left), Height(r->Right)) + 1;
	}
	//--------------------------------------------------------------------------------------------------------------//
	AVLNode <Var> * RR(AVLNode <Var> * r)
	{
		AVLNode <Var> * temp = r->Right;
		r->Right = temp->Left;
		temp->Left = r;
		return temp;
	}
	//--------------------------------------------------------------------------------------------------------------//
	AVLNode <Var> * RL(AVLNode <Var> * r)
	{
		AVLNode <Var> * a = r->Right;
		AVLNode <Var> * b = a->Left;
		r->Right = b->Left;
		a->Left = b->Right;
		b->Right = a;
		b->Left = r;
		return b;
	}
	//--------------------------------------------------------------------------------------------------------------//
	AVLNode <Var> * LL(AVLNode <Var> * r)
	{
		AVLNode <Var> * temp = r->Left;
		r->Left = temp->Right;
		temp->Right = r;
		return temp;
	}
	//--------------------------------------------------------------------------------------------------------------//
	AVLNode <Var> * LR(AVLNode <Var> * r)
	{
		AVLNode <Var> * a = r->Left;
		AVLNode <Var> * b = a->Right;
		a->Right = b->Left;
		r->Left = b->Right;
		b->Right = r;
		b->Left = a;
		return b;
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool Search(const Var & data, AVLNode <Var> * r)
	{
		if (r == nullptr)
		{
			return false;
		}
		if (data == r->Data)
		{
			return true;
		}
		else
		{
			if (data <= r->Data)
				return Search(data, r->Left);
			else
				return Search(data, r->Right);
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	void LeftYal(int x, int y, int height)
	{
		for (size_t i = x, j = y; i >= x - height && j < y + height; i--, j++)
		{
			gotoxy(i, j);
			color(0xF6);
			cerr << "/";
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	void RightYal(int x, int y, int height)
	{
		for (size_t i = x, j = y; i < x + height && j < y + height; i++, j++)
		{
			gotoxy(i, j);
			color(0xF6);
			cerr << "\\";
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	void Show(int x, int y, AVLNode <Var> * r)
	{
		if (r == nullptr)
		{
			return;
		}
		Sleep(500);
		gotoxy(x, y);
		color(0xF9);
		cerr << r->Data;
		if (r->Left)
		{
			int height = 3 * Height(r->Left) + Height(r) + 1;
			LeftYal(x, y + 1, height);
			Show(x - height, y + height + 1, r->Left);
		}
		if (r->Right)
		{
			int height = 3 * Height(r->Right) + Height(r) + 1;
			RightYal(x + 1, y + 1, height);
			Show(x + height, y + height + 1, r->Right);
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	AVLNode <Var> * FindParent(AVLNode <Var> * r)
	{
		AVLNode <Var> * cur = Root;
		while (cur)
		{
			if (cur->Left == r || cur->Right == r)
			{
				return cur;
			}
			else
			{
				if (r->Data > cur->Data)
				{
					cur = cur->Right;
				}
				else
				{
					cur = cur->Left;
				}
			}
		}
		return nullptr;
	}
	//--------------------------------------------------------------------------------------------------------------//
public:
	AVL() { Root = nullptr; }
	AVL(Var data) { Root = new AVLNode <Var>(data); }
	void Insert(const Var & data)
	{
		Root = Insert(data, Root);
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool Search(const Var & data)
	{
		return Search(data, Root);
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool Delete(const Var & data)
	{
		if (Search(data) == true)
		{
			if (!Root->Left && !Root->Right)
			{
				Root = nullptr;
				delete Root;
				return true;
			}
			stack <AVLNode <Var> *> s;
			AVLNode <Var> * cur = Root;
			AVLNode <Var> * parent = 0;
			while (cur) // Find Node
			{
				if (data < cur->Data)
				{
					s.push(cur);
					parent = cur;
					cur = cur->Left;
				}
				else if (data > cur->Data)
				{
					s.push(cur);
					parent = cur;
					cur = cur->Right;
				}
				else
				{
					break;
				}
			}
			if (cur->Left && cur->Right) // if Node Has 2Child
			{
				s.push(cur);
				AVLNode <Var> * temp = cur->Left;
				AVLNode <Var> * p = cur;
				while (temp->Right)
				{
					s.push(temp);
					p = temp;
					temp = temp->Right;
				}
				if (p != cur)
					p->Right = temp->Left;
				else
					p->Left = temp->Left;
				cur->Data = temp->Data;
				temp = nullptr;
				delete temp;
			}
			else if (cur->Right && cur->Left == nullptr) // if Node Has Right Child
			{
				if (parent->Left == cur)
				{
					parent->Left = cur->Right;
					s.push(parent->Left);
				}
				else
				{
					parent->Right = cur->Right;
					s.push(parent->Right);
				}
				delete cur;
			}
			else if (cur->Left && cur->Right == nullptr) // if Node Has Left Child
			{
				if (parent->Left == cur)
				{
					parent->Left = cur->Left;
					s.push(parent->Left);
				}
				else
				{
					parent->Right = cur->Left;
					s.push(parent->Right);
				}
				delete cur;
			}
			else if (cur->Left == nullptr && cur->Right == nullptr) // if Node HasNot Child
			{
				if (parent->Left == cur)
				{
					delete cur;
					parent->Left = nullptr;
				}
				else
				{
					delete cur;
					parent->Right = nullptr;
				}
			}
			while (!s.empty()) // Fix the Tree After Delete Node
			{
				AVLNode <Var> * temp = s.top();
				AVLNode <Var> * p = 0;
				s.pop();
				if (Height(temp->Left) - Height(temp->Right) == 2)
				{
					if (temp->Data > temp->Left->Data)
					{
						if (temp == Root)
						{
							Root = LL(temp);
						}
						else
						{
							p = FindParent(temp);
							if (p->Left == temp)
							{
								p->Left = LL(temp);
							}
							else
							{
								p->Right = LL(temp);
							}
						}
					}
					else
					{
						if (temp == Root)
						{
							Root = LR(temp);
						}
						else
						{
							p = FindParent(temp);
							if (p->Left == temp)
							{
								p->Left = LR(temp);
							}
							else
							{
								p->Right = LR(temp);
							}
						}
					}
				}
				if (Height(temp->Left) - Height(temp->Right) == -2)
				{
					if (temp->Data < temp->Right->Data)
					{
						if (temp == Root)
						{
							Root = RR(temp);
						}
						else
						{
							p = FindParent(temp);
							if (p->Left == temp)
							{
								p->Left = RR(temp);
							}
							else
							{
								p->Right = RR(temp);
							}
						}
					}
					else
					{
						if (temp == Root)
						{
							Root = RL(temp);
						}
						else
						{
							p = FindParent(temp);
							if (p->Left == temp)
							{
								p->Left = RL(temp);
							}
							else
							{
								p->Right = RL(temp);
							}
						}
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	void Show()
	{
		system("cls");
		Show(50, 5, Root);
		color(0xF0);
		_getch();
		system("cls");
	}
};
//--------------------------------------------------------------------------------------------------------------//
void Run()
{
	/*string str;
	int num;
	AVL <int> Tree;
	while (cin >> str)
	{
		if (str == "ins")
		{
			cin >> num;
			Tree.Insert(num);
			cerr << "Ok!\n";
		}
		else if (str == "search")
		{
			cin >> num;
			cerr << boolalpha << Tree.Search(num) << "\n";
		}
		else if (str == "show")
		{
			Tree.Show();
		}
		else if (str == "del")
		{
			cin >> num;
			cerr << boolalpha << Tree.Delete(num) << "\n";
		}
	}*/

	AVL <int> Tree;
	int a[101], j = 0, k = 0;
	srand(time(NULL));
	while (j < 25)
	{
		int num = rand() % 100;
		bool sw = true;
		for (size_t i = 0; i < j; i++)
			if (num == a[i])
				sw = false;
		if (sw == true)
		{
			a[j++] = num;
			Tree.Insert(num);
		}
		//else if (sw == false)
		//cerr << k++ << ": " << boolalpha << sw << "\n";
	}
	Tree.Show();
	//cerr << "Temos" << "\n";
}
//--------------------------------------------------------------------------------------------------------------//
int main()
{
	ios::sync_with_stdio(false);
	color(0xF0);
	system("cls");
	Run();

	/*
	string str;
	int num;
	avl_tree <int> Tree;
	while (cin >> str >> num)
	{
		if (str == "ins")
		{
			Tree.insert(num);
		}
		else if (str == "search")
		{
			node <int> * find = Tree.find(num);
			if (find == NULL)
			{
				cerr << "Not Found!" << "\n";
			}
			else
				cerr << find->data << "\n";
		}
	}
	*/

	system("pause>0");
	return 0;
}