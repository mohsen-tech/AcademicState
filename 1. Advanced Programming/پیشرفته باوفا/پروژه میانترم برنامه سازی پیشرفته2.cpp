#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////
struct PrivateInformation
{
	string Name, Family, FatherName;
	int MelliCode, IdNum;
};
struct StudentInformation
{
	int StudentNumber, SaleVorod;
	string UniName, MaghTahsil, ReshteTahsil, Gerayesh;
	double AverageKol;
};
struct TermInformation
{
	int TermNumber, NimSal, SaleTahsil, TedadVahed, TedadDars, TedadVahedDars[100], NomreHarDars[100];
	string Vaziat[5];
	char NameDoros[100][30];
	float Average;
};
struct Student
{
	PrivateInformation privateInfo;
	StudentInformation stuInfo;
	TermInformation termInfo[12];
};
///////////////////////////////////////////////////////////////////////////////////////////////////
PrivateInformation ScanPriInfo();
StudentInformation ScanStuInfo();
TermInformation ScanTermInfo();
Student ScanStudent();
void HarTerm(Student students[], int n, int StuNum);
void KoleTerm(Student students[], int n, int StuNum);
void Moshahede(Student students[], int n, int StuNum);
int nStu(Student students[], int n, string UniName);
void ShagerdAval(Student students[], int n);
void Sort(Student students[], int n);
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int size = 0;
	Student * students = new Student[size];
	while (!false)
	{
		int choose;
		cout << "1.Ezafe Krdn Daneshjo\n";
		cout << "2.Moshakhasate Daneshjo\n";
		cout << "3.Moshakhasate Daneshjo Dar Har Term\n";
		cout << "4.Moshahedeye Moshakhasate Shakhsi Va Daneshjoyi\n";
		cout << "5.Tedade Kolle DaneshjoHaye Yek Daneshgah\n";
		cout << "6.Moshakhasate Shagerde Avall\n";
		cout << "7.Khoroj\n";
		cout << "Entekhab Konid: ";
		cin >> choose;
		if (choose == 1)
		{
			system("cls");
			int x, n;
			cout << "Tedad Daneshjoha: ";
			cin >> x;
			Student * temp = new Student[size];
			for (size_t i = 0; i < size; i++)
			{
				temp[i] = students[i];
			}
			delete[] students;
			n = size;
			size += x;
			students = new Student[size];
			for (size_t i = 0; i < n; i++)
			{
				students[i] = temp[i];
			}
			delete[] temp;
			cout << "\n";
			for (size_t i = n; i < size; i++)
			{
				cout << "Moshakhasate Daneshjoye " << i + 1 << "\n";
				students[i] = ScanStudent();
				system("cls");
			}
			_getch();
			system("cls");
		}
		else if (choose == 2)
		{
			system("cls");
			int StudentNumber;
			cout << "Shomare Daneshjo Ra Vared Konid: ";
			cin >> StudentNumber;
			KoleTerm(students, size, StudentNumber);
			_getch();
			system("cls");
		}
		else if (choose == 3)
		{
			system("cls");
			int StudentNumber;
			cout << "Shomare Daneshjo Ra Vared Konid: ";
			cin >> StudentNumber;
			HarTerm(students, size, StudentNumber);
			_getch();
			system("cls");
		}
		else if (choose == 4)
		{
			system("cls");
			int StudentNumber;
			cout << "Shomare Daneshjo Ra Vared Konid: ";
			cin >> StudentNumber;
			Moshahede(students, size, StudentNumber);
			_getch();
			system("cls");
		}
		else if (choose == 5)
		{
			system("cls");
			string UnivercityName;
			cout << "Name Daneshgah Ra Vared Konid: ";
			cin >> UnivercityName;
			nStu(students, size, UnivercityName);
			_getch();
			system("cls");
		}
		else if (choose == 6)
		{
			system("cls");
			cout << "Moshakhasate Shagerde Avall:\n";
			ShagerdAval(students, size);
			_getch();
			system("cls");
		}
		else if (choose == 7)
		{
			delete[] students;
			exit(0);
		}
		else
		{
			delete[] students;
			exit(0);
		}
	}
	delete[] students;
	system("pause>0");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
PrivateInformation ScanPriInfo()
{
	PrivateInformation Temp;
	cout << "Name: ";
	cin >> Temp.Name;
	cout << "Family: ";
	cin >> Temp.Family;
	cout << "Name Pedar: ";
	cin >> Temp.FatherName;
	cout << "CodeMelli: ";
	cin >> Temp.MelliCode;
	cout << "Shomare Shenasname: ";
	cin >> Temp.IdNum;
	return Temp;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
StudentInformation ScanStuInfo()
{
	StudentInformation stuInfo;
	cout << "Shomare Daneshjoyi: ";
	cin >> stuInfo.StudentNumber;
	cout << "Name Daneshga: ";
	cin >> stuInfo.UniName;
	cout << "MaqtA Tahsili: ";
	cin >> stuInfo.MaghTahsil;
	cout << "Reshte Tahsili: ";
	cin >> stuInfo.ReshteTahsil;
	cout << "Gerayesh: ";
	cin >> stuInfo.Gerayesh;
	cout << "Sale Vorod: ";
	cin >> stuInfo.SaleVorod;
	return stuInfo;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
TermInformation ScanTermInfo()
{
	TermInformation TermInfo;
	cout << "Shomare Term: ";
	cin >> TermInfo.TermNumber;
	cout << "NimSal 1ya2? ";
	cin >> TermInfo.NimSal;
	cout << "Sale Tahsili: ";
	cin >> TermInfo.SaleTahsil;
	int choose, sw;
	cout << "Vaziat Tahsili:\n";
	cout << "1.faAl 2.Morakhasi 3.Mehman 4.HazfTerm\n";
	cin >> choose;
	switch (choose)
	{
	case 1:
		TermInfo.Vaziat[0] = 1;
		break;
	case 2:
		TermInfo.Vaziat[1] = 1;
		break;
	case 3:
		cout << "1.Az 2.Be: ";
		cin >> sw;
		if (sw == 1)
		{
			cin >> TermInfo.Vaziat[3];
		}
		else if (sw == 2)
		{
			cin >> TermInfo.Vaziat[4];
		}
		break;
	case 4:
		TermInfo.Vaziat[2] = 1;
		break;
	default:
		break;
	}
	cout << "Tedad Vahed Akhz Shode Dar In Term: ";
	cin >> TermInfo.TedadVahed;
	if (TermInfo.TedadVahed > 24)
	{
		cout << "Error\n";
		exit(1);
	}
	cout << "Tedad Doros In Term: ";
	cin >> TermInfo.TedadDars;
	int n = 0, sum = 0;
	for (size_t i = 0; i < TermInfo.TedadDars; i++)
	{
		cout << i + 1 << ":\n";
		cout << "1.NameDoros: ";
		cin >> TermInfo.NameDoros[i];
		cout << "2.Tedad Vahed Dars: ";
		cin >> TermInfo.TedadVahedDars[i];
		if (1 <= TermInfo.TedadVahedDars[i] && TermInfo.TedadVahedDars[i] <= 3)
		{
			cout << "Error\n";
			exit(1);
		}
		cout << "3.Nomre Dars: ";
		cin >> TermInfo.NomreHarDars[i];
		n += TermInfo.TedadVahedDars[i];
		sum += n * TermInfo.NomreHarDars[i];
	}
	TermInfo.Average = (float)sum / n;
	return TermInfo;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
Student ScanStudent()
{
	Student student;
	cout << " - EtelaAte Shakhsi - \n";
	student.privateInfo = ScanPriInfo();
	system("cls");
	cout << " - EtelaAte Daneshjoyi - \n";
	student.stuInfo = ScanStuInfo();
	int n, sum = 0;
	system("cls");
	cout << " - EtelaAte Har Nimsal - \n";
	cout << "Moshakhasate Chand Term: ";
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cout << "Moshakhasate Term " << i + 1 << "\n";
		student.termInfo[i] = ScanTermInfo();
		sum += student.termInfo[i].Average;
		system("cls");
	}
	student.stuInfo.AverageKol = (float)sum / n;
	return student;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void HarTerm(Student students[], int n, int StuNum) //Moshakhasate Har Term
{
	int Id, ShomareTerm, cnt = 0;
	for (size_t i = 0; i < n; i++)
		if (StuNum == students[i].stuInfo.StudentNumber)
			Id = i;
	cout << "Shomare Term: ";
	cin >> ShomareTerm;
	for (size_t i = 0; i < students[Id].termInfo[ShomareTerm].TedadDars; i++)
		if (students[Id].termInfo[ShomareTerm].NomreHarDars[i] >= 10)
			cnt++;
	cout << StuNum << " Dar Term " << ShomareTerm << ":\n";
	cout << cnt << " Vahed Pas Shode\n";
	cout << "Moadel " << students[Id].termInfo[ShomareTerm].Average << "\n";
	if (students[Id].termInfo[ShomareTerm].Average <= 12)
		cout << "Mashrot!\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void KoleTerm(Student students[], int n, int StuNum) //Moshakhasate Kolle Term
{
	int Id, cntAkhz = 0, cntPass = 0, cntMashrot = 0;
	for (size_t i = 0; i < n; i++)
		if (StuNum == students[i].stuInfo.StudentNumber)
			Id = i;
	for (size_t i = 0; students[Id].termInfo[i].TermNumber > 0; i++)
	{
		cntAkhz += students[Id].termInfo[i].TedadVahed;
		for (size_t j = 0; j < students[Id].termInfo[i].TedadDars; j++)
			if (students[Id].termInfo[i].NomreHarDars[j] >= 10)
				cntPass += students[Id].termInfo[i].TedadVahedDars[j];
		if (students[Id].termInfo[i].Average <= 12)
			cntMashrot++;
	}
	cout << StuNum << " Dar Kolle TermHa:\n";
	cout << "Tedad Kolle VahedHaye Pass Shode: " << cntPass << "\n";
	cout << "Tedad Kolle VahedHaye Akhz Shode: " << cntAkhz << "\n";
	cout << "MoAdele Kol: " << students[Id].stuInfo.AverageKol << "\n";
	cout << "Tedad TermHaye Mashroti: " << cntMashrot << "\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Moshahede(Student students[], int n, int StuNum) //Moshahedeye Moshakhasate Daneshjoha
{
	int Id;
	for (size_t i = 0; i < n; i++)
		if (StuNum == students[i].stuInfo.StudentNumber)
			Id = i;
	cout << students[Id].privateInfo.Name << "\n";
	cout << students[Id].privateInfo.Family << "\n";
	cout << students[Id].privateInfo.IdNum << "\n";
	cout << students[Id].privateInfo.MelliCode << "\n";
	cout << students[Id].privateInfo.FatherName << "\n";
	cout << students[Id].stuInfo.AverageKol << "\n";
	cout << students[Id].stuInfo.Gerayesh << "\n";
	cout << students[Id].stuInfo.MaghTahsil << "\n";
	cout << students[Id].stuInfo.ReshteTahsil << "\n";
	cout << students[Id].stuInfo.StudentNumber << "\n";
	cout << students[Id].stuInfo.UniName << "\n";
	cout << students[Id].stuInfo.SaleVorod << "\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Sort(Student students[], int n) //Moratab Sazi
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = i + 1; j < n; j++)
			if (students[i].stuInfo.AverageKol < students[j].stuInfo.AverageKol)
				swap(students[i], students[j]);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int nStu(Student students[], int n, string UniName) //Tedad Kolle Daneshjohaye Daneshgahe x
{
	int cnt = 0;
	for (size_t i = 0; i < n; i++)
		if (UniName == students[i].stuInfo.UniName)
			cnt++;
	return cnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void ShagerdAval(Student students[], int n) //Moshakhasate Shagerde Avall
{
	int maxx = -9999, maxi;
	for (size_t i = 0; i < n; i++)
	{
		if (students[i].stuInfo.AverageKol > maxx)
		{
			maxx = students[i].stuInfo.AverageKol;
			maxi = i;
		}
	}
	cout << students[maxi].stuInfo.AverageKol << "\n";
	cout << students[maxi].stuInfo.Gerayesh << "\n";
	cout << students[maxi].stuInfo.MaghTahsil << "\n";
	cout << students[maxi].stuInfo.ReshteTahsil << "\n";
	cout << students[maxi].stuInfo.StudentNumber << "\n";
	cout << students[maxi].stuInfo.UniName << "\n";
	cout << students[maxi].stuInfo.SaleVorod << "\n";
}
