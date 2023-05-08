#include<iostream>
#include<cstring>
using namespace std;
struct Dots
{
	char name[100];
	int a, b;
};
int Tartib(int a, int b)
{
	if (a < b)
		return 0;
	return 1;
}
int main()
{
	Dots a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].name >> a[i].a >> a[i].b;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (Tartib(a[i].a, a[j].a) && Tartib(a[i].b, a[j].b))
				swap(a[i], a[j]);

	for (int i = 0; i < n; i++)
		cout << a[i].name << " " << a[i].a << " " << a[i].b << endl;

	return 0;
}