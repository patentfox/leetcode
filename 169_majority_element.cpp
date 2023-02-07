// https://leetcode.com/problems/majority-element/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// Uses Boyer-Moore Majority vote algorithm
// https://www.techiedelight.com/find-majority-element-in-an-array-boyer-moore-majority-vote-algorithm/
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int current = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (count > 0) {
        count += nums[i] == current ? 1 : -1;
      } else {
        current = nums[i];
        count = 1;
      }
    }
    return current;
  }
};