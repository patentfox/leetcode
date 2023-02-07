

#include <algorithm>
#include <any>
#include <cmath>
#include <iostream>
#include <span>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger() {}

  // Constructor initializes a single integer.
  NestedInteger(int value) { list_.push_back(value); }

  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const { throw "Unimplemented"; }

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const { throw "Unimplemented"; }

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value) { throw "Unimplemented"; }

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger &ni) { list_.push_back(ni); }

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const { throw "Unimplemented"; }

 private:
  std::vector<std::any> list_;
};

struct Token {
  char type;
  int val;
};

class Solution {
 public:
  NestedInteger deserialize(string s) {
    int index = 0;
    return deserialize(s, index);
  }

 private:
  Token cache_;
  bool isFull_;

  NestedInteger deserialize(string s, int &index) {
    Token tok = getNextToken(s, index);
    if (tok.type == '0') {
      return NestedInteger(tok.val);
    } else {
      NestedInteger list;
      Token temp = getNextToken(s, index);
      if (temp.type == ']') {
        return list;
      }
      putBack(temp);
      while (true) {
        list.add(deserialize(s, index));
        Token nextTok = getNextToken(s, index);
        if (nextTok.type == ']') {
          break;
        }
      }
      return list;
    }
  }

  Token getNextToken(string s, int &index) {
    if (isFull_) {
      isFull_ = false;
      return cache_;
    }
    if (string("[],").find(s[index]) != string::npos) {
      return {
          s[index++],
      };
    }
    int num = 0;
    int multiply = 1;
    if (s[index] == '-') {
      multiply = -1;
      ++index;
    }
    while (index < s.size() && (isdigit(s[index]))) {
      num = num * 10 + toInt(s[index]);
      ++index;
    }
    return {'0', num * multiply};
  }

  void putBack(Token tok) {
    assert(isFull_ == false);
    cache_ = tok;
    isFull_ = true;
  }

  int toInt(char c) { return c - '0'; }
};

int main() {
  Solution sol;
  NestedInteger ni = sol.deserialize("-3");
  return 0;
}
