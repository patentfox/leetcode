//
//  53_maximum_subarray.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 01.07.21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int maxSubArray(const vector<int>& nums) {
    int maxSum = *max_element(nums.begin(), nums.end());
    if (maxSum < 0) {
      return maxSum;
    }
    int runningSum = 0;
    for (int x: nums) {
      if (x > 0) {
        runningSum += x;
        maxSum = max(maxSum, runningSum);
      } else {
        if (runningSum + x > 0) {
          runningSum += x;
        } else {
          runningSum = 0;
        }
      }
    }
    return maxSum;
  }
};

int main() {
  Solution sol;
  assert(sol.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
  assert(sol.maxSubArray({1}) == 1);
  assert(sol.maxSubArray({5, 4, -1, 7, 8}) == 23);
}
