#include <iostream>
#include <string>
#define PI 3.141592
using namespace std;
// <in.txt> out.txt
class GeometricShapes
{
public:
	GeometricShapes() { }
	void f()
	{
		int n;
		cout << "1. Square\n";
		cout << "2. Rectangle\n";
		cout << "3. Circle\n";
		cout << "4. Louzi\n";
		cout << "5. Triangle\n";
		cout << "? ";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "side of square: ";
			cin >> this->side;
			cout << "Mohit: " << this->side * 4 << "\n";
			cout << "Area: " << this->side * this->side << "\n";
			break;
		case 2:
			cout << "length of rectangle: ";
			cin >> this->length;
			cout << "width of rectangle: ";
			cin >> this->width;
			cout << "Mohit: " << (this->length + this->width) * 2 << "\n";
			cout << "Area: " << this->length * this->width << "\n";
			break;
		case 3:
			cout << "diameter of circle: ";
			cin >> this->diameter1;
			this->radius = this->diameter1 / 2;
			cout << "Mohit: " << PI * this->diameter1 << "\n";
			cout << "Area: " << this->radius * this->radius * PI << "\n";
			break;
		case 4:
			cout << "diameter1 of louzi: ";
			cin >> this->diameter1;
			cout << "diameter2 of louzi: ";
			cin >> this->diameter2;
			cout << "side of louzi: ";
			cin >> this->side;
			cout << "Mohit: " << this->side * 4 << "\n";
			cout << "Area: " << (this->diameter1 * this->diameter2) / 2 << "\n";
			break;
		case 5:
			cout << "side1 of triangle: ";
			cin >> this->side;
			cout << "side2 of triangle: ";
			cin >> this->length;
			cout << "side3 of triangle: ";
			cin >> this->width;
			cout << "rule of triangle: ";
			cin >> this->rule;
			cout << "height of triangle: ";
			cin >> this->height;
			cout << "Mohit: " << this->side + this->length + this->width << "\n";
			cout << "Area: " << (this->rule * this->height) / 2 << "\n";
			break;
		default:
			break;
		}
	}
private:
	double side, length, width, rule, height, diameter1, diameter2, radius;
};
int main()
{
	ios_base::sync_with_stdio(false);

	GeometricShapes temp;
	temp.f();

	system("pause>0");
	return 0;
}