#include <string>
#include "Time.h"
class PersonalInformation
{
	friend istream & operator >> (istream &, PersonalInformation &);
	friend ostream & operator << (ostream &, const PersonalInformation &);
private:
	string name, placeBirth, phoneNumber, nationalCode;
	Time birth;
public:
	void setPerson(string _name, string _placeBirth, int _phoneNumber, int _nationalCode, Time _birth)
	{
		name = _name; placeBirth = _placeBirth; phoneNumber = _phoneNumber; nationalCode = _nationalCode; birth = _birth;
	}
	string getName() const
	{
		return name;
	}
};
istream & operator >> (istream & in, PersonalInformation & obj)
{
	if (file_flag == false)
		cout << "name: ";
	in >> obj.name;
	if (file_flag == false)
		cout << "phone number: ";
	in >> obj.phoneNumber;
	if (file_flag == false)
		cout << "tarikh tavalod (roz/mah/sal): ";
	in >> obj.birth;
	if (file_flag == false)
		cout << "mahale tavalod: ";
	in >> obj.placeBirth;
	if (file_flag == false)
		cout << "national code: ";
	in >> obj.nationalCode;
	return in;
}
ostream & operator << (ostream & out, const PersonalInformation & obj)
{
	if (file_flag == false)
		out << "name: ";
	out << obj.name << "\n";
	if (file_flag == false)
		out << "phone number: ";
	out << obj.phoneNumber << "\n";
	if (file_flag == false)
		out << "tarikh tavalod: ";
	out << obj.birth << "\n";
	if (file_flag == false)
		out << "mahale tavalod: ";
	out << obj.placeBirth << "\n";
	if (file_flag == false)
		out << "national code: ";
	out << obj.nationalCode << "\n";
	return out;
}
//--------------------------------------------------------------------------------------------------------------//
struct Info
{
	Time play;
	string tvChannel;
};
istream & operator >> (istream & in, Info & obj)
{
	if (file_flag == false)
		cout << "tarikh pakhsh (roz/mah/sal): ";
	in >> obj.play;
	if (file_flag == false)
		cout << "chanale namayesh dahande: ";
	in >> obj.tvChannel;
	return in;
}
ostream & operator << (ostream & out, const Info & obj)
{
	if (file_flag == false)
		out << "tarikh pakhsh: ";
	out << obj.play << "\n";
	if (file_flag == false)
		out << "dar chanale ";
	out << obj.tvChannel << "\n";
	return out;
}