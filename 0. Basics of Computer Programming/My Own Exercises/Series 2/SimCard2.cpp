#include <iostream>
using namespace std;
int main()
{
	int c;
	int d;

	int ParsTel;
	int ParsCell;
	int ParsPhone;

	int ParsTel_call = 30, ParsTel_data = 40;
	int ParsCell_call = 35, ParsCell_data = 30;
	int ParsPhone_call = 40, ParsPhone_data = 20;

	for (int i = 1; i <= 5; i++)
	{
		cout << "Student " << i << "\n";
		cout << "Call: ";
		cin >> c;
		cout << "Data: ";
		cin >> d;
		cout << "\n\n";
		if (d >= 1 && c >= 1)
		{
			if (d <= 1000 && c <= 1000)
			{
				ParsTel = c * ParsTel_call + d * ParsTel_data;
				ParsCell = c * ParsCell_call + d * ParsCell_data;
				ParsPhone = c * ParsPhone_call + d * ParsPhone_data;

				if (ParsTel < ParsCell)
				{
					if (ParsPhone < ParsTel)
					{
						cout << ParsPhone << "-->ParsPhone\n\n";
					}
					else if (ParsPhone < ParsCell)
					{
						cout << ParsTel << "-->ParsTel\n\n";
					}
					else
					{
						cout << ParsTel << "-->ParsTel\n\n";
					}
				}
				else
				{
					if (ParsPhone < ParsCell)
					{
						cout << ParsPhone << "-->ParsPhone\n\n";
					}
					else if (ParsPhone < ParsTel)
					{
						cout << ParsCell << "-->ParsCell\n\n";
					}
					else
					{
						cout << ParsCell << "-->ParsCell\n\n";
					}
				}
			}
			else
			{
				cout << "1<=Call,Data<=1000 \n\n";
			}
		}

		else
		{
			cout << "1<=Call,Data<=1000 \n\n";
		}
	}
	cout << "\n\n";

	return 0;
}