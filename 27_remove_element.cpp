#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }
    int i = 0, j = (int) nums.size() - 1;
    while (i < j) {
      if (nums[i] == val) {
        swap(nums[i], nums[j--]);
      } else {
        ++i;
      }
    }
    return nums[i] == val ? i : i + 1;
  }
};

int main() {
  vector<int> nums = {3, 2, 2, 3};
  Solution sol;
  assert(sol.removeElement(nums, 3) == 2);
}
