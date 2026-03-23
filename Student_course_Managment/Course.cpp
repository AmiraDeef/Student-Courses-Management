#include "Course.h"
#include <random>
Course::Course(int id,string n) {
	name = n;
	this->id = id;
}
Course::~Course() {}
int Course::getId()const {
	return id;
}
string Course::gatName() const{
	return name;
}
bool Course::operator<(const Course& c)const {
	return this->name < c.name;
}

