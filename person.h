#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
 *有一些信息是需要从Person类中解耦出来，
 *否则每次定义都需要加上这些引用计数的功能
 *我们将这些信息抽离出来。
 * */
class RefCount {
private:
	int refCount;
protected:
public:
	RefCount():refCount(0){cout << "RefCount constructor!!"<<endl;};
	void incRefCount(){refCount++;};
	void decRefCount(){refCount--;};
	int getRefCount()const{return refCount;} ;
};
class Person: public RefCount {
private:
	string sex;
	string name;
public:
	string getName() {return this->name;};
	string getSex() {return this->sex;};
	Person(string sex, string name);
	void myInfo(){cout << name <<"+"<<sex<<endl;};
	~Person();
};
