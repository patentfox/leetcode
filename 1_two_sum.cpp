// https://leetcode.com/problems/two-sum/

#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<NumAndIndex> vec;
    for (int i = 0; i < nums.size(); ++i) {
      vec.push_back({nums[i], i});
    }
    sort(vec.begin(), vec.end(),
         [](NumAndIndex a, NumAndIndex b) {
           return a.num < b.num;
         });
    for (int i = 0; i < nums.size() - 1; ++i) {
      int first = vec[i].num;
      int second = target - first;
      int index = search(vec, i + 1, (int) vec.size() - 1, second);
      if (index != -1) {
        return {vec[i].index, vec[index].index};
      }
    }
    return {};
  }

 private:
  struct NumAndIndex {
    int num;
    int index;
  };
  int search(const vector<NumAndIndex>& vec, int start, int end, int val) {
    if (start > end) {
      return -1;
    }
    int mid = (start + end) / 2;
    if (vec[mid].num == val) {
      return mid;
    }
    if (val > vec[mid].num) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    return search(vec, start, end, val);
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 2, 4};
  myutils::print(sol.twoSum(nums, 6));
}
