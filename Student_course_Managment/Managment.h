#ifndef MANAGMENT_H_
#define MANAGMENT_H_
#include <iostream>
#include "Student.h"
#include "Course.h"
#include <string>
#include <vector>
class Managment
{
private:
	vector<Student> students;


public:
	void addStdt(int id, string n, double g);
	void removeStd(int id);
	void sortByGPA();
	void enrollStd(int std_id, string c_name);
	void  searchStd(int id);
	void diplayAllStd();


};
#endif // !MANAGMENT_H_



