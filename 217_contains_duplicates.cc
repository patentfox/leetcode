// https://leetcode.com/problems/contains-duplicate/description/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> num_set;
    for(int x: nums) {
      num_set.insert(x);
    }
    return num_set.size() != nums.size();
  }
};