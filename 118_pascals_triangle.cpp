// https://leetcode.com/problems/pascals-triangle/

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result = {{1}};
    for (int i = 1; i < numRows; ++i) {
      vector<int> row{1};
      for (int j = 1; j < i; ++j) {
        row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
      }
      row.push_back(1);
      result.push_back(row);
    }
    return result;
  }
};

int main() {
  Solution s;
  myutils::print(s.generate(5)[4]);
}