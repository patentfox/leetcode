//
//  28_create_strstr.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 30.06.21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "") {
      return 0;
    }
    if (needle.size() > haystack.size()) {
      return -1;
    }
    int i = 0, j;
    while (i <= haystack.size() - needle.size()) {
      j = 0;
      while (j < needle.size() && haystack[i + j] == needle[j]) {
        ++j;
      }
      if (j == needle.size()) {
        return i;
      } else {
        ++i;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  assert(sol.strStr("hello", "ll") == 2);
}
