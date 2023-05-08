#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>

#define N 100
using namespace std;

void press_any_key();

class Kala
{
	friend istream & operator >> (istream & in, Kala & _obj);
	friend ostream & operator << (ostream & out, const Kala & _obj);
public:
	Kala() {}
	~Kala() {}
	void setName(const string & _name)
	{
		this->name = _name;
	}
	void setCode(const string & _code)
	{
		this->code = _code;
	}
	void setNumber(const int & _number)
	{
		this->number = _number;
	}
	void setPrice(const int & _price)
	{
		this->price = _price;
	}
	string getName() const
	{
		return this->name;
	}
	string getCode() const
	{
		return this->code;
	}
	int getNumber() const
	{
		return this->number;
	}
	int getPrice() const
	{
		return this->price;
	}
private:
	string name, code;
	int number, price;
};
istream & operator >> (istream & in, Kala & _obj)
{
	cout << "name kala (bedon space): ";
	in >> _obj.name;
	cout << "code kala (bedon space): ";
	in >> _obj.code;
	cout << "tedad kala: ";
	in >> _obj.number;
	cout << "qeymat kala: ";
	in >> _obj.price;
	return in;
}
ostream & operator << (ostream & out, const Kala & _obj)
{
	out << "name kala: " << _obj.name << "\n";
	out << "code kala: " << _obj.code << "\n";
	out << "tedad kala: " << _obj.number << "\n";
	out << "qeymat kala: " << _obj.price << "\n";
	return out;
}

class User
{
public:
	User() { size = 0; }
	~User() {}
	void add(const Kala & _kala)
	{
		int index = search(_kala.getCode());
		if (index == -1)
			kala[size++] = _kala;
		else
			kala[index].setNumber(kala[index].getNumber() + _kala.getNumber());
	}
	void invoice()
	{
		unsigned long long int sum = 0;
		cout << "name kala\ttedad kala\tqeymat kala\tqeymat tamam shode baraye in kala\n\n";
		for (int i = 0; i < size; i++)
		{
			int temp = kala[i].getNumber() * kala[i].getPrice();
			cout << kala[i].getName() << "\t\t" << kala[i].getNumber() << "\t\t" << kala[i].getPrice() << "\t\t" << temp << "\n";
			sum += temp;
		}
		cout << "qeymat tamam shode baraye hame kalaHa = " << sum << "\n";
	}
private:
	Kala kala[N];
	int size;
	int search(const string & _code)
	{
		for (int i = 0; i < size; i++)
			if (kala[i].getCode() == _code)
				return i;
		return -1;
	}
};

class Store
{
public:
	Store() { size = 0; }
	~Store() {}
	void shopFromStore(User & user)
	{
		string str;
		cout << "code kala ra vared konid: ";
		cin >> str;
		int index = this->search(str);
		if (index != -1)
		{
			int number;
			cout << "tedad kala ra vared konid: ";
			cin >> number;
			if (number <= this->kala[index].getNumber())
			{
				cout << "\n\n" << kala[index] << "\n";
				cout << "aya mikhahid " << number << " adad az kala ba moshakhasat bala ra bekharid (send \"yes\"/\"no\")? ";
				cin >> str;
				if (str == "yes")
				{
					Kala temp;
					temp.setCode(kala[index].getCode());
					temp.setName(kala[index].getName());
					temp.setNumber(number);
					kala[index].setNumber(kala[index].getNumber() - number);
					temp.setPrice(kala[index].getPrice());
					user.add(temp);
					cout << "kala be sabad kharid ezafe shod!\n";
				}
				else
					cout << "pas hichi dg!\n";
			}
			else
				cout << "mojodi kafi nist!\n";
		}
		else
			cout << "kala yaft nashod!\n";
	}
	void add()
	{
		Kala temp;
		cout << "\t\t <add>\n\n";
		cout << "kala jadid ra vared konid\n";
		cin >> temp;
		if (this->add(temp) == true)
			cout << "\nkala ezafe shod!\n";
		else
			cout << "\nin kala ba in code mojod ast!\n";
	}
	void edit()
	{
		string str;
		cout << "\t\t <edit>\n\n";
		cout << "code kala ra vared konid: ";
		cin >> str;
		if (this->edit(str) == true)
			cout << "\nkala edit shod!\n";
		else
			cout << "\nkala virayesh nashod!\n";
	}
	void remove()
	{
		string str;
		cout << "\t\t <remove>\n\n";
		cout << "code kala ra vared konid: ";
		cin >> str;
		if (this->remove(str) == true)
			cout << "\nkala hazf shod!\n";
		else
			cout << "\nin kala ba in code mojod nist!\n";
	}
	void search()
	{
		string str;
		cout << "\t\t <search>\n\n";
		cout << "code kala ra vared konid: ";
		cin >> str;
		int index = this->search(str);
		if (index != -1)
			cout << "\n" << kala[index] << "\n";
		else
			cout << "\nin kala ba in code mojod nist!\n";
	}
	void writeToFile()
	{
		ofstream fout("kala.txt");
		if (fout.is_open())
		{
			fout << size << "\n";
			for (int i = 0; i < size; i++)
			{
				fout << kala[i].getName() << "\n";
				fout << kala[i].getCode() << "\n";
				fout << kala[i].getNumber() << "\n";
				fout << kala[i].getPrice() << "\n";
			}
			fout.close();
		}
	}
	void readFromFile()
	{
		ifstream fin("kala.txt");
		if (fin.is_open())
		{
			fin >> size;
			for (int i = 0; i < size; i++)
			{
				Kala temp;
				string name, code;
				int number, price;
				fin >> name >> code >> number >> price;
				temp.setName(name);
				temp.setCode(code);
				temp.setNumber(number);
				temp.setPrice(price);
				this->kala[i] = temp;
			}
			fin.close();
		}
	}
private:
	Kala kala[N];
	int size;
	int search(const string & _code)
	{
		for (int i = 0; i < size; i++)
			if (kala[i].getCode() == _code)
				return i;
		return -1;
	}
	bool add(const Kala & _kala)
	{
		if (search(_kala.getCode()) == -1)
		{
			kala[size++] = _kala;
			return true;
		}
		return false;
	}
	bool edit(const string & _code)
	{
		int index = search(_code);
		if (index != -1)
			return edit(index);
		return false;
	}
	bool remove(const string & _code)
	{
		if (search(_code) != -1)
		{
			for (int i = 0; i < size; i++)
			{
				if (kala[i].getCode() == _code)
				{
					for (int j = i; j < size - 1; j++)
						kala[j] = kala[j + 1];
					size--;
					return true;
				}
			}
		}
		return false;
	}
	bool edit(const int & _idx)
	{
		cout << "\n\nkala qabl az edit:\n" << kala[_idx];
		cout << "\n\naya mikhahid edit shavad (send \"yes\"/\"no\")? ";
		string str;
		cin >> str;
		if (str == "yes")
		{
			cin >> kala[_idx];
			return true;
		}
		return false;
	}
};
Store store;

void f1()
{
	while (true)
	{
		int n;
		cout << "1. ezafe kardan kala\n";
		cout << "2. virayesh kardan kala\n";
		cout << "3. hazf kardan kala\n";
		cout << "4. jostojo kardan kala\n";
		cout << "5. bazgasht\n";
		cout << "adad ra vared konid: ";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			store.add();
			press_any_key();
			break;
		case 2:
			system("cls");
			store.edit();
			press_any_key();
			break;
		case 3:
			system("cls");
			store.remove();
			press_any_key();
			break;
		case 4:
			system("cls");
			store.search();
			press_any_key();
			break;
		case 5:
			return;
			break;
		default:
			break;
		}
		system("cls");
	}
}
void f2()
{
	User user;
	int n;
	cout << "tedad kala ra vared konid: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\n\nkala" << i + 1 << ":\n";
		store.shopFromStore(user);
	}
	cout << "\n\n________________________________________\n\n";
	cout << "<sorat hesab kharid shoma>\n\n";
	user.invoice();
	cout << "________________________________________\n\n";
	press_any_key();
}
void run()
{
	while (true)
	{
		int n;
		cout << "1. modiriat foroshgah\n";
		cout << "2. kharid az foroshgah\n";
		cout << "3. khoroj\n";
		cout << "adad ra vared konid: ";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			f1();
			break;
		case 2:
			system("cls");
			f2();
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
		system("cls");
	}
}
int main()
{
	store.readFromFile();
	run();
	store.writeToFile();

	//system("pause>0");
	return 0;
}

void press_any_key()
{
	cout << "--------------------------\n";
	cout << "press any key to continue";
	while (1)
	{
		if (_kbhit())
			return;
		cout << " .";
		Sleep(1e3);
	}
	_getch();
	system("cls");
}