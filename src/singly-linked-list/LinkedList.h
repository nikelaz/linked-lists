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

      void push(T);
      void insertAfter(std::shared_ptr<Node<T>>, T);
      void append(T);
      std::shared_ptr<Node<T>> getHead();
  };

  template <class T>
  LinkedList<T>::LinkedList() {
    head = nullptr;
  }

  // Insert a node at the beggining of the list
  template<class T>
  void LinkedList<T>::push(T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, head));
    head = newNode;
  }

  // Insert a node after another node
  template<class T>
  void LinkedList<T>::insertAfter(std::shared_ptr<Node<T>> refNode, T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, refNode->getNext()));
    refNode->setNext(newNode);
  }

  // Insert a node at the end of the list
  template<class T>
  void LinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);

    Node<T>* tmp = head;
    while (tmp->getNext() !== nullptr) {
      tmp->getNext();
    }

    tmp.setNext(newNode);
  }

  template<class T>
  std::shared_ptr<Node<T>> LinkedList<T>::getHead() {
    return head;
  }
}