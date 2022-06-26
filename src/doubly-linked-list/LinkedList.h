#pragma once
#include <memory.h>
#include "Node.h"

namespace Doubly {
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
    std::shared_ptr<Node<T>> newNode(new Node<T>(data));
    newNode->setNext(head);

    if (head != nullptr) head->setPrev(newNode);

    head = newNode;
  }

  template<class T>
  void LinkedList<T>::insertAfter(std::shared_ptr<Node<T>> refNode, T data) {
    std::shared_ptr<Node<T>> nextNode = refNode->getNext();
    std::shared_ptr<Node<T>> newNode(new Node<T>(data, refNode, nextNode));
    nextNode->setPrev(newNode);
    refNode->setNext(newNode);
  }

  template<class T>
  void LinkedList<T>::append(T data) {
    std::shared_ptr<Node<T>> newNode(new Node<T>(data));

    std::shared_ptr<Node<T>> tmp(head);
    while (tmp->getNext() != nullptr) {
      tmp = tmp->getNext();
    }

    newNode->setPrev(tmp);
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
  void LinkedList<T>::pop() {
    if (head == nullptr) return;
    std::shared_ptr<Node<T>> nextItem(head->getNext());

    if (nextItem == nullptr) {
      head = nullptr;
      return;
    }
    
    head = nextItem;
  }

  template<class T>
  void LinkedList<T>::removeTail() {
    std::shared_ptr<Node<T>> tmp(head);
    while(tmp->getNext()->getNext() != nullptr) {
      tmp = tmp->getNext();
    }

    tmp->setNext(nullptr);
  }

  template<class T>
  void LinkedList<T>::removeNode(std::shared_ptr<Node<T>> node) {
    std::shared_ptr<Node<T>> prevNode(node->getPrev());
    std::shared_ptr<Node<T>> nextNode(node->getNext());

    if (prevNode != nullptr) prevNode->setNext(nextNode);
    if (nextNode != nullptr) nextNode->setPrev(prevNode);
  }

  template<class T>
  void LinkedList<T>::removeAt(int index) {
    std::shared_ptr<Node<T>> tmp(head);

    for (int i = 0; i < index; i++) {
      if (tmp == nullptr) return;
      tmp = tmp->getNext();
    }

    if (tmp->getNext() == nullptr) return;

    removeNode(tmp);
  }

  template<class T>
  std::shared_ptr<Node<T>> LinkedList<T>::getHead() {
    return head;
  }
}
