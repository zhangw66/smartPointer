#include "smartPointer.h"
/*
 * level1:
 * 	    利用函数返回的时候会析构非new出来的对象这个特性.
 * */
template <typename T> sp<T>::sp(T *person) : p(person)
{
	cout << "sp::sp(Person *person):p(person)" << endl;
	if (p)
		p->incRefCount();
}
template <typename T> sp<T>::sp(const sp &op)
{
	cout << "sp::sp(const sp& op)" << endl;
	this->p = op.p;
	if (p) 
		p->incRefCount();
}
template <typename T> sp<T>::~sp()
{
	cout << "sp::~sp()" << endl;
	p->decRefCount();
	if (!(p->getRefCount())) {
		cout << "recount is 0,release memory" << endl;
		if (p)
			delete p;
	}
}
template <typename T> T &sp<T>::operator*() 
{
	//cout << "T &sp<T>::operator*()" <<endl; 
	return (*p);
}

template <typename T> T *sp<T>::operator->()
{
	//cout << "T *sp<T>::operator->()" << endl;
	return this->p;
}
