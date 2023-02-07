// https://leetcode.com/problems/valid-palindrome/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    s = transform(s);
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

 private:
  string transform(string input) {
    string result;
    for (char c : input) {
      if (c >= 'A' && c <= 'Z') {
        result.push_back(static_cast<char>(tolower(c)));
      } else if (isalnum(c)) {
        result.push_back(c);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
}