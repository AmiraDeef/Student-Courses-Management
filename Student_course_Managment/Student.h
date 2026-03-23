#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include<string>
#include "Person.h"
#include "Course.h"
#include <set>

using namespace std;
class Student :public Person
{
private:

	int id;
	double gpa = 0.0;
	set<Course>courses;



public:
	Student(int id, string n, double g);
	int getId();
	double getGPA();
	void addCourse(int c_id,string c_name);
	void displayCourses();
	void setGPA(double g);
	//bool operator>(Student& s);



};

#endif 



