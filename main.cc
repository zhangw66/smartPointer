#include <iostream>
#include "person.h"
#include "smartPointer.h"
using namespace std;
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
	sp pa = new Person("man", "liguan");
	pa->myInfo();	
}

int main(int argc, const char *argv[])
{
	int count = 1;
	Person a = Person("man", "zhangw");
	printHumanBaseInfo(a);
	while (count--) {
		//test_pointer();
		testSmartPointer();
	}
	return 0;
}
