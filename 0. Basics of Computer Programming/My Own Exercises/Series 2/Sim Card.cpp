#include <iostream>
using namespace std;

int main()
{
	int c[10];
	int d[10];
	int ParsTel[10];
	int ParsCell[10];
	int ParsPhone[10];

	int ParsTel_call = 30, ParsTel_data = 40;
	int ParsCell_call = 35, ParsCell_data = 30;
	int ParsPhone_call = 40, ParsPhone_data = 20;

	for (int i = 1; i <= 5; i++)
	{
		cout << "Student " << i << "\n";
		cout << "Call: ";
		cin >> c[i];
		cout << "Data: ";
		cin >> d[i];
		cout << "\n";
	}
	for (int i = 1; i <= 5; i++)
	{
		ParsTel[i] = c[i] * ParsTel_call + d[i] * ParsTel_data;
		ParsCell[i] = c[i] * ParsCell_call + d[i] * ParsCell_data;
		ParsPhone[i] = c[i] * ParsPhone_call + d[i] * ParsPhone_data;

		if (ParsTel[i] < ParsCell[i])
		{
			if (ParsPhone[i] < ParsTel[i])
			{
				cout << ParsPhone[i] << "-->ParsPhone\n\n";
			}
			else if (ParsPhone[i] < ParsCell[i])
			{
				cout << ParsTel[i] << "-->ParsTel\n\n";
			}
			else
			{
				cout << ParsTel[i] << "-->ParsTel\n\n";
			}
		}
		else
		{
			if (ParsPhone[i] < ParsCell[i])
			{
				cout << ParsPhone[i] << "-->ParsPhone\n\n";
			}
			else if (ParsPhone[i] < ParsTel[i])
			{
				cout << ParsCell[i] << "-->ParsCell\n\n";
			}
			else
			{
				cout << ParsCell[i] << " -->ParsCell\n\n";
			}
		}

	}
	cout << "\n";

	return 0;
}