#pragma once
#include <memory.h>
#include "Node.h"

namespace Circly {
  template <class T>
  class LinkedList
  {
    private:
      std::shared_ptr<Node<T>> head;
      std::shared_ptr<Node<T>> tail;
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

      // Remove the node at head (first node)
      void pop();

      // Remove the last node (tail node)
      void removeTail();

      // Remove a specific node from the list
      void removeNode(std::shared_ptr<Node<T>>);

      // Remove a node at index from the list
      void removeAt(int);

      std::shared_ptr<Node<T>> getHead();
  };

  template <class T>
  LinkedList<T>::LinkedList() {
    head = nullptr;
  }

  template<class T>
  void LinkedList<T>::push(T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, head));

    if (head == nullptr) {
      tail = head = newNode;
      return;
    }

    head = newNode;
    tail->setNext(newNode);
  }

  template<class T>
  void LinkedList<T>::insertAfter(std::shared_ptr<Node<T>> refNode, T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, refNode->getNext()));

    refNode->setNext(newNode);

    if (refNode == tail) tail = refNode;
  }

  template<class T>
  void LinkedList<T>::append(T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, head));

    tail->setNext(newNode);
    tail = newNode;
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
  void LinkedList<T>::pop() {
    if (head == nullptr) return;

    head = head->getNext();

    if (head == nullptr) {
      tail = nullptr;
      return;
    }

    if (tail != nullptr) tail->setNext(head);
  }

  template<class T>
  void LinkedList<T>::removeTail() {
    std::shared_ptr<Node<T>> tmp(head);
    while(tmp->getNext()->getNext() != head) {
      tmp = tmp->getNext();
    }

    tmp->setNext(head);
    tail = tmp;
  }

  template<class T>
  void LinkedList<T>::removeNode(std::shared_ptr<Node<T>> node) {
    if (node == head) {
      pop();
      return;
    }

    if (node == tail) {
      removeTail();
      return;
    }

    std::shared_ptr<Node<T>> tmp(head);
    while(tmp->getNext() != node) {
      tmp = tmp->getNext();
    }

    tmp->setNext(node->getNext());
  }

  template<class T>
  void LinkedList<T>::removeAt(int index) {
    if (index == 0) {
      pop();
      return;
    }

    std::shared_ptr<Node<T>> tmp(head);

    for (int i = 0; i < index - 1; i++) {
      if (tmp == nullptr) return;
      tmp = tmp->getNext();
    }

    std::shared_ptr<Node<T>> nextItem(tmp->getNext());

    if (nextItem == nullptr) return;

    if (nextItem == tail) tail = tmp;

    tmp->setNext(tmp->getNext()->getNext());
  }

  template<class T>
  std::shared_ptr<Node<T>> LinkedList<T>::getHead() {
    return head;
  }
}
