// https://leetcode.com/problems/happy-number/

#include <set>
using namespace std;

class Solution {
 public:
  bool isHappy(int num) {
    set<int> seen_set;
    while (num > 1) {
      if (seen_set.find(num) != seen_set.end()) {
        return false;
      }
      seen_set.insert(num);
      num = sum_digits_squared(num);
    }
    return true;
  }

 private:
  int sum_digits_squared(int num) {
    int result = 0;
    while (num > 0) {
      int digit = num % 10;
      result += digit * digit;
      num /= 10;
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(!sol.isHappy(2));
  assert(sol.isHappy(19));
}