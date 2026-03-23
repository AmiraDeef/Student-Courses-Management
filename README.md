# Student & Course Management System

## About the Project
I built this project as a simple console application in C++ to manage students and their courses. The main goal was to practice OOP concepts and also handle real problems like storing data and keeping it after closing the program.

---

## 📊 System Design
Below is the UML class diagram showing the relationships between classes (Inheritance, Aggregation, and Association).

![UML Diagram](./digrams/std_class_digram.png)

---

## What I implemented

### 1. OOP Design
I used Object-Oriented Programming to structure the project:
- A base class `Person`
- A derived class `Student`

This helped me organize the data and keep the code clean and reusable.

---

### 2. Managing Students
I stored all students using a `vector`.

Each student has:
- Auto-generated ID
- Name
- GPA
- List of enrolled courses

---

### 3. Course System
I created predefined courses with IDs instead of letting the user type names manually.

This helped:
- Avoid input mistakes
- Make the system more realistic

Also, I made sure a student cannot enroll in the same course twice.

---

### 4. File Handling (Save & Load)
I implemented saving and loading using a text file:

- Data is saved in `students.txt`
- When the program starts, it loads all previous data
- This prevents losing data after closing the program

I used:
- `fstream` for file handling
- `stringstream` to parse the data

---

## 🛠️ Requirements

To run this project, you need:
- C++ compiler (GCC or Visual Studio)
- Windows OS (recommended for Visual Studio users)

---

## ▶️ How to Compile and Run

### Option 1: Using Visual Studio
1. Open Visual Studio
2. Go to **File > Open > Project/Solution**
3. Select the project file (`.sln`)
4. Press `Ctrl + Shift + B` to build
5. Press `Ctrl + F5` to run

---

### Option 2: Using G++ (Command Line)

Make sure all `.cpp` files are in the same folder, then run:

```bash
g++ -o StudentSystem Student_course_Managment.cpp Student.cpp Managment.cpp Course.cpp Person.cpp
```
---

## Challenges I faced

- Handling file parsing correctly (especially courses)
- Avoiding crashes when reading wrong or empty data
- Making sure IDs stay unique after reloading the file

---

## Limitations

- The program uses a text file, so it’s not suitable for large systems
- No graphical interface (only console)
- No validation for duplicate student names

---

## Future Improvements

- Use a database instead of a text file
- Add a simple GUI
- Improve input validation
- Add editing (update student data)

---

## Final Note

This project helped me understand OOP, file handling, and how real systems manage data step by step.  
I also learned how small mistakes in input or file parsing can cause crashes, and how to debug them.
