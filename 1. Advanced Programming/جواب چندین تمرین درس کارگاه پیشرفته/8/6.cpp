#include <iostream>
#include <vector>
#include <string>
using namespace std;
// <in.txt> out.txt
class BuyersOfStore;
class InfoOfKala
{
	friend class BuyersOfStore;
	friend istream & operator >> (istream &, InfoOfKala &);
	friend ostream & operator << (ostream &, const InfoOfKala &);
public:
	InfoOfKala() { cnt = 0; }
	~InfoOfKala()
	{
		name.clear();
	}
	int majmoKharid()
	{
		return this->cnt * this->price;
	}
private:
	string name;
	int code, cnt, price;
};
istream & operator >> (istream & in, InfoOfKala & _obj)
{
	cout << "name kala: ";
	in >> _obj.name;
	cout << "code kala: ";
	in >> _obj.code;
	cout << "teded kala: ";
	in >> _obj.cnt;
	cout << "qeymat kala: ";
	in >> _obj.price;
	return in;
}
ostream & operator << (ostream & out, const InfoOfKala & _obj)
{
	out << "name kala: " << _obj.name << "\n";
	out << "code kala: " << _obj.code << "\n";
	out << "teded kala: " << _obj.cnt << "\n";
	out << "qeymat kala: " << _obj.price << "\n";
	return out;
}
//--------------------------------------------------------------------------------------------------
class BuyersOfStore
{
	friend istream & operator >> (istream &, BuyersOfStore &);
	friend ostream & operator << (ostream &, const BuyersOfStore &);
public:
	int majmoKharid()
	{
		int sum = 0;
		for (int i = 0; i < this->purchases.size(); i++)
		{
			sum += this->purchases[i].majmoKharid();
		}
		return sum;
	}
	int majmoKharidWithTakhfif()
	{
		int sum = 0;
		for (int i = 0; i < this->purchases.size(); i++)
		{
			int temp = this->purchases[i].majmoKharid();
			if (this->purchases[i].price <= 50)
				sum += (temp - (temp / 10));
			else if (this->purchases[i].price > 50)
				sum += (temp - (30 / 100) * temp);
		}
		return sum;
	}
	int getMelliCode() const
	{
		return this->melliCode;
	}
	BuyersOfStore() { };
	~BuyersOfStore()
	{
		this->purchases.clear();
	};
private:
	vector <InfoOfKala> purchases;
	int melliCode;
};
istream & operator >> (istream & in, BuyersOfStore & _obj)
{
	int n;
	cout << "tedad kala kharidari shode: ";
	in >> n;
	for (int i = 0; i < n; i++)
	{
		InfoOfKala temp;
		in >> temp;
		_obj.purchases.push_back(temp);
	}
	cout << "code melli: ";
	in >> _obj.melliCode;
	return in;
}
ostream & operator << (ostream & out, const BuyersOfStore & _obj)
{
	out << "tedad kala kharidari shode: " << _obj.purchases.size() << "\n";
	for (int i = 0; i < _obj.purchases.size(); i++)
	{
		out << i << ":\n" << _obj.purchases[i] << "\n";
	}
	out << "code melli: " << _obj.melliCode << "\n";
	return out;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	vector <BuyersOfStore> buyers;
	cout << "tedad kharidaran: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		BuyersOfStore temp;
		cin >> temp;
		buyers.push_back(temp);
		cout << "--------------------------------------------------\n";
	}
	for (int i = 0; i < buyers.size(); i++)
	{
		cout << "kharidere " << i + 1 << " ba codeMelii " << buyers[i].getMelliCode() << ":\n";
		int temp = buyers[i].majmoKharid();
		cout << "A: " << temp << "\n";
		cout << "B: " << temp - (temp / 5) << "\n";
		cout << "C: " << buyers[i].majmoKharidWithTakhfif() << "\n";
	}
	if (buyers.size() > 10)
	{
		int sum = 0;
		for (int i = 0; i < 10; i++)
			sum += buyers[i].majmoKharid();
		cout << "D: mizan forosh rozane b tor nesbi: " << sum << "\n";
	}
	cout << "E: kharid haye balaye 500t\n";
	for (int i = 0; i < buyers.size(); i++)
	{
		if (buyers[i].majmoKharid() > 500)
			cout << buyers[i] << "\n";
	}

	system("pause>0");
	return 0;
}