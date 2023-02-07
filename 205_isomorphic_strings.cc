// https://leetcode.com/problems/isomorphic-strings/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    return isomorphicHelper(s, t) && isomorphicHelper(t, s);
  }

 private:
  bool isomorphicHelper(string s, string t) {
    unordered_map<char, char> mapping;
    for (int i = 0; i < s.size(); ++i) {
      char c1 = s[i], c2 = t[i];
      auto it = mapping.find(c1);
      if (it != mapping.end()) {
        if (c2 != it->second) {
          return false;
        }
      } else {
        mapping[c1] = c2;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  assert(sol.isIsomorphic("egg", "add"));
  assert(!sol.isIsomorphic("foo", "bar"));
}