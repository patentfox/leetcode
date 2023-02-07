// https://leetcode.com/problems/pascals-triangle-ii/

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    int num_elements = rowIndex + 1;
    vector<int> triangle_row(num_elements, 0);
    for (int i = 0; i <= rowIndex; ++i) {
      populateRow(triangle_row, i);
    }
    return triangle_row;
  }

 private:
  void populateRow(vector<int>& row, int row_number) {
    if (row_number == 0) {
      row[0] = 1;
      return;
    }
    int index = 1;
    int temp_prev = 1, temp_cur;
    while (index < row_number) {
      temp_cur = row[index];
      row[index] += temp_prev;
      temp_prev = temp_cur;
      ++index;
    }
    row[index] = 1;
  }
};

int main() {
  Solution sol;
  int row_num;
  while (cin >> row_num) {
    myutils::print(sol.getRow(row_num));
  }
}

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/