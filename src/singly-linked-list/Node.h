#pragma once
#include <memory.h>

namespace Singly {
  template <class T>
  class Node
  {
    private:
      T data;
      std::shared_ptr<Node> next;

    public:
      Node();
      Node(T);
      Node(T, std::shared_ptr<Node>);

      T getData();
      void setData(T);

      std::shared_ptr<Node> getNext();
      void setNext(std::shared_ptr<Node>);
  };

  template <class T>
  Node<T>::Node() {
    data = 0;
    next = nullptr;
  }

  template <class T>
  Node<T>::Node(T inputData) {
    data = inputData;
    next = nullptr;
  }

  template <class T>
  Node<T>::Node(T inputData, std::shared_ptr<Node<T>> inputNext) {
    data = inputData;
    next = inputNext;
  }

  template <class T>
  void Node<T>::setData(T inputData) {
    data = inputData;
  }

  template <class T>
  T Node<T>::getData() {
    return data;
  }

  template <class T>
  void Node<T>::setNext(std::shared_ptr<Node<T>> inputNext) {
    next = inputNext;
  }

  template <class T>
  std::shared_ptr<Node<T>> Node<T>::getNext() {
    return next;
  }
}