#pragma once
#include <memory.h>

namespace Doubly {
  template <class T>
  class Node
  {
    private:
      T data;
      std::shared_ptr<Node> next;
      std::shared_ptr<Node> prev;

    public:
      Node();
      Node(T);
      Node(T, std::shared_ptr<Node>, std::shared_ptr<Node>);

      T getData();
      void setData(T);

      std::shared_ptr<Node> getNext();
      void setNext(std::shared_ptr<Node>);

      std::shared_ptr<Node> getPrev();
      void setPrev(std::shared_ptr<Node>);
  };

  template <class T>
  Node<T>::Node() {
    data = 0;
    next = nullptr;
    prev = nullptr;
  }

  template <class T>
  Node<T>::Node(T inputData) {
    data = inputData;
    next = nullptr;
    prev = nullptr;
  }

  template <class T>
  Node<T>::Node(T inputData, std::shared_ptr<Node<T>> inputPrev, std::shared_ptr<Node<T>> inputNext) {
    data = inputData;
    prev = inputPrev;
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

  template <class T>
  void Node<T>::setPrev(std::shared_ptr<Node<T>> inputPrev) {
    prev = inputPrev;
  }

  template <class T>
  std::shared_ptr<Node<T>> Node<T>::getPrev() {
    return prev;
  }
}
