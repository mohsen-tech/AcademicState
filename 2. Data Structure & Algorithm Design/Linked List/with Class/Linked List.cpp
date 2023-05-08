class LinkedList
{
public:
	void Add(int data)
	{
		LinkedList *pos = this;
		while (pos->Next != NULL)
		{
			pos = pos->Next;
		}
		pos->Next = new LinkedList;
		pos = pos->Next;
		pos->Data = Data;
		pos->Next = NULL;
	}
	void Print()
	{
		LinkedList * pos = this;
		while (pos != NULL)
		{
			cout << pos->Data << " ";
			pos = pos->Next;
		}
		cout << "\n";
	}
	void Reverse()
	{
		LinkedList *left = this;
		LinkedList *head = this;
		LinkedList *right, *mid;
		while (head != NULL)
		{
			mid->Next = left;
			left = mid;
			mid = right;
			right = right->Next;
		}
		head = mid;
	}
private:
	int Data;
	LinkedList * Next;
};