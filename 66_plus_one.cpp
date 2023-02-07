#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(const vector<int>& digits) {
    vector<int> result(digits.size() + 1);
    int i = (int) digits.size() - 1;
    int carry = 1;
    while (i >= 0) {
      int newDigit = digits[i] + carry;
      carry = 0;
      if (newDigit >= 10) {
        newDigit %= 10;
        carry = 1;
      }
      result[i + 1] = newDigit;
      --i;
    }
    if (carry == 1) {
      result[0] = 1;
      return result;
    } else {
      return vector<int>(result.begin() + 1, result.end());
    }
  }
};

int main() {
  Solution sol;
  assert(sol.plusOne({1, 2, 3}) == vector<int>({1, 2, 4}));
  assert(sol.plusOne({0}) == vector<int>({1}));
  assert(sol.plusOne({1, 9}) == vector<int>({2, 0}));
  assert(sol.plusOne({9, 9}) == vector<int>({1, 0, 0}));
  cout << "Success\n";
}
