#include "Student.h"


Student::Student(int id, string n, double g) {
	this->id = id;
	this->name = n;
	gpa = g;
}
int Student::getId() {
	return id;

}
double Student::getGPA() {
	return gpa;
}
void Student::setGPA(double g) {
	if (g >= 0 && g <= 4.0) {
		gpa = g;
	}
	else {
		gpa = 0.0;
		cout << "invalid gpa" << endl;
	}
	
}
void Student::addCourse(string c_name) {
	courses.insert(Course( c_name));
}

void Student::displayCourses() {
	if (courses.empty()) {
		cout << "no courses found" << endl;
		return;
	}
	for (Course c : courses) {
		cout << c.gatName() << endl;

	}
}

bool Student::operator>(Student& s) {
	return this->getGPA() > s.getGPA();
}

