#pragma once
#include <memory.h>
#include "Node.h"

namespace Singly {
  template <class T>
  class LinkedList
  {
    private:
      std::shared_ptr<Node<T>> head;
    public:
      LinkedList();

      // Insert a node at the beggining of the list
      void push(T);

      // Insert a node after another node
      void insertAfter(std::shared_ptr<Node<T>>, T);

      // Insert a node at the end of the list
      void append(T);

      // Retrieve a node at index
      std::shared_ptr<Node<T>> at(int);

      std::shared_ptr<Node<T>> getHead();
  };

  template <class T>
  LinkedList<T>::LinkedList() {
    head = nullptr;
  }

  template<class T>
  void LinkedList<T>::push(T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, head));
    head = newNode;
  }

  template<class T>
  void LinkedList<T>::insertAfter(std::shared_ptr<Node<T>> refNode, T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, refNode->getNext()));
    refNode->setNext(newNode);
  }

  template<class T>
  void LinkedList<T>::append(T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data));

    std::shared_ptr<Node<T>> tmp(head);
    while (tmp->getNext() != nullptr) {
      tmp = tmp->getNext();
    }

    tmp->setNext(newNode);
  }

  template<class T>
  std::shared_ptr<Node<T>> LinkedList<T>::at(int index) {
    std::shared_ptr<Node<T>> tmp(head);

    for (int i = 0; i < index; i++) {
      std::shared_ptr<Node<T>> next(tmp->getNext());
      
      if (next == nullptr) return tmp;

      tmp = next;
    }

    return tmp;
  }

  template<class T>
  std::shared_ptr<Node<T>> LinkedList<T>::getHead() {
    return head;
  }
}