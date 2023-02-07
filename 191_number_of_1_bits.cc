#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "utils.h"
using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int num_set_bits = 0;
    while (n > 0) {
      if (n % 2 == 1) {
        ++num_set_bits;
      }
      n /= 2;
    }
    return num_set_bits;
  }
};

int main() {
  Solution obj;
  assert(obj.hammingWeight(5) == 2);
}
