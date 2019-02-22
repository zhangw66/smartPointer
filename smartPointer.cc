#include "smartPointer.h"
/*
 * level1:
 * 	    利用函数返回的时候会析构非new出来的对象这个特性.
 * */
template <typename T> sp<T>::sp():p(nullptr)
{
	cout << "sp<T>::sp():p(nullptr)" << endl;
}
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
	if (p)
		p->decRefCount();
	/*原先释放对象是在这里做的,但是更换到RefCount类中去做更好*/
	#if 0
	if (!(p->getRefCount())) {
		cout << "recount is 0,release memory" << endl;
		if (p)
			delete p;
	}
	#endif
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

/*
	sp之间的相互赋值:
	指向新的内存:先对原先的内存引用计数减一,在对新的加1
*/
template <typename T> sp<T>& sp<T>::operator=(const sp& pother)
{
	cout << "sp<T>& sp<T>::operator=(const sp& pother)" << endl;
	if (pother.p != this->p) {
		if (p)
			p->decRefCount();
		this->p = pother.p;
		if (p) 
			p->incRefCount();
	}
}
/*
	sp被object指针赋值.可以是nullptr
*/
template <typename T> sp<T>& sp<T>::operator=(const T* pother)
{
	cout << "sp<T>& sp<T>::operator=(const T* pother)" << endl;
	if (pother != this->p) {
		if (p) p->decRefCount();
		this->p = const_cast<T *>(pother);
		if (p) p->incRefCount();
	}
}