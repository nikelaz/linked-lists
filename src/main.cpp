#include <iostream>
#include <memory.h>
#include "./singly-linked-list/Node.h"
#include "./singly-linked-list/LinkedList.h"

int main() {
  // Singly Linked List Demo
  std::cout << "Singly Linked List Demo" << std::endl;
  
  std::unique_ptr<Singly::LinkedList<int>> list1(new Singly::LinkedList<int>());

  list1->push(1);
  list1->push(3);
  list1->push(4);
  list1->insertAfter(list1->getHead()->getNext(), 2);
  list1->append(0);

  std::shared_ptr<Singly::Node<int>> i(list1->getHead());

  while (i != nullptr) {
    std::cout << i->getData() << std::endl;
    i = i->getNext();
  }

  std::cout << "item at [3]:" << list1->at(3)->getData() << std::endl;

  return 0;
}
