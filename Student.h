

#ifndef ASS3_STUDENT_H
#define ASS3_STUDENT_H
using namespace std;

// Class Headers
#include "Course.h"
#include "FCI_VECTOR.h"

class Student
{
private:
    FCI_VECTOR<Course>Courses;
    string Name,Department;
    int ID;
public:
    // Constructor

    Student(string , int ,string); // Name // ID // Department
    Student(); // Initialize the attributes.

    // Setters' Prototypes

    void setName (string); // String Name
    void setDepartment (string); // String Department
    void setID  (int); // Int Year

    // Getters' Prototypes

    string getName();
    string getDepartment();
    int getID();

    // Methods' Prototypes

    void printStudentInfo();

    void addStudentCourses(Student& s);
    void printStudentCourses(Student& s);


    // Overloading Prototypes

    friend istream & operator >> (istream &in, Student &s);
    friend ostream& operator << (ostream&out,  Student &s);

};

#endif //ASS3_STUDENT_H
