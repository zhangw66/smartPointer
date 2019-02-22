#include <iostream>
#include "person.h"
#include "smartPointer.cc"
using namespace std;
template <typename T>int printPersonObjRefCount(sp<T> &);
void printHumanBaseInfo(Person& p)
{
	cout << "getName:" << p.getName() << endl;
	cout << "getSex:" << p.getSex() << endl;
}
void test_pointer()
{
	Person *pb = new Person("lala", "mc"); //new 的对象必须delete才可以调用析构,否则内存泄漏.
	printHumanBaseInfo(*pb);
	delete pb;
	Person *pa = new Person("woman", "zhangjing"); //new 的对象必须free才可以调用析构,否则内存泄漏.
	printHumanBaseInfo(*pa);
	Person b = Person("gay", "lj");  //不使用NEW的方式,对象在stack上,函数返回会导致对象调用析构
	printHumanBaseInfo(b);
}
void testSmartPointer()
{
	sp<Person> pa = new Person("man", "ligan");
	pa->myInfo();
	printPersonObjRefCount(pa);
	sp<Person> pb = nullptr;
	pb = pa;
	printPersonObjRefCount(pa);
	pa = new Person("woman", "lili");
	pb = nullptr;
	pa = pb;
}
void testSmartPointer1(const sp<Person> &p)
{
	sp<Person> ptmp = p;
	printPersonObjRefCount(ptmp);
	/*
	 * 一块内存一定是要可以多个指针同时指向的，所以什么时候释放呢？如果随着指针变量生命周期
	 * 的结束而释放内寸显然是不合适的,因为别的指针可能还会用，那怎么办，如果new出来的对象（一块内存）
	 * 里边有引用计数，即知道当前有没有多少指针指向它就好了。
	 * 那样就可以在指针变量的生命周期结束的时候并且当前没有其他指针指向那片内存的时候释放就好了。
	 * 
	 */
	ptmp->myInfo();
	(*ptmp).myInfo();
}
template <typename T> 
int printPersonObjRefCount(/*const*/ sp<T> &p)
{
	int rc;
	rc = (*p).getRefCount();
	cout << "cur Person object's ref count:" << rc <<endl;
	return rc;
}
int main(int argc, const char *argv[])
{
	cout << "main func in<<<<<<<<<" << endl;
	testSmartPointer();
	cout << "main func end>>>>>>>>>" <<endl;
	return 0;
}
