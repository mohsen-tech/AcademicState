#include <iostream>
#include <conio.h>
#define PI 3.141592
using namespace std;
// <in.txt> out.txt
class Shape
{
protected:
	double a, b;
public:
	Shape() { }
	virtual void area() = 0;
	virtual void mohit() = 0;
};
class Square : public Shape
{
public:
	Square()
	{
		cout << "side of square: ";
		cin >> this->a;
	}
	void area()
	{
		cout << "Area of Square: " << this->a * this->a << "\n";
	}
	void mohit()
	{
		cout << "Mohit of Square: " << this->a * 4 << "\n";
	}
};
class Rectangle : public Shape
{
public:
	Rectangle()
	{
		cout << "length of rectangle: ";
		cin >> this->a;
		cout << "width of rectangle: ";
		cin >> this->b;
	}
	void area()
	{
		cout << "Area of Rectangle: " << this->a * this->b << "\n";
	}
	void mohit()
	{
		cout << "Mohit of Rectangle: " << (this->a + this->b) * 2 << "\n";
	}
};
class Circle : public Shape
{
public:
	Circle()
	{
		cout << "diameter of circle: ";
		cin >> this->a;
		this->b = this->a / 2;
	}
	void area()
	{
		cout << "Area of Circle: " << this->b * this->b * PI << "\n";
	}
	void mohit()
	{
		cout << "Mohit of Circle: " << PI * this->a << "\n";
	}
};
class Louzi : public Shape
{
private:
	double c;
public:
	Louzi()
	{
		cout << "diameter1 of louzi: ";
		cin >> this->a;
		cout << "diameter2 of louzi: ";
		cin >> this->b;
		cout << "side of louzi: ";
		cin >> this->c;
	}
	void area()
	{
		cout << "Area of Louzi: " << (this->a * this->b) / 2 << "\n";
	}
	void mohit()
	{
		cout << "Mohit of Louzi: " << this->c * 4 << "\n";
	}
};

int main()
{
	ios_base::sync_with_stdio(false);

	Shape * pointer;
	while (true)
	{
		int n;
		cout << "1. Square\n";
		cout << "2. Rectangle\n";
		cout << "3. Circle\n";
		cout << "4. Louzi\n";
		cout << "5. Exit\n";
		cout << "? ";
		cin >> n;
		if (n == 1)
		{
			Square temp;
			pointer = &temp;
			pointer->mohit();
			pointer->area();
		}
		else if (n == 2)
		{
			Rectangle temp;
			pointer = &temp;
			pointer->mohit();
			pointer->area();
		}
		else if (n == 3)
		{
			Circle temp;
			pointer = &temp;
			pointer->mohit();
			pointer->area();
		}
		else if (n == 4)
		{
			Louzi temp;
			pointer = &temp;
			pointer->mohit();
			pointer->area();
		}
		else if (n == 5)
		{
			exit(0);
		}
		else
		{
			cout << ":/\n";
		}
		cout << "\npress any key . . .";
		_getch();
		system("cls");
	}

	system("pause>0");
	return 0;
}