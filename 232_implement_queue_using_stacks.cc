// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
  stack<int> s_push_, s_pop_;
 public:
  void push(int x) {
    while (!s_pop_.empty()) {
      int temp = s_pop_.top();
      s_push_.push(temp);
      s_pop_.pop();
    }
    s_push_.push(x);
  }

  int pop() {
    while (!s_push_.empty()) {
      int temp = s_push_.top();
      s_pop_.push(temp);
      s_push_.pop();
    }
    int temp = s_pop_.top();
    s_pop_.pop();
    cout << "popping " << temp << endl;
    return temp;
  }

  int peek() {
    while (!s_push_.empty()) {
      int temp = s_push_.top();
      s_pop_.push(temp);
      s_push_.pop();
    }
    cout << "peek " << s_pop_.top() << endl;
    return s_pop_.top();
  }

  bool empty() {
    return s_push_.empty() && s_pop_.empty();
  }
};

int main() {
  MyQueue que;
  que.push(1);
  que.push(2);
  que.pop();    // pop 1
  que.push(3);
  que.push(4);
  que.peek();   // peek 2
  que.pop();    // pop 2
  que.pop();    // pop 3
  que.peek();   // peek 4
  que.pop();    // pop 4
}