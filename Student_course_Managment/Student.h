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
	static int counter;
	double gpa = 0.0;
	set<Course>courses;



public:
	Student( string n, double g);
	int getId();
	double getGPA();
	set<Course> getCourses();
	void addCourse(int c_id,string c_name);
	void displayCourses();
	void setGPA(double g);
	void setId(int up_id);
	static void setCounter(int latest_id);

	//bool operator>(Student& s);



};

#endif 



