#pragma once

#include "Node.h"

template <class T>
class LinkedList
{
  private:
    Node<T>* head;
  public:
    LinkedList();
    LinkedList(Node<T>*);

    void push(Node<T>*);
    Node<T>* getHead();
};

template <class T>
LinkedList<T>::LinkedList() {
  head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(Node<T>* inputHead) {
  head = inputHead;
}

template<class T>
void LinkedList<T>::push(Node<T>* newNode) {
  newNode->setNext(head);
  head = newNode;
}

template<class T>
Node<T>* LinkedList<T>::getHead() {
  return head;
}
