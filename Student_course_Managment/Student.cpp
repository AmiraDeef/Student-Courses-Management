#include "Student.h"

int Student::counter = 100;

Student::Student(string n, double g) {
	this->id= ++counter;
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
void Student::addCourse(int c_id,string c_name) {
	auto value=courses.insert(Course( c_id, c_name));
	if (value.second) {
		cout << c_name << " added to your courses." << endl;
	}
	else {
		cout << "[Notice] You are already enrolled in " << c_name << "!" << endl;
	}
}

void Student::displayCourses() {
	if (courses.empty()) {
		cout << "no courses found" << endl;
		return;
	}
	for (Course c : courses) {
		cout << c.gatName() << "\t";

	}
}

//bool Student::operator>(Student& s) {
//	return this->getGPA() > s.getGPA();
//}

