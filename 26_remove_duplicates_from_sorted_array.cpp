//
//  26_remove_duplicates_from_sorted_array.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 30.06.21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int i = 1;
    int shift = 0;
    while (i < nums.size()) {
      if (nums[i] == nums[i - shift - 1]) {
        ++shift;
      } else {
        nums[i - shift] = nums[i];
      }
      ++i;
    }
    return i - shift;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 1, 2};
  assert(sol.removeDuplicates(nums) == 2);
}
