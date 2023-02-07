// https://leetcode.com/problems/reverse-bits/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    int reversed = 0;
    int count = 32;
    while (count-- > 0) {
      reversed = reversed * 2 + n % 2;
      n /= 2;
    }
    return reversed;
  }
};

int main() {
  Solution obj;
  assert(obj.reverseBits(43261596) == 964176192);
}