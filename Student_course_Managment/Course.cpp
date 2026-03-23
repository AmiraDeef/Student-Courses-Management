#include "Course.h"
#include <random>
Course::Course(string n) {
	name = n;
	id = 0;
}
Course::~Course() {}
int Course::getId() {
	return id;
}
string Course::gatName() {
	return name;
}