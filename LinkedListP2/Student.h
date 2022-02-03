//template of 'Student.cpp'
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student {
    //local variables
    char firstname[100];
    char lastname[100];
    int id;
    double GPA;
  public:
    Student(char* newFirst, char* newLast, int newId, int newGPA); //constructer
    int getId(); //getter for id
    double getGPA(); //getter for GPA
    void print(); //prints student
};

#endif