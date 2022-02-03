//Student functions
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student(char* newFirstname, char* newLastname, int newId, int newGPA) { //constructor
    strcpy(firstname, newFirstname);
    strcpy(lastname, newLastname);
    id = newId;
    GPA = newGPA;
}

int Student::getId() { //getter for id
    return id;
}

double Student::getGPA() { //getter for id
    return GPA;
}

void Student::print() { //prints student name, id, and GPA
    cout << firstname << " " << lastname << ", " << id << ", " << fixed << setprecision(2) << GPA << endl;
}