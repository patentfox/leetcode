// https://leetcode.com/problems/implement-stack-using-queues/

#include <queue>
#include <iostream>
using namespace std;

class MyStack {
  queue<int> q1;
  queue<int> q2;
  bool use_q1;

 public:
  MyStack() : use_q1(true) {}

  void push(int x) {
    use_q1 ? q1.push(x) : q2.push(x);
  }

  int pop() {
    int x;
    if (use_q1) {
      int sz = q1.size();
      for (int i = 0; i < sz - 1; ++i) {
        q2.push(q1.front());
        q1.pop();
      }
      x = q1.front();
      q1.pop();
      use_q1 = false;
    } else {
      int sz = q2.size();
      for (int i = 0; i < sz - 1; ++i) {
        q1.push(q2.front());
        q2.pop();
      }
      x = q2.front();
      q2.pop();
      use_q1 = true;
    }
    return x;
  }

  int top() {
    int x = pop();
    push(x);
    return x;
  }

  bool empty() {
    return q1.empty() && q2.empty();
  }
};

int main() {
  MyStack* obj = new MyStack();
  for (int i = 0; i < 5; ++i) {
    obj->push(i);
  }
  for (int i = 0; i < 5; ++i) {
    cout << "Top: " << obj->top() << endl;
    cout << "Pop: " << obj->pop() << endl << endl;
  }
  assert(obj->empty());
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */