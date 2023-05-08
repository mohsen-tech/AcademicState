#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#define userFileName "users.txt"
#define bookFileName "books.txt"
using namespace std;
bool sw = true;

class Book
{
	friend istream & operator >> (istream & in, Book & obj);
	friend ostream & operator << (ostream & out, const Book & obj);
public:
	Book() { numberOfInventory = numberOfBorrowed = 0; };
	~Book() {};
	void inventoryIncrease()
	{
		numberOfInventory++;
	}
	bool inventoryReduction()
	{
		if (numberOfInventory - 1 < 0)
			return false;
		return true;
	}
	void increasingNumberOfBorrowed()
	{
		numberOfInventory--;
		numberOfBorrowed++;
	}
	bool ReducingNumberOfBorrowed()
	{
		if (numberOfBorrowed - 1 < 0)
			return false;
		numberOfBorrowed--;
		return true;
	}
	int getCode() const
	{
		return code;
	}
private:
	string name, writer;
	int code, numberOfInventory, numberOfBorrowed;
};
istream & operator >> (istream & in, Book & obj)
{
	if (sw == true)
		cout << "Name: ";
	in >> obj.name;
	if (sw == true)
		cout << "Writer: ";
	in >> obj.writer;
	if (sw == true)
		cout << "Code: ";
	in >> obj.code;
	if (sw == true)
		cout << "Number of inventory: ";
	in >> obj.numberOfInventory;
	if (sw == false)
		in >> obj.numberOfBorrowed;
	return in;
}
ostream & operator << (ostream & out, const Book & obj)
{
	if (sw == true)
		out << "Name: ";
	out << obj.name << "\n";
	if (sw == true)
		out << "Writer: ";
	out << obj.writer << "\n";
	if (sw == true)
		out << "Code: ";
	out << obj.code << "\n";
	if (sw == true)
		out << "Number of inventory: ";
	out << obj.numberOfInventory << "\n";
	if (sw == true)
		out << "Number of borrowed: ";
	out << obj.numberOfBorrowed << "\n";
	return out;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
class User
{
	friend istream & operator >> (istream & in, User & obj);
	friend ostream & operator << (ostream & out, const User & obj);
public:
	User() {}
	~User() {}
	bool addBook(const Book & book)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getCode() == book.getCode())
			{
				cout << "You already got this book.\n";
				return false;
			}
		}
		books.push_back(book);
		return true;
	}
	bool removeBook(const int & code)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getCode() == code)
			{
				books.erase(books.begin() + i);
				return true;
			}
		}
		return false;
	}
	int getID() const
	{
		return id;
	}
private:
	string name, family;
	int id;
	vector <Book> books;
};
istream & operator >> (istream & in, User & obj)
{
	if (sw == true)
		cout << "Name: ";
	in >> obj.name;
	if (sw == true)
		cout << "Family: ";
	in >> obj.family;
	if (sw == true)
		cout << "ID: ";
	in >> obj.id;
	return in;
}
ostream & operator << (ostream & out, const User & obj)
{
	if (sw == true)
		out << "Name: ";
	out << obj.name << "\n";
	if (sw == true)
		out << "Family: ";
	out << obj.family << "\n";
	if (sw == true)
		out << "ID: ";
	out << obj.id << "\n";
	return out;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
class Library
{
public:
	Library() {}
	~Library() {}
	int getBookIndex(const int & code)
	{
		for (int i = 0; i < books.size(); i++)
			if (books[i].getCode() == code)
				return i;
		return -1;
	}
	void addBook()
	{
		cout << "Enter the book information.\n";
		Book temp;
		cin >> temp;
		if (getBookIndex(temp.getCode()) == -1)
		{
			books.push_back(temp);
			cout << "The book was added.\n";
		}
		else
			cout << "This book is available.\n";
	}
	void removeBook()
	{
		cout << "Enter the desired book code: ";
		int code, index;
		cin >> code;
		index = getBookIndex(code);
		if (index != -1)
		{
			books.erase(books.begin() + index);
			cout << "The desired book code has been deleted.\n";
		}
		else
			cout << "The book was not found.\n";
	}
	void editBook()
	{
		cout << "Enter the desired book code: ";
		int code, index;
		cin >> code;
		index = getBookIndex(code);
		if (index != -1)
		{
			cout << "Enter new information for the desired book.\n";
			cin >> books[index];
		}
		else
			cout << "The book was not found.\n";
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	int getUserIndex(const int & id)
	{
		for (int i = 0; i < users.size(); i++)
			if (users[i].getID() == id)
				return i;
		return -1;
	}
	void addUser()
	{
		cout << "Enter user details.\n";
		User temp;
		cin >> temp;
		if (getUserIndex(temp.getID()) == -1)
		{
			users.push_back(temp);
			cout << "The user was added.\n";
		}
		else
			cout << "This user is available.\n";
	}
	void removeUser()
	{
		cout << "Enter the desired user ID: ";
		int id, index;
		cin >> id;
		index = getUserIndex(id);
		if (index != -1)
		{
			users.erase(users.begin() + index);
			cout << "The desired user code has been deleted.\n";
		}
		else
			cout << "The user was not found.\n";
	}
	void editUser()
	{
		cout << "Enter the desired user ID: ";
		int id, index;
		cin >> id;
		index = getUserIndex(id);
		if (index != -1)
		{
			cout << "Enter the new information of the desired user.\n";
			cin >> users[index];
		}
		else
			cout << "The user was not found.\n";
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	void borrowingBooks()
	{
		cout << "Enter the desired user ID: ";
		int temp, userIndex;
		cin >> temp;
		userIndex = getUserIndex(temp);
		if (userIndex != -1)
		{
			cout << "Enter the desired book code: ";
			cin >> temp;
			int bookIndex = getBookIndex(temp);
			if (bookIndex != -1)
			{
				if (books[bookIndex].inventoryReduction() == true)
				{
					if (users[userIndex].addBook(books[bookIndex]) == true)
					{
						books[bookIndex].increasingNumberOfBorrowed();
						cout << "The book with code " << books[bookIndex].getCode() << " was loaned to the user with ID " << users[userIndex].getID() << ".\n";
					}
				}
				else
					cout << "Insufficient inventory.\n";
			}
			else
				cout << "The book was not found.\n";
		}
		else
			cout << "The user was not found.\n";
	}
	void returnBook()
	{
		cout << "Enter the desired user ID: ";
		int temp, userIndex;
		cin >> temp;
		userIndex = getUserIndex(temp);
		if (userIndex != -1)
		{
			cout << "Enter the desired book code: ";
			cin >> temp;
			if (users[userIndex].removeBook(temp) == true)
			{
				int bookIndex = getBookIndex(temp);
				books[bookIndex].inventoryIncrease();
				books[bookIndex].ReducingNumberOfBorrowed();
				cout << "The book with code " << temp << " was withdrawn from the user with ID " << users[userIndex].getID() << ".\n";
			}
			else
				cout << "You do not have this book.\n";
		}
		else
			cout << "The user was not found.\n";
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	void searchBook()
	{
		cout << "Enter the desired book code: ";
		int code, index;
		cin >> code;
		index = getBookIndex(code);
		if (index != -1)
		{
			cout << books[index] << "\n";
		}
		else
			cout << "The book was not found.\n";
	}
	void searchUser()
	{
		cout << "Enter the desired user ID: ";
		int id, index;
		cin >> id;
		index = getUserIndex(id);
		if (index != -1)
		{
			cout << users[index] << "\n";
		}
		else
			cout << "The user was not found.\n";
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	void listOfUsers()
	{
		for (int i = 0; i < users.size(); i++)
			cout << "user " << i << "\n" << users[i] << "\n";
	}
	void listOfBooks()
	{
		for (int i = 0; i < books.size(); i++)
			cout << "book " << i << "\n" << books[i] << "\n";
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------
	void readFromFile()
	{
		Book book;
		ifstream myfile1(bookFileName);
		if (myfile1.is_open())
		{
			while (myfile1 >> book)
				books.push_back(book);
			myfile1.close();
		}
		else cout << "Unable to open " << bookFileName << " file.\n\n";

		User user;
		ifstream myfile2(userFileName);
		if (myfile2.is_open())
		{
			while (myfile2 >> user)
				users.push_back(user);
			myfile2.close();
		}
		else cout << "Unable to open " << userFileName << " file.\n\n";
	}
	void writeToFile()
	{
		ofstream myfile1(bookFileName);
		if (myfile1.is_open())
		{
			for (int i = 0; i < books.size(); i++)
				myfile1 << books[i] << "\n";
			myfile1.close();
		}
		else cout << "Unable to open " << bookFileName << " file.\n\n";

		ofstream myfile2(userFileName);
		if (myfile2.is_open())
		{
			for (int i = 0; i < users.size(); i++)
				myfile2 << users[i] << "\n";
			myfile2.close();
		}
		else cout << "Unable to open " << userFileName << " file.\n\n";
	}
private:
	vector <Book> books;
	vector <User> users;
};
Library library;
//--------------------------------------------------------------------------------------------------------------------------------------------------------
void user()
{
	while (true)
	{
		int temp;
		cout << "1. Add user\n";
		cout << "2. Remove user\n";
		cout << "3. Edit user\n";
		cout << "4. Search user\n";
		cout << "5. Back\n";
		cout << "Select one: ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			system("cls");
			library.addUser();
			_getch();
			break;
		case 2:
			system("cls");
			library.removeUser();
			_getch();
			break;
		case 3:
			system("cls");
			library.editUser();
			_getch();
			break;
		case 4:
			system("cls");
			library.searchUser();
			_getch();
			break;
		case 5:
			system("cls");
			return;
			break;
		default:
			system("cls");
			return;
			break;
		}
		system("cls");
	}
}
void book()
{
	while (true)
	{
		int temp;
		cout << "1. Add book\n";
		cout << "2. Remove book\n";
		cout << "3. Edit book\n";
		cout << "4. Search book\n";
		cout << "5. Back\n";
		cout << "Select one: ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			system("cls");
			library.addBook();
			_getch();
			break;
		case 2:
			system("cls");
			library.removeBook();
			_getch();
			break;
		case 3:
			system("cls");
			library.editBook();
			_getch();
			break;
		case 4:
			system("cls");
			library.searchBook();
			_getch();
			break;
		case 5:
			system("cls");
			return;
			break;
		default:
			system("cls");
			return;
			break;
		}
		system("cls");
	}
}
void menu()
{
	while (true)
	{
		int temp;
		cout << "1. User\n";
		cout << "2. Book\n";
		cout << "3. Borrowing book\n";
		cout << "4. Return book\n";
		cout << "5. Show users\n";
		cout << "6. Show Books\n";
		cout << "7. Exit\n";
		cout << "Select one: ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			system("cls");
			user();
			break;
		case 2:
			system("cls");
			book();
			break;
		case 3:
			system("cls");
			library.borrowingBooks();
			_getch();
			break;
		case 4:
			system("cls");
			library.returnBook();
			_getch();
			break;
		case 5:
			system("cls");
			library.listOfUsers();
			_getch();
			break;
		case 6:
			system("cls");
			library.listOfBooks();
			_getch();
			break;
		case 7:
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
	sw = false;
	library.readFromFile();
	sw = true;
	menu();
	sw = false;
	library.writeToFile();
	system("pause>A");
	return 0;
}