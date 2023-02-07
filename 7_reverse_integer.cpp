// https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    if (x == 0 || x == INT_MIN) {
      return 0;
    }
    int sgn = x / abs(x);
    x = abs(x);
    int rev = 0;
    while (x != 0) {
      int temp = (long) rev * 10;
      if (temp / 10 != rev) {
        return 0;
      }
      rev = temp;
      temp = (long) rev + x % 10;
      if (temp < 0) {
        return 0;
      }
      rev = temp;
      x /= 10;
    }
    return rev * sgn;
  }
};

int main() {
  Solution sol;
  cout << sol.reverse(123) << endl;
}
