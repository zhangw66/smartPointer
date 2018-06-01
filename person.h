#pragma once
#include <iostream>
#include <string>
using namespace std; 
class Person {
private:
	string sex;
	string name;
public:
	string getName() {return this->name;};
	string getSex() {return this->sex;};
	Person(string sex, string name);
	~Person();
};
