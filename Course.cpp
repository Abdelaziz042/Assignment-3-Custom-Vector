// ID       : 20180178
// Group   : G9 / G10
// Name   : Omar Abdelaziz Gamal Eldin Ahmed

#include "Course.h"
#include <iostream>
#include <iomanip>

// Constructor

Course:: Course()
{
    courseName="";
    courseCode="";
    courseGrade=' ';
    coursePoint=0.0;
    courseYear=0;
    courseSemester=0;
}

// Setters Implementation

void Course:: setCourseName (string CN ){courseName=CN;}
void Course:: setCourseCode (string CC ){courseCode=CC;}
void Course:: setCourseGrade (char CG){courseGrade=CG;}
void Course:: setCoursePoint (float CP){coursePoint=CP;}
void Course:: setCourseYear (int CY){courseYear=CY;}
void Course:: setCourseSemester (int CS){courseSemester=CS;}

// Getters Implementation

string Course:: getCourseName (){return courseName;}
string Course:: getCourseCode (){return courseCode;}
char   Course:: getCourseGrade (){return courseGrade;}
float  Course:: getCoursePoint (){return coursePoint;}
int    Course:: getCourseYear (){return courseYear;}
int    Course:: getCourseSemester (){return courseSemester;}

// Method

void Course:: printCourseInfo()
{
    cout << "Course Information: \n";
    cout << "\t- Course Name     : " << getCourseName() << " ( " << getCourseCode() << " )" << endl;
    cout << "\t- Course Grade    : " << getCourseGrade() << " ( " << getCoursePoint() << " )" << endl;
    cout << "\t- Course Year     : " << getCourseYear() << endl;
    cout << "\t- Course Semester : " << getCourseSemester() << endl << endl;
}

// Overloading Implementation

istream &operator>>(istream &in, Course &c)
{
    in.ignore();
    cout << "\t- Course Name     : "; getline(in,c.courseName);
    cout << "\t- Course Code     : "; in >> c.courseCode;
    cout << "\t- Course Grade    : "; in >> c.courseGrade;
    cout << "\t- Course Point    : "; in >> c.coursePoint;
    while((c.coursePoint < 0) || (c.coursePoint >101))
    {
        cout << "Course Point is out of range" << endl;
        cout << "\t- Course Point : "; in >> c.coursePoint;
    }
    cout << "\t- Course Year     : "; in >> c.courseYear;
    while(c.courseYear < 1970 || c.courseYear > 2030)
    {
        cout << "\t- Course Year : "; in >> c.courseYear;
    }
    cout << "\t- Course Semester : ";
    while(!(in >> c.courseSemester))
    {
            cout << "\nWrong Input!" << endl;
            cin.clear();
            cin.ignore(1000 ,'\n');
            cout << "\t- Course Semester : ";
    }

    return in;
}

 ostream &operator<<(ostream &out,const Course &c)
{
    out << "\t- Course Name     : " << c.courseName << endl;
    out << "\t- Course Code     : " << c.courseCode << endl;
    out << "\t- Course Grade    : " << char(toupper(c.courseGrade)) << endl;
    out << "\t- Course Point    : " << setprecision(3) << c.coursePoint << endl;
    out << "\t- Course Year     : " << c.courseYear << endl;
    out << "\t- Course Semester : " << c.courseSemester << endl << endl;

    return out;
}
