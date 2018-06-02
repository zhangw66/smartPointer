#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;
class sp {
private:
	Person *p;
protected:
public:
	Person * operator->();
	sp(Person *);
	sp(const sp&);
	~sp();
};
