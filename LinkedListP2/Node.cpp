// create node code here
#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

// set up all functions for LinkedList

Node::Node(Student* student){
  studentpointer = student;
  nextpointer = NULL;
}

Node::~Node(){
  delete studentpointer;
  nextpointer = NULL;
}

Student* Node::getStudent(){  
  return studentpointer;

}

Node* Node::getNext(){
  // return next node
  return nextpointer;
  
}

void Node::setNext(Node* nextnode){

  nextpointer = nextnode;
  
}
