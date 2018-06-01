#include "smartPointer.h"
/*
 * level1:
 * 	    利用函数返回的时候会析构非new出来的对象这个特性.
 * */
sp::sp(Person *person):p(person)
{

}
sp::~sp()
{
	if (p)
		delete p;
}
Person * sp::operator->()
{
	return this->p;
}
