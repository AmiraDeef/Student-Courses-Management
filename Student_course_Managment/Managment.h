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

	void addStdt( string n, double g);
	void removeStd(int id);
	void displayCourses();
	void sortByGPA();
	void enrollStd(int std_id, int c_id);
	void searchStd(int id);
	void diplayAllStd();
	void displayStdCourses(int id);
	void saveToFile();
	void loadFromFile();


};
#endif // !MANAGMENT_H_



