// https://leetcode.com/problems/single-number/

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int x : nums) {
      result ^= x;
    }
    return result;
  }
};