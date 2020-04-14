#ifndef ASS3_COURSE_H
#define ASS3_COURSE_H

#include <string>
using namespace std;

class Course
{
private:
    string courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear,courseSemester;
protected:
    string courseName;
public:
    // Constructor

    Course(); //Initializes the attributes.

    // Setters Prototypes

    void setCourseName (string);
    void setCourseCode (string);
    void setCourseGrade (char);
    void setCoursePoint (float);
    void setCourseYear (int);
    void setCourseSemester (int);

    // Getters Prototypes

    string getCourseName();
    string getCourseCode();
    char   getCourseGrade();
    float  getCoursePoint();
    int    getCourseYear();
    int    getCourseSemester();

    // Methods Prototypes

    void printCourseInfo();

   // Overloading Prototypes

    friend istream & operator >> (istream &in,  Course &c);
    friend ostream& operator << (ostream&out, const Course &c);
};

#endif //ASS3_COURSE_H
