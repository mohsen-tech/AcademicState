#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// <in.txt> out.txt
int main()
{
	ios_base::sync_with_stdio(false);

	string line;
	vector <int> numbers;
	ifstream file("file.txt");
	if (file.is_open())
	{
		while (getline(file, line))
			if ('0' <= line[0] && line[0] <= '9')
				numbers.push_back(stoi(line));
		file.close();
	}
	else cout << "Unable to open file\n";

	ofstream file2("file2.txt");
	if (file2.is_open())
	{
		for (int i = 0; i + 5 < numbers.size(); i += 5)
		{
			int sum = numbers[i] + numbers[i + 1] + numbers[i + 2] + numbers[i + 3] + numbers[i + 4];
			file2 << sum << "\n";
		}
		file2.close();
	}
	else cout << "Unable to open file2\n";

	for (int i = 0; i < numbers.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < numbers.size(); j++)
			if (i != j && numbers[i] > numbers[j])
				cnt++;

		if (cnt >= 2)
			cout << numbers[i] << "\n";
	}

	system("pause>0");
	return 0;
}