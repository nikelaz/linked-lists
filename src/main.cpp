#include <iostream>

namespace Singly {
  #include "./singly-linked-list/Node.h"
  #include "./singly-linked-list/LinkedList.h"
}

int main() {
  /* Singly Linked List Demo
   ************************************** */
  Singly::LinkedList<int>* list1 = new Singly::LinkedList<int>();

  list1->push(new Singly::Node<int>(1));
  list1->push(new Singly::Node<int>(2));
  list1->push(new Singly::Node<int>(3));

  Singly::Node<int>* i = list1->getHead();

  std::cout << "Singly Linked List Demo" << std::endl;

  while (i != nullptr) {
    std::cout << i->getData() << std::endl;
    i = i->getNext();
  }

  return 0;
}
