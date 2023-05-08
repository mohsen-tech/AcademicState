#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <conio.h>
using namespace std;
int globaltime;
struct process
{
	string id;
	char type;
	int burstTime;
	bool operator == (const process & left)
	{
		if (this->id == left.id && this->type == left.type && this->burstTime == left.burstTime)
			return true;
		return false;
	}
	bool operator != (const process & left)
	{
		return !(*this == left);
	}
};
bool compareProcess(process a, process b)
{
	return (a.burstTime < b.burstTime);
}
bool check(int & A, int & B, int & C, const process & a)
{
	if (a.type == 'X')
	{
		if (A - 1 >= 0 && B - 1 >= 0)
		{
			A--;
			B--;
			return true;
		}
	}
	else if (a.type == 'Y')
	{
		if (B - 1 >= 0 && C - 1 >= 0)
		{
			B--;
			C--;
			return true;
		}
	}
	else if (a.type == 'Z')
	{
		if (A - 1 >= 0 && C - 1 >= 0)
		{
			A--;
			C--;
			return true;
		}
	}
	return false;
}
void Cores(int & a, int & b, int & c, queue <process> & ready, process & core, int & idleTimeCore, const process & null, int & i)
{
	if (ready.size() && core == null)
	{
		if (check(a, b, c, ready.front()) == true)
		{
			core = ready.front();
			ready.pop();
		}
		else
		{
			idleTimeCore++;
			return;
		}
	}
	if (core != null && core.burstTime > 0)
	{
		core.burstTime--;
		i++;
	}
	else
		idleTimeCore++;
}
void endProcess(int & a, int & b, int & c, process & core, const process & null, queue <process> & deadProcess)
{
	if (core != null)
		if (core.burstTime == 0)
		{
			if (core.type == 'X')
			{
				a++;
				b++;
			}
			else if (core.type == 'Y')
			{
				b++;
				c++;
			}
			else if (core.type == 'Z')
			{
				a++;
				c++;
			}
			deadProcess.push(core);
			core = null;
		}
}
void killProcess(int & a, int & b, int & c, process & core, const process & null)
{
	if (core.type == 'X')
	{
		a++;
		b++;
	}
	else if (core.type == 'Y')
	{
		b++;
		c++;
	}
	else if (core.type == 'Z')
	{
		a++;
		c++;
	}
	core = null;
}
void input(int & A, int & B, int & C, queue <process> & ready)
{
	ifstream infile;
	infile.open("input.txt", ios::in);
	if (!infile)
		exit(0);
	int n;
	infile >> A >> B >> C >> n;
	for (int i = 0; i < n; i++)
	{
		process temp;
		infile >> temp.id >> temp.type >> temp.burstTime;
		globaltime += temp.burstTime;
		ready.push(temp);
	}
	infile.close();
}
void output(int & a, int & b, int & c, const queue <process> & ready, const queue <process> & deadProcess, ofstream & outfile)
{
	queue <process> temp1 = ready, temp2 = deadProcess;
	vector <process> waiting, dead;
	while (temp1.size())
	{
		waiting.push_back(temp1.front());
		temp1.pop();
	}
	while (temp2.size())
	{
		dead.push_back(temp2.front());
		temp2.pop();
	}
	outfile << "A: " << a << " B: " << b << " C: " << c << endl;
	outfile << "waiting queue: ";
	if (waiting.size() == 0)
		outfile << "empty!";
	else
		for (int i = 0; i < waiting.size(); i++)
			outfile << waiting[i].id << " ";
	outfile << "\nending queue: ";
	if (dead.size() == 0)
		outfile << "empty!";
	else
		for (int i = 0; i < dead.size(); i++)
			outfile << dead[i].id << " ";
	outfile << "\n----------------------------------------------------------------\n\n";
}
void outputCores(process & core, const process & null, ofstream & outfile, const int & coreId)
{
	if (core == null)
		outfile << "cpu" << coreId << ": Idle\n";
	else
		outfile << "cpu" << coreId << ": " << core.id << endl;
}
void output(const int & idleTimeCore1, const int & idleTimeCore2, const int & idleTimeCore3, const int & idleTimeCore4, ofstream & outfile)
{
	outfile << "cpu1 Idle-Time: " << idleTimeCore1;
	outfile << "\ncpu2 Idle-Time: " << idleTimeCore2;
	outfile << "\ncpu3 Idle-Time: " << idleTimeCore3;
	outfile << "\ncpu4 Idle-Time: " << idleTimeCore4;
}
void runProcess(int & a, int & b, int & c, queue <process> & ready, process & core1, process & core2, process & core3, process & core4, const process & null, int & idleTimeCore1, int & idleTimeCore2, int & idleTimeCore3, int & idleTimeCore4, ofstream & outfile, int & i, queue <process> & deadProcess)
{
	Cores(a, b, c, ready, core1, idleTimeCore1, null, i);
	outputCores(core1, null, outfile, 1);
	endProcess(a, b, c, core1, null, deadProcess);
	Cores(a, b, c, ready, core2, idleTimeCore2, null, i);
	outputCores(core2, null, outfile, 2);
	endProcess(a, b, c, core2, null, deadProcess);
	Cores(a, b, c, ready, core3, idleTimeCore3, null, i);
	outputCores(core3, null, outfile, 3);
	endProcess(a, b, c, core3, null, deadProcess);
	Cores(a, b, c, ready, core4, idleTimeCore4, null, i);
	outputCores(core4, null, outfile, 4);
	endProcess(a, b, c, core4, null, deadProcess);
	output(a, b, c, ready, deadProcess, outfile);
}
void FCFS(const int & A, const int & B, const int & C, queue <process> & ready, process & core1, process & core2, process & core3, process & core4, const process & null, queue <process> & deadProcess)
{
	ofstream outfile;
	outfile.open("FCFS.txt", ios::out);
	int i = 0;
	core1 = core2 = core3 = core4 = null;
	int idleTimeCore1 = 0,
		idleTimeCore2 = 0,
		idleTimeCore3 = 0,
		idleTimeCore4 = 0,
		a = A, b = B, c = C;
	while (i < globaltime)
	{
		runProcess(a, b, c, ready, core1, core2, core3, core4, null, idleTimeCore1, idleTimeCore2, idleTimeCore3, idleTimeCore4, outfile, i, deadProcess);
	}
	output(idleTimeCore1, idleTimeCore2, idleTimeCore3, idleTimeCore4, outfile);
	outfile.close();
}
void Sorting(queue <process> & ready)
{
	vector <process> temp;
	while (ready.size())
	{
		temp.push_back(ready.front());
		ready.pop();
	}
	sort(temp.begin(), temp.end(), compareProcess);
	for (int i = 0; i < temp.size(); i++)
		ready.push(temp[i]);
}
void SJF(const int & A, const int & B, const int & C, queue <process> & ready, process & core1, process & core2, process & core3, process & core4, const process & null, queue <process> & deadProcess)
{
	ofstream outfile;
	outfile.open("SJF.txt", ios::out);
	int i = 0;
	Sorting(ready);
	core1 = core2 = core3 = core4 = null;
	int idleTimeCore1 = 0,
		idleTimeCore2 = 0,
		idleTimeCore3 = 0,
		idleTimeCore4 = 0,
		a = A, b = B, c = C;
	while (i < globaltime)
	{
		runProcess(a, b, c, ready, core1, core2, core3, core4, null, idleTimeCore1, idleTimeCore2, idleTimeCore3, idleTimeCore4, outfile, i, deadProcess);
	}
	output(idleTimeCore1, idleTimeCore2, idleTimeCore3, idleTimeCore4, outfile);
	outfile.close();
}
void RR(const int & A, const int & B, const int & C, queue <process> & ready, process & core1, process & core2, process & core3, process & core4, const process & null, queue <process> & deadProcess)
{
	ofstream outfile;
	outfile.open("RR.txt", ios::out);
	int Q, q = 0, i = 0;
	cout << "Q: ";
	cin >> Q;
	core1 = core2 = core3 = core4 = null;
	int idleTimeCore1 = 0,
		idleTimeCore2 = 0,
		idleTimeCore3 = 0,
		idleTimeCore4 = 0,
		a = A, b = B, c = C;
	while (i < globaltime)
	{
		if (q < Q)
		{
			runProcess(a, b, c, ready, core1, core2, core3, core4, null, idleTimeCore1, idleTimeCore2, idleTimeCore3, idleTimeCore4, outfile, i, deadProcess);
			q++;
		}
		else if (q == Q)
		{
			if (core1 != null)
			{
				ready.push(core1);
				killProcess(a, b, c, core1, null);
			}
			if (core2 != null)
			{
				ready.push(core2);
				killProcess(a, b, c, core2, null);
			}
			if (core3 != null)
			{
				ready.push(core3);
				killProcess(a, b, c, core3, null);
			}
			if (core4 != null)
			{
				ready.push(core4);
				killProcess(a, b, c, core4, null);
			}
			q = 0;
		}
	}
	output(idleTimeCore1, idleTimeCore2, idleTimeCore3, idleTimeCore4, outfile);
	outfile.close();
}
void menu(const int & A, const int & B, const int & C, queue <process> & ready, process & core1, process & core2, process & core3, process & core4, const process & null)
{
	int n;
	while (true)
	{
		queue <process> temp = ready;
		queue <process> deadProcess;
		cout << "1. First-Come First-Serve Scheduling\n";
		cout << "2. Shortest-Job-First Scheduling\n";
		cout << "3. Round Robin Scheduling\n";
		cout << "4. Exit\n";
		cout << ": ";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			FCFS(A, B, C, temp, core1, core2, core3, core4, null, deadProcess);
			break;
		case 2:
			system("cls");
			SJF(A, B, C, temp, core1, core2, core3, core4, null, deadProcess);
			break;
		case 3:
			system("cls");
			RR(A, B, C, temp, core1, core2, core3, core4, null, deadProcess);
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
		cout << "Done!\n";
		cout << "Press any key to continue . . .";
		_getch();
		system("cls");
	}
}
int main()
{
	int A, B, C;
	queue <process> ready;
	const process null = { "" , NULL , NULL };
	process core1, core2, core3, core4;
	input(A, B, C, ready);
	menu(A, B, C, ready, core1, core2, core3, core4, null);
	return 0;
}