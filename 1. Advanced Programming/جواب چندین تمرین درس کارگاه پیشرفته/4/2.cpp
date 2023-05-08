#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// <in.txt> out.txt
int main()
{
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	string line;
	ifstream file("file.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (int i = 0; i + 3 < line.size(); i++)
				if (line[i] == 'B' && line[i + 1] == 'O' && line[i + 2] == 'O' && line[i + 3] == 'K')
					cnt++;
		}
		file.close();
	}
	else cout << "Unable to open file\n";

	cout << cnt << "\n";

	system("pause>0");
	return 0;
}