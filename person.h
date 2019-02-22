#pragma once
#include "android_ref/StrongPointer.h"
#include <iostream>
#include <string>
using namespace std;
using namespace ::android::RSC;
/*
 *有一些信息是需要从Person类中解耦出来，
 *否则每次定义都需要加上这些引用计数的功能
 *我们将这些信息抽离出来。
 * */
template <typename T>
class RefCount {
private:
	int refCount;
protected:
  	~RefCount(){ cout << "RefCount disconstructor!!" << endl; };

public:
	RefCount():refCount(0){cout << "RefCount constructor!!"<<endl;};
	void incStrong(sp<T> *p) { refCount++; };
	void decStrong(sp<T> *p)
	{
		refCount--; 
		if (!refCount) 
		{
			cout << "refcount is 0,delete object" << endl;
			/*这里的操作类似于向下转换,从基类RefCount转换为派生类Person*/
			delete static_cast<const T *>(this); 
		}
	};
	int getRefCount()const{return refCount;} ;
};
class Person: public RefCount<Person> {
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
