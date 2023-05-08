#include "AVL.h"
AVL tree;
void one()
{
	cout << "1. ezafe krdn yek barname\n";
	TvProgramNode temp;
	cin >> temp;
	if (tree.search(temp.getCode()) == false)
		tree.insert(temp);
	else
		cout << "code barname mojod ast!\n";
}
void two()
{
	int code;
	cout << "2. hazf yek barname\n";
	cout << "code barname ra vared konid: ";
	cin >> code;
	if (tree.Delete(code) == true)
		cout << "barname hazf shod!\n";
	else
		cout << "barname peyda nashod!\n";
}
void three()
{
	int code;
	cout << "3. virayeshe etelaAte yek barname\n";
	cout << "code barname ra vared konid: ";
	cin >> code;
	if (tree.edit(code, 0) != false)
		cout << "\nbarname edit shod!\n";
	else
		cout << "barname peyda nashod!\n";
}
void four()
{
	int code;
	cout << "4. jostojoye yek barname\n";
	cout << "code barname ra vared konid: ";
	cin >> code;
	if (tree.search(code) == true)
		cout << "barname hast!\n";
	else
		cout << "barname nist!\n";
}
void five()
{
	int code;
	cout << "5. sabt tarikh namayesh barname\n";
	cout << "6. sabt tarikh namayesh avalin tekrar barname\n";
	cout << "code barname ra vared konid: ";
	cin >> code;
	if (tree.edit(code, 1) != false)
		cout << "tarikh namayesh barname update shod!\n";
	else
		cout << "barname peyda nashod!\n";
}
void seven()
{
	cout << "7. chap moratab tamam barnameha bar hasb code\n";
	tree.print();
}
void eight()
{
	Time temp;
	cout << "8. chap barnamehaye mojod dar yek tarikh moshakhas\n";
	cout << "(roz/mah/sal): ";
	cin >> temp;
	tree.print(temp);
}
void nine()
{
	string chanel;
	cout << "9. chap barnamehaye marbot b yek shabake moshakhas\n";
	cout << "chanal: ";
	cin >> chanel;
	tree.print(chanel, 0);
}
void ten()
{
	string str;
	cout << "10. chap barnamehaye marbot b yek sazande moshakhas\n";
	cout << "name sazande: ";
	cin >> str;
	tree.print(str, 1);
}
void eleven()
{
	int n;
	cout << "11. chap barnamehayi k hadeAqal n bar tekrar shodeAn\n";
	cout << "n: ";
	cin >> n;
	tree.print(n);
}
void loadFile()
{
	fstream input("TvProgramFile.txt", ios::in);
	if (input.fail())
		return;
	file_flag = true;
	int n;
	input >> n;
	TvProgramNode temp;
	while (n--)
	{
		input >> temp;
		tree.insert(temp);
	}
	file_flag = false;
}
//--------------------------------------------------------------------------------------------------------------//
void Run()
{
	loadFile();
	while (true)
	{
		int n;
		cout << "1. ezafe krdn yek barname\n";
		cout << "2. hazf yek barname\n";
		cout << "3. virayeshe etelaAte yek barname\n";
		cout << "4. jostojoye yek barname\n";
		cout << "5. sabt tarikh namayesh barname\n";
		cout << "6. sabt tarikh namayesh avalin tekrar barname\n";
		cout << "7. chap moratab tamam barnameha bar hasb code\n";
		cout << "8. chap barnamehaye mojod dar yek tarikh moshakhas\n";
		cout << "9. chap barnamehaye marbot b yek shabake moshakhas\n";
		cout << "10. chap barnamehaye marbot b yek sazande moshakhas\n";
		cout << "11. chap barnamehayi k hadeAqal n bar tekrar shodeAn\n";
		cout << "12. khoroj\n\n";
		cout << "[1...12]? ";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			one();
			z();
			break;
		case 2:
			system("cls");
			two();
			z();
			break;
		case 3:
			system("cls");
			three();
			z();
			break;
		case 4:
			system("cls");
			four();
			z();
			break;
		case 5:
			system("cls");
			five();
			z();
			break;
		case 6:
			system("cls");
			five();
			z();
			break;
		case 7:
			system("cls");
			seven();
			z();
			break;
		case 8:
			system("cls");
			eight();
			z();
			break;
		case 9:
			system("cls");
			nine();
			z();
			break;
		case 10:
			system("cls");
			ten();
			z();
			break;
		case 11:
			system("cls");
			eleven();
			z();
			break;
		case 12:
			return;
			break;
		default:
			system("cls");
			break;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------//
int main()
{
	Run();
	tree.saveFile();
	system("pause>0");
	return 0;
}
