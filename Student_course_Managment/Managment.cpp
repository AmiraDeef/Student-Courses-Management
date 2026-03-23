#include "Managment.h"
#include "Student.h"
#include <algorithm>
#include "Course.h"
#include<set>
#include <fstream>
#include <sstream>



static vector<Course>courses = {
	Course(101,"Math"),
	Course(102,"OOP"),
	Course(103,"Data Strucure"),
	Course(104,"Operating Systems"),
	Course(105,"Frontend"),
	Course(106,"Backend")
};

void Managment::addStdt( string n, double g){
	while (g < 0 || g>4) {
		cout << "re-enter GPA,GPA must between 0.0 and 4.0";
		cin >> g;

 }
	Student newStd(n, g);
	students.push_back(newStd);
	cout <<"student with Id:  " << newStd.getId() << "  added successfully" << endl;
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
	
		cout << "std id:  " << s.getId()<< "\t" << "std name:  " << s.getName() << "\t" << "std GPA: " << s.getGPA() << endl;
		cout << "std courses: "<<"\n";
		s.displayCourses();
		cout << endl;
	}



}
void Managment::sortByGPA(){
	if (students.empty()) return;
	sort(students.begin(), students.end(), [](Student a, Student b) {
		return a.getGPA() > b.getGPA();});
	cout << "Students sorted by GPA dessending: " << endl;
	//diplayAllStd();
		
}
void Managment::displayCourses() {
	cout << "\n--- Available Courses ---" << endl;
	for (Course& c : courses) {
		cout << c.getId() << " . " << c.gatName() << "\n";
	}
	cout << "\n--------------------------" << endl;
}
void Managment::enrollStd(int std_id,int c_id){

	
	
	auto ptr_std = find_if(students.begin(), students.end(), [std_id](Student & std) {
		return std.getId() == std_id;
		});

	if (ptr_std != students.end()) {
		auto ptr_co = find_if(courses.begin(), courses.end(), [c_id](Course c) {
			return c.getId() == c_id;
			});
		if (ptr_co != courses.end()) {
			//string c_name= ptr_co->gatName();
			ptr_std->addCourse(ptr_co->getId(), ptr_co->gatName());
			//cout << ptr_co->gatName() << " course added to student named: " << ptr_std->getName() << endl;
		}
		else {
			cout << "invalid input"<<endl;
		}
		
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
void Managment::displayStdCourses(int id) {
		auto ptr_std = find_if(students.begin(), students.end(), [id](Student& std) {
		return std.getId() == id;
		});
	if (ptr_std != students.end()) {
		cout << "std name: " << ptr_std->getName() << "  GPA: " << ptr_std->getGPA() << endl;
		cout << "std courses: ";
		ptr_std->displayCourses();
	}
	else {
		cout << "Student not found" << endl;
	}
}
void Managment::saveToFile(){
	ofstream file("students.txt", ios::trunc);
	if (!file) {
		cout << "not found" << endl;
		return;
	}
	for (auto s:students)
	{
		file << s.getId() << "," << s.getName() << "," << s.getGPA() ;
		for (auto c : s.getCourses()) {
			file<< "," << c.getId()<< ","<<c.gatName() ;
		}
		file << "\n";

	}

	file.close();
}
void Managment::loadFromFile(){
	ifstream file("students.txt");
	if (!file) {
		cout << "not found" << endl;
		return;
	}
	string line;
	int max_id = 1000;
	while(getline(file, line)) {
		stringstream str(line);
		string id_str, name, gpa_str, courses_str;
		getline(str, id_str, ',');
		getline(str, name, ',');
		getline(str, gpa_str, ',');
		getline(str, courses_str);
		int id = stoi(id_str);
		double gpa = stod(gpa_str);
		
		Student::setCounter(id - 1);
		Student s(name, gpa);
		s.setGPA(gpa);
		 id > max_id ? max_id = id : max_id;
		

		 stringstream ss_co(courses_str);
		 string c_name, c_id_str;

		 while (getline(ss_co, c_id_str, ',') && getline(ss_co, c_name, ',')) {
			 if (!c_id_str.empty() && !c_name.empty()) {
				 s.addCourse(stoi(c_id_str), c_name);
			 }
		 }
		students.push_back(s);
	}
	Student::setCounter(max_id);

}
