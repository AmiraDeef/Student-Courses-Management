// Student_course_Managment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Managment.h"
#include <vector>
#include <iostream>
using namespace std;

void displayMenu() {
    vector<string>commands = {
       "Exit",                         
        "Add New Student",               
        "Remove Student",               
        "Search for Student",            
        "Display All Students",         
        "Enroll Student in Course",     
        "Sort Students by GPA"
    };

    cout << "\n====================================" << endl;
    cout << "   STUDENT MANAGEMENT SYSTEM " << endl;
    cout << "====================================" << endl;


    for (int i = 0; i < commands.size(); i++)
    {
		cout << i << ". " << commands[i] << endl;

    }
	cout << "choose a num of choice: ";
	

}


int validateId() {
    int id;
    while(true) {
        if (cin >> id) {
			return id;
        }
        else {
            cout << "Invalid input. Pls enter a valid ID number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
	}
}

void validateChoice(int x, Managment& mRef) {
	bool flag = false;
    while (!flag)
    {
        switch (x) {
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
			flag = true;
            break;
        case 1: {
           
            string name;
            double gpa;
            cout << "Enter student ID: ";
            int id = validateId();
            cin.ignore();
            cout << "Enter student name: ";
			getline(cin, name);
            
            cout << "Enter student GPA: ";
            cin >> gpa;
            cin.ignore();

            mRef.addStdt(id, name, gpa);
            flag = true;

            break;
        }
        case 2: {
          
            cout << "Enter student ID to remove: ";
            int id=validateId();
            mRef.removeStd(id);
            flag = true;

            break;
        }
        case 3: {
            
            cout << "Enter student ID to search: ";
            int id = validateId();
            mRef.searchStd(id);
			flag = true;
            break;
        }
        case 4:
            mRef.diplayAllStd();
			flag = true;
            break;
        case 5: {
            
           mRef.displayCourses();
            cout << "Enter student id to enroll in course: ";
            int std_id = validateId();

         
            cout << "Enter course id: ";
            int c_id = validateId();
            
            mRef.enrollStd(std_id, c_id);
			flag = true;
            break;
        }
        case 6:
            mRef.sortByGPA();
            mRef.diplayAllStd();
			flag = true;
            break;
        default:

            cout << "Invalid choice. Re-enter num of commands(0-6)" << endl;
           if(!(cin>>x)){
               cin.clear();
            cin.ignore(1000, '\n');
		   }
           break;
            
            



        }

    }
       
}



int main()
{
    Managment m1;
	int choice;
    do
    {
        displayMenu();
		//cin >> choice;
        while (!(cin >> choice)) {
            cout << "Invalid choice. Enter number (0-6): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
		validateChoice(choice, m1);


    } while (choice != 0);
	
   
    return 0;
}

  