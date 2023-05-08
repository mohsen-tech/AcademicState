﻿#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <ctime>
using namespace std;
//-----------------------------------------------------------------------------------------
void Run();
void About();
void Frame();
void UserRun();
void AddAdmin();
void AdminRun();
void AdminMenu();
void RemoveSans();
void RemoveFilm();
void RemoveUser();
void RemoveChair();
void AmareForosh();
void RemoveConcert();
void VisitShowtimes();
void Create_AddUser();
void Create_AddFilm();
void Create_AddChair();
void Color(int number);
void Remove_AdminMenu();
void Create_AdminMenu();
void Create_AddConcert();
void gotoxy(int x, int y);
void Create_AddShowtimes();
void UserMenu(int UserIndex);
void VisitProgram(int UserIndex);
void UserMenu_Ticket(int UserIndex);
void UserMenu_VisitTicket(int UserIndex);
void UserMenu_RemoveTicket(int UserIndex);
void UserMenu_ChangePassword(int UserIndex);
//-----------------------------------------------------------------------------------------
class Film
{
public:
	void setFilm(int code, string name, string genere, int time, int year, string directoryName, int price)
	{
		Code = code;;
		Name = name;
		Genere = genere;
		Time = time;
		Year = year;
		DirectoryName = directoryName;
		Price = price;
		count++;
	}
	int getCode() const
	{
		return Code;
	}
	int getPrice() const
	{
		return Price;
	}
	string getName() const
	{
		return Name;
	}
	string getDirectoryName() const
	{
		return DirectoryName;
	}
	string getGenere() const
	{
		return Genere;
	}
	int getTime() const
	{
		return Time;
	}
	int getYear() const
	{
		return Year;
	}
	static int getCount()
	{
		return count;
	}
	static void setCount()
	{
		count--;
	}
private:
	int Code;
	string Name;
	string Genere;
	int Time;
	int Year;
	string DirectoryName;
	int Price;
	static int count;
};
int Film::count = 0;
Film films[100];
//-----------------------------------------------------------------------------------------
class Concert
{
public:
	void setConcert(int code, string name, string genere, vector <string> groupName, int price)
	{
		Code = code;
		Name = name;
		Genere = genere;
		GroupName = groupName;
		Price = price;
		count++;
	}
	int getCode() const
	{
		return Code;
	}
	int getPrice() const
	{
		return Price;
	}
	string getName() const
	{
		return Name;
	}
	string getGenere() const
	{
		return Genere;
	}
	static int getCount()
	{
		return count;
	}
	static void setCount()
	{
		count--;
	}
	bool SearchGroupName(string str)
	{
		for (size_t i = 0; i < GroupName.size(); i++)
			if (GroupName[i] == str)
				return true;
		return false;
	}
	void ShowGroupName()
	{
		for (size_t i = 0; i < GroupName.size(); i++)
		{
			cout << GroupName[i];
			if (i != GroupName.size() - 1)
				cout << " , ";
		}
	}
private:
	int Code;
	string Name;
	string Genere;
	vector <string> GroupName;
	int Price;
	static int count;
};
int Concert::count = 0;
Concert concerts[100];
//-----------------------------------------------------------------------------------------
class Person
{
public:
	Person()
	{
		Age = 0;
	}
	void setName(string name)
	{
		Name = name;
	}
	string getName() const
	{
		return Name;
	}
	void setFamily(string family)
	{
		Family = family;
	}
	string getFamily() const
	{
		return Family;
	}
	void setAge(int age)
	{
		Age = age;
	}
	int getAge() const
	{
		return Age;
	}
	void setSex(bool sex)
	{
		Sex = sex;
	}
	bool getSex() const
	{
		return Sex;
	}
	void setId(int id)
	{
		Id = id;
	}
	int getId() const
	{
		return Id;
	}
	void setPassword(int password)
	{
		Password = password;
	}
	int getPassword() const
	{
		return Password;
	}
protected:
	string Name;
	string Family;
	int Age;
	bool Sex; // True == Man , False == Woman
	int Id;
	int Password;
};
//-----------------------------------------------------------------------------------------
class Admin : public Person
{
public:
	void setAdmin(string name, string family, int age, bool sex, int id, int password)
	{
		Name = name;
		Family = family;
		Age = age;
		Sex = sex;
		Id = id;
		Password = password;
		count++;
	}
	static int getCount()
	{
		return count;
	}
private:
	static int count;
};
int Admin::count = 0;
Admin admins[20];
//-----------------------------------------------------------------------------------------
class Chair
{
	friend void RemoveUser();
	friend void UserMenu_Ticket(int UserIndex);
	friend void UserMenu_RemoveTicket(int UserIndex);
public:
	void setChair(int number, int row)
	{
		Number = number;
		Row = row;
	}
	bool Size(int number, int row)
	{
		if (number * row <= n)
			return true;
		return false;
	}
	int getNumber() const
	{
		return Number;
	}
	int getRow() const
	{
		return Row;
	}
private:
	int Number, Row;
	bool Chairs[11][11];
	int n = 100;
};
Chair chair;
//-----------------------------------------------------------------------------------------
class Showtimes
{
	friend void RemoveUser();
	friend void UserMenu_Ticket(int UserIndex);
	friend void UserMenu_RemoveTicket(int UserIndex);
public:
	void setShowtimes(int code, int codeProgram, string programName, int date, int hour)
	{
		Code = code;
		CodeProgram = codeProgram;
		ProgramName = programName;
		Date = date;
		Hour = hour;
		count++;
	}
	static int getCount()
	{
		return count;
	}
	static void setCount()
	{
		count--;
	}
	void setChair(Chair &chairObj)
	{
		chairs = chairObj;
	}
	void Selected(Film &filmObj)
	{
		film = filmObj;
		choose = true;
	}
	void Selected(Concert &concertObj)
	{
		concert = concertObj;
		choose = false;
	}
	int getCode()  const
	{
		return Code;
	}
	int getDate() const
	{
		return Date;
	}
	int getHour() const
	{
		return Hour;
	}
	int getCodeProgram()  const
	{
		return CodeProgram;
	}
	string getProgramName() const
	{
		return ProgramName;
	}
	bool getChoose() const
	{
		return choose;
	}
private:
	int Code;
	int CodeProgram;
	string ProgramName;
	int Date;
	int Hour;
	static int count;
	bool choose; // true == film , flase =  concert
	Chair chairs;
	Film film;
	Concert concert;
};
int Showtimes::count = 0;
Showtimes showtimes[100];
//-----------------------------------------------------------------------------------------
class Ticket
{
public:
	~Ticket()
	{
		count--;
	}
	void setTicket(int serial, int serialProgram, int price, int codeShowtimes, int date, int rowChair, int numberChair, string name, string family, int buyerCode)
	{
		Serial = serial;
		SerialProgram = serialProgram;
		Price = price;
		CodeShowtimes = codeShowtimes;
		Date = date;
		RowChair = rowChair;
		NumberChair = numberChair;
		Name = name;
		Family = family;
		BuyerCode = buyerCode;
		count++;
	}
	void Show(int buyerCode)
	{
		if (buyerCode == BuyerCode)
		{
			cout << "Serial: " << Serial << "\n";
			cout << "Price: " << Price << "\n";
			cout << "CodeShowtimes: " << CodeShowtimes << "\n";
			cout << "Date: " << Date << "\n";
			cout << "RowChair: " << RowChair << "\n";
			cout << "NumberChair: " << NumberChair << "\n";
		}
	}
	static void setCount()
	{
		count--;
	}
	static int getCount()
	{
		return count;
	}
	int getSerialProgram() const
	{
		return SerialProgram;
	}
	int getBuyerCode() const
	{
		return BuyerCode;
	}
	int getRowChair() const
	{
		return RowChair;
	}
	int getNumberChair() const
	{
		return NumberChair;
	}
	int getCodeShowtimes() const
	{
		return CodeShowtimes;
	}
	void setPrice(int price)
	{
		Price = price;
	}
	void setDate(int price)
	{
		Price = price;
	}
	int getPrice() const
	{
		return Price;
	}
	int getSerial() const
	{
		return Serial;
	}
private:
	int Serial;
	int SerialProgram;
	int Price;
	int CodeShowtimes;
	int Date;
	int RowChair;
	int NumberChair;
	string Name;
	string Family;
	int BuyerCode;
	static int count;
};
int Ticket::count = 0;
Ticket tickets[100];
//-----------------------------------------------------------------------------------------
class User : public Person
{
public:
	void setUser(string name, string family, int age, bool sex, int id, int password)
	{
		Name = name;
		Family = family;
		Age = age;
		Sex = sex;
		Id = id;
		Password = password;
		count++;
	}
	static int getCount()
	{
		return count;
	}
	static void setCount()
	{
		count--;
	}
private:
	static int count;
};
int User::count = 0;
User users[100];
//-----------------------------------------------------------------------------------------
int getIndexShowtimes(int Code, int Date)
{
	int length = Showtimes::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == showtimes[i].getCode() && Date == showtimes[i].getDate())
			return i;
	return -1;
}
//-----------------------------------------------------------------------------------------
bool YektaShowtimes(int Code, int Date)
{
	int length = Showtimes::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == showtimes[i].getCode() || Date == showtimes[i].getDate())
			return false;
	return true;
}
//-----------------------------------------------------------------------------------------
int getIndexConcert(int Code, string Name)
{
	int length = Concert::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == concerts[i].getCode() && Name == concerts[i].getName())
			return i;
	return -1;
}
//-----------------------------------------------------------------------------------------
bool YektaConcert(int Code, string Name)
{
	int length = Concert::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == concerts[i].getCode() || Name == concerts[i].getName())
			return false;
	return true;
}
//-----------------------------------------------------------------------------------------
int getIndexFilm(int Code, string Name)
{
	int length = Film::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == films[i].getCode() && Name == films[i].getName())
			return i;
	return -1;
}
//-----------------------------------------------------------------------------------------
bool YektaFilm(int Code, string Name)
{
	int length = Film::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == films[i].getCode() || Name == films[i].getName())
			return false;
	return true;
}
//-----------------------------------------------------------------------------------------
int getIndexAdmin(int Id, int Password)
{
	int length = Admin::getCount();
	for (size_t i = 0; i < length; i++)
		if (Id == admins[i].getId() && Password == admins[i].getPassword())
			return i;
	return -1;
}
//-----------------------------------------------------------------------------------------
bool YektaAdmin(int Id, int Password)
{
	int length = Admin::getCount();
	for (size_t i = 0; i < length; i++)
		if (Id == admins[i].getId() || Password == admins[i].getPassword())
			return false;
	return true;
}
//-----------------------------------------------------------------------------------------
int getIndexUser(int Id, int Password)
{
	int length = User::getCount();
	for (size_t i = 0; i < length; i++)
		if (Id == users[i].getId() && Password == users[i].getPassword())
			return i;
	return -1;
}
//-----------------------------------------------------------------------------------------
bool YektaUser(int Id, int Password)
{
	int length = User::getCount();
	for (size_t i = 0; i < length; i++)
		if (Id == users[i].getId() || Password == users[i].getPassword())
			return false;
	return true;
}
//-----------------------------------------------------------------------------------------
int main()
{
	Color(0xF9);
	system("cls");
	Run();
	system("pause>0");
	return 0;
}
//-----------------------------------------------------------------------------------------
void Run()
{
	Frame();
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "Cinema Ticket";
	gotoxy(x + 2, y + 4);
	cout << "Vorod Be Onvane?";
	gotoxy(x + 2, y + 7);
	cout << "1.Admin";
	gotoxy(x + 2, y + 10);
	cout << "2.User";
	gotoxy(x + 2, y + 13);
	cout << "3.About";
	gotoxy(x + 2, y + 16);
	cout << "4.Exit";
	y += 7;
	char ch;
	while (true)
	{
		gotoxy(x, y);
		cout << ">";
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 11)
			{
				y = 20;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 20)
			{
				y = 11;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 11)
			{
				system("cls");
				AdminRun();
			}
			else if (y == 14)
			{
				system("cls");
				UserRun();
			}
			else if (y == 17)
			{
				system("cls");
				About();
			}
			else if (y == 20)
			{
				system("cls");
				exit(0);
			}
		}
		else if (ch == 27)
		{
			system("cls");
			exit(0);
		}
	}
}
//-----------------------------------------------------------------------------------------
void UserRun()
{
	Frame();
	int Id, Password;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- User -";
	gotoxy(x, y + 4);
	cout << "Enter Id: ";
	cin >> Id;
	gotoxy(x, y + 7);
	cout << "Enter Password: ";
	char ch;
	int number = 0, i = 0;
	int xxx = x + 16, yyy = y + 7;
	while (true && i < 8)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
		else if (!('0' <= ch && ch <= '9'))
		{
			gotoxy(4, 23);
			cout << "Password Bayad Adad Bashad!";
			_getch();
			system("cls");
			Run();
		}
		gotoxy(xxx++, yyy);
		cout << "*";
		number = ch - '0' + 10 * number;
		i++;
	}
	Password = number;
	int Index = getIndexUser(Id, Password);
	if (Index != -1)
	{
		system("cls");
		UserMenu(Index);
	}
	else
	{
		gotoxy(4, 23);
		cout << "Maqadire Vared Shode Dorost Nist!";
		_getch();
		system("cls");
		Run();
	}
}
//-----------------------------------------------------------------------------------------
void UserMenu(int UserIndex)
{
	Frame();
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- User Menu -";
	gotoxy(x + 2, y + 4);
	cout << "1.Taqir Ramz";
	gotoxy(x + 2, y + 7);
	cout << "2.Kharid Blit";
	gotoxy(x + 2, y + 10);
	cout << "3.Moshahedeye Tamami BlitHa";
	gotoxy(x + 2, y + 13);
	cout << "4.Moshahedeye BarnameHa";
	gotoxy(x + 2, y + 16);
	cout << "5.Ebtal Blit";
	gotoxy(x + 2, y + 19);
	cout << "6.Back";
	y += 4;
	char ch;
	while (true)
	{
		gotoxy(x, y);
		cout << ">";
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 23;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 23)
			{
				y = 8;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 8)
			{
				system("cls");
				UserMenu_ChangePassword(UserIndex);
			}
			else if (y == 11)
			{
				system("cls");
				UserMenu_Ticket(UserIndex);
			}
			else if (y == 14)
			{
				system("cls");
				UserMenu_VisitTicket(UserIndex);
			}
			else if (y == 17)
			{
				system("cls");
				VisitProgram(UserIndex);
			}
			else if (y == 20)
			{
				system("cls");
				UserMenu_RemoveTicket(UserIndex);
			}
			else if (y == 23)
			{
				system("cls");
				Run();
			}
		}
		else if (ch == 27)
		{
			system("cls");
			Run();
		}
	}
}
//-----------------------------------------------------------------------------------------
void VisitProgram(int UserIndex)
{
	Frame();
	int x = 7, y = 4;
	string str;
	gotoxy(x + 3, y - 1);
	cout << "- Moshahedeye BarnameHa -";
	gotoxy(2, y + 4);
	cout << "Mesle Google Search Kon: ";
	cin >> str;
	int length = Film::getCount();
	for (size_t i = 0; i < length; i++)
	{
		if (films[i].getName() == str || films[i].getDirectoryName() == str)
		{
			gotoxy(x, y + 7);
			cout << "Code: " << films[i].getCode();
			gotoxy(x, y + 10);
			cout << "Name: " << films[i].getName();
			gotoxy(x, y + 13);
			cout << "Genere: " << films[i].getGenere();
			gotoxy(x, y + 16);
			cout << "Modat Zaman: " << films[i].getTime();
			gotoxy(x, y + 19);
			cout << "Sale Sakht: " << films[i].getYear();
			gotoxy(x, y + 22);
			cout << "Kargardan: " << films[i].getDirectoryName();
			gotoxy(x, y + 25);
			cout << "Qeymat: " << films[i].getPrice();
			_getch();
			system("cls");
			UserMenu(UserIndex);
		}
	}
	length = Concert::getCount();
	for (size_t i = 0; i < length; i++)
	{
		if (concerts[i].getName() == str || concerts[i].SearchGroupName(str) == true)
		{
			gotoxy(x, y + 7);
			cout << "Code: " << concerts[i].getCode();
			gotoxy(x, y + 10);
			cout << "Name: " << concerts[i].getName();
			gotoxy(x, y + 13);
			cout << "Genere: " << concerts[i].getGenere();
			gotoxy(4, y + 16);
			cout << "Azaye Goroh: ";
			gotoxy(x, y + 17);
			concerts[i].ShowGroupName();
			gotoxy(x, y + 20);
			cout << "Qeymat: " << concerts[i].getPrice();
			_getch();
			system("cls");
			UserMenu(UserIndex);
		}
	}
	gotoxy(x, y + 22);
	cout << "Barname Yaft Nashod!";
	_getch();
	system("cls");
	UserMenu(UserIndex);
}
//-----------------------------------------------------------------------------------------
void UserMenu_RemoveTicket(int UserIndex)
{
	Frame();
	int x = 7, y = 4;
	int Serial;
	gotoxy(x + 6, y - 1);
	cout << "- Ebtal Blit -";
	gotoxy(x, y + 4);
	cout << "Shomare Serial Blit: ";
	cin >> Serial;
	int length = Ticket::getCount();
	int TicketIndex = -1;
	for (size_t i = 0; i < length; i++)
	{
		if (Serial == tickets[i].getSerial() && users[UserIndex].getId() == tickets[i].getBuyerCode())
		{
			TicketIndex = i;
		}
	}
	if (TicketIndex != -1)
	{
		int length1 = Showtimes::getCount();
		for (size_t i = 0; i < length1; i++)
		{
			if (tickets[TicketIndex].getCodeShowtimes() == showtimes[i].getCode())
			{
				showtimes[i].chairs.Chairs[tickets[TicketIndex].getRowChair()][tickets[TicketIndex].getNumberChair()] = false;
				break;
			}
		}
		for (size_t i = TicketIndex; i < length - 1; i++)
		{
			tickets[i] = tickets[i + 1];
		}
		Ticket::setCount();
		gotoxy(x, y + 7);
		cout << "Blit Batel Shod!";
		_getch();
		system("cls");
	}
	else
	{
		cout << "Blit Yaft Nashod!";
		_getch();
		system("cls");
	}
	UserMenu(UserIndex);
}
//-----------------------------------------------------------------------------------------
void UserMenu_VisitTicket(int UserIndex)
{
	int length = Ticket::getCount();
	cout << users[UserIndex].getName() << " " << users[UserIndex].getFamily() << "\n\n";
	for (size_t i = 0; i < length; i++)
	{
		tickets[i].Show(users[UserIndex].getId());
		cout << "\n\n";
	}
	if (length == 0)
	{
		cout << "Blit Vojod Nadarad!\n";
	}
	int sw = 0;
	char back;
	while (sw == 0)
	{
		back = _getch();
		if (back == 27)
		{
			sw = 1;
			system("cls");
			UserMenu(UserIndex);
		}
	}
}
//-----------------------------------------------------------------------------------------
void UserMenu_Ticket(int UserIndex)
{
	gotoxy(50, 0);
	cout << "Name Barname \t Zaman Ejra";
	int xx = 1;
	int length = Showtimes::getCount();
	for (size_t i = 0; i < length; i++)
	{
		gotoxy(50, xx += 3);
		cout << showtimes[i].getProgramName() << " \t" << showtimes[i].getDate();
	}
	Frame();
	const int x = 7, y = 4;
	int Date, Index = -1;
	gotoxy(x + 6, y - 1);
	cout << "- Kharid Blit -";
	gotoxy(x, y + 4);
	cout << "Tarikh Barname: ";
	cin >> Date;
	for (size_t i = 0; i < length; i++)
	{
		if (showtimes[i].getDate() == Date)
		{
			Index = i;
			break;
		}
	}
	if (Index == -1)
	{
		gotoxy(x + 2, y + 7);
		cout << "Yaft Nashod!";
		_getch();
		system("cls");
		UserMenu(UserIndex);
	}
	else
	{
		system("cls");
		Frame();
		gotoxy(x + 6, y - 1);
		cout << "- Kharid Blit -";
		xx = 1;
		for (size_t i = 0; i < showtimes[Index].chairs.Row; i++)
		{
			gotoxy(50, i);
			for (size_t j = 0; j < showtimes[Index].chairs.Number; j++)
				if (showtimes[Index].chairs.Chairs[i][j] == false)
				{
					cout << i << "," << j << "  ";
				}
				else
				{
					cout << "     ";
				}
			cout << "\n\n";
		}
		int Radif, Soton;
		gotoxy(x, y + 4);
		cout << "Radif: ";
		cin >> Radif;
		gotoxy(x, y + 7);
		cout << "Soton: ";
		cin >> Soton;
		gotoxy(x, y + 10);
		if (Radif < showtimes[Index].chairs.Row && Soton < showtimes[Index].chairs.Number)
		{
			if (showtimes[Index].chairs.Chairs[Radif][Soton] == false)
			{
				showtimes[Index].chairs.Chairs[Radif][Soton] = true;
				int TicketIndex = Ticket::getCount();
				int iSecret;
				srand(time(NULL));
				iSecret = rand() % 9000000 + 1000000;
				if (showtimes[Index].getChoose() == true)
				{
					tickets[TicketIndex].setTicket(iSecret, showtimes[Index].getCodeProgram(),
						showtimes[Index].film.getPrice(), showtimes[Index].getCode(),
						showtimes[Index].getDate(), Radif,
						Soton, users[UserIndex].getName(),
						users[UserIndex].getFamily(), users[UserIndex].getId()
					);
				}
				else
				{
					tickets[TicketIndex].setTicket(iSecret, showtimes[Index].getCodeProgram(),
						showtimes[Index].concert.getPrice(), showtimes[Index].getCode(),
						showtimes[Index].getDate(), Radif,
						Soton, users[UserIndex].getName(),
						users[UserIndex].getFamily(), users[UserIndex].getId()
					);
				}
				cout << "Done!";
			}
			else
			{
				cout << "Sandali Rezerv Ast!";
			}
		}
		else
		{
			cout << "Na Motabar!";
		}
	}
	_getch();
	system("cls");
	UserMenu(UserIndex);
}
//-----------------------------------------------------------------------------------------
void UserMenu_ChangePassword(int UserIndex)
{
	Frame();
	int x = 7, y = 4;
	int Id, Password;
	gotoxy(x + 6, y - 1);
	cout << "- Taqir Ramz -";
	gotoxy(x, y + 4);
	cout << "Ramz Qadimi: ";
	cin >> Password;
	if (Password == users[UserIndex].getPassword())
	{
		gotoxy(x, y + 7);
		cout << "Ramz Jadid: ";
		cin >> Password;
		users[UserIndex].setPassword(Password);

		gotoxy(x, y + 12);
		cout << "Ramz Jadid Update Shod!";
		_getch();
	}
	else
	{
		gotoxy(x, y + 12);
		cout << "Ramz Na Motabar Ast!";
		_getch();
	}
	system("cls");
	UserMenu(UserIndex);
}
//-----------------------------------------------------------------------------------------
void AdminRun()
{
	Frame();
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Admin -";
	gotoxy(x + 2, y + 4);
	cout << "1.Ezafe Krdn Admin";
	gotoxy(x + 2, y + 7);
	cout << "2.Menu Admin";
	gotoxy(x + 2, y + 10);
	cout << "3.Back";
	y += 4;
	char ch;
	while (true)
	{
		gotoxy(x, y);
		cout << ">";
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 14;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 14)
			{
				y = 8;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 8)
			{
				system("cls");
				AddAdmin();
				system("cls");
				AdminRun();
			}
			else if (y == 11)
			{
				int Id, Password;
				gotoxy(5, 17);
				cout << "Enter Id: ";
				cin >> Id;
				gotoxy(5, 20);
				cout << "Enter Password: ";
				char ch;
				int number = 0, i = 0;
				int xxx = 21, yyy = 20;
				while (true && i < 8)
				{
					ch = _getch();
					if (ch == 13)
					{
						break;
					}
					else if (!('0' <= ch && ch <= '9'))
					{
						gotoxy(4, 23);
						cout << "Password Bayad Adad Bashad!";
						_getch();
						system("cls");
						AdminRun();
					}
					gotoxy(xxx++, yyy);
					cout << "*";
					number = ch - '0' + 10 * number;
					i++;
				}
				Password = number;
				if (getIndexAdmin(Id, Password) != -1)
				{
					system("cls");
					AdminMenu();
				}
				else
				{
					gotoxy(4, 23);
					cout << "Maqadire Vared Shode Dorost Nist!";
					_getch();
					system("cls");
					AdminRun();
				}
			}
			else if (y == 14)
			{
				system("cls");
				Run();
			}
		}
		else if (ch == 27)
		{
			system("cls");
			Run();
		}
	}
}
//-----------------------------------------------------------------------------------------
void AdminMenu()
{
	Frame();
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Admin Menu -";
	gotoxy(x + 2, y + 4);
	cout << "1.Ijad";
	gotoxy(x + 2, y + 7);
	cout << "2.Hazf";
	gotoxy(x + 2, y + 10);
	cout << "3.Virayesh EtelaAte Blit";
	gotoxy(x + 2, y + 13);
	cout << "4.Gozareshe Amare Forosh";
	gotoxy(x + 2, y + 16);
	cout << "5.Moshahedeye SansHa";
	gotoxy(x + 2, y + 19);
	cout << "6.Back";
	y += 4;
	char ch;
	while (true)
	{
		gotoxy(x, y);
		cout << ">";
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 23;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 23)
			{
				y = 8;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 8)
			{
				system("cls");
				Create_AdminMenu();
			}
			else if (y == 11)
			{
				system("cls");
				Remove_AdminMenu();
			}
			else if (y == 14)
			{
				system("cls");
				Frame();
				gotoxy(7, 10);
				cout << "Mored Dare!";
				_getch();
				system("cls");
				AdminMenu();
			}
			else if (y == 17)
			{
				system("cls");
				AmareForosh();
			}
			else if (y == 20)
			{
				system("cls");
				VisitShowtimes();
			}
			else if (y == 23)
			{
				system("cls");
				AdminRun();
			}
		}
		else if (ch == 27)
		{
			system("cls");
			AdminRun();
		}
	}
}
//-----------------------------------------------------------------------------------------
void Remove_AdminMenu()
{
	Frame();
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Hazf Krdn -";
	gotoxy(x + 2, y + 4);
	cout << "1.Karbar";
	gotoxy(x + 2, y + 7);
	cout << "2.Film";
	gotoxy(x + 2, y + 10);
	cout << "3.Concert";
	gotoxy(x + 2, y + 13);
	cout << "4.Sans";
	gotoxy(x + 2, y + 16);
	cout << "5.Sandali";
	gotoxy(x + 2, y + 19);
	cout << "6.Back";
	y += 4;
	char ch;
	while (true)
	{
		gotoxy(x, y);
		cout << ">";
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 23;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 23)
			{
				y = 8;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 8)
			{
				system("cls");
				RemoveUser();
				_getch();
				system("cls");
				Remove_AdminMenu();
			}
			else if (y == 11)
			{
				system("cls");
				RemoveFilm();
				_getch();
				system("cls");
				Remove_AdminMenu();
			}
			else if (y == 14)
			{
				system("cls");
				RemoveConcert();
				_getch();
				system("cls");
				Remove_AdminMenu();
			}
			else if (y == 17)
			{
				system("cls");
				RemoveSans();
				_getch();
				system("cls");
				Remove_AdminMenu();
			}
			else if (y == 20)
			{
				system("cls");
				RemoveChair();
				_getch();
				system("cls");
				Remove_AdminMenu();
			}
			else if (y == 23)
			{
				system("cls");
				AdminMenu();
			}
		}
		else if (ch == 27)
		{
			system("cls");
			AdminMenu();
		}
	}
}
//-----------------------------------------------------------------------------------------
void RemoveChair()
{
	Frame();
	int Row, Number;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Hazf Krdn Sandali -";
	gotoxy(2, y + 4);
	cout << "Bayad Radif Va Soton Jadid Ra Vared Konid";
	gotoxy(2, y + 5);
	cout << "*Ba Taqire Sandali BlitHa Hazf Mishavand";
	gotoxy(x, y + 8);
	cout << "Radif: ";
	cin >> Row;
	gotoxy(x, y + 11);
	cout << "Soton: ";
	cin >> Number;
	gotoxy(x, y + 14);
	if (chair.Size(Number, Row) == true)
	{
		chair.setChair(Number, Row);
		int length = Showtimes::getCount();
		for (size_t i = 0; i < length; i++)
		{
			showtimes[i].setChair(chair);
		}
		length = Ticket::getCount();
		for (size_t i = 0; i < length; i++)
		{
			tickets[i].~Ticket();
		}
		cout << "Done!";
	}
	else cout << "Bishtar Az Hade Mojaz!";
}
//-----------------------------------------------------------------------------------------
void RemoveSans()
{
	Frame();
	string Name;
	int Code;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Hazf Krdn Sans -";
	gotoxy(x, y + 4);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 7);
	cout << "Code: ";
	cin >> Code;
	int ShowtimesIndex = -1;
	int length = Showtimes::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == showtimes[i].getCode() && Name == showtimes[i].getProgramName())
			ShowtimesIndex = i;
	if (ShowtimesIndex == -1)
	{
		gotoxy(x, y + 13);
		cout << "Sans Yaft Nashod!";
		return;
	}
	int length1 = Ticket::getCount();
	for (size_t j = 0; j < length1; j++)
	{
		if (showtimes[ShowtimesIndex].getCode() == tickets[j].getCodeShowtimes())
		{
			for (size_t k = j; k < length1 - 1; k++)
			{
				tickets[k] = tickets[k + 1];
			}
			Ticket::setCount();
			length1 = Ticket::getCount();
		}
	}
	for (size_t k = ShowtimesIndex; k < length - 1; k++)
	{
		showtimes[k] = showtimes[k + 1];
	}
	Showtimes::setCount();
	gotoxy(x, y + 13);
	cout << "Sans Hazf Shod!";
}
//-----------------------------------------------------------------------------------------
void RemoveConcert()
{
	Frame();
	string Name;
	int Code;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Hazf Krdn Concert -";
	gotoxy(x, y + 4);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 7);
	cout << "Code: ";
	cin >> Code;
	int ConcertIndex = -1;
	int length = Concert::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == concerts[i].getCode() && Name == concerts[i].getName())
			ConcertIndex = i;
	if (ConcertIndex == -1)
	{
		gotoxy(x, y + 13);
		cout << "Concert Yaft Nashod!";
		return;
	}
	length = Showtimes::getCount();
	for (size_t i = 0; i < length; i++)
	{
		if (concerts[ConcertIndex].getCode() == showtimes[i].getCodeProgram())
		{
			int length1 = Ticket::getCount();
			for (size_t j = 0; j < length1; j++)
			{
				if (showtimes[i].getCode() == tickets[j].getCodeShowtimes())
				{
					for (size_t k = j; k < length1 - 1; k++)
					{
						tickets[k] = tickets[k + 1];
					}
					Ticket::setCount();
					length1 = Ticket::getCount();
				}
			}
			for (size_t k = i; k < length - 1; k++)
			{
				showtimes[k] = showtimes[k + 1];
			}
			Showtimes::setCount();
			length = Showtimes::getCount();
		}
	}
	length = Concert::getCount();
	for (size_t j = ConcertIndex; j < length - 1; j++)
	{
		concerts[j] = concerts[j + 1];
	}
	Concert::setCount();
	gotoxy(x, y + 13);
	cout << "Concert Hazf Shod!";
}
//-----------------------------------------------------------------------------------------
void RemoveFilm()
{
	Frame();
	string Name;
	int Code;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Hazf Krdn Film -";
	gotoxy(x, y + 4);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 7);
	cout << "Code: ";
	cin >> Code;
	int FilmIndex = -1;
	int length = Film::getCount();
	for (size_t i = 0; i < length; i++)
		if (Code == films[i].getCode() && Name == films[i].getName())
			FilmIndex = i;
	if (FilmIndex == -1)
	{
		gotoxy(x, y + 13);
		cout << "Film Yaft Nashod!";
		return;
	}
	length = Showtimes::getCount();
	for (size_t i = 0; i < length; i++)
	{
		if (films[FilmIndex].getCode() == showtimes[i].getCodeProgram())
		{
			int length1 = Ticket::getCount();
			for (size_t j = 0; j < length1; j++)
			{
				if (showtimes[i].getCode() == tickets[j].getCodeShowtimes())
				{
					for (size_t k = j; k < length1 - 1; k++)
					{
						tickets[k] = tickets[k + 1];
					}
					Ticket::setCount();
					length1 = Ticket::getCount();
				}
			}
			for (size_t k = i; k < length - 1; k++)
			{
				showtimes[k] = showtimes[k + 1];
			}
			Showtimes::setCount();
			length = Showtimes::getCount();
		}
	}
	length = Film::getCount();
	for (size_t j = FilmIndex; j < length - 1; j++)
	{
		films[j] = films[j + 1];
	}
	Film::setCount();
	gotoxy(x, y + 13);
	cout << "Film Hazf Shod!";
}
//-----------------------------------------------------------------------------------------
void RemoveUser()
{
	Frame();
	string Name;
	int Id;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Hazf Krdn User -";
	gotoxy(x, y + 4);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 7);
	cout << "Id: ";
	cin >> Id;
	int UserIndex = -1;
	int length = User::getCount();
	for (size_t i = 0; i < length; i++)
		if (Id == users[i].getId() && Name == users[i].getName())
			UserIndex = i;
	if (UserIndex == -1)
	{
		gotoxy(x, y + 13);
		cout << "Karbar Yaft Nashod!";
		return;
	}
	length = Ticket::getCount();
	for (size_t i = 0; i < length; i++)
	{
		if (users[UserIndex].getId() == tickets[i].getBuyerCode())
		{
			int length1 = Showtimes::getCount();
			for (size_t j = 0; j < length1; j++)
			{
				if (tickets[i].getCodeShowtimes() == showtimes[j].getCode())
				{
					showtimes[j].chairs.Chairs[tickets[i].getRowChair()][tickets[i].getNumberChair()] = false;
				}
			}
			for (size_t j = i; j < length - 1; j++)
			{
				tickets[j] = tickets[j + 1];
			}
			Ticket::setCount();
			length = Ticket::getCount();
		}
	}
	length = User::getCount();
	for (size_t j = UserIndex; j < length - 1; j++)
	{
		users[j] = users[j + 1];
	}
	User::setCount();
	gotoxy(x, y + 13);
	cout << "Karbar Hazf Shod!";
}
//-----------------------------------------------------------------------------------------
void VisitShowtimes()
{
	Frame();
	int x = 7, y = 4;
	int Date;
	gotoxy(x + 6, y - 1);
	cout << "- Moshahedeye SansHa -";
	gotoxy(x, y + 4);
	cout << "Tarikh Barname: ";
	cin >> Date;
	int length = Showtimes::getCount();
	int sw = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (showtimes[i].getDate() == Date)
		{
			gotoxy(x, y + 7);
			cout << "Code: " << showtimes[i].getCode();
			gotoxy(x, y + 10);
			cout << "Code Barname: " << showtimes[i].getCodeProgram();
			gotoxy(x, y + 13);
			cout << "Name Barname: " << showtimes[i].getProgramName();
			gotoxy(x, y + 16);
			cout << "Tarikh Barname: " << showtimes[i].getDate();
			gotoxy(x, y + 19);
			cout << "Saat Barname: " << showtimes[i].getHour();
			sw = 1;
			break;
		}
	}
	if (sw == 0)
	{
		gotoxy(x, y + 16);
		cout << "Yaft Nashod!";
	}
	_getch();
	system("cls");
	AdminMenu();
}
//-----------------------------------------------------------------------------------------
void AmareForosh()
{
	Frame();
	int x = 7, y = 4;
	string Name;
	gotoxy(x + 6, y - 1);
	cout << "- Amare Forosh -";
	gotoxy(x, y + 4);
	cout << "Name Barname: ";
	cin >> Name;

	int ProgramCode = -1;
	int length = Film::getCount();
	for (size_t i = 0; i < length; i++)
	{
		if (Name == films[i].getName())
		{
			ProgramCode = films[i].getCode();
			break;
		}
	}
	if (ProgramCode == -1)
	{
		length = Concert::getCount();
		for (size_t i = 0; i < length; i++)
		{
			if (Name == concerts[i].getName())
			{
				ProgramCode = concerts[i].getCode();
				break;
			}
		}
	}
	int cnt = 0;
	int foroshKol = 0;
	if (ProgramCode != -1)
	{
		length = Ticket::getCount();
		for (size_t i = 0; i < length; i++)
		{
			if (ProgramCode == tickets[i].getSerialProgram())
			{
				cnt++;
				foroshKol += tickets[i].getPrice();
			}
		}
		gotoxy(x, y + 7);
		cout << "Barnameye " << Name;
		gotoxy(x, y + 10);
		cout << "Tedad Blit " << cnt;
		gotoxy(x, y + 13);
		cout << "Forosh Kol " << foroshKol;
	}
	else
	{
		gotoxy(x, y + 13);
		cout << "Barname Yaft Nashod";
	}
	_getch();
	system("cls");
	AdminMenu();
}
//-----------------------------------------------------------------------------------------
void Create_AdminMenu()
{
	Frame();
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ijad Krdn -";
	gotoxy(x + 2, y + 4);
	cout << "1.Karbar";
	gotoxy(x + 2, y + 7);
	cout << "2.Film";
	gotoxy(x + 2, y + 10);
	cout << "3.Concert";
	gotoxy(x + 2, y + 13);
	cout << "4.Sans";
	gotoxy(x + 2, y + 16);
	cout << "5.Sandali";
	gotoxy(x + 2, y + 19);
	cout << "6.Back";
	y += 4;
	char ch;
	while (true)
	{
		gotoxy(x, y);
		cout << ">";
		ch = _getch();
		gotoxy(x, y);
		cout << " ";
		if (ch == 72)
		{
			y -= 3;
			if (y < 8)
			{
				y = 23;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 80)
		{
			y += 3;
			if (y > 23)
			{
				y = 8;
			}
			gotoxy(x + 2, y);
		}
		else if (ch == 13)
		{
			if (y == 8)
			{
				system("cls");
				Create_AddUser();
				system("cls");
				Create_AdminMenu();
			}
			else if (y == 11)
			{
				system("cls");
				Create_AddFilm();
				system("cls");
				Create_AdminMenu();
			}
			else if (y == 14)
			{
				system("cls");
				Create_AddConcert();
				system("cls");
				Create_AdminMenu();
			}
			else if (y == 17)
			{
				system("cls");
				Create_AddShowtimes();
				system("cls");
				Create_AdminMenu();
			}
			else if (y == 20)
			{
				system("cls");
				Create_AddChair();
				system("cls");
				Create_AdminMenu();
			}
			else if (y == 23)
			{
				system("cls");
				AdminMenu();
			}
		}
		else if (ch == 27)
		{
			system("cls");
			AdminMenu();
		}
	}
}
//-----------------------------------------------------------------------------------------
void Create_AddChair()
{
	Frame();
	int Row, Number;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ezafe Krdn Sandali -";
	gotoxy(x, y + 4);
	cout << "Radif: ";
	cin >> Row;
	gotoxy(x, y + 7);
	cout << "Soton: ";
	cin >> Number;
	gotoxy(x, y + 10);
	if (chair.Size(Number, Row) == true)
	{
		chair.setChair(Number, Row);
		int length = Showtimes::getCount();
		for (size_t i = 0; i < length; i++)
		{
			showtimes[i].setChair(chair);
		}
		cout << "Done!";
	}
	else cout << "Bishtar Az Hade Mojaz!";
	_getch();
}
//-----------------------------------------------------------------------------------------
void Create_AddShowtimes()
{
	Frame();
	int Code;
	int CodeProgram;
	string ProgramName;
	int Date;
	int Hour;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ezafe Krdn Sans -";
	gotoxy(x, y + 4);
	cout << "Code: ";
	cin >> Code;
	gotoxy(x, y + 7);
	cout << "Code Barname: ";
	cin >> CodeProgram;
	gotoxy(x, y + 10);
	cout << "Name Barname: ";
	cin >> ProgramName;
	gotoxy(x, y + 13);
	cout << "Tarikh Barname: ";
	cin >> Date;
	gotoxy(x, y + 16);
	cout << "Saat Barname: ";
	cin >> Hour;
	bool swYekta = YektaShowtimes(Code, Date);
	gotoxy(x, y + 19);
	if (swYekta == true)
	{
		int sw = -1, sw2 = 0;
		sw = getIndexFilm(CodeProgram, ProgramName);
		if (sw != -1)
		{
			int Index = Showtimes::getCount();
			showtimes[Index].setShowtimes(Code, CodeProgram, ProgramName, Date, Hour);
			showtimes[Index].setChair(chair);
			showtimes[Index].Selected(films[sw]);
			cout << "Done!";
			sw2 = 1;
		}
		sw = getIndexConcert(CodeProgram, ProgramName);
		if (sw != -1)
		{
			int Index = Showtimes::getCount();
			showtimes[Index].setShowtimes(Code, CodeProgram, ProgramName, Date, Hour);
			showtimes[Index].setChair(chair);
			showtimes[Index].Selected(concerts[sw]);
			cout << "Done!";
			sw2 = 1;
		}
		else if (sw2 == 0)
		{
			cout << "Maqadire Vared Shode Dorost Nist!";
		}
	}
	else cout << "Maqadire Vared Shode Tekrarist!";
	_getch();
}
//-----------------------------------------------------------------------------------------
void Create_AddConcert()
{
	Frame();
	int Code;
	string Name;
	string Genere;
	vector <string> GroupName;
	string str;
	int Price;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ezafe Krdn Concert -";
	gotoxy(x, y + 4);
	cout << "Code: ";
	cin >> Code;
	gotoxy(x, y + 7);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 10);
	cout << "Genere: ";
	cin >> Genere;
	gotoxy(x, y + 13);
	cout << "Group Name: (End = 0)";
	gotoxy(x, y + 14);
	while (cin >> str &&  str != "0")
	{
		GroupName.push_back(str);
	}
	gotoxy(x, y + 17);
	cout << "Price: ";
	cin >> Price;
	gotoxy(x, y + 20);
	bool sw = YektaFilm(Code, Name);
	if (sw == true)
	{
		int Index = Concert::getCount();
		concerts[Index].setConcert(Code, Name, Genere, GroupName, Price);
		cout << "Done!";
	}
	else cout << "Maqadire Vared Shode Tekrarist!";
	_getch();
}
//-----------------------------------------------------------------------------------------
void Create_AddFilm()
{
	Frame();
	int Code;
	string Name;
	string Genere;
	int Time;
	int Year;
	string DirectoryName;
	int Price;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ezafe Krdn Film -";
	gotoxy(x, y + 4);
	cout << "Code: ";
	cin >> Code;
	gotoxy(x, y + 7);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 10);
	cout << "Genere: ";
	cin >> Genere;
	gotoxy(x, y + 13);
	cout << "Time: ";
	cin >> Time;
	gotoxy(x, y + 16);
	cout << "Year: ";
	cin >> Year;
	gotoxy(x, y + 19);
	cout << "Directory Name: ";
	cin >> DirectoryName;
	gotoxy(x, y + 22);
	cout << "Price: ";
	cin >> Price;
	gotoxy(x, y + 25);
	bool sw = YektaFilm(Code, Name);
	if (sw == true)
	{
		int Index = Film::getCount();
		films[Index].setFilm(Code, Name, Genere, Time, Year, DirectoryName, Price);
		cout << "Done!";
	}
	else cout << "Maqadire Vared Shode Tekrarist!";
	_getch();
}
//-----------------------------------------------------------------------------------------
void Create_AddUser()
{
	Frame();
	string Name;
	string Family;
	int Age;
	bool Sex;
	int Id;
	int Password;
	bool sw;
	string gender;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ezafe Krdn User -";
	gotoxy(x, y + 4);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 7);
	cout << "Family: ";
	cin >> Family;
	gotoxy(x, y + 10);
	cout << "Age: ";
	cin >> Age;
	gotoxy(x, y + 13);
	cout << "Id: ";
	cin >> Id;
	gotoxy(x, y + 16);
	cout << "Password: ";
	char ch;
	int number = 0, i = 0;
	int xxx = x + 10, yyy = y + 16;
	while (true && i < 8)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
		else if (!('0' <= ch && ch <= '9'))
		{
			gotoxy(4, 23);
			cout << "Password Bayad Adad Bashad!";
			_getch();
			return;
		}
		gotoxy(xxx++, yyy);
		cout << "*";
		number = ch - '0' + 10 * number;
		i++;
	}
	Password = number;
	gotoxy(x, y + 19);
	cout << "Jensiat(man or woman): ";
	cin >> gender;
	gotoxy(x, y + 22);
	if (gender == "man")
		Sex = true;
	else if (gender == "woman")
		Sex = false;
	else
	{
		cout << "Maqadire Vared Shode Dorost Nist!";
		_getch();
		return;
	}
	sw = YektaUser(Id, Password);
	if (sw == true)
	{
		int Index = User::getCount();
		users[Index].setUser(Name, Family, Age, Sex, Id, Password);
		cout << "Done!";
	}
	else cout << "Maqadire Vared Shode Tekrarist!";
	_getch();
}
//-----------------------------------------------------------------------------------------
void AddAdmin()
{
	Frame();
	string Name;
	string Family;
	int Age;
	bool Sex;
	int Id;
	int Password;
	bool sw;
	string gender;
	int x = 7, y = 4;
	gotoxy(x + 6, y - 1);
	cout << "- Ezafe Krdn Admin -";
	gotoxy(x, y + 4);
	cout << "Name: ";
	cin >> Name;
	gotoxy(x, y + 7);
	cout << "Family: ";
	cin >> Family;
	gotoxy(x, y + 10);
	cout << "Age: ";
	cin >> Age;
	gotoxy(x, y + 13);
	cout << "Id: ";
	cin >> Id;
	gotoxy(x, y + 16);
	cout << "Password: ";
	char ch;
	int number = 0, i = 0;
	int xxx = x + 10, yyy = y + 16;
	while (true && i < 8)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
		else if (!('0' <= ch && ch <= '9'))
		{
			gotoxy(4, 23);
			cout << "Password Bayad Adad Bashad!";
			_getch();
			return;
		}
		gotoxy(xxx++, yyy);
		cout << "*";
		number = ch - '0' + 10 * number;
		i++;
	}
	Password = number;
	gotoxy(x, y + 19);
	cout << "Jensiat(man or woman): ";
	cin >> gender;
	gotoxy(x, y + 22);
	if (gender == "man")
		Sex = true;
	else if (gender == "woman")
		Sex = false;
	else
	{
		cout << "Maqadire Vared Shode Dorost Nist!";
		_getch();
		return;
	}
	sw = YektaAdmin(Id, Password);
	if (sw == true)
	{
		int Index = Admin::getCount();
		admins[Index].setAdmin(Name, Family, Age, Sex, Id, Password);
		cout << "Done!";
	}
	else cout << "Maqadire Vared Shode Tekrarist!";
	_getch();
}
//-----------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------
void Color(int number)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, number);
}
//-----------------------------------------------------------------------------------------
void About()
{
	int x = 2, sw = 0;
	char back;
	Frame();
	gotoxy(x, 10);
	Color(0xF6);
	cout << "Cinema Ticket | Ver 1.0.0";
	gotoxy(x, 15);
	Color(0xF0);
	cout << "Programmers:";
	gotoxy(x, 18);
	Color(0xF5);
	cout << "Mohsen AliMohammadi";
	gotoxy(x, 20);
	Color(0xF5);
	cout << "Pouya AliKhanZade";
	gotoxy(x, 22);
	Color(0xF5);
	cout << "Hasan Aboyi";
	Color(0xF0);
	while (sw == 0)
	{
		back = _getch();
		if (back == 27)
		{
			sw = 1;
			system("cls");
			Run();
		}
	}
}
//-----------------------------------------------------------------------------------------
void Frame()
{
	Color(0xF9);
	int n = 40, m = 40;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			gotoxy(j, i);
			if (i == 0 && j == 0)
			{
				cout << char(218);
			}
			else if (i == 0 && j == m - 1)
			{
				cout << char(191);
			}
			else if (i == n - 1 && j == 0)
			{
				cout << char(192);
			}
			else if (i == n - 1 && j == m - 1)
			{
				cout << char(217);
			}
			else if (i == 0 || i == n - 1)
			{
				cout << char(196);
			}
			else if (j == 0 || j == m - 1)
			{
				cout << char(179);
			}
		}
	}
	Color(0xF0);
}
//-----------------------------------------------------------------------------------------