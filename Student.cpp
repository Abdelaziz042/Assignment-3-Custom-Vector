// ID       : 20180178
// Group   : G9 / G10
// Name   : Omar Abdelaziz Gamal Eldin Ahmed

#include <iostream>
#include "Student.h"
#include "Course.h"
// Constructor and Destructor

Student :: Student()
{
    Name="";
    Department="";
    ID=0;
}
Student :: Student(string name, int id, string Depart)
{
    setName(name);
    setID(id);
    setDepartment(Depart);
}

//Student :: ~Student(){}

// Setters Implementation

void Student :: setName(string name) {Name=name;}
void Student :: setDepartment(string Depart){Department=Depart;}
void Student :: setID(int id){ID=id;}

// Getters Implementation

string Student :: getName(){return Name;}
string Student :: getDepartment(){return Department;}
int Student    :: getID(){return ID;}

// Method

void Student :: printStudentInfo()
{
    cout << "Student Information: \n";
    cout << "- Name : " << getName() << endl;
    cout << "- ID : " << getID() << endl;
    cout << "- Department : " << getDepartment() << endl << endl;
}
void Student :: addStudentCourses(Student& s)
{
    Course c;
    int sCourse;
    cout << "Number of Courses : "; cin >> sCourse;
    for(int i=0;i<sCourse;i++)
    {
        if(i==0) {
            cout << s.getName().substr(0, s.getName().find(' ')) << " , ";
            cout << "Please fill your course " << "#" << i + 1 << " information " << endl;
        } else
        { cout << "Fill your course " << "#" << i + 1 << " information " << endl;}
        cin >> c;
        s.Courses.push_back(c);
    }
}

void Student :: printStudentCourses(Student& s)
{
    for (int i=0;i<s.Courses.getSize();i++)
    {
        cout << "Course " << "#"  <<i+1 << " Information : " << endl;
        cout <<s.Courses[i] << endl;
    }
}

// Overloading Implementation

 istream &operator>>(istream &in, Student &s)
{
    cout << "Please fill your information \n";
    in.ignore();
    cout << "\t-    Name       : ";  getline(in,s.Name) ;
    cout << "\t-    ID         : ";
    while(!(in >> s.ID))
    {
        cout << "\nWrong Input!\n";
        in.clear();
        in.ignore(1000 ,'\n');
        cout << "\t-    ID         : ";
    }
    in.ignore();
    cout << "\t-    Department : ";  getline(in,s.Department);

    s.addStudentCourses(s);
    return in;
}
 ostream &operator<<(ostream &out, Student &s)
{
    out << "\nHi "<< s.getName().substr(0,s.getName().find(' ')) << ".Your student information : " << endl;

    out << "\t-     Name       : " << s.Name << endl;
    out << "\t-     ID         : " << s.ID << endl;
    out << "\t-     Department : " << s.Department << endl << endl;

    s.printStudentCourses(s);

    return out;
}



