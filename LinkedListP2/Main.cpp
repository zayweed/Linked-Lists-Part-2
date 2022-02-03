#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node* head) {
    
}

void del(Node* head) {
    
}

void print(Node* head) {
    if (head != NULL) {
        head->getStudent()->print();
        print(head->getNext());
    }
}

double average(Node* head, double sum, double num) {
    if (head != NULL) {
        sum+=head->getStudent()->getGPA();
        num++;
    }
    else {
        return sum/num;
    }
}

int main() {

    Node* head = NULL;

    bool stillRunning = true;
    while (stillRunning == true) {
        cout << "What would you like to do next? (ADD, DELETE, PRINT, AVERAGE, QUIT)" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "ADD") == 0) {
            
        }

        else if (strcmp(input, "DELETE") == 0) {
            
        }

        else if (strcmp(input, "PRINT") == 0) {
            print(head);
        }

        else if (strcmp(input, "AVERAGE") == 0) {
            cout << fixed << setprecision(2) << average(head, 0, 0);
        }

        else if (strcmp(input, "QUIT") == 0) {
            cout << "You quit." << endl;
            stillRunning = false;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
}