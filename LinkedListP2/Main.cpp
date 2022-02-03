#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node* &head, Node* current, Node* newNode) { //method that adds using recursion
    if (head == NULL) { //empty list
        head = newNode;
    }
    else if (newNode->getStudent()->getId() < head->getStudent()->getId()) { //id is less than head which means it is the new head
        head = newNode;
        head->setNext(current);
    }
    else if (current->getNext() == NULL) { //id reaches end of list which means it is biggest id and is added
        current->setNext(newNode);
    }
    else if (current->getStudent()->getId() < newNode->getStudent()->getId() && current->getNext()->getStudent()->getId() > newNode->getStudent()->getId()) { //added in between current and next
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
    else { //recursion
        add(head, current->getNext(), newNode);
    }
}

void remove(Node* &head, Node* current, Node* previous, int id) { //method that deletes using recursion
    if (head == NULL) { //empty list
        cout << "Empty list.";
    }
    else if (head->getStudent()->getId() == id) { //head is being removed which means head's next is made new head
        Node* temp = head;
        head = head->getNext();
        temp->~Node();
    }
    else if (current == NULL) { //reaches end of list without finding id which means student is not in the list
        cout << "This student is not in the list.";
    }
    else if (current->getStudent()->getId() == id) { //removes current head if id is found
        previous->setNext(current->getNext());
        current->~Node();
    }
    else {
        remove(head, current->getNext(), previous->getNext(), id); //recursion
    }
}

void print(Node* head) { //method that prints every student in the list
    if (head != NULL) {
        head->getStudent()->print();
        print(head->getNext());
    }
}

double average(Node* head, double sum, double num) { //method that returns average gpa of the students in the list
    if (head != NULL) {
        sum+=head->getStudent()->getGPA();
        num++;
        average(head->getNext(), sum, num);
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
            char firstname[100];
            char lastname[100];
            int id;
            double GPA;
            cout << "Enter the student's first name:" << endl;
            cin >> firstname;
            cout << "Enter the student's last name:" << endl;
            cin >> lastname;
            cout << "Enter the student's id:" << endl;
            cin >> id;
            cout << "Enter the student's GPA:" << endl;
            cin >> GPA;

            Student* student = new Student(firstname, lastname, id, GPA);
            Node* node = new Node(student);

            add(head, head, node);
        }

        else if (strcmp(input, "DELETE") == 0) {
            int id;
            cout << "Enter the student's id:" << endl;
            cin >> id;

            remove(head, head->getNext(), head, id);
        }

        else if (strcmp(input, "PRINT") == 0) {
            print(head);
        }

        else if (strcmp(input, "AVERAGE") == 0) {
            cout << fixed << setprecision(2) << average(head, 0, 0) << endl;
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