#include <iostream>
#include <string>
using namespace std;
struct PrivateInfo
{
	string Name, Family, FatherName;
	int MelliCode, IdNum;
};
struct StuInfo
{
	int StuNum;
	string UniName;
	string MaqtA_Tahsili;
	string ReshteTahsili;
	string Gerayesh;
	int YearCame;
	double AvgKol;
};
struct TermInfo
{
	int TermNum;
	int NimSal;
	int SaleTahsili;
	string Vaziat[5];
	int TedadVahed;
	int TedadDars;
	char NameDoros[100][30];
	int TedadVahedDars[100];
	int NomreHarDars[100];
	float Avg;
};
struct Student
{
	PrivateInfo privateInfo;
	StuInfo stuInfo;
	TermInfo termInfo[100];
};
PrivateInfo ScanPriInfo()
{
	PrivateInfo Temp;
	cerr << "Name: ";
	cin >> Temp.Name;
	cerr << "Family: ";
	cin >> Temp.Family;
	cerr << "Name Pedar: ";
	cin >> Temp.FatherName;
	cerr << "CodeMelli: ";
	cin >> Temp.MelliCode;
	cerr << "Shomare Shenasname: ";
	cin >> Temp.IdNum;
	return Temp;
}
StuInfo ScanStuInfo()
{
	StuInfo stuInfo;
	cerr << "Shomare Daneshjoyi: ";
	cin >> stuInfo.StuNum;
	cerr << "Name Daneshga: ";
	cin >> stuInfo.UniName;
	cerr << "MaqtA Tahsili: ";
	cin >> stuInfo.MaqtA_Tahsili;
	cerr << "Reshte Tahsili: ";
	cin >> stuInfo.ReshteTahsili;
	cerr << "Gerayesh: ";
	cin >> stuInfo.Gerayesh;
	cerr << "Sale Vorod: ";
	cin >> stuInfo.YearCame;
	return stuInfo;
}
TermInfo ScanTermInfo()
{
	TermInfo TermInfo;
	cerr << "Shomare Term: ";
	cin >> TermInfo.TermNum;
	cerr << "NimSal 1ya2? ";
	cin >> TermInfo.NimSal;
	cerr << "Sale Tahsili: ";
	cin >> TermInfo.SaleTahsili;
	int choose, sw;
	cerr << "Vaziat Tahsili:\n";
	cerr << "1.faAl 2.Morakhasi 3.Mehman 4.HazfTerm\n";
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
		cerr << "1.Az 2.Be: ";
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
	cerr << "Tedad Vahed Akhz Shode Dar In Term: ";
	cin >> TermInfo.TedadVahed;
	if (TermInfo.TedadVahed > 24)
	{
		cerr << "Error\n";
		exit(1);
	}
	cerr << "Tedad Doros In Term: ";
	cin >> TermInfo.TedadDars;
	int n = 0, sum = 0;
	for (size_t i = 0; i < TermInfo.TedadDars; i++)
	{
		cerr << i + 1 << ":\n";
		cerr << "1.NameDoros: ";
		cin >> TermInfo.NameDoros[i];
		cerr << "2.Tedad Vahed Dars: ";
		cin >> TermInfo.TedadVahedDars[i];
		if (1 <= TermInfo.TedadVahedDars[i] && TermInfo.TedadVahedDars[i] <= 3)
		{
			cerr << "Error\n";
			exit(1);
		}
		cerr << "3.Nomre Dars: ";
		cin >> TermInfo.NomreHarDars[i];
		n += TermInfo.TedadVahedDars[i];
		sum += n * TermInfo.NomreHarDars[i];
	}
	TermInfo.Avg = (float)sum / n;
	return TermInfo;
}
Student ScanStudent()
{
	Student student;
	cerr << " - EtelaAte Shakhsi - \n";
	student.privateInfo = ScanPriInfo();
	system("cls");
	cerr << " - EtelaAte Daneshjoyi - \n";
	student.stuInfo = ScanStuInfo();
	int n, sum = 0;
	system("cls");
	cerr << " - EtelaAte Har Nimsal - \n";
	cerr << "Moshakhasate Chand Term: ";
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cerr << "Moshakhasate Term " << i + 1 << "\n";
		student.termInfo[i] = ScanTermInfo();
		sum += student.termInfo[i].Avg;
		system("cls");
	}
	student.stuInfo.AvgKol = (float)sum / n;
	return student;
}
void HarTerm(Student students[], int n, int StuNum) //Moshakhasate Har Term
{
	int Id, ShomareTerm, cnt = 0;
	for (size_t i = 0; i < n; i++)
		if (StuNum == students[i].stuInfo.StuNum)
			Id = i;
	cerr << "Shomare Term: ";
	cin >> ShomareTerm;
	for (size_t i = 0; i < students[Id].termInfo[ShomareTerm].TedadDars; i++)
		if (students[Id].termInfo[ShomareTerm].NomreHarDars[i] >= 10)
			cnt++;
	cerr << StuNum << " Dar Term " << ShomareTerm << ":\n";
	cerr << cnt << " Vahed Pas Shode\n";
	cerr << "Moadel " << students[Id].termInfo[ShomareTerm].Avg << "\n";
	if (students[Id].termInfo[ShomareTerm].Avg <= 12)
		cerr << "Mashrot!\n";
}
void KoleTerm(Student students[], int n, int StuNum) //Moshakhasate Kolle Term
{
	int Id, cntAkhz = 0, cntPass = 0, cntMashrot = 0;
	for (size_t i = 0; i < n; i++)
		if (StuNum == students[i].stuInfo.StuNum)
			Id = i;
	for (size_t i = 0; students[Id].termInfo[i].TermNum > 0; i++)
	{
		cntAkhz += students[Id].termInfo[i].TedadVahed;
		for (size_t j = 0; j < students[Id].termInfo[i].TedadDars; j++)
			if (students[Id].termInfo[i].NomreHarDars[j] >= 10)
				cntPass += students[Id].termInfo[i].TedadVahedDars[j];
		if (students[Id].termInfo[i].Avg <= 12)
			cntMashrot++;
	}
	cerr << StuNum << " Dar Kolle TermHa:\n";
	cerr << "Tedad Kolle VahedHaye Pass Shode: " << cntPass << "\n";
	cerr << "Tedad Kolle VahedHaye Akhz Shode: " << cntAkhz << "\n";
	cerr << "MoAdele Kol: " << students[Id].stuInfo.AvgKol << "\n";
	cerr << "Tedad TermHaye Mashroti: " << cntMashrot << "\n";
}
void Moshahede(Student students[], int n, int StuNum) //Moshahedeye Moshakhasate Daneshjoha
{
	int Id;
	for (size_t i = 0; i < n; i++)
		if (StuNum == students[i].stuInfo.StuNum)
			Id = i;
	cerr << students[Id].privateInfo.Name << "\n";
	cerr << students[Id].privateInfo.Family << "\n";
	cerr << students[Id].privateInfo.IdNum << "\n";
	cerr << students[Id].privateInfo.MelliCode << "\n";
	cerr << students[Id].privateInfo.FatherName << "\n";
	cerr << students[Id].stuInfo.AvgKol << "\n";
	cerr << students[Id].stuInfo.Gerayesh << "\n";
	cerr << students[Id].stuInfo.MaqtA_Tahsili << "\n";
	cerr << students[Id].stuInfo.ReshteTahsili << "\n";
	cerr << students[Id].stuInfo.StuNum << "\n";
	cerr << students[Id].stuInfo.UniName << "\n";
	cerr << students[Id].stuInfo.YearCame << "\n";
}
int nStu(Student students[], int n, string UniName) //Tedad Kolle Daneshjohaye Daneshgahe x
{
	int cnt = 0;
	for (size_t i = 0; i < n; i++)
		if (UniName == students[i].stuInfo.UniName)
			cnt++;
	return cnt;
}
void ShagerdAval(Student students[], int n) //Moshakhasate Shagerde Avall
{
	int maxx = -9999, maxi;
	for (size_t i = 0; i < n; i++)
	{
		if (students[i].stuInfo.AvgKol > maxx)
		{
			maxx = students[i].stuInfo.AvgKol;
			maxi = i;
		}
	}
	cerr << students[maxi].stuInfo.AvgKol << "\n";
	cerr << students[maxi].stuInfo.Gerayesh << "\n";
	cerr << students[maxi].stuInfo.MaqtA_Tahsili << "\n";
	cerr << students[maxi].stuInfo.ReshteTahsili << "\n";
	cerr << students[maxi].stuInfo.StuNum << "\n";
	cerr << students[maxi].stuInfo.UniName << "\n";
	cerr << students[maxi].stuInfo.YearCame << "\n";
}
void Sort(Student students[], int n) //Moratab Sazi
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = i + 1; j < n; j++)
			if (students[i].stuInfo.AvgKol < students[j].stuInfo.AvgKol)
				swap(students[i], students[j]);
}
int main()
{
	int n;
	cerr << "Tedad Daneshjoha: ";
	cin >> n;
	Student * students = new Student[n];
	for (size_t i = 0; i < n; i++)
	{
		cerr << "Moshakhasate Daneshjoye " << i + 1 << "\n";
		students[i] = ScanStudent();
		system("cls");
	}
	/* Menu */
	delete[] students;
	system("pause>0");
	return 0;
}