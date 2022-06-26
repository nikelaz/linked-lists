#pragma once

template <class T>
class Node
{
  private:
    T data;
    Node* next;

  public:
    Node();
    Node(T);
    Node(T, Node*);

    T getData();
    void setData(T);

    Node* getNext();
    void setNext(Node*);
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
Node<T>::Node(T inputData, Node* inputNext) {
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
void Node<T>::setNext(Node* inputNext) {
  next = inputNext;
}

template <class T>
Node<T>* Node<T>::getNext() {
  return next;
}
