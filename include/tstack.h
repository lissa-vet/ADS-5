// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
 private:
  T* arr;
  int top;

 public:
  TStack(): top(-1) {
    arr = new T[size];
  }
  void push(T value) {
    if (isFull()) {
      throw std::string("Full stack");
    } else {
      srr[++top] = value;
    }
  }

  const T& pop() {
    if (isEmpty()) {
    throw std::string("Empty stack");
    } else {
      return arr[top--];
    }
  }

  const T& get() const {
    if (isEmpty()) {
      throw std::string("Empty stack");
    } else {
      return arr[top];
    }
  }

  bool isEmpty() const {
    if (top == -1) {
      return true;
    } else {
      return false;
    }
  }

  bool isFull() const {
    if (top == (size-1)) {
      return true;
    } else {
      return false;
    }
  }
};

#endif  // INCLUDE_TSTACK_H_
