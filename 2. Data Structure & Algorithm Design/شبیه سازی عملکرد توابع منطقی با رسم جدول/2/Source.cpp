#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Oprand
{
	friend Oprand operator +(const Oprand &, const Oprand &); // or
	friend Oprand operator -(const Oprand &, const Oprand &); // nor
	friend Oprand operator *(const Oprand &, const Oprand &); // and
	friend Oprand operator /(const Oprand &, const Oprand &); // nand
	friend Oprand operator ^(const Oprand &, const Oprand &); // xor
	friend Oprand operator %(const Oprand &, const Oprand &); // xnor
	friend Oprand operator ~(const Oprand &); // not
public:
	vector <int> data;
	int index;
	string path;
	static int Length;
	Oprand() { }
	Oprand & operator =(const Oprand & right)
	{
		Oprand temp(right);
		temp.swap(*this);
		return *this;
	}
	void swap(Oprand & s) throw()
	{
		std::swap(this->data, s.data);
		std::swap(this->path, s.path);
	}
};
class Operator
{
public:
	int or (const int & a, const int & b)
	{
		return a | b;
	}
	int nor(const int & a, const int & b)
	{
		return this->not(this-> or (a, b));
	}
	int and(const int & a, const int & b)
	{
		return a & b;
	}
	int nand(const int & a, const int & b)
	{
		return this->not(this-> and (a, b));
	}
	int xor(const int & a, const int & b)
	{
		return a ^ b;
	}
	int xnor(const int & a, const int & b)
	{
		return this->not(this-> xor (a, b));
	}
	int not(const int & a)
	{
		return (a == true) ? false : true;
	}
};
Operator operators;
int Oprand::Length = 1024;
Oprand operator +(const Oprand & left, const Oprand & right)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators. or (left.data[i], right.data[i]);
		result.data.push_back(t);
	}
	result.path += left.path + right.path + "or ba " + to_string(left.index) + " , " + to_string(right.index) + " ";
	return result;
}
Oprand operator -(const Oprand & left, const Oprand & right)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators.nor(left.data[i], right.data[i]);
		result.data.push_back(t);
	}
	result.path += left.path + right.path + "nor ba " + to_string(left.index) + " , " + to_string(right.index) + " ";
	return result;
}
Oprand operator *(const Oprand & left, const Oprand & right)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators. and (left.data[i], right.data[i]);
		result.data.push_back(t);
	}
	result.path += left.path + right.path + "and ba " + to_string(left.index) + " , " + to_string(right.index) + " ";
	return result;
}
Oprand operator /(const Oprand & left, const Oprand & right)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators.nand(left.data[i], right.data[i]);
		result.data.push_back(t);
	}
	result.path += left.path + right.path + "nand ba " + to_string(left.index) + " , " + to_string(right.index) + " ";
	return result;
}
Oprand operator ^(const Oprand & left, const Oprand & right)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators. xor (left.data[i], right.data[i]);
		result.data.push_back(t);
	}
	result.path += left.path + right.path + "xor ba " + to_string(left.index) + " , " + to_string(right.index) + " ";
	return result;
}
Oprand operator %(const Oprand & left, const Oprand & right)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators.xnor(left.data[i], right.data[i]);
		result.data.push_back(t);
	}
	result.path += left.path + right.path + "xnor ba " + to_string(left.index) + " , " + to_string(right.index) + " ";
	return result;
}
Oprand operator ~(const Oprand & obj)
{
	Oprand result;
	for (int i = 0; i < Oprand::Length; i++)
	{
		int t = operators.not(obj.data[i]);
		result.data.push_back(t);
	}
	result.path += obj.path + "not ba " + to_string(obj.index) + " ";
	return result;
}
// Primary inputs:
Oprand A1, A2, A3, A4, A5, A6, A7, A8, A9, A10;
Oprand O1, O2, O3;
void init()
{
	int i = 1;
	A1.index = i++;
	A2.index = i++;
	A3.index = i++;
	A4.index = i++;
	A5.index = i++;
	A6.index = i++;
	A7.index = i++;
	A8.index = i++;
	A9.index = i++;
	A10.index = i++;
}
void read_input()
{
	ifstream Cin("input.txt");
	if (Cin.is_open())
	{
		int a;
		while (Cin >> a)
		{
			A1.data.push_back(a);
			Cin >> a;
			A2.data.push_back(a);
			Cin >> a;
			A3.data.push_back(a);
			Cin >> a;
			A4.data.push_back(a);
			Cin >> a;
			A5.data.push_back(a);
			Cin >> a;
			A6.data.push_back(a);
			Cin >> a;
			A7.data.push_back(a);
			Cin >> a;
			A8.data.push_back(a);
			Cin >> a;
			A9.data.push_back(a);
			Cin >> a;
			A10.data.push_back(a);
		}
		Cin.close();
	}
}
void write_output()
{
	ofstream Cout("output.txt");
	if (Cout.is_open())
	{
		Cout << "O1:\tO2:\tO3:\n";
		for (int i = 0; i < Oprand::Length; i++)
		{
			Cout << O1.data[i] << "\t" << O2.data[i] << "\t" << O3.data[i] << "\n";
		}
		Cout.close();
	}
}
/*
Operators:
	+	or
	-	nor
	*	and
	/	nand
	^	xor
	%	xnor
	~	not
*/
int main()
{
	init();
	read_input();

	// Functions
	O1 = (A6 + ~A6) * (((~A5 * ((A4 ^ ~A1) * ~A2)) + (A5 * ((A4 ^ ~A1) * A2))));
	O2 = (A7 + O1) * (A6 + A5 + A8);
	O3 = (O1 * O2) + A9;

	write_output();

	return 0;
}