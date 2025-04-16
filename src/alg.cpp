// Copyright 2025 NNTU-CS
#include "tstack.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::ostringstream postfix;
  std::istringstream iss(inf);
  std::string token;

  while (iss >> token) {
    if (std::isdigit(token[0])) {
      postfix << token << " ";
    } else if (token[0] == '(') {
      stack.push('(');
    } else if (token[0] == ')') {
      while (!stack.isEmpty() && stack.peek() != '(') {
        postfix << stack.pop() << " ";
      }
      stack.pop();
    } else {
      while (!stack.isEmpty() &&
             precedence(stack.peek()) >= precedence(token[0])) {
        postfix << stack.pop() << " ";
      }
      stack.push(token[0]);
    }
  }

  while (!stack.isEmpty()) {
    postfix << stack.pop() << " ";
  }
  return postfix.str();
}

int eval(const std::string& post) {
  TStack<int, 100> stack;
  std::istringstream iss(post);
  std::string token;

  while (iss >> token) {
    if (std::isdigit(token[0])) {
      stack.push(std::stoi(
          token));
    } else {
      int b = stack.pop();
      int a = stack.pop();
      switch (token[0]) {
        case '+':
          stack.push(a + b);
          break;
        case '-':
          stack.push(a - b);
          break;
        case '*':
          stack.push(a * b);
          break;
        case '/':
          stack.push(a / b);
          break;
      }
    }
  }
  return stack.pop();
}
