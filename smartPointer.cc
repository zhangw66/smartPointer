#include "smartPointer.h"
/*
 * level1:
 * 	    利用函数返回的时候会析构非new出来的对象这个特性.
 * */
sp::sp(Person *person):p(person)
{
	cout << "sp::sp(Person *person):p(person)" << endl;
	p->incRefCount();
}
sp::sp(const sp& op)
{
	cout << "sp::sp(const sp& op)" << endl;
	this->p = op.p;
	p->incRefCount();
}
sp::~sp()
{
	cout << "sp::~sp()" << endl;
	p->decRefCount();
	if (!(p->getRefCount())) {
		cout << "recount is 0,release memory" << endl;
		if (p)
			delete p;
	}
}
Person& sp::operator*()
{
	return (*p);
}
Person * sp::operator->()
{
	cout << "Person * sp::operator->()" << endl;
	return this->p;
}
