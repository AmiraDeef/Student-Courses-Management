#include "Person.h"


Person::Person(){}
Person::Person(string name){
	this->name = name;
}

string Person::getName(){
	return name;
}

Person::~Person() {}