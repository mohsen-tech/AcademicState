#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
// <in.txt> out.txt

class Product;
class Shopstore;
class User;

void addProduct(Shopstore & shopstore);
void editProduct(Shopstore & shopstore);
void deleteProduct(Shopstore & shopstore);
void findProduct(Shopstore & shopstore);
void admin(Shopstore & shopstore);

void shoppingFromStore(Shopstore & shopstore, User & user);

void read(Shopstore & shopstore);
void f();

class Shopstore;
class Product
{
	friend class Shopstore;
	friend void read(Shopstore & shopstore);
	friend istream & operator >> (istream & in, Product & obj);
	friend ostream & operator << (ostream & out, const Product & obj);
private:
	string code, name;
	int price, number;
public:
	string getCode() const { return code; }
	string getName() const { return name; }
	void setNumber(const int & newNumber) { number = newNumber; }
	int getNumber() const { return number; }
	int getPrice() const { return price; }
};
istream & operator >> (istream & in, Product & obj)
{
	cout << "code: "; in >> obj.code;
	cout << "name: "; in >> obj.name;
	cout << "number: "; in >> obj.number;
	cout << "price: "; in >> obj.price;
	return in;
}
ostream & operator << (ostream & out, const Product & obj)
{
	out << "code: " << obj.code << "\n";
	out << "name: " << obj.name << "\n";
	out << "number: " << obj.number << "\n";
	out << "price: " << obj.price << "\n";
	return out;
}
//-----------------------------------------------------------------------------------
class User
{
private:
	vector <Product> products;
public:
	void add(const Product & temp) { products.push_back(temp); }
	void purchaseInvoice()
	{
		long long int totalCost = 0;
		for (int i = 0; i < products.size(); i++)
		{
			cout << "\n\nProduct No. " << i + 1 << "\n" << products[i];
			totalCost += products[i].getNumber() * products[i].getPrice();
		}
		cout << "\n\nTotal cost of your purchase: " << totalCost << "\n";
	}
};
//-----------------------------------------------------------------------------------
class Shopstore
{
private:
	vector <Product> products;
public:
	void add(const Product & temp)
	{
		products.push_back(temp);
	}
	void edit(const int & index, const Product & temp)
	{
		products[index] = temp;
	}
	void remove(const int & index)
	{
		products.erase(products.begin() + index);
	}
	int find(const string & str)
	{
		for (int i = 0; i < products.size(); i++)
			if (products[i].name == str || products[i].code == str)
				return i;
		return -1;
	}
	Product & operator [](const int & index)
	{
		if (0 <= index && index < products.size())
			return this->products[index];
		_DEBUG_ERROR("vector subscript out of range");
		_SCL_SECURE_OUT_OF_RANGE;
	}
	void write()
	{
		ofstream file("products.txt");
		if (file.is_open())
		{
			int n = products.size();
			file << n << "\n";
			for (int i = 0; i < n; i++)
			{
				file << products[i].code << "\n";
				file << products[i].name << "\n";
				file << products[i].number << "\n";
				file << products[i].price << "\n";
			}
			file.close();
		}
	}
};
//-----------------------------------------------------------------------------------
void _main()
{
	Shopstore shopstore;
	read(shopstore);
	while (true)
	{
		string str;
		cout << "1. Admin\n2. User\n3. Exit\nPlease enter \"admin\" or \"user\" or \"exit\": ";
		cin >> str;
		if (str == "admin")
			admin(shopstore);
		else if (str == "user")
		{
			User user;
			system("cls");
			shoppingFromStore(shopstore, user);
		}
		else if (str == "exit")
		{
			shopstore.write();
			return;
		}
		else
			system("cls");
	}
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//ios::sync_with_stdio(false), cin.tie(0);

	_main();

	system("pause>0");
	return 0;
}
//-----------------------------------------------------------------------------------
void addProduct(Shopstore & shopstore)
{
	cout << "\t[Add Product Page]\n\n";
	Product temp;
	cout << "Enter the following information\n";
	cin >> temp;
	if (shopstore.find(temp.getCode()) == -1)
	{
		shopstore.add(temp);
		cout << "\nProduct added\n";
	}
	else
		cout << "\nThis product is available\n";
	f();
	system("cls");
}
void editProduct(Shopstore & shopstore)
{
	cout << "\t[Edit Product Page]\n\n";
	string str;
	cout << "Enter the product information(name or code): ";
	cin >> str;
	int index = shopstore.find(str);
	if (index != -1)
	{
		cout << "Product information before editing\n";
		cout << shopstore[index] << "\n\n";
		Product temp;
		cout << "Enter the following information to edit the product\n";
		cin >> temp;
		if (shopstore.find(temp.getCode()) == -1)
		{
			shopstore.edit(index, temp);
			cout << "\nProduct edited\n";
		}
		else
			cout << "\nCannot be edited because this product is available\n";
	}
	else
		cout << "\nThis product is not available\n";
	f();
	system("cls");
}
void deleteProduct(Shopstore & shopstore)
{
	cout << "\t[Delete Product Page]\n\n";
	string str;
	cout << "Enter the product information(name or code): ";
	cin >> str;
	int index = shopstore.find(str);
	if (index != -1)
	{
		shopstore.remove(index);
		cout << "\nProduct removed\n";
	}
	else
		cout << "\nThis product is not available\n";
	f();
	system("cls");
}
void findProduct(Shopstore & shopstore)
{
	cout << "\t[Find Product Page]\n\n";
	string str;
	cout << "Enter the product information(name or code): ";
	cin >> str;
	int index = shopstore.find(str);
	if (index != -1)
	{
		cout << "\nProduct found. Product information includes the following:\n";
		cout << shopstore[index] << "\n";
	}
	else
		cout << "\nThis product is not available\n";
	f();
	system("cls");
}
void admin(Shopstore & shopstore)
{
	system("cls");
	cout << "\t[Admin Page]\n\n";
	cout << "1. Add product\n";
	cout << "2. Edit product\n";
	cout << "3. Delete product\n";
	cout << "4. Find product\n";
	cout << "else. Go back page\n";
	int a;
	cout << "Please enter one: ";
	cin >> a;
	switch (a)
	{
	case 1:
		system("cls");
		addProduct(shopstore);
		break;
	case 2:
		system("cls");
		editProduct(shopstore);
		break;
	case 3:
		system("cls");
		deleteProduct(shopstore);
		break;
	case 4:
		system("cls");
		findProduct(shopstore);
		break;
	default:
		break;
	}
	system("cls");
}
//-----------------------------------------------------------------------------------
void shoppingFromStore(Shopstore & shopstore, User & user)
{
	cout << "\t[User - Shopping From Store Page]\n\n";
	int n;
	cout << "How many products do you want to buy? ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cout << "\n\n" << i + 1 << ": Enter the product information(name or code): ";
		cin >> str;
		int index = shopstore.find(str);
		if (index != -1)
		{
			int number, shopstoreNumber = shopstore[index].getNumber();
			cout << "How many " << shopstore[index].getName() << " do you want to buy? ";
			cin >> number;
			if (number <= shopstoreNumber)
			{
				Product temp = shopstore[index];
				temp.setNumber(number);
				user.add(temp);
				shopstore[index].setNumber(shopstoreNumber - number);
				cout << "\nAdded to cart\n";
			}
			else
				cout << "\nThe number of products requested is more than the inventory\n";
		}
		else
			cout << "\nThis product is not available\n";
	}
	cout << "\n\nYour purchase invoice is as follows";
	user.purchaseInvoice();
	f();
	system("cls");
}
//-----------------------------------------------------------------------------------
void read(Shopstore & shopstore)
{
	ifstream file("products.txt");
	if (file.is_open())
	{
		int n;
		file >> n;
		for (int i = 0; i < n; i++)
		{
			Product temp;
			file >> temp.code >> temp.name >> temp.number >> temp.price;
			shopstore.add(temp);
		}
		file.close();
	}
}
void f()
{
	cout << "\n\npress any key to continue";
	while (1)
		if (_kbhit())
			return;
}