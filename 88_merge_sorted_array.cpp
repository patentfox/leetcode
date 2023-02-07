#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // shift elements of nums1 to back
    for (int i = m - 1; i >= 0; --i) {
      nums1[i + n] = nums1[i];
    }

    // now merge
    int i = n, j = 0, k = 0;
    while (i < m + n && j < n) {
      if (nums1[i] < nums2[j]) {
        nums1[k++] = nums1[i++];
      } else {
        nums1[k++] = nums2[j++];
      }
    }
    while (i < m + n) {
      nums1[k++] = nums1[i++];
    }
    while (j < n) {
      nums1[k++] = nums2[j++];
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  sol.merge(nums1, 3, nums2, 3);
  myutils::print(nums1);
}
