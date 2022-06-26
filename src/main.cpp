#include <iostream>
#include <memory.h>
#include "./singly-linked-list/Node.h"
#include "./singly-linked-list/LinkedList.h"
#include "./doubly-linked-list/Node.h"
#include "./doubly-linked-list/LinkedList.h"

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


  // Doubly Linked List Demo
  std::cout << "Doubly Linked List Demo" << std::endl;

  std::unique_ptr<Doubly::LinkedList<int>> list2(new Doubly::LinkedList<int>());

  list2->push(1);
  list2->push(2);
  list2->push(2);
  list2->pop(); 
  list2->push(3);
  list2->push(4);

  std::cout << "List items backwards:" << std::endl;
  
  std::shared_ptr<Doubly::Node<int>> j(list2->getHead());

  while (j->getNext() != nullptr) {
    j = j->getNext();
  }

  while (j != nullptr) {
    std::cout << j->getData() << std::endl;
    j = j->getPrev();
  }

  return 0;
}
