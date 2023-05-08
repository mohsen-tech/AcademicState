#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <stack>
#include <time.h>
using namespace std;
int gcdNumber(int a, int h)
{
	int temp;
	while (true)
	{
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}
bool primeNumber(int n)
{
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}
int findRandomNumber(int start, int end)
{
	srand(time(NULL));
	while (true)
	{
		int temp = pow(2, start) + rand() % int(pow(2, end));
		if (primeNumber(temp) == true)
			return temp;
	}
}
int main()
{
	unsigned long long int size, p, q, n, e, phi, d, msg, c, m;
	cout << "Pls enter size of key: ";
	cin >> size;
	cout << "Pls enter message to be encrypted: ";
	cin >> msg;
	if (size == 1)
	{
		p = findRandomNumber(0, 8);
		while (true)
		{
			q = findRandomNumber(0, 8);
			if (p != q)
				break;
		}
	}
	else if (size == 2)
	{
		p = findRandomNumber(8, 16);
		while (true)
		{
			q = findRandomNumber(8, 16);
			if (p != q)
				break;
		}
	}
	else if (size == 3)
	{
		p = findRandomNumber(16, 24);
		while (true)
		{
			q = findRandomNumber(16, 24);
			if (p != q)
				break;
		}
	}
	else if (size == 4)
	{
		p = findRandomNumber(24, 32);
		while (true)
		{
			q = findRandomNumber(24, 32);
			if (p != q)
				break;
		}
	}
	n = p * q;
	phi = (p - 1) * (q - 1);
	for (e = 2; e < phi; e++)
		if (gcdNumber(e, phi) == 1)
			break;
	cout << "\np:" << p << "  q:" << q << "  N:" << n << "  phi:" << phi << "  e:" << e << "\n";
	for (int i = 1; i < 10; i++)
	{
		int x = 1 + i * phi;
		if (x % e == 0)
		{
			d = x / e;
			break;
		}
	}
	cout << "Message data = " << msg;
	c = pow(msg, e);
	c = fmod(c, n);
	cout << "\nEncrypted data = " << c;
	m = pow(c, d);
	m = fmod(m, n);
	cout << "\nOriginal Message Sent = " << m;
	return 0;
}