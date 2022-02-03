// this is .h file for node
#include <iostream>
#include "Student.h"

using namespace std;

class Node {

public:

  // set up all required parts for Linked List
  
  Node* nextpointer;
  Student* studentpointer;
  Student* getStudent();
  Node* getNext();  
  void setNext(Node*);
  
  Node(Student*);
  ~Node();
  
};