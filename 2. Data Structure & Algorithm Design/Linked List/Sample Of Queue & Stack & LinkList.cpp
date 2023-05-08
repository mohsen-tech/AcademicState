#include <iostream>

#include <string>

#define MAX 1000

using namespace std;

template <typename Var>
class Node // Create Node
{
public:
	Node * Next;
	Var Data;
	Node()
	{
		Next = NULL;
	}
	Node(Var data)
	{
		Data = data;
		Next = NULL;
	}
};
template <typename Var>
class List // Create LinkList
{
public:
	Node <Var> * First;
	List()
	{
		First = new Node <Var>;
	}
	List(Var data)
	{
		First = new Node <Var>(data);
	}
	bool InsAtFirst(Var data)
	{
		Node <Var> * temp = new Node <Var>(data);
		if (!temp)
		{
			return false;
		}
		temp->Next = First;
		First = temp;
		return true;
	}
	bool InsAtLast(Var data)
	{
		Node <Var> * temp = new Node <Var>(data);
		if (!temp)
		{
			return false;
		}
		Node <Var> * help = First;
		while (help->Next)
		{
			help = help->Next;
		}
		help->Next = temp;
		return true;
	}
	bool DelFromFirst(Var & data)
	{
		if (!First)
		{
			return false;
		}
		data = First->Data;
		Node <Var> * temp = First;
		First = First->Next;
		delete temp;
		return true;
	}
	bool DelFromLast(Var & data)
	{
		if (!First)
		{
			return false;
		}
		Node <Var> * help = First;
		while (help->Next->Next)
		{
			help = help->Next;
		}
		data = help->Next->Data;
		help->Next = NULL;
		delete help->Next;
		return true;
	}
	void Print()
	{
		Node <Var> * temp = First;
		while (temp)
		{
			cout << temp->Data << "  ";
			temp = temp->Next;
		}
		cout << "\n";
	}
	void MakeNull()
	{
		Node <Var> * temp = First;
		while (First)
		{
			temp = First;
			First = First->Next;
			delete temp;
		}
	}
	~List()
	{
		MakeNull();
	}
};
template <typename Var>
class Queue // Create Queue With Array
{
private:
	int Front, Rear;
	Var Data[MAX];
public:
	Queue()
	{
		Front = 0;
		Rear = -1;
	}
	bool empty() const
	{
		return Front > Rear;
	}
	Var front()
	{
		if (!empty())
			return Data[Front];
	}
	Var back()
	{
		if (!empty())
			return Data[Rear];
	}
	void push(Var temp)
	{
		Data[++Rear] = temp;
	}
	void pop()
	{
		if (!empty())
			Front++;
	}
	int size() const
	{
		return Rear - Front + 1;
	}
};
template <typename Var>
class ListQueue // Create Queue With LinkList
{
private:
	Node <Var> * Front;
	Node <Var> * Rear;
	int counter;
public:
	ListQueue()
	{
		Front = Rear = NULL;
		counter = 0;
	}
	bool empty() const
	{
		if (!Front)
			return true;
		return false;
	}
	Var front()
	{
		if (!empty())
			return Front->Data;
	}
	Var back()
	{
		if (!empty())
			return Rear->Data;
	}
	void push(Var data)
	{
		Node <Var> * temp = new Node <Var>(data);
		if (!Rear)
		{
			Front = Rear = temp;
		}
		else
		{
			Rear->Next = temp;
			Rear = temp;
		}
		counter++;
	}
	void pop()
	{
		if (!Front->Next)
		{
			delete Front;
			Front = Rear = NULL;
		}
		else if (!empty())
		{
			Node <Var> * temp = Front;
			Front = Front->Next;
			delete temp;
		}
		counter--;
	}
	int size() const
	{
		return counter;
	}
};
template <typename Var>
class Stack // Create Stack With Array
{
private:
	int top_index;
	Var data[MAX];
public:
	Stack()
	{
		top_index = MAX;
	}
	bool empty() const
	{
		return top_index == MAX;
	}
	void push(Var temp)
	{
		data[--top_index] = temp;
	}
	void pop()
	{
		top_index++;
	}
	int size() const
	{
		return MAX - top_index;
	}
	Var top()
	{
		return data[top_index];
	}
};
template <typename Var>
class ListStack // Create Stack With LinkList
{
private:
	Node <Var> * Top;
	int counter;
public:
	ListStack()
	{
		Top = NULL;
		counter = 0;
	}
	bool empty() const
	{
		if (!Top)
			return false;
		return true;
	}
	void push(Var data)
	{
		Node <Var> * temp = new Node <Var>(data);
		temp->Next = Top;
		Top = temp;
		counter++;
	}
	void pop()
	{
		if (Top)
		{
			Node <Var> * temp = Top;
			Top = Top->Next;
			delete temp;
			counter--;
		}
	}
	int size() const
	{
		return counter;
	}
	Var top()
	{
		return Top->Data;
	}
};