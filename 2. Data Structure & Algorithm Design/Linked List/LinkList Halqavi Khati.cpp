#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node * next;
	Node()
	{
		next = NULL;
	}
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};
class List // ÍáÞæí ÎØí
{
public:
	Node * First;
	Node * Last;
	List()
	{
		First = NULL;
		Last = NULL;
	}
	bool InsAtFirst(int x);
	bool InsAtLast(int x);
	bool InsNextP(Node * p, int x);
	bool InsPerP(Node * p, int x);
	bool DeleteFromFirst();
	bool DeleteFromLast();
	bool DeleteFromP(Node * p);
	bool DeleteFromPerP(Node * p);
	bool DeleteFromNextP(Node * p);
	void PrintFromFirst();
	void PrintFromLast();
	void f_PrintFromLast(Node * temp);
	void MakeNull();
	Node * Find(int x);
};
bool List::InsAtFirst(int x)
{
	Node * temp = new Node(x);
	if (!temp)
		return false;
	temp->next = First;
	First = temp;
	Last->next = First;
	return true;
}
bool List::InsAtLast(int x)
{
	Node * temp = new Node(x);
	if (!temp)
		return false;
	if (First == NULL && Last == NULL)
		First = temp;
	Last->next = temp;
	temp->next = NULL;
	Last = temp;
	Last->next = First;
	return true;
}
bool List::InsNextP(Node * p, int x)
{
	Node * temp = new Node(x);
	if (p->next == NULL)
		Last = temp;
	temp->next = p->next;
	p->next = temp;
	temp->next = p;
	return true;
}
bool List::InsPerP(Node * p, int x)
{
	Node * temp = new Node(x);
	if (p == First)
	{
		temp->next = First;
		Last->next = First;
		First = temp;
		return true;
	}
	if (p == Last)
	{
		temp->next = Last;
		return true;
	}
	temp->next = p;
	return true;
}
bool List::DeleteFromFirst()
{
	if (First == Last)
	{
		delete First;
		First = NULL;
		Last = NULL;
		return true;
	}
	Node * help = First->next;
	Last->next = help;
	delete help;
	First = Last->next;
	return true;
}
bool List::DeleteFromLast()
{
	if (!First)
		return false;
	if (First == Last)
	{
		delete First;
		First = NULL;
		Last = NULL;
		return true;
	}
	Node * temp = First;
	while (!temp->next->next)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
	Last = temp;
	return true;
}
bool List::DeleteFromP(Node * p)
{
	Node * help = First->next;
	if (!First)
		return false;
	if (p == First)
	{
		First = p->next;
		delete p;
		return true;
	}
	if (p == Last)
	{
		while (help->next != p)
			help = help->next;
		Last = help;
		Last->next = First;
		delete help;
		return true;
	}
	while (help != p)
		help = help->next;
	help->next = p->next;
	delete p;
	return true;
}
void List::PrintFromFirst()
{
	if (First == NULL)
		return;
	Node * help = First;
	while (help != NULL)
	{
		cout << help->data << "\t";
		help = help->next;
	}
}
void List::PrintFromLast()
{
	if (!First)
		return;
	f_PrintFromLast(First);
}
void List::f_PrintFromLast(Node * temp)
{
	if (temp->next)
		f_PrintFromLast(temp->next);
	cout << temp->data << "\t";
}
void List::MakeNull()
{
	if (!Last)
		return;
	Node * temp;
	while (First)
	{
		temp = First;
		First = temp->next;
		delete temp;
	}
	First = NULL;
	Last = NULL;
	return;
}
Node * List::Find(int x)
{
	Node * help = First;
	while (help != NULL)
	{
		if (help->data == x)
			return help;
		help = help->next;
	}
	return NULL;
}