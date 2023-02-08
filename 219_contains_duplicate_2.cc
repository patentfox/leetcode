// https://leetcode.com/problems/contains-duplicate-ii/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(const vector<int>& nums, int k) {
    vector<pair<int, int>> num_index;
    for (int i = 0; i < nums.size(); ++i) {
      num_index.emplace_back(nums[i], i);
    }
    sort(num_index.begin(),
         num_index.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.first < b.first ? 1 : (a.first > b.first ? 0 : a.second
               < b.second);
         });
    int i = 1;
    while (i < num_index.size()) {
      if (num_index[i].first == num_index[i - 1].first
          && num_index[i].second - num_index[i - 1].second <= k) {
        return true;
      }
      ++i;
    }
    return false;
  }
};

int main() {
  Solution sol;
  assert(sol.containsNearbyDuplicate({1, 2, 3, 1}, 3));
  assert(!sol.containsNearbyDuplicate({1,2,3,1,2,3}, 2));
  assert(sol.containsNearbyDuplicate({1,0,1,1}, 1));
}