#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int i = 0;
    string word = "";
    bool wordEnd = false;
    while (i < s.size()) {
      if (s[i] == ' ') {
        wordEnd = true;
      } else {
        if (wordEnd) {
          word = string(1, s[i]);
          wordEnd = false;
        } else {
          word += s[i];
        }
      }
      ++i;
    }
    return (int) word.size();
  }
};

int main() {
  Solution sol;
  assert(sol.lengthOfLastWord("hello there") == 5);
}
