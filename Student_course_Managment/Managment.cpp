#include "Managment.h"
#include "Student.h"
#include <algorithm>


void Managment::addStdt(int id, string n, double g){
	while (g < 0 || g>4) {
		cout << "re-enter GPA,GPA must between 0.0 and 4.0";
		cin >> g;

 }
	students.push_back(Student( id,  n,  g));
	cout << "Student added" << endl;
}
void Managment::removeStd(int id){
	auto ptr_std = find_if(students.begin(), students.end(), [id](Student std) {
		return std.getId() == id;
		});
	if (ptr_std != students.end()) {
		students.erase(ptr_std);
		cout << "student removed successfully" << endl;

	}
	else {
		cout << "student not found." << endl;
	}

}
void Managment::diplayAllStd() {

	if (students.empty()) {
		cout << "There are no students";
		
	 return;
	}
	for (auto s : students) {
		cout << "std id: " << s.getId() << "std name: " << s.getName() << "std GPA: " << s.getGPA() << endl; 
		cout << "std courses: " << "\t";
		s.displayCourses();
	}



}
void Managment::sortByGPA(){
	if (students.empty()) return;
	sort(students.begin(), students.end(), [](Student a, Student b) {
		return a.getGPA() > b.getGPA();});
	cout << "Students sorted by GPA dessending: " << endl;
	//diplayAllStd();
		
}
void Managment::enrollStd(int std_id,string c_name){
	auto ptr_std = find_if(students.begin(), students.end(), [std_id](Student std) {
		return std.getId() == std_id;
		});

	if (ptr_std != students.end()) {
		ptr_std->addCourse(c_name);
		cout << c_name << " course added to student named: " << ptr_std->getName() << endl;
	}
	else {
		cout << "Student not found" << endl;

	}
}
void Managment::searchStd(int id){
	auto ptr_std = find_if(students.begin(), students.end(), [id](Student std) {
		return std.getId() == id;
		});
	if (ptr_std != students.end()) {
		cout << "std name: " << ptr_std->getName() << "  GPA: " << ptr_std->getGPA() << endl;
	}
	else {
		cout << "Student not found" << endl;
	}
}
