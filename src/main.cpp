#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
  LinkedList<int>* list1 = new LinkedList<int>();


  list1->push(new Node<int>(1));
  list1->push(new Node<int>(2));
  list1->push(new Node<int>(3));

  // Print all items from the list
  Node<int>* i = list1->getHead();

  while (i != nullptr) {
    std::cout << i->getData() << std::endl;
    i = i->getNext();
  }

  return 0;
}
