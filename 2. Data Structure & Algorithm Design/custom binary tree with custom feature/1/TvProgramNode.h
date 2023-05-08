#include <vector>
#include "Information.h"
class TvProgramNode
{
	friend istream & operator >> (istream &, TvProgramNode &);
	friend ostream & operator << (ostream &, const TvProgramNode &);
	friend class AVL;
private:
	string name;
	int code, numberRepeat, type;
	Time productionDate, firstShowDate;
	vector <Info> info;
	vector <PersonalInformation> producer, director, actor, secretaryScene, stuntman, executor, contestants;
	TvProgramNode *left, *right;
public:
	int getCode() const
	{
		return this->code;
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool checkStr(const string & str)
	{
		for (int i = 0; i < producer.size(); i++)
			if (producer[i].getName() == str)
				return true;
		for (int i = 0; i < director.size(); i++)
			if (director[i].getName() == str)
				return true;
		return false;
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool checkChannel(const string & str)
	{
		for (int i = 0; i < info.size(); i++)
			if (info[i].tvChannel == str)
				return true;
		return false;
	}
	//--------------------------------------------------------------------------------------------------------------//
	bool checkTime(const Time & t)
	{
		if (firstShowDate == t)
			return true;
		for (int i = 0; i < info.size(); i++)
			if (info[i].play == t)
				return true;
		return false;
	}
	//--------------------------------------------------------------------------------------------------------------//
	void updateInfo()
	{
		Info temp;
		cin >> temp;
		this->info.push_back(temp);
		this->numberRepeat++;
	}
	//--------------------------------------------------------------------------------------------------------------//
	void edit()
	{
		while (true)
		{
			int n;
			cout << "kodam mored edit shavad?\n";
			cout << "1. name barname\n";
			cout << "2. tarikh sakht\n";
			cout << "3. tarikh avalin namayesh\n";
			cout << "4. noye barname\n";
			cout << "5. etelaAte pakhsh barname\n";
			cout << "6. etelaAte producer\n";
			cout << "7. etelaAte director\n";
			if (type == 1 || type == 2)
			{
				cout << "8. etelaAte actor\n";
				cout << "9. etelaAte badal karan\n";
			}
			else if (type == 3 || type == 4)
			{
				cout << "8. etelaAte monshi sahne\n";
				cout << "9. etelaAte mojri\n";
			}
			if (type == 3)
			{
				cout << "10. etelaAte sherkat konanDegan dar mosabeqe\n";
			}
			cout << "0. khoroj\n";
			cout << "[1...10]? ";
			cin >> n;
			if (n == 0) break;
			if (n == 1)
			{
				system("cls");
				cout << "name barname: " << this->name << "\n";
				if (a() == true)
					cin >> this->name;
				z();
			}
			else if (n == 2)
			{
				system("cls");
				cout << "tarikh sakht: " << this->productionDate << "\n";
				if (a() == true)
				{
					cout << "(roz/mah/sal) ";
					cin >> this->productionDate;
				}
				z();
			}
			else if (n == 3)
			{
				system("cls");
				cout << "tarikh avalin namayesh: " << this->firstShowDate << "\n";
				if (a() == true)
				{
					cout << "(roz/mah/sal) ";
					cin >> this->firstShowDate;
				}
				z();
			}
			else if (n == 4)
			{
				system("cls");
				cout << "noye barname: ";
				if (this->type == 1)
					cout << "film\n";
				else if (this->type == 2)
					cout << "serial\n";
				else if (this->type == 3)
					cout << "mosabeqe\n";
				else if (this->type == 4)
					cout << "mizGerd\n";
				if (a() == true)
				{
					cout << "1. film\t2. serial\t3. mosabeqe\t4. mizGerd\n";
					cin >> n;
					if (n > 0 && n < 5)
						this->setType(n);
					else
						cout << "?!\n";
				}
				z();
			}
			else if (n == 5)
			{
				system("cls");
				cout << "etelaAte pakhsh barname\n";
				for (int i = 0; i < info.size(); i++)
					cout << i << ":\n" << this->info[i] << endl;
				cout << "kodam andis edit shavad? ";
				cin >> n;
				if (n < info.size() && a() == true)
				{
					cin >> this->info[n];
				}
				z();
			}
			else if (n == 6)
			{
				system("cls");
				cout << "etelaAte producer\n";
				for (int i = 0; i < producer.size(); i++)
					cout << i << ":\n" << this->producer[i] << endl;
				cout << "kodam andis edit shavad? ";
				cin >> n;
				if (n < producer.size() && a() == true)
				{
					cin >> this->producer[n];
				}
				z();
			}
			else if (n == 7)
			{
				system("cls");
				cout << "etelaAte director\n";
				for (int i = 0; i < director.size(); i++)
					cout << i << ":\n" << this->director[i] << endl;
				cout << "kodam andis edit shavad? ";
				cin >> n;
				if (n < director.size() && a() == true)
				{
					cin >> this->director[n];
				}
				z();
			}
			else if (n == 8)
			{
				system("cls");
				if (type == 1 || type == 2)
				{
					cout << "etelaAte actor\n";
					for (int i = 0; i < actor.size(); i++)
						cout << i << ":\n" << this->actor[i] << endl;
					cout << "kodam andis edit shavad? ";
					cin >> n;
					if (n < actor.size() && a() == true)
					{
						cin >> this->actor[n];
					}
				}
				else if (type == 3 || type == 4)
				{
					cout << "etelaAte monshi sahne\n";
					for (int i = 0; i < secretaryScene.size(); i++)
						cout << i << ":\n" << this->secretaryScene[i] << endl;
					cout << "kodam andis edit shavad? ";
					cin >> n;
					if (n < secretaryScene.size() && a() == true)
					{
						cin >> this->secretaryScene[n];
					}
				}
				z();
			}
			else if (n == 9)
			{
				system("cls");
				if (type == 1 || type == 2)
				{
					cout << "etelaAte badal karan\n";
					for (int i = 0; i < stuntman.size(); i++)
						cout << i << ":\n" << this->stuntman[i] << endl;
					cout << "kodam andis edit shavad? ";
					cin >> n;
					if (n < stuntman.size() && a() == true)
					{
						cin >> this->stuntman[n];
					}
				}
				else if (type == 3 || type == 4)
				{
					cout << "etelaAte mojri\n";
					for (int i = 0; i < executor.size(); i++)
						cout << i << ":\n" << this->executor[i] << endl;
					cout << "kodam andis edit shavad? ";
					cin >> n;
					if (n < executor.size() && a() == true)
					{
						cin >> this->executor[n];
					}
				}
				z();
			}
			else if (n == 10 && type == 3)
			{
				system("cls");
				cout << "etelaAte sherkat konanDegan dar mosabeqe\n";
				for (int i = 0; i < contestants.size(); i++)
					cout << i << ":\n" << this->contestants[i] << endl;
				cout << "kodam andis edit shavad? ";
				cin >> n;
				if (n < contestants.size() && a() == true)
				{
					cin >> this->contestants[n];
				}
				z();
			}
		}
	}
	//--------------------------------------------------------------------------------------------------------------//
	void setType(int _type)
	{
		int n;
		PersonalInformation temp;
		if (_type == 1 || _type == 2)
		{
			secretaryScene.clear(); executor.clear(); contestants.clear();
			cout << "tedad actor: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				actor.push_back(temp);
			}
			cout << "tedad badal karan: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				stuntman.push_back(temp);
			}
		}
		else if (_type == 3)
		{
			actor.clear(); stuntman.clear();
			cout << "tedad monshi sahne: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				secretaryScene.push_back(temp);
			}
			cout << "tedad mojri: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				executor.push_back(temp);
			}
			cout << "tedad sherkat konanDegan dar mosabeqe: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				contestants.push_back(temp);
			}
		}
		if (_type == 4)
		{
			actor.clear(); stuntman.clear(); contestants.clear();
			cout << "tedad monshi sahne: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				secretaryScene.push_back(temp);
			}
			cout << "tedad mojri: ";
			cin >> n;
			while (n--)
			{
				cin >> temp;
				executor.push_back(temp);
			}
		}
		this->type = _type;
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode()
	{
		left = right = nullptr; numberRepeat = 0;
	}
	//--------------------------------------------------------------------------------------------------------------//
	TvProgramNode(const TvProgramNode & obj)
	{
		name = obj.name; type = obj.type;
		code = obj.code; numberRepeat = obj.numberRepeat;
		productionDate = obj.productionDate; firstShowDate = obj.firstShowDate;
		info = obj.info;
		producer = obj.producer;
		director = obj.director;
		actor = obj.actor;
		secretaryScene = obj.secretaryScene;
		stuntman = obj.stuntman;
		executor = obj.executor;
		contestants = obj.contestants;
		left = right = nullptr;
	}
	//--------------------------------------------------------------------------------------------------------------//
	~TvProgramNode()
	{
		producer.clear(); director.clear(); actor.clear(); secretaryScene.clear(); stuntman.clear(); executor.clear(); contestants.clear(); info.clear();
	}
};
//--------------------------------------------------------------------------------------------------------------//
ostream & operator << (ostream & out, const TvProgramNode & obj)
{
	if (file_flag == false)
		out << "name barname: ";
	out << obj.name << "\n";
	if (file_flag == false)
		out << "code barname: ";
	out << obj.code << "\n";
	if (file_flag == false)
		out << "tarikh sakht: ";
	out << obj.productionDate << "\n";
	if (file_flag == false)
		out << "tarikh avalin namayesh: ";
	out << obj.firstShowDate << "\n";
	if (file_flag == false)
		out << "noye barname: ";
	if (file_flag == false)
		if (obj.type == 1)
			out << "film\n";
		else if (obj.type == 2)
			out << "serial\n";
		else if (obj.type == 3)
			out << "mosabeqe\n";
		else if (obj.type == 4)
			out << "mizGerd\n";
	if (file_flag == true)
		out << obj.type << "\n";
	if (file_flag == false)
		out << "etelaAte pakhsh barname\n";
	if (file_flag == true)
		out << obj.info.size() << "\n";
	for (int i = 0; i < obj.info.size(); i++)
		if (file_flag == false)
			out << i << ":\n" << obj.info[i] << endl;
		else if (file_flag == true)
			out << obj.info[i] << endl;
	if (file_flag == false)
		out << "tedade tekrar pakhsh: ";
	out << obj.numberRepeat << "\n";
	if (file_flag == false)
		out << "etelaAte producer\n";
	if (file_flag == true)
		out << obj.producer.size() << "\n";
	for (int i = 0; i < obj.producer.size(); i++)
		if (file_flag == false)
			out << i << ":\n" << obj.producer[i] << endl;
		else if (file_flag == true)
			out << obj.producer[i] << endl;
	if (file_flag == false)
		out << "etelaAte director\n";
	if (file_flag == true)
		out << obj.director.size() << "\n";
	for (int i = 0; i < obj.director.size(); i++)
		if (file_flag == false)
			out << i << ":\n" << obj.director[i] << endl;
		else if (file_flag == true)
			out << obj.director[i] << endl;
	if (obj.type == 1 || obj.type == 2)
	{
		if (file_flag == false)
			out << "etelaAte actor\n";
		if (file_flag == true)
			out << obj.actor.size() << "\n";
		for (int i = 0; i < obj.actor.size(); i++)
			if (file_flag == false)
				out << i << ":\n" << obj.actor[i] << endl;
			else if (file_flag == true)
				out << obj.actor[i] << endl;
		if (file_flag == false)
			out << "etelaAte badal karan\n";
		if (file_flag == true)
			out << obj.stuntman.size() << "\n";
		for (int i = 0; i < obj.stuntman.size(); i++)
			if (file_flag == false)
				out << i << ":\n" << obj.stuntman[i] << endl;
			else if (file_flag == true)
				out << obj.stuntman[i] << endl;
	}
	else if (obj.type == 3 || obj.type == 4)
	{
		if (file_flag == false)
			out << "etelaAte monshi sahne\n";
		if (file_flag == true)
			out << obj.secretaryScene.size() << "\n";
		for (int i = 0; i < obj.secretaryScene.size(); i++)
			if (file_flag == false)
				out << i << ":\n" << obj.secretaryScene[i] << endl;
			else if (file_flag == true)
				out << obj.secretaryScene[i] << endl;
		if (file_flag == false)
			out << "etelaAte mojri\n";
		if (file_flag == true)
			out << obj.executor.size() << "\n";
		for (int i = 0; i < obj.executor.size(); i++)
			if (file_flag == false)
				out << i << ":\n" << obj.executor[i] << endl;
			else if (file_flag == true)
				out << obj.executor[i] << endl;
	}
	if (obj.type == 3)
	{
		if (file_flag == false)
			out << "etelaAte sherkat konanDegan dar mosabeqe\n";
		if (file_flag == true)
			out << obj.contestants.size() << "\n";
		for (int i = 0; i < obj.contestants.size(); i++)
			if (file_flag == false)
				out << i << ":\n" << obj.contestants[i] << endl;
			else if (file_flag == true)
				out << obj.contestants[i] << endl;
	}
	return out;
}
//--------------------------------------------------------------------------------------------------------------//
istream & operator >> (istream & in, TvProgramNode & obj)
{
	int n;
	if (file_flag == false)
		cout << "name barname: ";
	in >> obj.name;
	if (file_flag == false)
		cout << "code barname: ";
	in >> obj.code;
	if (file_flag == false)
		cout << "tarikh sakht (roz/mah/sal): ";
	in >> obj.productionDate;
	if (file_flag == false)
		cout << "tarikh avalin namayesh (roz/mah/sal): ";
	in >> obj.firstShowDate;
	if (file_flag == false)
		cout << "noye barname:\n";
	if (file_flag == false)
		cout << "1. film\t2. serial\t3. mosabeqe\t4. mizGerd\n";
	in >> obj.type;
	if (file_flag == true)
	{
		Info temp;
		in >> n;
		while (n--)
		{
			in >> temp;
			obj.info.push_back(temp);
		}
		in >> obj.numberRepeat;
	}
	PersonalInformation temp;
	if (file_flag == false)
		cout << "tedad producer: ";
	in >> n;
	while (n--)
	{
		in >> temp;
		obj.producer.push_back(temp);
	}
	if (file_flag == false)
		cout << "tedad director: ";
	in >> n;
	while (n--)
	{
		in >> temp;
		obj.director.push_back(temp);
	}
	if (obj.type == 1 || obj.type == 2)
	{
		if (file_flag == false)
			cout << "tedad actor: ";
		in >> n;
		while (n--)
		{
			in >> temp;
			obj.actor.push_back(temp);
		}
	}
	if (obj.type == 3 || obj.type == 4)
	{
		if (file_flag == false)
			cout << "tedad monshi sahne: ";
		in >> n;
		while (n--)
		{
			in >> temp;
			obj.secretaryScene.push_back(temp);
		}
	}
	if (obj.type == 1 || obj.type == 2)
	{
		if (file_flag == false)
			cout << "tedad badal karan: ";
		in >> n;
		while (n--)
		{
			in >> temp;
			obj.stuntman.push_back(temp);
		}
	}
	if (obj.type == 3 || obj.type == 4)
	{
		if (file_flag == false)
			cout << "tedad mojri: ";
		in >> n;
		while (n--)
		{
			in >> temp;
			obj.executor.push_back(temp);
		}
	}
	if (obj.type == 3)
	{
		if (file_flag == false)
			cout << "tedad sherkat konanDegan dar mosabeqe: ";
		in >> n;
		while (n--)
		{
			in >> temp;
			obj.contestants.push_back(temp);
		}
	}
	return in;
}