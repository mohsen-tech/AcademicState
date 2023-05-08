#include <iostream>
#include <string>
using namespace std;
template<typename Var>
class Node
{
public:
	Var Data;
	Node * Next;
	Node() { Next = NULL; }
	Node(Var data) { Data = data; Next = NULL; }
};
template<typename Var>
class List
{
private:
	Node <Var> * First;
public:
	List() { First = new Node<Var>; }

	List(Var var) { First = new Node<Var>(var); }

	bool InsAtFirst(Var data);

	bool InsAtLast(Var data);

	void MakeNull();

	void Show();

	//------------------------------------------------------------------------------
	void DelZoj() // 1
	{
		Node <Var> * temp = First;
		Node <Var> * help;
		while (temp->Next)
		{
			help = temp->Next;
			temp->Next = temp->Next->Next;
			delete help;
			if (temp->Next)
				temp = temp->Next;
		}
	}
	//------------------------------------------------------------------------------
	void operator = (const List & Obj)  // 2
	{
		MakeNull();
		First = Obj.First;
	}
	//------------------------------------------------------------------------------
	void ShowInverse() // 3
	{
		f_ShowInverse(First);
	}
	void f_ShowInverse(Node <Var> * temp)
	{
		if (temp->Next)
			f_ShowInverse(temp->Next);
		cout << temp->Data << " ";
	}
	//------------------------------------------------------------------------------
	void DelWithoutObj() // 4 ?!
	{
		MakeNull(First);
	}
	void MakeNull(Node <Var> * temp)
	{
		if (First->Next)
			MakeNull(First->Next);
		delete First;
	}
	//------------------------------------------------------------------------------
	void ListInverse()  // 5
	{
		f_ListInverse(First);
	}
	void f_ListInverse(Node <Var> * temp)
	{
		Node <Var> * help = new Node <Var>(temp->Data);
		if (temp->Next->Next)
		{
			f_ListInverse(temp->Next);
		}
		else if (!temp->Next->Next)
		{
			First = temp->Next;
		}
		temp = First;
		while (temp->Next)
		{
			temp = temp->Next;
		}
		temp->Next = help;
	}
	//------------------------------------------------------------------------------
};
template<typename Var>
bool List<Var>::InsAtFirst(Var data)
{
	Node <Var> * temp = new Node <Var>(data);
	if (!temp)
		return false;
	temp->Next = First;
	First = temp;
	return true;
}
template<typename Var>
bool List<Var>::InsAtLast(Var data)
{
	Node <Var> * temp = new Node <Var>(data);
	if (!temp)
		return false;
	Node <Var> * help = First;
	while (help->Next)
	{
		help = help->Next;
	}
	help->Next = temp;
	return true;
}
template<typename Var>
void List<Var>::MakeNull()
{
	Node <Var> * temp;
	while (First)
	{
		temp = First;
		First = temp->Next;
		delete temp;
	}
}
template<typename Var>
void List<Var>::Show()
{
	Node <Var> * help = First;
	while (help)
	{
		cout << help->Data << " ";
		help = help->Next;
	}
}