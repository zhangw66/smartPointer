#include "person.h"
Person::Person(string s, string n):sex(s),name(n), refCount(0)
{
	cout << "Person constructor in" <<endl;
	cout << "name:" << this->name << "sex:" << this->sex << endl;
}
Person::~Person()
{
	cout << "Person:"<< this->name << " disconstructor in" <<endl;
}
