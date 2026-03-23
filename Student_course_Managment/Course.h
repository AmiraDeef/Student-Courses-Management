#ifndef COURSE_H_
#define COURSE_H_
#include <string>
#include<iostream>
using namespace std;

class Course
{
private:
	string name;
	int id;

public:
	Course(string n);
	~Course();
	int getId();
	string gatName();
	bool operator<(const Course& c) const {
		return name < c.name;
	}

};




#endif 


