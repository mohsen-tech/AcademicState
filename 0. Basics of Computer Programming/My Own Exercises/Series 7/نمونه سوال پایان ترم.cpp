#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[100] = { 'I' },
		b[100] = { 'w','i','l','l' },
		c[100] = { 'p','a','s','s' },
		d[100] = { 't','h','i','s' },
		e[100] = { 'c','o','u','r','s','e' };
	//{ 'I',' ','w','i','l','l',' ','p','a','s','s',' ','t','h','i','s',' ','c','o','u','r','s','e' };
	for (int i = 0; i < 5; i++)
		cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
	return 0;
}