//
//  35_search_insert_position.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 30.06.21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int searchInsert(const vector<int>& nums, int target) {
    return position(nums, 0, (int) nums.size() - 1, target);
  }

 private:
  int position(const vector<int>& nums, int start, int end, int target) {
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (mid == start) {
      if (target < nums[start]) {
        return start;
      } else if (target > nums[end]) {
        return end + 1;
      }
      return start + 1;
    }
    if (nums[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    return position(nums, start, end, target);
  }
};

int main() {
  Solution sol;
  assert(sol.searchInsert({1, 3, 5, 6}, 5) == 2);
  assert(sol.searchInsert({1, 3, 5, 6}, 2) == 1);
  assert(sol.searchInsert({1, 3, 5, 6}, 7) == 4);
  assert(sol.searchInsert({1, 3}, 0) == 0);
}
