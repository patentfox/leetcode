// https://leetcode.com/problems/excel-sheet-column-title/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string title = "";

    while (columnNumber > 0) {
      char c = (columnNumber - 1) % 26 + 'A';
      title.push_back(c);
      columnNumber = (columnNumber - 1) / 26;
    }
    std::reverse(title.begin(), title.end());
    return title;
  }
};

int main() {
  Solution s;
  assert(s.convertToTitle(2) == "B");
  assert(s.convertToTitle(28) == "AB");
  assert(s.convertToTitle(26) == "Z");
  assert(s.convertToTitle(52) == "AZ");
  assert(s.convertToTitle(701) == "ZY");
}
