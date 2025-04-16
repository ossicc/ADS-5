// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int kSize>
class TStack {
 private:
  T data[kSize];
  int top;

 public:
  TStack() : top(-1) {}

  void push(const T& value) {
    if (top >= kSize - 1) {
      throw std::overflow_error("Stack overflow");
    }
    data[++top] = value;
  }

  T pop() {
    if (top < 0) {
      throw std::underflow_error("Stack underflow");
    }
    return data[top--];
  }

  T peek() const {
    if (top < 0) {
      throw std::underflow_error("Stack is empty");
    }
    return data[top];
  }

  bool isEmpty() const { return top < 0; }
};

#endif  // INCLUDE_TSTACK_H_
