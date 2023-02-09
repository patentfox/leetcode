// https://leetcode.com/problems/summary-ranges/

#include <vector>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(const vector<int>& nums) {
    vector<string> result;
    int start = 0;
    while (start < nums.size()) {
      int end = findConsecutiveIndex(nums, start);
      string range = to_string(nums[start]);
      if (end > start) {
        range += "->" + to_string(nums[end]);
      }
      result.push_back(range);
      start = end + 1;
    }
    return result;
  }
 private:
  int findConsecutiveIndex(const vector<int>& nums, int start_index) {
    int end_index = start_index + 1;
    while (end_index < nums.size()
        && nums[end_index] == nums[end_index - 1] + 1) {
      ++end_index;
    }
    return end_index - 1;
  }
};

int main() {
  Solution sol;
  myutils::print(sol.summaryRanges({0, 1, 2, 4, 5, 7}));
}