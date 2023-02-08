// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(const vector<string>& strs) {
    char common[200];
    bool shouldBreak = false;
    for (int i = 0; i < 200; ++i) {
      if (strs[0].size() == i) {
        common[i] = 0;
        break;
      }
      char c = strs[0][i];
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[j].size() == i || strs[j][i] != c) {
          shouldBreak = true;
          break;
        }
      }
      if (!shouldBreak) {
        common[i] = c;
      } else {
        common[i] = 0;
        break;
      }
    }

    return string(common);
  }
};

int main() {
  Solution sol;
  assert(sol.longestCommonPrefix({"flower", "flow", "flight"}) == "fl");
  assert(sol.longestCommonPrefix({"dog", "racecar", "car"}) == "");
  assert(sol.longestCommonPrefix({""}) == "");
}
