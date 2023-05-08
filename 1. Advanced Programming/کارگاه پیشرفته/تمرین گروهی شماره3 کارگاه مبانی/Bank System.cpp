//Mohsen AliMohammadi
//Pouya AliKhanZade
//Hasan Aboyi
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
using namespace std;
//----------------------------------------------------------------------------------------
class Bank;
class Account;
void MainMenu();
int GetSizeBank(Bank & bank);
void BankMenu(Bank & bank, Account accounts[]);
void AccountMenu(Bank & bank, Account accounts[]);
//----------------------------------------------------------------------------------------
class Account
{
	friend class Bank;
public:
	Account()
	{
		Stock = 0;
	}
	//----------------------------------------------------------------------------------------
	void Amaliat()
	{
		int size = Result.size();
		for (size_t i = 0; i < size; i++)
		{
			if (i && Result[i] == ' ')
			{
				cout << "\n";
			}
			else
			{
				cout << Result[i];
			}
		}
	}
	//----------------------------------------------------------------------------------------
	void Enteqal(int size, Account accounts[], int Id, long long int AccNumSec)
	{
		int Maqsad = -1;
		for (size_t i = 0; i < size; i++)
		{
			if (accounts[i].AccNum == AccNumSec)
			{
				Maqsad = i;
			}
		}
		if (Maqsad != -1)
		{
			int Meqdar;
			cerr << "Meqdar Enteqal Be Hesabe " << AccNumSec << " Vared Konid: ";
			cin >> Meqdar;
			if (/*accounts[Id].*/Stock >= Meqdar)
			{
				/*accounts[Id].*/BardashtStock(Meqdar);
				accounts[Maqsad].VarizStock(Meqdar);
				cerr << "Enteqal Anjam Shod.\n";

				ostringstream convert, converts;
				convert << Meqdar;
				Result += " " + convert.str() + "Be";
				converts << AccNumSec;
				Result += converts.str() + "Enteqal";
			}
			else
			{
				cerr << "Mojodi Kafi Nist.\n";
			}
		}
		else
		{
			cerr << "Shomare Hesabe Maqsad Yaft Nashod.\n";
		}
	}
	//----------------------------------------------------------------------------------------
	void ChangePass(int pass)
	{
		int NewPass;
		if (Pass == pass)
		{
			cerr << "Ramz Jadid Ra Vared Konid: ";
			cin >> NewPass;
			Pass = NewPass;
			cerr << "Ramz Update Shod.\n";

			Result += " TaqirRamz";
		}
		else
		{
			cerr << "Ramz Eshtebah Ast.\n";
		}
	}
	//----------------------------------------------------------------------------------------
	void VarizStock(long long int stock)
	{
		Stock += stock;

		ostringstream convert;
		convert << stock;
		Result += " " + convert.str() + "Variz";
	}
	//----------------------------------------------------------------------------------------
	void BardashtStock(long long int stock)
	{
		Stock -= stock;

		ostringstream convert;
		convert << stock;
		Result += " " + convert.str() + "Bardasht";
	}
	//----------------------------------------------------------------------------------------
	long long int GetStock()
	{
		Result += " Mojodi";
		return Stock;
	}
	//----------------------------------------------------------------------------------------
	long long int GetStock(int i) const
	{
		return Stock;
	}
	//----------------------------------------------------------------------------------------
	long long int GetAccNum() const
	{
		return AccNum;
	}
	//----------------------------------------------------------------------------------------
private:
	long long int AccNum, Stock;
	int Pass;
	string Result;
};
//----------------------------------------------------------------------------------------
class Bank
{
public:
	Bank()
	{
		size = 0;
	}
	//----------------------------------------------------------------------------------------
	void CreateAccount(Account accounts[], long long int AccNum, int Pass)
	{
		accounts[size].AccNum = AccNum;
		accounts[size++].Pass = Pass;
		cerr << "Sabt Shod.\n";
	}
	//----------------------------------------------------------------------------------------
	bool Yekta(Account accounts[], int AccNum)
	{
		for (size_t i = 0; i < size; i++)
			if (accounts[i].AccNum == AccNum)
				return 0;
		return 1;
	}
	//----------------------------------------------------------------------------------------
	long long int SumOfStock(Account accounts[])
	{
		long long int sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += accounts[i].Stock;
		}
		return sum;
	}
	//----------------------------------------------------------------------------------------
	int SearchAccount(Account accounts[], long long int AccNum, int Pass)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (accounts[i].AccNum == AccNum && accounts[i].Pass == Pass)
			{
				return i;
			}
		}
		return -1;
	}
	//----------------------------------------------------------------------------------------
	int GetSize() const
	{
		return size;
	}
	//----------------------------------------------------------------------------------------
private:
	int size;
};
//----------------------------------------------------------------------------------------
int GetSizeBank(Bank & bank)
{
	return bank.GetSize();
}
//----------------------------------------------------------------------------------------
void BankMenu(Bank & bank, Account accounts[])
{
	int Choose;
	cerr << "1. Sabt Moshtari Jadid\n2. Barresie Tamame MojodiHa\n3. Back\nVared Konid: ";
	cin >> Choose;
	switch (Choose)
	{
	case 1:
		system("cls");
		long long int AccNum;
		int Pass;
		cerr << "Shomare Hesab: ";
		cin >> AccNum;
		if (bank.Yekta(accounts, AccNum) == 0)
		{
			cerr << "Shomare Hesab Mojod Ast.\n";
		}
		else
		{
			cerr << "Ramz: ";
			cin >> Pass;
			bank.CreateAccount(accounts, AccNum, Pass);
		}
		_getch();
		system("cls");
		MainMenu();
		break;
	case 2:
		system("cls");
		cerr << "Jame Tamame Mojodie MoshtariHa " << bank.SumOfStock(accounts) << " .\n";
		_getch();
		system("cls");
		MainMenu();
		break;
	default:
		system("cls");
		MainMenu();
		break;
	}
}
//----------------------------------------------------------------------------------------
void AccountMenu(Bank & bank, Account accounts[])
{
	int Id;
	if (bank.GetSize())
	{
		long long int AccNum;
		int Pass, stock, Choose;
		cerr << "Shomare Hesab Khod Ra Vared Konid: ";
		cin >> AccNum;
		cerr << "Ramz Obor Hesab Khod Ra Vared Konid: ";
		cin >> Pass;
		Id = bank.SearchAccount(accounts, AccNum, Pass);
		if (Id != -1)
		{
			while (1)
			{
				cerr << "1. Moshahedeye Mojodi Hesab\n";
				cerr << "2. Variz Be Hesab\n";
				cerr << "3. Bardasht Az Hesab\n";
				cerr << "4. Enteqal\n";
				cerr << "5. Moshahedeye AmaliatHaye Akhir\n";
				cerr << "6. Taqire Ramz Obor\n";
				cerr << "7. Back\n";
				cerr << "Vared Konid: ";
				cin >> Choose;
				switch (Choose)
				{
				case 1:
					system("cls");
					cerr << "Mojodi Hesabe " << accounts[Id].GetAccNum() << " : ";
					cerr << accounts[Id].GetStock() << "\n";
					_getch();
					system("cls");

					break;
				case 2:
					system("cls");
					cerr << "Ch Meqdar Variz Shavad: ";
					cin >> stock;
					accounts[Id].VarizStock(stock);
					cerr << "Variz Shod.\n";
					_getch();
					system("cls");

					break;
				case 3:
					system("cls");
					cerr << "Ch Meqdar Bardasht Shavad: ";
					cin >> stock;
					if (accounts[Id].GetStock(0) >= stock)
					{
						accounts[Id].BardashtStock(stock);
						cerr << "Bardasht Shod.\n";
					}
					else
					{
						cerr << "Mojodi Kafi Nist.\n";
					}
					_getch();
					system("cls");

					break;
				case 4:
					system("cls");
					long long int AccNumSec;
					cerr << "Shomare Hesabe Maqsad Ra Vared Konid: ";
					cin >> AccNumSec;
					accounts[Id].Enteqal(GetSizeBank(bank), accounts, Id, AccNumSec);
					_getch();
					system("cls");

					break;
				case 5:
					cerr << "AmaliatHaye Akhir " << accounts[Id].GetAccNum() << ":\n";
					accounts[Id].Amaliat();
					_getch();
					system("cls");

					break;
				case 6:
					system("cls");
					int pass;
					cerr << "Ramz Khod Ra Vared Konid: ";
					cin >> pass;
					accounts[Id].ChangePass(pass);
					_getch();
					system("cls");

					break;
				default:
					system("cls");
					MainMenu();
					break;
				}
			}
		}
		else
		{
			cerr << "Maqadire Vared Shode Sahih Nemibashad.\n";
			_getch();
			system("cls");
			MainMenu();
		}
	}
	else
	{
		cerr << "Hesabi Vared Nashode.\n";
		_getch();
		system("cls");
		MainMenu();
	}
}
//----------------------------------------------------------------------------------------
Bank bank;
Account accounts[100];
//----------------------------------------------------------------------------------------
void MainMenu()
{
	int Choose;
	cerr << "1. Bank\n2. Karbar\n3. Khoroj\nVared Konid: ";
	cin >> Choose;
	switch (Choose)
	{
	case 1:
		system("cls");
		BankMenu(bank, accounts);
		break;
	case 2:
		system("cls");
		AccountMenu(bank, accounts);
		break;
	default:
		exit(0);
		break;
	}
}
//----------------------------------------------------------------------------------------
int main()
{
	MainMenu();
	system("pause>0");
	return 0;
}