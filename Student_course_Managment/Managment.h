#ifndef MANAGMENT_H_
#define MANAGMENT_H_
#include <iostream>
#include "Student.h"
#include "Course.h"
#include <string>
#include <vector>
#include <set>
class Managment
{
private:
	vector<Student> students;
	
public:

	void addStdt(int id, string n, double g);
	void removeStd(int id);
	void displayCourses();
	void sortByGPA();
	void enrollStd(int std_id, int c_id);
	void searchStd(int id);
	void diplayAllStd();
	void displayStdCourses(int id);


};
#endif // !MANAGMENT_H_



