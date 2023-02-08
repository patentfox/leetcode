// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;

    int i = 0;
    while (i < s.size()) {
      char expected = 0;
      if (s[i] == ')') {
        expected = '(';
      } else if (s[i] == '}') {
        expected = '{';
      } else if (s[i] == ']') {
        expected = '[';
      }
      if (expected == 0) {
        st.push(s[i]);
      } else {
        if (!st.empty() && st.top() == expected) {
          st.pop();
        } else {
          return false;
        }
      }
      ++i;
    }
    return st.empty();
  }
};

int main() {
  Solution sol;
  assert(sol.isValid("") == true);
  assert(sol.isValid("{{}}") == true);
  assert(sol.isValid("{}[]") == true);
  assert(sol.isValid("{}[()]") == true);
  assert(sol.isValid("{}[(()]") == false);
  assert(sol.isValid("{{}") == false);
  assert(sol.isValid("}") == false);
}
