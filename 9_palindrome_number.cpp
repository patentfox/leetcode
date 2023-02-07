// https://leetcode.com/problems/palindrome-number/

#include <iostream>
using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    long rev = 0;
    int y = x;
    while (y > 0) {
      rev *= (long) 10;
      rev += (long) y % 10;
      y /= 10;
    }
    return rev == x;
  }
};

int main() {
  Solution sol;
  assert(sol.isPalindrome(121) == true);
  assert(sol.isPalindrome(123) == false);
  assert(sol.isPalindrome(-121) == false);
}

