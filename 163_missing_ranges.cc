// https://leetcode.com/problems/missing-ranges/

#include <vector>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
 public:
  vector<string> findMissingRanges(const vector<int>& nums,
                                   int lower,
                                   int upper) {
    int index = 0;
    int current = lower;
    vector<string> ranges;
    while (index < nums.size()) {
      if (current < nums[index]) {
        string range = to_string(current);
        if (current + 1 < nums[index]) {
          range += "->" + to_string(nums[index] - 1);
        }
        ranges.push_back(range);
      }
      current = nums[index] + 1;
      ++index;
    }
    if (current == upper) {
      ranges.push_back(to_string(upper));
    } else if (current < upper) {
      ranges.push_back((to_string(current) + "->" + to_string(upper)));
    }
    return ranges;
  }
};

int main() {
  Solution sol;
  vector<string> result = sol.findMissingRanges({0, 1, 3, 50, 75}, 0, 99);
  myutils::print(result);
}