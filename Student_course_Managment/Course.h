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
	Course(int id,string n);
	~Course();
	int getId()const;
	string gatName()const;
	bool operator<(const Course& c)const;

};




#endif 


