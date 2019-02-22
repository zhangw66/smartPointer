#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;
template <typename T>
class sp {
private:
	T *p;
protected:
public:
	T* operator->();
	T&  operator*();
	sp& operator=(const sp&);
	sp& operator=(const T*);
	sp();
	sp(T *);
	sp(const sp&);
	~sp();
};
